#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT(12, 11); // RX, TX
String command = ""; // Stores response of bluetooth device

int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

void setup()
{
  Serial.begin(9600);
  Serial.println("Type AT command-------------s!");
  BT.begin(9600); // HC-05 usually default baud-rate 
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (IN3, OUTPUT);
  pinMode (IN4, OUTPUT);
}

void loop() {
     String c = Serial.readString(); 
     command = c;  
    
    Serial.println(command);
    
    if(command=="F"){
      emFrenteOn();
    }else if(command=="S"){
      parar();
    }else if(command=="B"){
      paraTrasOn();
    }else if(command=="L"){
      virarEsquerdaOn();
    }else if(command=="R"){
      virarDireitaOn();
    }else if(command=="X"){
      parar(); 
    }  else{
      parar();
    }
    command = ""; 
  } 


void emFrenteOn(){
 analogWrite(IN1, HIGH);
 analogWrite(IN2, LOW);
 analogWrite(IN3, LOW);
 analogWrite(IN4, HIGH);
}

void paraTrasOn(){
 analogWrite(IN1, LOW);
 analogWrite(IN2, HIGH);
 analogWrite(IN3, HIGH);
 analogWrite(IN4, LOW);
}

void virarEsquerdaOn(){
  analogWrite(IN4, HIGH);
}

void virarDireitaOn(){
 analogWrite(IN1, HIGH);
}

void parar(){
 analogWrite(IN1,LOW);
 analogWrite(IN2, LOW);
 analogWrite(IN3, LOW);
 analogWrite(IN4, LOW);
  
}
