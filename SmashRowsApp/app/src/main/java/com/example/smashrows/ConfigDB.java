package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class ConfigDB extends AppCompatActivity {

    Button BtSave, BtSearch, BtUpdate, BtDelete;
    EditText UserId, UserName, UserLastName, UserDrugs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config_db);

        BtSave = (Button)findViewById(R.id.BtSave);
        BtSearch = (Button)findViewById(R.id.BtSearch);
        BtUpdate = (Button)findViewById(R.id.BtUpdate);
        BtDelete = (Button)findViewById(R.id.BtDelete);

        UserId = (EditText)findViewById(R.id.UserId);
        UserName = (EditText)findViewById(R.id.UserName);
        UserLastName = (EditText)findViewById(R.id.UserLastName);
        UserDrugs = (EditText)findViewById(R.id.UserDrugs);

    }
    //Button Back MainLayout
    public void back(View view){
        Intent back = new Intent(this, MainActivity.class);
        startActivity(back);
    }

}