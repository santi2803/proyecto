#include <require_cpp11.h>
#include <MFRC522.h>
#include <deprecated.h>
#include <MFRC522Extended.h>

#include <Stepper.h>

#include <RTClib.h>

#include <AT24CX.h>

#include <Wire.h>

#include <EEPROM.h>

#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal.h>
RTC_DS1307 rtc;
AT24C32 EepromRTC;

/*
  LCD RS to PIN 14
  LCD E to PIN 15
  LCD D4 to PIN 16
  LCD D5 to PIN 17
  LCD D6 to PIN 18
  LCD D7 to PIN 19
*/
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

/*==========================
 * Configuration keyboard
============================*/

/*
*/
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},  
};
/*
  Filas y columnas a las que van conectado el teclado
*/
byte rowPins[rows] = {10,8,7,6};
byte colPins[cols] = {5,4,3,2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

/*=============================
 * Global Variables
====================================*/
char pin[] = "1234";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  rtc.begin();
  lcd.begin(16, 2);
  
  bienvenida();
}

void loop() {
  // put your main code here, to run repeatedly:

}

/*==============================================
FUNCIONES DEL TECLADO
================================================*/

/*===============================================
TERMINAN FUNCIONES DEL TECLADO
=================================================*/

/*===============================================
BIENVENIDA
=================================================*/
void bienvenida() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Bienvenido al");
  lcd.setCursor("parqueadero SAM");
  delay(3000);
  pedirPinOTarjeta();
}

void pedirPinOTarjeta() {
  lcd.clear();
  lcd.setCursor();
  lcd.print("Ingrese pin o");
  lcd.setCursor();
  lcd.print("pase la tarjeta");
}
