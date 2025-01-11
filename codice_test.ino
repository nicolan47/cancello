#define fotocellulaInt 1
#define fotocellulaEst 2
#define apriSx 3
#define chiudiSx 4
#define apriDx 5
#define chiudiDx 6
#define luceLavoro 7
#define vuoto 8
#define ledRosso 9
#define ledVerde 10
#define pulsanteApertura 11
#define radio 12
#define amperometroSx A0
#define amperometroDx A1
bool aperturaInCorso = false;
bool chiusuraInCorso = false;

void setup() {
pinMode(fotocellulaInt, INPUT_PULLUP);
pinMode(fotocellulaEst, INPUT_PULLUP);
pinMode(apriSx, OUTPUT);
pinMode(chiudiSx, OUTPUT);
pinMode(apriDx, OUTPUT);
pinMode(chiudiDx, OUTPUT);
pinMode(luceLavoro, OUTPUT);
pinMode(vuoto, OUTPUT);
pinMode(ledRosso, OUTPUT);
pinMode(ledVerde, OUTPUT);
pinMode(pulsanteApertura, INPUT_PULLUP);
pinMode(radio, INPUT_PULLUP);
pinMode(amperometroSx, INPUT);
pinMode(amperometroDx, INPUT);

}

void loop() {
  if (digitalRead(pulsanteApertura) == LOW)
  {
    aperturaInCorso = true;
    digitalWrite(apriDx, HIGH);
    delay(500);
    digitalWrite(apriSx, HIGH);
    delay(25000);
    digitalWrite(apriDx, LOW);
    delay(500);
    digitalWrite(apriSx, LOW);
    delay(15000);
    digitalWrite(chiudiSx, HIGH);
    delay(2000);
    digitalWrite(chiudiDx, HIGH);
    delay(25000);
    digitalWrite(chiudiSx, LOW);
    delay(2000);
    digitalWrite(chiudiDx, LOW);
  }

}
