package com.example.myapplication;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.widget.Button;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // 启动执行
        super.onCreate(savedInstanceState);
        setContentView(R.layout.first_layout);
        Button button1 = findViewById(R.id.button_1);
        //button1.setOnClickListener(v -> { finish(); });
        /*
        button1.setOnClickListener(v -> {
            Intent intent = new Intent("com.example.myapplication.ACTION_START");
            intent.addCategory("com.example.myapplication.MY_CATEGORY");
            startActivity(intent);
        }
        );*/
        /*button1.setOnClickListener(v -> {
            Intent intent = new Intent(Intent.ACTION_VIEW);
            intent.setData(Uri.parse("https://www.bing.com"));
            startActivity(intent);
        });*/
        /*button1.setOnClickListener(v -> {
            String data = "Activity2 Test";
            Intent intent = new Intent(getApplicationContext(),SecondActivity.class);
            intent.putExtra("extra_data",data);
            Log.d(TAG, "onCreate: putExtra");
            startActivity(intent);
        });*/
        button1.setOnClickListener(v -> {
            Intent intent = new Intent(getApplicationContext(), ThirdActivity.class);
            startActivityForResult(intent, 1);
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        switch(requestCode){
            case 1:
                if(requestCode == resultCode){
                    String returnedData = data.getStringExtra("data");
                    Log.d(TAG, returnedData);
                }
                break;
            default:
        }
        super.onActivityResult(requestCode, resultCode, data);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // 设置菜单
        getMenuInflater().inflate(R.menu.main, menu);
        return super.onCreateOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(@NonNull MenuItem item) {
        // 点击菜单的触发动作
        /*if(item.getItemId() == R.id.setting){
            Intent intent = new Intent(getApplicationContext(),SecondActivity.class);
            startActivity(intent);
        }*/
        if (item.getItemId() == R.id.setting) {
            Toast.makeText(getApplicationContext(), "Clicked Setting.", Toast.LENGTH_SHORT).show();
        }
        return super.onOptionsItemSelected(item);
    }
}