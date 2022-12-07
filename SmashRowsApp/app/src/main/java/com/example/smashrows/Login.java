package com.example.smashrows;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class Login<string> extends AppCompatActivity {

    Button Login;
    EditText Usuario, Contraseña;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        Login = (Button) findViewById(R.id.Login);
        Usuario = (EditText) findViewById(R.id.Usuario);
        Contraseña = (EditText) findViewById(R.id.Password);

        string clave = (string) Contraseña.getText().toString();
        string user = (string) Usuario.getText().toString();

        Login.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if ("12345" == user) {
                    if ("12345" == clave) {
                        Intent go = new Intent(Login.this, ConfigDB.class);
                        startActivity(go);
                    }
                }
            }
        });
    }

    //Button Back --> MainLayout
    public void back (View view){
        Intent back = new Intent(this, MainActivity.class);
        startActivity(back);
    }
}