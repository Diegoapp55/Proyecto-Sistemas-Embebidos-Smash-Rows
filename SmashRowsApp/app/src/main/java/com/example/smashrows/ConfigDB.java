package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class ConfigDB extends AppCompatActivity {

    Button BtSave, BtSearch, BtUpdate, BtDelete;
    EditText UserId, UserName, UserLastName, UserDrugs;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config_db);

        //Instanciar elementos de la interfaz.
        BtSave = (Button)findViewById(R.id.BtSave);
        BtSearch = (Button)findViewById(R.id.BtSearch);
        BtUpdate = (Button)findViewById(R.id.BtUpdate);
        BtDelete = (Button)findViewById(R.id.BtDelete);

        UserId = (EditText)findViewById(R.id.UserId);
        UserName = (EditText)findViewById(R.id.UserName);
        UserLastName = (EditText)findViewById(R.id.UserLastName);
        UserDrugs = (EditText)findViewById(R.id.UserDrugs);

        //Creacion de objeto de la DB
        HelpDB helpDB = new HelpDB(getApplicationContext());

        BtSave.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //DB configurada para escribir
                SQLiteDatabase db_users = helpDB.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put(HelpDB.DATATABLE.COLUMN_ID, UserId.getText().toString());
                values.put(HelpDB.DATATABLE.COLUMN_NAME, UserName.getText().toString());
                values.put(HelpDB.DATATABLE.COLUMN_LAST_NAME, UserLastName.getText().toString());
                values.put(HelpDB.DATATABLE.COLUMN_DRUGS, UserDrugs.getText().toString());

                Long IdSave = db_users.insert(HelpDB.DATATABLE.TABLE_NAME, HelpDB.DATATABLE.COLUMN_ID, values);
                Toast.makeText(getApplicationContext(), "Se guardo el usuario " + IdSave, Toast.LENGTH_LONG).show();
            }
        });

        BtSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        BtUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        BtDelete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });
    }

    //Button Back MainLayout
    public void back(View view){
        Intent back = new Intent(this, MainActivity.class);
        startActivity(back);
    }

}