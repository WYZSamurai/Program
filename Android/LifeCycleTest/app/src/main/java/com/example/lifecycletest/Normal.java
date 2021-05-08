package com.example.lifecycletest;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;

public class Normal extends BaseActivity {

    private static final String TAG = "NormalActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "Task id is " + getTaskId());
        setContentView(R.layout.activity_normal);
        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(v -> {
            Intent intent = new Intent(getApplicationContext(),Dialog.class);
            startActivity(intent);
        });
    }
}