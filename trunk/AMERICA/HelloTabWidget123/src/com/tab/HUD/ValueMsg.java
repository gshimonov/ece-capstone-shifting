package com.tab.HUD;
public class ValueMsg {
	private int reading;
	private int gear;
	private int cadence;

 
	public ValueMsg(int reading , int gear, int cadence) {

		this.reading = reading;
		this.gear = gear;
		this.cadence = cadence;

	}
 
	public int getReading() {
		return reading;
	}
	public int getGear() {
		return gear;
	}
	public int getCadence() {
		return cadence;
	}
 
}
