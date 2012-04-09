package com.tab.textfield;

import android.app.Application;

public class Values extends Application {
	public Integer rider=70;
	public Integer bike=8;
	public int cad=60;
	public int pow=150;
	public int slide=50;
	
	public void Valuesetall(Integer rider, Integer bike, Integer cad, Integer pow, Integer slide){
		this.rider = rider;
		this.bike = bike;
		this.cad = cad;
		this.pow = pow;
		this.slide=slide;
	}
 
	public void Valuesetrider(Integer rider, Integer bike) {
		this.rider = rider;
		this.bike = bike;
		
	}
	
	public void Valuesetcad(Integer cad, Integer pow) {
		this.cad = cad;
		this.pow = pow;
	}
	
	public void Valuesetslider(Integer slide){
		this.slide=slide;
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
	public int getslider() {
		return slide;
	}
}
