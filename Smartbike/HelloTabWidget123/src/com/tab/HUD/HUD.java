package com.tab.HUD;

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
public class HUD extends Activity implements Orientation_Listener, Runnable {

	// TAG is used to debug in Android logcat console
	private static final String TAG = "ArduinoAccessory_CUZTOM DEBUG";

	private static final String ACTION_USB_PERMISSION = "com.google.android.DemoKit.action.USB_PERMISSION";

	private UsbManager mUsbManager;
	private PendingIntent mPermissionIntent;
	private boolean mPermissionRequestPending;
	private ToggleButton buttonLED;
	float pitcher;


	TextView mResponseField_s;
	TextView mResponseField_c;
	TextView mResponseField_g;
	UsbAccessory mAccessory;
	ParcelFileDescriptor mFileDescriptor;
	FileInputStream mInputStream;
	FileOutputStream mOutputStream;
	
	float pitchReturn;
	Values valor;
	Serialz serial;
	int AMERICA=99;
		
	private static Context CONTEXT;
	
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
		setupbroadcaster();
        setContentView(R.layout.main_hud);
        CONTEXT = this;
        mResponseField_s = (TextView)findViewById(R.id.Speed);
        mResponseField_c = (TextView)findViewById(R.id.Cadence);
        mResponseField_g = (TextView)findViewById(R.id.Gears);
        valor = (Values) getApplicationContext();
//        run.start();

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
		
		
//		((TextView) findViewById(R.id.pitch)).setText(
//				String.valueOf(pitch));
//
//		pitcher=pitch;
//		if(ByteOrder.LITTLE_ENDIAN == ByteOrder.nativeOrder()){
//		 AMERICA = -1;
//	}
//	
//	if(ByteOrder.BIG_ENDIAN == ByteOrder.nativeOrder()){
//	      AMERICA = 1;
//	}
	

		
	}
	
	public void run() {
//		((TextView) findViewById(R.id.roll)).setText("r:"+valor.getrider()+" b:"+valor.getbike()+
//				" cad:"+valor.getcad()+" pow:"+valor.getpow()+" slide:"+valor.getslider());
		int ret = 0;
		byte[] buffer = new byte[4];
		int i;
		byte [] buffer2 = new byte[12];
		byte[] buffer_pitch = new byte[10];
		byte[] buffer_pow = new byte[5];
		byte[] buffer_cad = new byte[5];
		byte[] buffer_ride = new byte[5];
		
 
		while (true) { // read data
			try {
				ret = mInputStream.read(buffer);
			} catch (IOException e) {
				break;
			}
 
			i = 0;
			while (i < ret) {
				int len = ret - i;
				if (len >= 3) {
					
					Message m = Message.obtain(mHandler);
					int speed = (int) buffer[i];
					int gear = (int) buffer[i+1];
					int cadence = (int) buffer[i+2];
//					int value_2= (int)buffer[i+1];
					// 'f' is the flag, use for your own logic
					// value is the value from the arduino
					m.obj = new ValueMsg(speed, gear, cadence);
					mHandler.sendMessage(m);
				}
				i += 3; // number of bytes sent from arduino
			}
		

			int floatBits = Float.floatToIntBits(pitcher);
			
			buffer_pitch[0] = (byte)(floatBits >> 24);
			buffer_pitch[1] = (byte)(floatBits >> 16);
			buffer_pitch[2] = (byte)(floatBits >> 8);
			buffer_pitch[3] = (byte)(floatBits);	
			
			
			buffer_pow[0]=(byte) ((valor.getpow() & 0x0000FF00) >> 8);
			buffer_pow[1]=(byte) (valor.getpow() & 0x000000FF);
			
			buffer_cad[0]=(byte) ((valor.getcad() & 0x0000FF00) >> 8);
			buffer_cad[1]=(byte) (valor.getcad() & 0x000000FF);
			
			buffer_ride[0]=(byte) ((valor.getrider() & 0x0000FF00) >> 8);
			buffer_ride[1]=(byte) (valor.getrider() & 0x000000FF);
			
			
				Log.e("!!!!!!!!!HelloBIKEPROJECT", "POWER: "+buffer_pow[0]+"|"+buffer_pow[1]+"|" +buffer_pow[2]+"|"+buffer_pow[3]+"|"+buffer_pow[4]+
				" buffer3: " +buffer_pitch[0]+" "+buffer_pitch[1]+" "+buffer_pitch[2]+" "+buffer_pitch[3]+" " +
				" buffer2:"+buffer2[4]+" "+buffer2[5]+" "+buffer2[6]+" "+buffer2[7]);
				buffer2[0]=(byte) buffer_pitch[0];
				buffer2[1]=(byte) buffer_pitch[1];
				buffer2[2]=(byte) buffer_pitch[2];
				buffer2[3]=(byte) buffer_pitch[3];
				buffer2[4]=(byte) valor.getbike();
				buffer2[5]=(byte) buffer_ride[0];
				buffer2[6]=(byte) buffer_ride[1];
				buffer2[7]=(byte) buffer_cad[0];
				buffer2[8]=(byte) buffer_cad[1];
				buffer2[9]=(byte) valor.getslider();
				buffer2[10]=(byte) buffer_pow [0];
				buffer2[11]=(byte) buffer_pow [1];
				
			if (mOutputStream != null) {
				try {
					mOutputStream.write(buffer2);
					Log.e("!!!!SPEED_VALUE_WRITE_SUCCESS", "buff: "+buffer2[0]+buffer2[1]+buffer2[2]+buffer2[3]+
							buffer2[4]+buffer2[5]+buffer2[6]+buffer2[7]+buffer2[8]+buffer2[9]);
				} catch (IOException e) {
					Log.e(TAG, "write failed", e);
				}

			}
			
		}
		
	}
	
	
	Handler mHandler = new Handler() {
		@Override
		public void handleMessage(Message msg) {
			ValueMsg t = (ValueMsg) msg.obj;
			// this is where you handle the data you sent. You get it by calling the getReading() function
			mResponseField_s.setText(" "+t.getReading());
			mResponseField_c.setText(" "+t.getCadence());
			mResponseField_g.setText(" "+t.getGear());
		}
	};
	
	@Override
	public void onBackPressed(){

    	this.onDestroy();
     	super.onBackPressed();
        this.finish();
	}
	
    
}