#include <SoftwareSerial.h>






SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  
  Serial.begin(9600);   //inicio HW Serial 

  Serial.println("iniciando");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());

    
}
