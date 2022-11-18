package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;

import java.io.File;
import java.util.Scanner;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    //Button to exit the application
    public void exitApp(View view) {
    finish();
    }

    //Button Insert Document --> Insert Document Layout
    public void insertDocument(View view){
        Intent insertDocument = new Intent(this, InserDocument.class);
        startActivity(insertDocument);
    }

    //Button Scanner Document --> Scanner Document Layout
    public void scannerDocument(View view){
        Intent scannerDocument = new Intent(this, ScannerDocument.class);
        startActivity(scannerDocument);
    }

    //Button Scanner Document --> Scanner Document Layout
    public void aboutUs(View view){
        Intent aboutUs = new Intent(this, AboutUs.class);
        startActivity(aboutUs);
    }

    //Button Config --> ConfigDB Layout
    public void config(View view){
        Intent config= new Intent(this, ConfigDB.class);
        startActivity(config);
    }


}