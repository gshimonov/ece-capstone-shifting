package com.tab.seek;

import android.app.Activity;
import android.os.Bundle;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.SeekBar.OnSeekBarChangeListener;
import android.widget.TextView;

import com.tab.R;

public class Seek extends Activity implements OnSeekBarChangeListener{
	private SeekBar bar;
	private int progression;
	private TextView textProgress,textAction;
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
        textProgress = (TextView)findViewById(R.id.textViewProgress);
        // make text label for action
        textAction = (TextView)findViewById(R.id.textViewAction);
        ImageView image = (ImageView) findViewById(R.id.imageview);
        image.setImageResource(R.drawable.rider1);

    }

    @Override
    public void onProgressChanged(SeekBar seekBar, int progress,
    		boolean fromUser) {
    	// TODO Auto-generated method stub
        ImageView image = (ImageView) findViewById(R.id.imageview);
    	// change progress text label with current seekbar value
    	textProgress.setText("The value is: "+progress);
    	// change action text label to changing
    	textAction.setText("changing");
    	progression=bar.getProgress();
    	if (progression>67){
    		image.setImageResource(R.drawable.rider3);
    	}
    	
    	else if (progression<67&&progression>33){
    		image.setImageResource(R.drawable.rider2);
    	}
    	
    	else if (progression<33){
    		image.setImageResource(R.drawable.rider1);
    	}
    }

    @Override
    public void onStartTrackingTouch(SeekBar seekBar) {
    	// TODO Auto-generated method stub
    	textAction.setText("starting to track touch");

    }

    @Override
    public void onStopTrackingTouch(SeekBar seekBar) {
    	// TODO Auto-generated method stub

    	seekBar.setSecondaryProgress(seekBar.getProgress());
    	textAction.setText("ended tracking touch");
    	
    }

}
