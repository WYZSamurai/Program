package com.example.lifecycletest;

import android.os.Bundle;
import android.util.Log;

public class Dialog extends BaseActivity {

    private static final String TAG = "DialogActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "Task id is " + getTaskId());
        setContentView(R.layout.activity_dialog);
    }
}