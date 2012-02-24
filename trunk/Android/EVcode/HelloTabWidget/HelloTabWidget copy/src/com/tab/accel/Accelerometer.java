package com.tab.accel;

import com.tab.R;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.widget.TextView;
import android.widget.Toast;

/**
 * Android accelerometer sensor tutorial
 * @author antoine vianey
 * under GPL v3 : http://www.gnu.org/licenses/gpl-3.0.html
 */
public class Accelerometer extends Activity implements Accelerometer_Listener {
	
	private static Context CONTEXT;
	
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main_accel);
        CONTEXT = this;
    }

    protected void onResume() {
    	super.onResume();
    	if (Accelerometer_Manager.isSupported()) {
    		Accelerometer_Manager.startListening(this);
    	}
    }
    
    protected void onDestroy() {
    	super.onDestroy();
    	if (Accelerometer_Manager.isListening()) {
    		Accelerometer_Manager.stopListening();
    	}
    	
    }
	
    public static Context getContext() {
		return CONTEXT;
	}

    /**
     * onShake callback
     */
	public void onShake(float force) {
		Toast.makeText(this, "Phone shaked : " + force, 1000).show();
	}

	/**
	 * onAccelerationChanged callback
	 */
	public void onAccelerationChanged(float x, float y, float z) {
		((TextView) findViewById(R.id.x)).setText(String.valueOf(x));
		((TextView) findViewById(R.id.y)).setText(String.valueOf(y));
		((TextView) findViewById(R.id.z)).setText(String.valueOf(z));
	}
    
}