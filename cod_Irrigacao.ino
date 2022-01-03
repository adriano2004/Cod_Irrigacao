//#include <Wire.h>
#include "RTClib.h"

byte ledverde=3;
byte ledvermelho=4;

byte horaliga = 6;

RTC_DS3231 rtc;

//char dias[7][12] = {"Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"};

#define rele 6// é o de baixo olhando com a escrita 2 relay module
//para baixo

int sensor;

void setup() {
    pinMode(rele, OUTPUT);
    pinMode(ledverde, OUTPUT);
    pinMode(ledvermelho, OUTPUT);
    Serial.begin(9600);

    if(!rtc.begin()){
        //Serial.println("RTC NAO INICIALIZADO");
        while(1);
    }
    digitalWrite(rele, HIGH);
   // rtc.adjust(DateTime(2022, 1, 03, 10, 25, 00));
}

void loop() {
    sensor = analogRead(A0);
    DateTime agora = rtc.now();
    Serial.println(sensor);
    if (agora.hour() == horaliga){
        if (sensor > 500){
            digitalWrite(rele, LOW); 
            digitalWrite(ledverde, LOW);  
            digitalWrite(ledvermelho, HIGH);
            //Serial.println("Esta molhando");// não precisa ser molhada
        }
        else {
            digitalWrite(rele, HIGH);
            digitalWrite(ledverde, HIGH);  
            digitalWrite(ledvermelho, LOW);
            //Serial.println("Nao esta molhando");// precisa ser molhada
        }
    }
    else {
        digitalWrite(rele, HIGH);
        digitalWrite(ledverde, HIGH);  
        digitalWrite(ledvermelho, LOW);
        //Serial.println("Nao esta molhando");// precisa ser molhada
    }
}
