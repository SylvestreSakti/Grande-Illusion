/*
Commande de servo-moteur par impulsion
Nanomaître 2015
Le servo est connecté au pin 8 de l'arduino
*/
#include <Servo.h>

int pinServo1=9; // variable pour le pin connecté à la commande du servo
int pinServo2 = 10 ;
int pinMode1 = 0; //variable pour le bouton du mode1
int pinMode2 = 4 ;
int pinMode3 = 1 ;
int pinMode4 = 5 ;
int mode = 0; //mode0 = insertion //mode1 = vivant //mode2 = coupé //mode3 = reactif
Servo myServo1 ; // on définit un objet Servo nommé leServo
Servo myServo2 ; // on définit un objet Servo nommé leServo

void setup() {
  myServo1.attach(pinServo1); // on relie l'objet au pin de commande
  myServo2.attach(pinServo2); // on relie l'objet au pin de commande
  //attachInterrupt(pinMode1, executeMode1, FALLING);
  attachInterrupt(pinMode3, executeMode3, FALLING);
  pinMode(pinMode2,INPUT);
  pinMode(pinMode4,INPUT);
  Serial.begin(9600) ;
  mode = 2 ;  setAngle(90) ;
  mode = 0 ;
  mode = 2 ;
    setAngle(27) ;
    mode = 1 ;
    Serial.println("En mode1");
}

//boucle principale
void loop() {
  if((digitalRead(pinMode2))){
    if((mode==1)||(mode==4)){
      mode = 2 ;
      myServo2.write(70);
      myServo1.write(160-40);
      delay(400);
      myServo2.write(75);
      myServo1.write(160-80);
      delay(400);
      setAngle(90);
      Serial.println("En mode2");
    }
  }
  if((digitalRead(pinMode4))){
    if(mode==3){
      mode = 2 ;
      myServo2.write(75);
      myServo1.write(160-95);
      delay(900);
      myServo2.write(95);
      myServo1.write(160-75);
      delay(900);
      myServo2.write(75);
      myServo1.write(160-95);
      delay(900);
      setAngle(90) ; 
      delay(600);
      mode = 4 ;
      Serial.println("En mode4");
    }
  }
  
  if(mode==2){
    setAngle(92);delay(1166);
      setAngle(91);delay(133);
      setAngle(90);delay(66);
      setAngle(89);delay(66);
      setAngle(88);delay(33);
      setAngle(87);delay(66);
      setAngle(86);delay(66);
      setAngle(85);delay(66);
      setAngle(84);delay(333);
      setAngle(85);delay(166);
      setAngle(86);delay(66);
      setAngle(87);delay(66);
      setAngle(88);delay(66);
      setAngle(89);delay(99);
      setAngle(90);delay(99);
      setAngle(91);delay(333);
      setAngle(92);delay(66);
      setAngle(93);delay(66);
      setAngle(94);delay(66);
      setAngle(95);delay(66);
      setAngle(96);delay(66);
      setAngle(97);delay(66);
      setAngle(98);delay(133);
      setAngle(99);delay(66);
      setAngle(98);delay(133);
      setAngle(97);delay(133);
      setAngle(96);delay(66);
      setAngle(95);delay(66);
      setAngle(94);delay(166);
      setAngle(93);delay(399);
      setAngle(92);delay(499);
      setAngle(91);delay(99);
      setAngle(90);delay(66);
      setAngle(89);delay(199);
      setAngle(90);delay(66);
      setAngle(91);delay(133);
      setAngle(92);delay(66);
      setAngle(93);delay(66);
      setAngle(92);delay(566);
      setAngle(91);delay(66);
      setAngle(90);delay(66);
      setAngle(89);delay(33);
      setAngle(88);delay(133);
      setAngle(87);delay(66);
      setAngle(86);delay(166);
      setAngle(85);delay(33);
      setAngle(86);delay(33);
      setAngle(85);delay(166);
      setAngle(84);delay(66);
      setAngle(85);delay(33);
      setAngle(86);delay(33);
      setAngle(87);delay(33);
      setAngle(88);delay(99);
      setAngle(89);delay(66);
      setAngle(90);delay(33);
      setAngle(91);delay(99);
      setAngle(92);delay(99);
      setAngle(93);delay(66);
      setAngle(94);delay(99);
      setAngle(95);delay(66);
      setAngle(96);delay(300);
      setAngle(94);delay(33);
      setAngle(93);delay(233);
      setAngle(92);delay(1600);
      setAngle(91);delay(99);
      setAngle(90);delay(266);
      setAngle(91);delay(99);
      setAngle(92);delay(66);
      setAngle(93);delay(66);
      setAngle(94);delay(133);
      setAngle(93);delay(99);
      setAngle(92);delay(399);
      setAngle(91);delay(33);
      setAngle(92);delay(33);
      setAngle(91);delay(166);
      setAngle(90);delay(33);
      setAngle(89);delay(66);
      setAngle(88);delay(33);
      setAngle(87);delay(66);
      setAngle(86);delay(66);
      setAngle(85);delay(99);
      setAngle(84);delay(99);
      setAngle(83);delay(199);
      setAngle(84);delay(33);
      setAngle(85);delay(33);
      setAngle(87);delay(66);
      setAngle(88);delay(33);
      setAngle(89);delay(33);
      setAngle(91);delay(66);
      setAngle(92);delay(66);
      setAngle(93);delay(99);
      setAngle(94);
  }
}

void executeMode1(){
  if((mode==0)||(mode==2)){
    mode = 2 ;
    setAngle(27) ;
    mode = 1 ;
    Serial.println("En mode1");
  }
}

void executeMode3(){
    if(mode==2){
      mode = 23 ; //Mode 23 correspond à la transition entre le mode 2 et 3
    }
    if(mode==4){
      mode = 2 ;
      setAngle(27) ;
      mode = 1 ;
      Serial.println("En mode1");
    }
}

//fonction setAngle pour envoyer les impulsions
void setAngle(int a){
  if((mode == 2)){
    myServo2.write(a); // on transforme l'angle en microsecondes et on stocke dans la variable duree
    myServo1.write(160-a);
  }
  if((mode == 23)){
      myServo2.write(70);
      myServo1.write(160-90);
      delay(400);
      myServo2.write(80);
      myServo1.write(160-80);
      delay(400);
      myServo2.write(90);
      myServo1.write(160-65);
      delay(500);
      myServo2.write(95);
      myServo1.write(160-90);
      delay(400);
      myServo2.write(80);
      myServo1.write(160-80);
      delay(400);
      myServo2.write(90);
      myServo1.write(160-65);
      delay(500);
      myServo2.write(95);
      myServo1.write(160-90);
      delay(400);
      myServo2.write(60);
      myServo1.write(160-60);
      mode = 3;
      Serial.println("En mode3");
   }
}
