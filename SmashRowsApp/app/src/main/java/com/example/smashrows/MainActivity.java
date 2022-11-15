package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.View;
import android.widget.Button;

import java.io.File;

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


}