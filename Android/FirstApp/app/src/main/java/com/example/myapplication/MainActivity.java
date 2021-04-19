package com.example.myapplication;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // 启动执行
        super.onCreate(savedInstanceState);
        setContentView(R.layout.first_layout);
        Button button1 = (Button)findViewById(R.id.button_1);
        //button1.setOnClickListener(v -> { finish(); });
        button1.setOnClickListener(v -> {
            Intent intent = new Intent("com.example.myapplication.ACTION_START");
            startActivity(intent);
        }
        );
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // 设置菜单
        getMenuInflater().inflate(R.menu.main,menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        // 点击菜单的触发动作
        if(item.getItemId() == R.id.setting){
            Intent intent = new Intent(getApplicationContext(),SecondActivity.class);
            startActivity(intent);
        }
        /*
        if(item.getItemId() == R.id.setting){
            Toast.makeText(getApplicationContext(),"Clicked Setting.",Toast.LENGTH_SHORT).show();
        }
        */
        return super.onOptionsItemSelected(item);
    }
}