#include <SoftwareSerial.h>
#include "DHT.h"



#define DHTPIN 7
#define DHTTYPE DHT11

SoftwareSerial mySerial(2, 3); // RX, TX
DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  
  Serial.begin(9600);   //inicio HW Serial 

  Serial.println("iniciando");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
    dht.begin();
  
}

void loop() // run over and over
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read());

delay(2000);


  float h = dht.readHumidity();
 
  float t = dht.readTemperature();

  


  if (isnan(h) || isnan(t)) {         // Verificamos si falla la lectura
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  float hic = dht.computeHeatIndex(t, h, false);  //Calculamos la sensación térmica

  Serial.print(("Humedad: "));
  Serial.print(h);
  Serial.print(("%  Temperatura: "));
  Serial.print(t);
  Serial.print(("°C "));

  Serial.print(("Sensación térmica: "));
  Serial.print(hic);
  Serial.println(("°C "));
    
}
