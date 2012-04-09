package com.tab.textfield;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import com.tab.R;


public class WeightSetup extends Activity implements OnClickListener {

	EditText rider;
	EditText bike;
	UserParam u;
	String r;
	String b;
	TextView txt;
	Bundle extras;
	Values valor;
	
	
	@Override 
	public void onCreate (Bundle savedInstanceState) {
		 super.onCreate(savedInstanceState);
	        setContentView(R.layout.main_userw);
	        
	   Button button = (Button) findViewById(R.id.button1);
	        button.setOnClickListener(this);
	        

	      rider = (EditText) findViewById(R.id.editriderw);
	      bike = (EditText) findViewById(R.id.editbikew);
	      txt = (TextView) findViewById(R.id.txtdebug);
	      extras = getIntent().getExtras();
	      
	      rider.setText(extras.getString("Rider"));
	        bike.setText(extras.getString("Biker"));


	}
        
    public void onClick(View view) {
    	try{
        	r = rider.getText().toString();
        	b = bike.getText().toString();
        	}
        	catch(NumberFormatException e){
        	Log.e("NullPointerErrrrrrorz","Ball-Titties");
        	}
        	
        	
        	if (r.isEmpty() || b.isEmpty()){
        		
                Intent intent = new Intent();
                setResult(RESULT_CANCELED, intent);
                finish();
        }
        	else{
        		
//        		if (mOutputStream != null) {
//    				try {
//    					mOutputStream.write(buffer2);
//
//    				} catch (IOException e) {
//    					Log.e(TAG, "write failed", e);
//    				}
        		
//        		valor.Valuesetrider(r, b);
                Intent intent = new Intent();
                intent.putExtra("Rider1", r);
                intent.putExtra("Biker1", b);
                setResult(RESULT_OK, intent);
                finish();
        	
        	}
            
        }
    }
