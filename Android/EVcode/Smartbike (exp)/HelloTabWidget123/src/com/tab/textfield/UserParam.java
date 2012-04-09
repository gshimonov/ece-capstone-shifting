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

Integer rider=1;
Integer cad=1;
Integer pow=1;
Integer slide=50;
Integer bike=1;
TextView txt;
Values valor;
float aa;
float bb;



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
	 	valor = (Values) getApplicationContext();
	 	 
	 	  
	
	}
	
	public void onClick(View view) {
	    switch (view.getId()) {
        case R.id.buttonRider: 
        	Intent myIntent = new Intent(view.getContext(), WeightSetup.class);
        	myIntent.putExtra("Rider", rider.toString());
        	myIntent.putExtra("Biker", bike.toString());
        	myIntent.putExtra("Cad", cad.toString());
        	myIntent.putExtra("Pow", pow.toString());
        	myIntent.putExtra("Slider", slide.toString());
            startActivityForResult(myIntent, 0);
         break;
        case R.id.buttonCad:
        	Intent myIntent1 = new Intent(view.getContext(), CadenceSetup.class);
        	myIntent1.putExtra("Rider", rider.toString());
        	myIntent1.putExtra("Biker", bike.toString());
        	myIntent1.putExtra("Cad", cad.toString());
        	myIntent1.putExtra("Pow", pow.toString());
        	myIntent1.putExtra("Slider", slide.toString());
            startActivityForResult(myIntent1, 1);
         break;
        case R.id.buttonSlider:
        	Intent myIntent2 = new Intent(view.getContext(), com.tab.seek.Seek.class);
        	myIntent2.putExtra("Rider", rider.toString());
        	myIntent2.putExtra("Biker", bike.toString());
        	myIntent2.putExtra("Cad", cad.toString());
        	myIntent2.putExtra("Pow", pow.toString());
        	myIntent2.putExtra("Slider", slide.toString());
            startActivityForResult(myIntent2, 2);
         break;
     }
  }

	
	@Override
	protected void onActivityResult(int requestCode, int resultCode, Intent data){
		Log.d("NOT!!!ERRRRORRRRZZZZZZ", "check out on activity result: " +requestCode);
		switch(requestCode) {
	      case 0: 
//	            if (resultCode == RESULT_OK) {
//	             String   r = data.getStringExtra("Rider1");
//	              String  b = (String) data.getStringExtra("Biker1");
//	              aa = Float.valueOf(r);
//	              bb = Float.valueOf(b);
//	              if (r != null && b != null && aa < 2140000000 && bb < 2140000000){
//	              try{
//	            	  
//	            	rider = Integer.valueOf(r);
//	            	bike = Integer.valueOf(b);
//	              if(rider>200){
//	            	  rider=200;
//	              }
//	              if(bike>30){
//	            	  bike=30;
//	              }
//	              
//	              txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
//	              valor.Valuesetall(rider, bike, cad, pow, slide);
//	              Log.d("ERRRRORRRRZZZZZZ", "Values set Result-OK");
//	              }
//
//	              catch(NullPointerException e){
//	            	  Log.e("NullPointerErrrrrrorz","Check to see String to INT RIDER1");
//	              }
//	              }
//
//	            }
//	            
//	            
//	            else {
//	            	rider=200;
//	            	bike=30;
//	            	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
//	            	 Log.e("NULLLPOINTERSZZZZ", "resultscode "+resultCode+" null value strings");
//	            	 
//	              }
	    	  
	    	  
	    	  
		        if (resultCode == RESULT_OK) {
		        	String   r = data.getStringExtra("Rider1");
		            String  b = (String) data.getStringExtra("Biker1");
		            aa = Float.valueOf(r);
		            bb = Float.valueOf(b);
			             
			        	if (r != null && b != null && aa < 2140000000 && bb < 2140000000){
			        		try{
			        			rider = Integer.valueOf(r);
				            	bike = Integer.valueOf(b);
				            	if(rider>200){
					            	  rider=200;
					              }
					              if(bike>30){
					            	  bike=30;
					              }

					       txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
			               valor.Valuesetall(rider, bike, cad, pow, slide);
			        		   }
			        		catch(NullPointerException e){
				            	  Log.e("NullPointerErrrrrrorz","Check to see String to INT CADENCE1");
				              }
			              }
			              
					      	else{
					      		
				            	if(aa>200){
					            	  rider=200;
					              }
					              if(bb>30){
					            	  bike=30;
					              }
					        	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
					        	 Log.e("NULLLPOINTERSZZZZ", "ELSE STATEMENT");
					        }
			              
		                break;           
		       }
	      case 1: 
		        if (resultCode == RESULT_OK) {
		        	String   c = data.getStringExtra("Cad1");
		            String  p = (String) data.getStringExtra("Pow1");
		            aa = Float.valueOf(c);
		            bb = Float.valueOf(p);
			             
			        	if (c != null && p != null && aa < 2140000000 && bb < 2140000000){
			        		try{
			        			pow = Integer.valueOf(p);
				            	cad = Integer.valueOf(c);
				            	if(pow>500){
					            	  pow=500;
					              }
					              if(cad>200){
					            	  cad=200;
					              }

					       txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
			               valor.Valuesetall(rider, bike, cad, pow, slide);
			        		   }
			        		catch(NullPointerException e){
				            	  Log.e("NullPointerErrrrrrorz","Check to see String to INT CADENCE1");
				              }
			              }
			              
					      	else{
				            	if(bb > 500){
					            	  pow=500;
					              }
					              if(aa > 200){
					            	  cad=200;
					              }
					        	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
					        	 Log.e("NULLLPOINTERSZZZZ", "ELSE STATEMENT");
					        }
			              
		                break;           
		       }
	            
				
	      case 2: 
		        if (resultCode == RESULT_OK) {

			             String s = data.getStringExtra("Slide1");
			             if (s != null){
			              slide = Integer.valueOf(s);
			              
//			              double w = slide*((.2)/(100)) + .398;
			              
			              
			              txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
			              valor.Valuesetall(rider, bike, cad, pow, slide);
			             }
		                break;           
		        	}
		        else{
		        	 txt.setText("r:"+rider+" b:"+bike+" cad:"+cad+" pow:"+pow+" slide:"+slide);
		        	 Log.d("NULLLPOINTERSZZZZ", "resultscode "+resultCode+" null value strings");
		        }
	            
		}
	}
	

	
}
