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
unsigned long tempoApertura = 0;  // variabile per il controllo del tempo
unsigned long durataApertura = 5000;  // durata di 5 secondi (5000 millisecondi)

void setup() {
  Serial.begin(9600);  // Inizializza la comunicazione seriale
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
  // Controlliamo se deve partire l'apertura del cancello
  if (digitalRead(pulsanteApertura) == LOW && digitalRead(fotocellulaInt) == HIGH && digitalRead(fotocellulaEst)==HIGH) {
    Serial.println("Apertura Cancello");  // Messaggio di debug per apertura
    apriCancello();
  }

  // Controlliamo se è il momento di chiudere il cancello
  if (aperturaInCorso) {
    if (millis() - tempoApertura >= durataApertura) {  // Se sono passati 5000 ms (5 secondi) dall'apertura
      Serial.println("Tempo scaduto, chiusura cancello");  // Messaggio di debug per il tempo scaduto
      chiudiCancello();
    } else {
      Serial.print("Tempo trascorso: ");
      Serial.println(millis() - tempoApertura);  // Debug per mostrare quanto tempo è passato
    }
  }
}

// Funzione per aprire il cancello
void apriCancello() {
  if (!aperturaInCorso) {
    aperturaInCorso = true;  // Impostiamo aperturaInCorso su true per evitare che venga ripetuto
    digitalWrite(apriDx, HIGH);  // Apriamo l'anta destra
    delay(400);  // Delay per evitare che le due ante si sovrappongano troppo rapidamente
    digitalWrite(apriSx, HIGH);  // Apriamo l'anta sinistra
    tempoApertura = millis();  // Salviamo il tempo di inizio apertura
    Serial.println("Cancello aperto");  // Messaggio di debug per apertura
  }
}

// Funzione per chiudere il cancello
void chiudiCancello() {
  Serial.println("Chiusura cancello");  // Messaggio di debug per chiusura
  digitalWrite(apriSx, LOW);  // Chiudiamo l'anta sinistra
  digitalWrite(apriDx, LOW);  // Chiudiamo l'anta destra
  digitalWrite(chiudiSx, HIGH); // Azione di chiusura per l'anta sinistra
  delay(400);  // Tempo di ritardo tra i movimenti
  digitalWrite(chiudiDx, HIGH); // Azione di chiusura per l'anta destra

  aperturaInCorso = false;    // Resettiamo la variabile per evitare che il ciclo ripeta
}
