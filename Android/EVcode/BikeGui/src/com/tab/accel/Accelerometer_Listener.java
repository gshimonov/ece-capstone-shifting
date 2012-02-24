package com.tab.accel;

public interface Accelerometer_Listener {

	public void onAccelerationChanged(float x, float y, float z);
	
	public void onShake(float force);
	
}
