float duree = 500;
float pourcentage = 0.9;
float arret = duree * 1.5;

int Led1 = 2;
int Led2 = 4;
int Led3 = 17;
int Led4 = 18;
int Bouton = 27;

bool dernierEtatBouton = LOW;  // État précédent du bouton
unsigned long dernierTempsBouton = 0;  // Dernière fois qu'on a lu le bouton
const int debounceDelay = 50;  // Délai anti-rebond en millisecondes
bool etatBouton = digitalRead(Bouton);

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  pinMode(Bouton, INPUT);  // Bouton configuré comme entrée
  Serial.begin(9600);

}

void loop() {
  Serial.println(etatBouton);

}

void led(){
  if (duree > 1) {
        duree *= pourcentage;
        //Serial.println(duree);

        digitalWrite(Led1, HIGH);
        delay(duree);
        digitalWrite(Led1, LOW);

        digitalWrite(Led2, HIGH);
        delay(duree);
        digitalWrite(Led2, LOW);

        digitalWrite(Led3, HIGH);
        delay(duree);
        digitalWrite(Led3, LOW);

        digitalWrite(Led4, HIGH);
        delay(duree);
        digitalWrite(Led4, LOW);

        delay(arret);
        //Serial.println(arret);
      } else {
        //Serial.println("Durée réinitialisée !");
        duree = 500;
      }
}
