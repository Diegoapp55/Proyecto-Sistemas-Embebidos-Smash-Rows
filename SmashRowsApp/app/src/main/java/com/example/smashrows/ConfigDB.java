package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class ConfigDB extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config_db);
    }
    //Button Back MainLayout
    public void back(View view){
        Intent back = new Intent(this, MainActivity.class);
        startActivity(back);
    }

}