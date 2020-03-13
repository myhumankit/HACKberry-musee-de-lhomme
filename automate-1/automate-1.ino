/*
   Programme écrit spécifiquement pour la main HACKberry exposée au musée de l'Homme
   Julien Lebunetel le 2020-03-13

*/

// utilisation de la librairie « Servo »
#include <Servo.h>

// déclaration des constantes
int pinServoIndex;
int pinServoOther;
int pinServoThumb;

int indexMax = 170;
int indexMin = 35;

int otherMax = 110;
int otherMin = 65;

int thumbMax = 97;
int thumbMin = 7;

// déclation des objets « Servo »
Servo servoIndex; //index finger
Servo servoOther; //other three fingers
Servo servoThumb; //thumb

void setup() {
  // cette fonction est exécutée une seule fois au démarrage

  // démarrage des servomoteurs
  pinServoIndex  = 5;
  pinServoOther  = 6;
  pinServoThumb  = 9;

  servoIndex.attach(pinServoIndex);//index
  servoOther.attach(pinServoOther);//other
  servoThumb.attach(pinServoThumb);//thumb
}

void loop() {
  // tant que la main est alimentée, cette fonction est exécutée en boucle

  // on place la main en position de repos
  moveIndex(75);
  moveOther(50);
  moveThumb(50);

  // on attend 5 secondes
  delay(5000);

  // on ouvre tous les doigts
  moveIndex(100);
  moveOther(100);
  moveThumb(100);

  // on attend 5 secondes
  delay(5000);

  // on ferme tous les doigts
  moveIndex(0);
  moveOther(0);
  moveThumb(0);

  // on attend 5 secondes
  delay(5000);

  // on ouvre tous les doigts
  moveIndex(100);
  moveOther(100);
  moveThumb(100);

  // on attend 5 secondes
  delay(5000);

  // on ferme le pouce
  moveThumb(0);

  // on attend 5 secondes
  delay(5000);

  // on bouge l'index pour pincer
  moveIndex(30);

  // on attend 5 secondes
  delay(5000);

  // on ouvre tous les doigts
  moveIndex(100);
  moveOther(100);
  moveThumb(100);

  // on attend 5 secondes
  delay(5000);

  // on ferme le pouce et les autres doigts
  moveOther(0);
  moveThumb(0);

  // on attend 5 secondes
  delay(5000);

  // on ouvre tous les doigts
  moveIndex(100);
  moveOther(100);
  moveThumb(100);

  // on attend 5 secondes
  delay(5000);

  // au revoir !
  // on ferme et ouvre 3 fois tous les doigts sauf le pouce
  for (int i = 0 ; i < 3 ; i++) {
    moveIndex(0);
    moveOther(0);
    delay(500);

    moveIndex(100);
    moveOther(100);
    delay(500);
  }

  // on attend 5 secondes
  delay(5000);
}

// fonctions utiles
void moveIndex(int pos) {
  // pos = position de 0 (doigt fermé) à 100 (doigt ouvert)
  servoIndex.write(map(pos, 0, 100, indexMin, indexMax));
  delay(100);
  if (pos < 50) {
    servoIndex.write(map(pos, 0, 100, indexMin, indexMax) + 5);
  }
  else {
    servoIndex.write(map(pos, 0, 100, indexMin, indexMax) - 5);
  }
}

void moveOther(int pos) {
  // pos = position de 0 (doigt fermé) à 100 (doigt ouvert)
  servoOther.write(map(pos, 0, 100, otherMin, otherMax));
}

void moveThumb(int pos) {
  // pos = position de 0 (doigt fermé) à 100 (doigt ouvert)
  servoThumb.write(map(pos, 0, 100, thumbMin, thumbMax));
}
