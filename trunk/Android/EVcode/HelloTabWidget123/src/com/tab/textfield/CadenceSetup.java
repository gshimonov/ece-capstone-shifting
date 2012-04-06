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

public class CadenceSetup extends Activity implements OnClickListener {

	EditText pow;
	EditText cad;
	UserParam u;
	Button back;
	String c;
	String p;
	TextView txt;
	
	@Override 
	public void onCreate (Bundle savedInstanceState) {
		 super.onCreate(savedInstanceState);
	        setContentView(R.layout.main_usercad);

        back = (Button) findViewById(R.id.button2);
        pow = (EditText) findViewById(R.id.editpow);
        cad = (EditText) findViewById(R.id.editcad);
        txt = (TextView) findViewById(R.id.txtdebug);
        
        back.setOnClickListener(this);

      
    }
    public void onClick(View view) {
    	int x;
    	int y;
    	int w;
    	int z;
    	try{
    	p = pow.getText().toString();
    	c = cad.getText().toString();
    	}
    	catch(NumberFormatException e){
    	Log.e("NullPointerErrrrrrorz","Ball-Titties");
    	}
    	
    	
    	if (p.isEmpty() || c.isEmpty()){

            Intent intent = new Intent();
            setResult(RESULT_CANCELED, intent);
            finish();
        	
        
    		}
    	else{
    	
    	
        Intent intent = new Intent();

        intent.putExtra("Cad1", c);
        intent.putExtra("Pow1", p);
        setResult(RESULT_OK, intent);
        finish();
        
    }
    
    }
}
