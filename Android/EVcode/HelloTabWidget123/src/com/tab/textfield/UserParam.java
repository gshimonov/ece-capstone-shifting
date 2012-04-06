package com.tab.textfield;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.TextView;

import com.tab.R;

public class UserParam extends Activity implements OnClickListener{

Integer rider=0;
Integer cad=2;
Integer pow=3;
Integer slide=52;
Integer bike=1;
TextView txt;


	@Override
	public void onCreate(Bundle savedInstanceState){
		 super.onCreate(savedInstanceState);
	        setContentView(R.layout.main_userpref);
	        
	 	   Button button = (Button) findViewById(R.id.buttonRider);
	 	  Button button1 = (Button) findViewById(R.id.buttonCad);
	 	 Button button2 = (Button) findViewById(R.id.buttonSlider);
	 	txt = (TextView) findViewById(R.id.txtdebug);
	       
	 	   button.setOnClickListener(this);
	 	  button2.setOnClickListener(this);
	 	 button1.setOnClickListener(this);
	 	
	 	 txt.setText("AMERICANA");
	 	 
	 	  
	
	}
	
	public void onClick(View view) {
	    switch (view.getId()) {
        case R.id.buttonRider: 
        	Intent myIntent = new Intent(view.getContext(), WeightSetup.class);
        	myIntent.putExtra("Rider", rider.toString());
        	myIntent.putExtra("Biker", bike.toString());
            startActivityForResult(myIntent, 0);
         break;
        case R.id.buttonCad:
        	Intent myIntent1 = new Intent(view.getContext(), CadenceSetup.class);
        	myIntent1.putExtra("Cad", cad.toString());
        	myIntent1.putExtra("Pow", pow.toString());
            startActivityForResult(myIntent1, 1);
         break;
        case R.id.buttonSlider:
        	Intent myIntent2 = new Intent(view.getContext(), com.tab.seek.Seek.class);
        	myIntent2.putExtra("Slider", slide.toString());
            startActivityForResult(myIntent2, 2);
         break;
     }
  }

	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data){
		switch(requestCode) {
	      case 0: 
	            if (resultCode == RESULT_OK) {
	             String   r = data.getStringExtra("Rider1");
	              String  b = (String) data.getStringExtra("Biker1");
	              if (r != null && b != null){
	              try{
	              rider = Integer.parseInt(r);
	              bike = Integer.parseInt(b);
	              txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
	              }
	              catch(NullPointerException e){
	            	  Log.e("NullPointerErrrrrrorz","Check to see String to INT");
	              }
	              }

	            }
	            else {
	            	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
	              }
	            break;
	      case 1: 
		        if (resultCode == RESULT_OK) {

			             String   c = data.getStringExtra("Cad1");
			              String  p = (String) data.getStringExtra("Pow1");
			              if (c != null && p != null){
				         try{
			              cad = Integer.parseInt(c);
			              pow = Integer.parseInt(p);
			              txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
				              }
				         catch(NullPointerException e){
				            	  Log.e("NullPointerErrrrrrorz","Check to see String to INT");
				              }
			              }
		                break;           
		        	}
		        else{
		        	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
		        }
	            
				
	      case 2: 
		        if (resultCode == RESULT_OK) {

			             String s = data.getStringExtra("Slide1");
			             if (s != null){
			              slide = Integer.parseInt(s);
			              txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
			             }
		                break;           
		        	}
		        else{
		        	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
		        }
	            
		}
	}
	
}
