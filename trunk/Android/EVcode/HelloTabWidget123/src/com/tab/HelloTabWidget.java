package com.tab;


import android.app.TabActivity;
import android.content.Intent;
import android.content.res.Resources;
import android.os.Bundle;
import android.widget.TabHost;

import com.tab.orientation.Orientation;
import com.tab.textfield.UserParam;

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

   // Add Orientation Class
        intent = new Intent().setClass(this, Orientation.class);
        spec = tabHost.newTabSpec("Orientation").setIndicator("Orientation",res.getDrawable(R.drawable.ic_tab_speed))
        .setContent(intent);
        
        tabHost.addTab(spec);
        tabHost.getTabWidget().getChildAt(0).getLayoutParams().height = 80;
   
//   // Add Seek Class
//        intent = new Intent().setClass(this, Seek.class);
//        spec = tabHost.newTabSpec("Slider").setIndicator("Settings",res.getDrawable(R.drawable.ic_tab_settings))
//        .setContent(intent);
//        
//        tabHost.addTab(spec);
//        tabHost.getTabWidget().getChildAt(1).getLayoutParams().height = 80;
        
   // Add User Settings Class
        intent = new Intent().setClass(this, UserParam.class);
        spec = tabHost.newTabSpec("User").setIndicator("User Settings",res.getDrawable(R.drawable.ic_tab_settings))
        .setContent(intent);
        
        tabHost.addTab(spec);
        tabHost.getTabWidget().getChildAt(1).getLayoutParams().height = 80;
        
   // Select the starting tab, left most = 0
        tabHost.setCurrentTab(0);
    }
}