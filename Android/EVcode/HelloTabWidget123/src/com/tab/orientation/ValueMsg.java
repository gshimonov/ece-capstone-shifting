package com.tab.orientation;
public class ValueMsg {
	private char flag;
	private int reading;
	private int i;
	private int j;
 
	public ValueMsg(char flag, int reading, int i, int j) {
		this.flag = flag;
		this.reading = reading;
		this.i=i;
		this.j=j;
	}
 
	public int getReading() {
		return reading;
	}
 
	public char getFlag() {
		return flag;
	}
	public int geti() {
		return i;
	}
	public int getj(){
		return j;
	}
}
