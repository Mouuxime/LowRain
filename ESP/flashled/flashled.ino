float duree = 500;
float pourcentage = 0.9;
float arret = duree*1.5;

int Led1 = 2;
int Led2 = 4;
int Led3 = 17;
int Led4 = 18;

void setup() {
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  pinMode(Led3, OUTPUT);
  pinMode(Led4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (duree > 1 ) {
    duree *= pourcentage;
    Serial.println(duree);

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
    Serial.println(arret);
  } else {
    Serial.println("Durée réinitialisée !");
    duree = 500;
  }
}

