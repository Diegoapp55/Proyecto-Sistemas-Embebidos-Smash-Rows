package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.ContentValues;
import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

public class ConfigDB extends AppCompatActivity {

    //Botones Usuarios
    Button BtSaveUser, BtSearchUser, BtUpdateUser, BtDeleteUser;
    EditText UserId, UserName, UserLastName, UserDrugs, UserCount;

    //Botones Medicamentos
    Button BtSaveDrugs, BtSearchDrugs, BtUpdateDrugs, BtDeleteDrugs;
    EditText DrugsId, DrugsName, DrugsCount;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_config_db);

        //Instanciar elementos de la interfaz de Usuarios
        BtSaveUser = (Button)findViewById(R.id.BtSaveUser);
        BtSearchUser = (Button)findViewById(R.id.BtSearchUser);
        BtUpdateUser = (Button)findViewById(R.id.BtUpdateUser);
        BtDeleteUser = (Button)findViewById(R.id.BtDeleteUser);

        UserId = (EditText)findViewById(R.id.UserId);
        UserName = (EditText)findViewById(R.id.UserName);
        UserLastName = (EditText)findViewById(R.id.UserLastName);
        UserDrugs = (EditText)findViewById(R.id.UserDrugs);
        UserCount = (EditText)findViewById(R.id.UserCount);

        //Instanciar elementos de la interfaz Medicamentos
        BtSaveDrugs = (Button)findViewById(R.id.BtSaveDrugs);
        BtSearchDrugs = (Button)findViewById(R.id.BtSearchDrugs);
        BtUpdateDrugs = (Button)findViewById(R.id.BtUpdateDrugs);
        BtDeleteDrugs = (Button)findViewById(R.id.BtDeleteDrugs);

        DrugsId = (EditText)findViewById(R.id.DrugsId);
        DrugsName = (EditText)findViewById(R.id.DrugsName);
        DrugsCount = (EditText)findViewById(R.id.DrugsCount);

        //Creacion de objeto de la DB Usuarios
        HelpDBUser helpDBUser = new HelpDBUser(getApplicationContext());

        //Creacion de objeto de la DB Medicamentos
        HelpDBDrugs helpDBDrugs = new HelpDBDrugs(getApplicationContext());

        //Botones de la DB Usuarios
        BtSaveUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                //DB Usuarios configurada para escribir
                SQLiteDatabase db_users = helpDBUser.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put(HelpDBUser.DATATABLE.COLUMN_ID, UserId.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_NAME, UserName.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_LAST_NAME, UserLastName.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_DRUGS, UserDrugs.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_COUNT, UserCount.getText().toString());

                long IdSaveUser = db_users.insert(HelpDBUser.DATATABLE.TABLE_NAME, HelpDBUser.DATATABLE.COLUMN_ID, values);
                Toast.makeText(getApplicationContext(), "Se guardo el usuario " + IdSaveUser, Toast.LENGTH_LONG).show();
            }
        });

        BtSearchUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Configurar la DB para leer
                SQLiteDatabase db_users = helpDBUser.getReadableDatabase();
                String [] argsel = {UserId.getText().toString()};
                String [] projection = {HelpDBUser.DATATABLE.COLUMN_NAME, HelpDBUser.DATATABLE.COLUMN_LAST_NAME, HelpDBUser.DATATABLE.COLUMN_DRUGS, HelpDBUser.DATATABLE.COLUMN_COUNT};
                Cursor cursor = db_users.query(HelpDBUser.DATATABLE.TABLE_NAME, projection, HelpDBUser.DATATABLE.COLUMN_ID + " = ?", argsel,null,null,null);

                cursor.moveToFirst();
                UserName.setText(cursor.getString(0));
                UserLastName.setText(cursor.getString(1));
                UserDrugs.setText(cursor.getString(2));
                UserCount.setText(cursor.getString(3));
            }
        });

        BtUpdateUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SQLiteDatabase db_users = helpDBUser.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put(HelpDBUser.DATATABLE.COLUMN_ID, UserId.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_NAME, UserName.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_LAST_NAME, UserLastName.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_DRUGS, UserDrugs.getText().toString());
                values.put(HelpDBUser.DATATABLE.COLUMN_COUNT, UserCount.getText().toString());
                String [] argsel = {UserId.getText().toString()};
                String selection = HelpDBUser.DATATABLE.COLUMN_ID + " = ?";
                int count = db_users.update(HelpDBUser.DATATABLE.TABLE_NAME, values, selection, argsel);
            }
        });

        BtDeleteUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                SQLiteDatabase db_users = helpDBUser.getWritableDatabase();
                String selection = HelpDBUser.DATATABLE.COLUMN_ID + " = ?";
                String [] argsel = {UserId.getText().toString()};
                db_users.delete(HelpDBUser.DATATABLE.TABLE_NAME, selection, argsel);
            }
        });

        //Botones de la DB Medicamentos
        BtSaveDrugs.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //DB Medicamentos configurada para escribir
                SQLiteDatabase db_drugs = helpDBDrugs.getWritableDatabase();
                ContentValues values = new ContentValues();
                values.put(HelpDBDrugs.DATATABLE.COLUMN_ID, DrugsId.getText().toString());
                values.put(HelpDBDrugs.DATATABLE.COLUMN_DRUGS, DrugsName.getText().toString());
                values.put(HelpDBDrugs.DATATABLE.COLUMN_COUNT, DrugsCount.getText().toString());

                long IdSaveDrugs = db_drugs.insert(HelpDBDrugs.DATATABLE.TABLE_NAME, HelpDBDrugs.DATATABLE.COLUMN_ID, values);
                Toast.makeText(getApplicationContext(), "Se guardo el medicamento " + IdSaveDrugs, Toast.LENGTH_LONG).show();
            }
        });

        BtSearchUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        BtUpdateUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

            }
        });

        BtDeleteUser.setOnClickListener(new View.OnClickListener() {
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