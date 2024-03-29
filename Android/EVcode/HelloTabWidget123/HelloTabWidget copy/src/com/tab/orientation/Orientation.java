package com.tab.orientation;

import java.io.FileDescriptor;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import android.app.Activity;
import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.os.ParcelFileDescriptor;
import android.util.Log;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.ToggleButton;

import com.android.future.usb.UsbAccessory;
import com.android.future.usb.UsbManager;
import com.tab.R;

/**
 * Android orientation sensor tutorial
 * @author antoine vianey
 * under GPL v3 : http://www.gnu.org/licenses/gpl-3.0.html
 */
public class Orientation extends Activity implements Orientation_Listener {

	// TAG is used to debug in Android logcat console
	private static final String TAG = "ArduinoAccessory";

	private static final String ACTION_USB_PERMISSION = "com.google.android.DemoKit.action.USB_PERMISSION";

	private UsbManager mUsbManager;
	private PendingIntent mPermissionIntent;
	private boolean mPermissionRequestPending;
	private ToggleButton buttonLED;

	
	UsbAccessory mAccessory;
	ParcelFileDescriptor mFileDescriptor;
	FileInputStream mInputStream;
	FileOutputStream mOutputStream;
	
	float pitchReturn;
	
		
	private static Context CONTEXT;
	
	private final BroadcastReceiver mUsbReceiver = new BroadcastReceiver() {
		@Override
		public void onReceive(Context context, Intent intent) {
			String action = intent.getAction();
			if (ACTION_USB_PERMISSION.equals(action)) {
				synchronized (this) {
					UsbAccessory accessory = UsbManager.getAccessory(intent);
					if (intent.getBooleanExtra(
							UsbManager.EXTRA_PERMISSION_GRANTED, false)) {
						openAccessory(accessory);
					} else {
						Log.d(TAG, "permission denied for accessory "
								+ accessory);
					}
					mPermissionRequestPending = false;
				}
			} else if (UsbManager.ACTION_USB_ACCESSORY_DETACHED.equals(action)) {
				UsbAccessory accessory = UsbManager.getAccessory(intent);
				if (accessory != null && accessory.equals(mAccessory)) {
					closeAccessory();
				}
			}
		}
	};
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        mUsbManager = UsbManager.getInstance(this);
		mPermissionIntent = PendingIntent.getBroadcast(this, 0, new Intent(ACTION_USB_PERMISSION), 0);
		IntentFilter filter = new IntentFilter(ACTION_USB_PERMISSION);
		filter.addAction(UsbManager.ACTION_USB_ACCESSORY_DETACHED);
		registerReceiver(mUsbReceiver, filter);

		if (getLastNonConfigurationInstance() != null) {
			mAccessory = (UsbAccessory) getLastNonConfigurationInstance();
			openAccessory(mAccessory);
		}
		
        setContentView(R.layout.main_orient);
        CONTEXT = this;
        buttonLED = (ToggleButton) findViewById(R.id.toggleButtonLED);
    }
    
    
    
	@Override
	public Object onRetainNonConfigurationInstance() {
		if (mAccessory != null) {
			return mAccessory;
		} else {
			return super.onRetainNonConfigurationInstance();
		}
	}
    
    
	
	//public void onResume() {
	protected void onResume() {
		super.onResume();
		
    	if (Orientation_Manager.isSupported()) {
    		Orientation_Manager.startListening(this);
		if (mInputStream != null && mOutputStream != null) {
			return;
		}

		UsbAccessory[] accessories = mUsbManager.getAccessoryList();
		UsbAccessory accessory = (accessories == null ? null : accessories[0]);
		if (accessory != null) {
			if (mUsbManager.hasPermission(accessory)) {
				openAccessory(accessory);
			} else {
				synchronized (mUsbReceiver) {
					if (!mPermissionRequestPending) {
						mUsbManager.requestPermission(accessory,mPermissionIntent);
						mPermissionRequestPending = true;
					}
				}
			}
		} else {
			Log.d(TAG, "mAccessory is null");
		}
	}
}
	
	
	
    

