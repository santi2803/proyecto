#include <LiquidCrystal.h>

LiquidCrystal lcd(14, 15, 16, 17, 18, 19);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
