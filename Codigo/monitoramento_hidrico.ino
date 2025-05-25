#include <LiquidCrystal.h>

// Inicializa o LCD nos pinos correspondentes
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int phPin = A0;
int turbidezPin = A1;
int fluxoPin = 7; // Ajuste aqui para o pino correto conectado ao fluxo
int bomba = 8;    // Pino digital conectado à bomba (LED ou relé)

void setup() {
  pinMode(bomba, OUTPUT);
  pinMode(fluxoPin, INPUT);
  Serial.begin(9600);

  lcd.begin(16, 2); // LCD 16x2
  lcd.print("Sistema Iniciado");
  delay(2000);
  lcd.clear();
}

void loop() {
  int ph = analogRead(phPin);
  int turbidez = analogRead(turbidezPin);
  int fluxo = digitalRead(fluxoPin);

  // Exibe valores no Serial Monitor
  Serial.print("pH: "); Serial.print(ph);
  Serial.print(" | Turbidez: "); Serial.print(turbidez);
  Serial.print(" | Fluxo: "); Serial.println(fluxo);

  // Exibe valores no LCD
  lcd.setCursor(0, 0);
  lcd.print("pH: ");
  lcd.print(ph);
  lcd.print(" ");

  lcd.setCursor(0, 1);
  lcd.print("T: ");
  lcd.print(turbidez);
  lcd.print(" F:");
  lcd.print(fluxo);

  // Controle da bomba com base nos sensores
  if (ph < 500 && turbidez > 400 && fluxo == HIGH) {
    digitalWrite(bomba, HIGH);
  } else {
    digitalWrite(bomba, LOW);
  }

  delay(1000);
}
