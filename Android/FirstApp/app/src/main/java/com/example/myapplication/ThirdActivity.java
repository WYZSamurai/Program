package com.example.myapplication;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.widget.Button;

public class ThirdActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_third);
        Button button3 = findViewById(R.id.button_3);
        button3.setOnClickListener(v -> {
            Intent intent = new Intent();
            intent.putExtra("data","return data");
            setResult(1,intent);
            finish();
        });
    }

    @Override
    public void onBackPressed() {
        Intent intent = new Intent();
        intent.putExtra("data","return data");
        setResult(1,intent);
        super.onBackPressed();
    }
}