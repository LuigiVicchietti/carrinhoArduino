#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial BT(12, 11); // RX, TX
String command = ""; // Stores response of bluetooth device

int IN1 = 9;
int IN2 = 3;
int IN3 = 5;
int IN4 = 6;


void setup()
{
  Serial.begin(9600);
  Serial.println("Type AT command-------------s!");
  BT.begin(9600); // HC-05 usually default baud-rate
  
}


void loop()
{

  
  if (BT.available()){
    while(BT.available()){
     delay(15); 
     char c = BT.read(); 
     command = c; 
    } 
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
//     parar(); 
    }else if(command=="x"){
//     parar(); 
    }else if(command=="I"){
      diagDireitaOn();
    } else if(command=="G"){
      diagEsquerdaOn();
    } else if(command=="J"){
      diagDireitaTrasOn();
    } else if(command=="H") {
      diagEsquerdaTrasOn();
    }  else{
      parar();
    }
    command = ""; 

  
  }
}

void emFrenteOn(){
 analogWrite(IN1, 255);
 analogWrite(IN2, 0);
 analogWrite(IN3, 0);
 analogWrite(IN4, 255);
}

void paraTrasOn(){
 analogWrite(IN1, 0);
 analogWrite(IN2, 255);
 analogWrite(IN3, 255);
 analogWrite(IN4, 0);
}


void virarEsquerdaOn(){
  analogWrite(IN4, 255);
 
}

void virarDireitaOn(){

 analogWrite(IN1, 255);
 
}

void diagDireitaOn(){
    analogWrite(IN1, 255);
    analogWrite(IN4, 130);
  }


void diagEsquerdaOn(){
    analogWrite(IN1, 130);
    analogWrite(IN4, 255);
  }

void diagEsquerdaTrasOn(){
  analogWrite(IN3, 255);
  analogWrite(IN2, 130);
}

void diagDireitaTrasOn(){
    analogWrite(IN3, 130);
    analogWrite(IN2, 255);
  }

void parar(){
 analogWrite(IN1, 0);
 analogWrite(IN2, 0);
 analogWrite(IN3, 0);
 analogWrite(IN4, 0);
  
}
