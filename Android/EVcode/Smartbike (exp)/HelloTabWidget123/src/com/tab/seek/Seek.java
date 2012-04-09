package com.tab.seek;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;

import com.tab.R;
import com.tab.textfield.Values;

public class Seek extends Activity implements OnSeekBarChangeListener, OnClickListener{
	private SeekBar bar;
	private int progression;
	private TextView textProgress;
	private com.tab.textfield.UserParam user;
	private Button back;
	Bundle extras;
	String sliderp;
	Values valor;
	
	int prog1;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        // load the layout
        setContentView(R.layout.main_seek);
        bar = (SeekBar)findViewById(R.id.seekbar); // make seekbar object
        bar.setOnSeekBarChangeListener(this); // set seekbar listener.
        // since we are using this class as the listener the class is "this"

        // make text label for progress value
//        textProgress = (TextView)findViewById(R.id.textViewProgress);
        // make text label for action
   
        ImageView image = (ImageView) findViewById(R.id.imageview);
        back = (Button) findViewById(R.id.button3);
        back.setOnClickListener(this);
        extras = getIntent().getExtras();
      
        sliderp = extras.getString("Slider");
        int s = Integer.parseInt(sliderp);
        	bar.setProgress(s);

    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress,
    		boolean fromUser) {
    	// TODO Auto-generated method stub
        ImageView image = (ImageView) findViewById(R.id.imageview);
    	// change progress text label with current seekbar value
//    	textProgress.setText("The value is: "+progress);
    	// change action text label to changing
        prog1=progress;
    	progression=bar.getProgress();
    	
    	if (progression>90){
    		image.setImageResource(R.drawable.biker45);
    	}
    	else if (progression>80&&progression<90){
    		image.setImageResource(R.drawable.biker40);
    	}
    	else if (progression>70&&progression<80){
    		image.setImageResource(R.drawable.biker35);
    	}
    	else if (progression>60&&progression<70){
    		image.setImageResource(R.drawable.biker30);
    	}
    	else if (progression>50&&progression<60){
    		image.setImageResource(R.drawable.biker25);
    	}
    	else if (progression>40&&progression<50){
    		image.setImageResource(R.drawable.biker20);
    	}
    	else if (progression>30&&progression<40){
    		image.setImageResource(R.drawable.biker15);
    	}
    	else if (progression>20&&progression<30){
    		image.setImageResource(R.drawable.biker10);
    	}
    	else if (progression>10&&progression<20){
    		image.setImageResource(R.drawable.biker5);
    	}
    	else if (progression<10){
    		image.setImageResource(R.drawable.biker0);
    	}
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
    	// TODO Auto-generated method stub


    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
    	// TODO Auto-generated method stub

    	seekBar.setSecondaryProgress(seekBar.getProgress());
//    	if (seekBar.getProgress() == 0){
//    		seekBar.setProgress(1);
//    	}
   
    }
    
    public void onClick(View view) {
    	
    	String s=Integer.toString(prog1);
    	
    	if (s.isEmpty()){
            Intent intent = new Intent();
            setResult(RESULT_CANCELED, intent);
            finish();
    		
    	}
    	
    	else{
        Intent intent = new Intent();
        intent.putExtra("Slide1", s);
        setResult(RESULT_OK, intent);
        finish();
    	}
    }

}
