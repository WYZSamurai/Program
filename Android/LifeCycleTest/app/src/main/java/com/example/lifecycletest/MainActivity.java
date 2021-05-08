package com.example.lifecycletest;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.widget.Button;

public class MainActivity extends BaseActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        Log.d(TAG, "Task id is " + getTaskId());
        setContentView(R.layout.activity_main);
        Button button1 = findViewById(R.id.button_to_normal);
        Button button2 = findViewById(R.id.button_to_dialog);
        button1.setOnClickListener(v -> {
            Intent intent = new Intent(getApplicationContext(),Normal.class);
            startActivity(intent);
        });
        button2.setOnClickListener(v -> {
            Intent intent = new Intent(getApplicationContext(), Dialog.class);
            startActivity(intent);
        });
    }
}