package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.provider.ContactsContract;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class InserDocument extends AppCompatActivity {
    //Llamada de botones
    Button BtSearch, BtClaim, BtCancel;

    //Lamada de Edit Text
    EditText InsertDocument, Name, LastName, Drug;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_inser_document);
        //Instanciar elementos desde la interfaz del documento
        BtSearch = (Button)findViewById(R.id.ButtonSearch);
        BtClaim = (Button)findViewById(R.id.ButtonClaim);
        BtCancel = (Button)findViewById(R.id.ButtonCancel);

        InsertDocument = (EditText)findViewById(R.id.InsertDocument);
        Name = (EditText)findViewById(R.id.Name);
        LastName = (EditText)findViewById(R.id.LastName);
        Drug = (EditText)findViewById(R.id.Drug);

        //Creacion de objeto de la DB Usuarios
        HelpDBUser helpDBUser = new HelpDBUser(getApplicationContext());

        BtSearch.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Configurar la DB para leer
                SQLiteDatabase db_users = helpDBUser.getReadableDatabase();
                String [] argsel = {InsertDocument.getText().toString()};
                String [] projection = {HelpDBUser.DATATABLE.COLUMN_NAME, HelpDBUser.DATATABLE.COLUMN_LAST_NAME, HelpDBUser.DATATABLE.COLUMN_DRUGS};
                Cursor cursor = db_users.query(HelpDBUser.DATATABLE.TABLE_NAME, projection, HelpDBUser.DATATABLE.COLUMN_ID + " LIKE ?", argsel,null,null,null);

                cursor.moveToFirst();
                Name.setText(cursor.getString(0));
                LastName.setText(cursor.getString(1));
                Drug.setText(cursor.getString(2));
            }
        });


    }

    //Button Back --> MainLayout
    public void back(View view){
        Intent back = new Intent(this, MainActivity.class);
        startActivity(back);
    }
}