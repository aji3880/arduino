#include <SoftwareSerial.h>

const int LEDMerah = 2;
const int LEDHijau = 3;
const int LEDKuning = 4;

SoftwareSerial Bluetooth(6, 5);

int state = 0;

void setup(){
    Serial.begin(9600);
    Bluetooth.begin(9600);
    pinMode(LEDMerah, OUTPUT);
    pinMode(LEDHijau, OUTPUT);
    pinMode(LEDKuning, OUTPUT);
}

void loop(){
    if(Bluetooth.available()>0){
        state = Bluetooth.read();
        Serial.println("State = " + state);
        if(state == 'M'){
            digitalWrite(LEDMerah, HIGH);
            state = 0;
       }else if(state == 'H'){
           digitalWrite(LEDHijau, HIGH);
           state = 0;
       }else if(state == 'K'){
           digitalWrite(LEDKuning, HIGH);
           state = 0;
       }else if(state == 'N'){
           //untuk mematikan semua lampu
            digitalWrite(LEDMerah, LOW);
            digitalWrite(LEDHijau, LOW);
            digitalWrite(LEDKuning, LOW);
            state = 0;
       }
    }
}