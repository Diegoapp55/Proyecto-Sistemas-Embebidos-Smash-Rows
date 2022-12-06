package com.example.smashrows;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.provider.BaseColumns;

public class HelpDBUser extends SQLiteOpenHelper {

    //Crea los campos de la tabla
    public static class DATATABLE implements BaseColumns {
        public static final String TABLE_NAME = "Usuarios";
        public static final String COLUMN_ID = "id";
        public static final String COLUMN_NAME = "nombre";
        public static final String COLUMN_LAST_NAME = "apellido";
        public static final String COLUMN_DRUGS = "medicamento";

        //Sentencia para crear la tabla
        private static final String CREATE_TABLE_USERS =
                "CREATE TABLE " + DATATABLE.TABLE_NAME + " (" +
                        DATATABLE.COLUMN_ID + " INTEGER PRIMARY KEY," +
                        DATATABLE.COLUMN_NAME + " TEXT," +
                        DATATABLE.COLUMN_LAST_NAME + " TEXT,"+
                        DATATABLE.COLUMN_DRUGS + " TEXT)";

        //Sentencia para borrar la tabla
        private static final String SQL_DELETE_ENTRIES =
                "DROP TABLE IF EXISTS " + DATATABLE.TABLE_NAME;
    }

    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "Users.db";

    public HelpDBUser(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db_users) {
        db_users.execSQL(DATATABLE.CREATE_TABLE_USERS);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db_users, int i, int i1) {
        db_users.execSQL(DATATABLE.SQL_DELETE_ENTRIES);
        onCreate(db_users);
    }
}



