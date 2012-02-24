package com.tab;


import com.tab.accel.Accelerometer;
import com.tab.orientation.Orientation;
import com.tab.seek.Seek;

import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TabHost;

public class HelloTabWidget extends TabActivity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        
        Resources res = getResources(); // Resource object to get Drawables
        TabHost tabHost = getTabHost();  // The activity TabHost
        TabHost.TabSpec spec;  // Resusable TabSpec for each tab
        Intent intent;  // Reusable Intent for each tab

        // Create an Intent to launch an Activity for the tab (to be reused)
        intent = new Intent().setClass(this, Accelerometer.class);

        // Initialize a TabSpec for each tab and add it to the TabHost
        
        spec = tabHost.newTabSpec("Accelerometer").setIndicator("Accelerometer",
                          res.getDrawable(R.drawable.ic_tab_speed))
                      .setContent(intent);
        tabHost.addTab(spec);
        //Adjust height of the tab so text doesnt cover image
        tabHost.getTabWidget().getChildAt(0).getLayoutParams().height = 80;

        // Do the same for the other tabs
        intent = new Intent().setClass(this, Orientation.class);
        spec = tabHost.newTabSpec("Orientation").setIndicator("Orientation",
                          res.getDrawable(R.drawable.ic_tab_tirepressure))
                      .setContent(intent);
        tabHost.addTab(spec);
        tabHost.getTabWidget().getChildAt(1).getLayoutParams().height = 80;

        intent = new Intent().setClass(this, Seek.class);
        spec = tabHost.newTabSpec("Settings").setIndicator("Settings",
                          res.getDrawable(R.drawable.ic_tab_settings))
                      .setContent(intent);
        tabHost.addTab(spec);
        tabHost.getTabWidget().getChildAt(2).getLayoutParams().height = 80;

        // Select the starting tab, left most = 1
        tabHost.setCurrentTab(1);
    }
}