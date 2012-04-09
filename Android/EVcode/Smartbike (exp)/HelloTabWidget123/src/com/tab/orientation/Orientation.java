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
import android.os.Handler;
import android.os.Message;
import android.os.ParcelFileDescriptor;
import android.util.Log;
import android.widget.TextView;
import android.widget.ToggleButton;

import com.android.future.usb.UsbAccessory;
import com.android.future.usb.UsbManager;
import com.tab.R;
import com.tab.textfield.Values;

/**
 * Android orientation sensor tutorial
 * @author antoine vianey
 * under GPL v3 : http://www.gnu.org/licenses/gpl-3.0.html
 */
public class Orientation extends Activity implements Orientation_Listener, Runnable {

	// TAG is used to debug in Android logcat console
	private static final String TAG = "ArduinoAccessory";

	private static final String ACTION_USB_PERMISSION = "com.google.android.DemoKit.action.USB_PERMISSION";

	private UsbManager mUsbManager;
	private PendingIntent mPermissionIntent;
	private boolean mPermissionRequestPending;
	private ToggleButton buttonLED;
	float pitcher;


	TextView mResponseField;
	UsbAccessory mAccessory;
	ParcelFileDescriptor mFileDescriptor;
	FileInputStream mInputStream;
	FileOutputStream mOutputStream;
	
	float pitchReturn;
	Values valor;
	Serialz serial;
	
		
	private static Context CONTEXT;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
		setupbroadcaster();
        setContentView(R.layout.main_orient);
        CONTEXT = this;
        mResponseField = (TextView)findViewById(R.id.buffer11);
        valor = (Values) getApplicationContext();

    }
    
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
	
	public void setupbroadcaster(){
        mUsbManager = UsbManager.getInstance(this);
		mPermissionIntent = PendingIntent.getBroadcast(this, 0, new Intent(ACTION_USB_PERMISSION), 0);
		IntentFilter filter = new IntentFilter(ACTION_USB_PERMISSION);
		filter.addAction(UsbManager.ACTION_USB_ACCESSORY_DETACHED);
		registerReceiver(mUsbReceiver, filter);

		if (getLastNonConfigurationInstance() != null) {
			mAccessory = (UsbAccessory) getLastNonConfigurationInstance();
			openAccessory(mAccessory);
		}
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

    	
    @Override
    public void onPause() {
    	super.onPause();
    }
	private void openAccessory(UsbAccessory accessory) {
		mFileDescriptor = mUsbManager.openAccessory(accessory);
		if (mFileDescriptor != null) {
			mAccessory = accessory;
			FileDescriptor fd = mFileDescriptor.getFileDescriptor();
			mInputStream = new FileInputStream(fd);
			mOutputStream = new FileOutputStream(fd);
			Log.d(TAG, "accessory opened");
			Thread thread = new Thread(null, this, "america");
			thread.start();
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
		((TextView) findViewById(R.id.roll)).setText("r:"+valor.getrider()+" b:"+valor.getbike()+
				" cad:"+valor.getcad()+" pow:"+valor.getpow()+" slide:"+valor.getslider());
		pitcher=pitch;

		
	}
	
	public void run() {
//		((TextView) findViewById(R.id.roll)).setText("r:"+valor.getrider()+" b:"+valor.getbike()+
//				" cad:"+valor.getcad()+" pow:"+valor.getpow()+" slide:"+valor.getslider());
		int ret = 0;
		byte[] buffer = new byte[4];
		int i;
		byte buffer2[] = new byte[12];
		int j;
		byte[] buffer3 = new byte[3];
		
//		buffer3[0]=(byte) valor.getbike();
//		buffer3[1]=(byte) valor.getrider();
//		buffer3[2]=(byte) valor.getpow();
//		buffer3[3]=(byte) valor.getcad();
//		buffer3[4]=(byte) valor.getslider();
		
 
		while (true) { // read data
			try {
				ret = mInputStream.read(buffer);
			} catch (IOException e) {
				break;
			}
 
			i = 0;
			while (i < ret) {
				int len = ret - i;
				if (len >= 1) {
					
					Message m = Message.obtain(mHandler);
					int value = (int) buffer[i];
//					int value_2= (int)buffer[i+1];
					// 'f' is the flag, use for your own logic
					// value is the value from the arduino
					m.obj = new ValueMsg('w', value,i,ret);
					mHandler.sendMessage(m);
				}
				i += 1; // number of bytes sent from arduino
			}
			j=0;

			buffer = serial.serializeObject(valor.getpow());
			
			buffer3 = serial.serializeObject(pitcher);

			
			while(j < 40){
				buffer2[0]= buffer3[0];
				buffer2[1]= buffer3[1];
				buffer2[2]= buffer3[2];
				buffer2[3]= buffer3[3];
				buffer2[4]=(byte) valor.getbike();
				buffer2[5]=(byte) valor.getrider();
				buffer2[6]=(byte) valor.getcad();
				buffer2[7]=(byte) valor.getslider();
				buffer2[8]= buffer [0];
				buffer2[9]= buffer [1];
			if (mOutputStream != null) {
				try {
					mOutputStream.write(buffer2);
					mOutputStream.write(buffer3);

				} catch (IOException e) {
					Log.e(TAG, "write failed", e);
				}
			}
			j++;
			}
			
		}
		
	}
	
	
	Handler mHandler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			ValueMsg t = (ValueMsg) msg.obj;
			// this is where you handle the data you sent. You get it by calling the getReading() function
			mResponseField.setText(" "+t.getReading());
		}
	};
	
    
}