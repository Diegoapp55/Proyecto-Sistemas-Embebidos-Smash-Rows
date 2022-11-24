package com.example.smashrows;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.provider.BaseColumns;

public class HelpDBDrugs extends SQLiteOpenHelper {

    //Crea los campos de la tabla
    public static class DATATABLE implements BaseColumns {
        public static final String TABLE_NAME = "Medicamentos";
        public static final String COLUMN_ID = "id";
        public static final String COLUMN_DRUGS = "medicamento";
        public static final String COLUMN_COUNT = "cantidad";

        //Sentencia para crear la tabla
        private static final String CREATE_TABLE_DRUGS =
                "CREATE TABLE " + DATATABLE.TABLE_NAME + " (" +
                        DATATABLE.COLUMN_ID + " INTEGER PRIMARY KEY," +
                        DATATABLE.COLUMN_DRUGS + " TEXT," +
                        DATATABLE.COLUMN_COUNT + " TEXT)";

        //Sentencia para borrar la tabla
        private static final String SQL_DELETE_ENTRIES =
                "DROP TABLE IF EXISTS " + DATATABLE.TABLE_NAME;
    }

    public static final int DATABASE_VERSION = 1;
    public static final String DATABASE_NAME = "Drugs.db";

    public HelpDBDrugs(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db_drugs) {
        db_drugs.execSQL(DATATABLE.CREATE_TABLE_DRUGS);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db_drugs, int i, int i1) {
        db_drugs.execSQL(DATATABLE.SQL_DELETE_ENTRIES);
        onCreate(db_drugs);
    }
}
