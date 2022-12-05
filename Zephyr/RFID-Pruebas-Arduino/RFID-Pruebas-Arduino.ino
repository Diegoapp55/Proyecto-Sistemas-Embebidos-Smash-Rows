/*
  Capitulo 40 de Arduino desde cero en Español.
  Programa que obtiene el UID de la tarjeta o llavero del kit RFID RC522 y muestra 
  en monitor serie. Requiere instalar libreria MFRC522
  Autor: bitwiseAr  
*/

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  9    //Pin 9 para el reset del RC522
#define SS_PIN  10   //Pin 10 para el SS (SDA) del RC522
MFRC522 mfrc522(SS_PIN, RST_PIN); ///Creamos el objeto para el RC522

int GPIO=2;   //pin que vamos a conectar al GPIO de la ESP32

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600); //Iniciamos La comunicacion serial
  SPI.begin();        //Iniciamos el Bus SPI
  mfrc522.PCD_Init(); // Iniciamos el MFRC522
  Serial.println("Control de acceso:");
}

byte ActualUID[4]; //almacenará el código del Tag leído
byte Usuario1[4]= {0x6D, 0x2C, 0x2C, 0xEB} ; //código del usuario 1  6D 2C 2C EB
byte Usuario2[4]= {0x62, 0xDB, 0x56, 0x6F} ; //código del usuario 2  62 DB 56 6F
byte Usuario3[4]= {0xED, 0x18, 0x19, 0xA9} ; //código del usuario 3  ED 18 19 A9
void loop() {
  // Revisamos si hay nuevas tarjetas  presentes
  if ( mfrc522.PICC_IsNewCardPresent()) 
        {  
      //Seleccionamos una tarjeta
            if ( mfrc522.PICC_ReadCardSerial()) 
            {
                  // Enviamos serialemente su UID
                  Serial.print(F("Card UID:"));
                  for (byte i = 0; i < mfrc522.uid.size; i++) {
                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
                  } 
                  Serial.print("     ");                 
                  //comparamos los UID para determinar si es uno de nuestros usuarios  
                  if(compareArray(ActualUID,Usuario1)){
                    Serial.println("Bienvenido Sergio Guevara");
                    digitalWrite(GPIO, HIGH);
                    delay(500);
                    digitalWrite(GPIO, LOW);
                    delay(500);
                    }
                  else if(compareArray(ActualUID,Usuario2)){
                    Serial.println("Bienvenido Raúl Guzmán");
                    digitalWrite(GPIO, HIGH);
                    delay(500);
                    digitalWrite(GPIO, LOW);
                    delay(500);
                    }
                  else if(compareArray(ActualUID,Usuario3)){
                    Serial.println("Bienvenido Diego Sánchez");
                    digitalWrite(GPIO, HIGH);
                    delay(500);
                    digitalWrite(GPIO, LOW);
                    delay(500);
                    }
                  else{
                    Serial.println("Acceso denegado...Eduardo");
                    digitalWrite(GPIO, LOW);
                    delay(500);
                  }
                  // Terminamos la lectura de la tarjeta tarjeta  actual
                  mfrc522.PICC_HaltA();
          
            }
      
  }
  
}

//Función para comparar dos vectores
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
