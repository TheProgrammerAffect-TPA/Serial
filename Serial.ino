#include <SoftwareSerial.h>
SoftwareSerial BTserial(2, 3); // RX | TX
// Connect the HC-05 TX to Arduino pin 2 RX. 
// Connect the HC-05 RX to Arduino pin 3 TX through a voltage divider.
// 

char A = ' ';

int incomingByte = 0;
int led1 = 13;
int led3 = 2;


void setup() {
  Serial.begin(115200);
  Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");
 
    // HC-05 default serial speed for Command mode is 9600
    BTserial.begin(115200);  
  pinMode(led1, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  if (Serial.available())  {
    if (BTserial.available()) {
       BTserial.read();
        
    }
    //Read incoming Byte:
    incomingByte = Serial.read();

    

    switch (char(incomingByte)) {
      default:
      case 'A':

      Serial.println(" LED 1  ON");
      ledOn(led1);
      
    //  break;

   case 'a':
   Serial.println(" LED 1  OFF");
   ledOff(led1);
   break;

 case 'B':
   Serial.println(" LED 3 ON"); 
   ledOn(led3);
   

   break;
  
 case 'b':

   Serial.println(" LED 3 OFF"); 
   ledOff(led3);

   break;
    }

    
  }
}


void ledOn(int pin) {
  digitalWrite(pin, HIGH);

}

void ledOff(int pin) {
  digitalWrite(pin, LOW);

}