/*    protected void onResume() {
    	super.onResume();
    	if (OrientationManager.isSupported()) {
    		OrientationManager.startListening(this);
    	}
    }*/
    	
    @Override
    public void onPause() {
    	super.onPause();
    	closeAccessory();
    }
    
	
    protected void onDestroy() {
    	unregisterReceiver(mUsbReceiver);
    	super.onDestroy();
    	if (Orientation_Manager.isListening()) {
    		Orientation_Manager.stopListening();
    	}
    	
    }

    public static Context getContext() {
		return CONTEXT;
	}

	@Override
	public void onOrientationChanged(float azimuth, 
			float pitch, float roll) {
		((TextView) findViewById(R.id.azimuth)).setText(
				String.valueOf(azimuth));
		((TextView) findViewById(R.id.pitch)).setText(
				String.valueOf(pitch));
		((TextView) findViewById(R.id.roll)).setText(
				String.valueOf(roll));

		////////GS/////////
		pitchReturn = pitch;
		byte[] buffer2 = new byte[2];
		byte one = 1;
		byte zero = 0;
		
		/*if(buttonLED.isChecked()){
			//buffer[0]=(byte)0; // button says on, light is off
			buffer[0]=zero; // button says on, light is off
			buffer[1]=(byte)pitchReturn;
		}
		else {
			buffer[0]=one;
			buffer[1]=(byte)101;
			
			//buffer[0]=(byte)1; // button says off, light is on
		}
		*/
		if (pitch >= 0) {
			buffer2[0] = (byte)200; //200 is a code signifying angle is positive, no conversion necessary
			buffer2[1]=(byte)pitch;
		} else {
			buffer2[0] = (byte)255; //255 is a code signifying angle is negative, needs to be converted
			buffer2[1] = (byte)Math.abs(pitch);
		}
		
		//output via USB
		if (mOutputStream != null) {
			try {
				mOutputStream.write(buffer2);
				////
				//mOutputStream.write(test);
				////
			} catch (IOException e) {
				Log.e(TAG, "write failed", e);
			}
		}
		
	}
	
	private void openAccessory(UsbAccessory accessory) {
		mFileDescriptor = mUsbManager.openAccessory(accessory);
		if (mFileDescriptor != null) {
			mAccessory = accessory;
			FileDescriptor fd = mFileDescriptor.getFileDescriptor();
			mInputStream = new FileInputStream(fd);
			mOutputStream = new FileOutputStream(fd);
			Log.d(TAG, "accessory opened");
		} else {
			Log.d(TAG, "accessory open fail");
		}
	}

	private void closeAccessory() {
		try {
			if (mFileDescriptor != null) {
				mFileDescriptor.close();
			}
		} catch (IOException e) {
		} finally {
			mFileDescriptor = null;
			mAccessory = null;
		}
	}
	
//	public void sendCommand(byte command, byte target, int value) {
//		byte[] buffer = new byte[3];
//		if (value > 255)
//			value = 255;
//
//		buffer[0] = command;
//		buffer[1] = target;
//		buffer[2] = (byte) value;
//		if (mOutputStream != null && buffer[1] != -1) {
//			try {
//				mOutputStream.write(buffer);
//			} catch (IOException e) {
//				Log.e(TAG, "write failed", e);
//			}
//		}
//	}
	
	public void blinkLED(View v){
		byte[] buffer = new byte[2];
		byte one = 1;
		byte zero = 0;
		
		if(buttonLED.isChecked()){
			//buffer[0]=(byte)0; // button says on, light is off
			buffer[0]=zero; // button says on, light is off
			buffer[1]=(byte)pitchReturn;
		}
		else {
			buffer[0]=one;
			buffer[1]=(byte)101;
			
			//buffer[0]=(byte)1; // button says off, light is on
		}
		if (mOutputStream != null) {
			try {
				mOutputStream.write(buffer);
				////
				//mOutputStream.write(test);
				////
			} catch (IOException e) {
				Log.e(TAG, "write failed", e);
			}
		}
	}


	@Override
	public void onBottomUp() {
		Toast.makeText(this, "Bottom UP", 1000).show();
	}

	@Override
	public void onLeftUp() {
		Toast.makeText(this, "Left UP", 1000).show();
	}

	@Override
	public void onRightUp() {
		Toast.makeText(this, "Right UP", 1000).show();
	}

	@Override
	public void onTopUp() {
		Toast.makeText(this, "Top UP", 1000).show();
	}
    
}