package com.tab.textfield;

import android.app.Application;

public class Values extends Application {
	private Integer rider=0;
	private Integer bike=0;
	private int cad=0;
	private int pow=0;
 
	public void Valuesetrider(Integer rider, Integer bike) {
		this.rider = rider;
		this.bike = bike;
		
	}
	
	public void Valuesetcad(Integer cad, Integer pow) {
		this.cad = cad;
		this.pow = pow;
	}
 
	public int getrider() {
		return rider;
	}
	
	public int getbike() {
		return bike;
	}
	
	public int getpow() {
		return pow;
	}
	
	public int getcad() {
		return cad;
	}
}
