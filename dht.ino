#include "DHT.h"

/* DHT*/
  #define DHTPIN 2   
  #define DHTTYPE DHT22   
  DHT dht(DHTPIN, DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  pinMode(DHTPIN, OUTPUT);
  digitalWrite(DHTPIN, LOW);
}



void loop() {
  dhtSensor();
  delay(5000);
}


void dhtSensor(){
  float h = dht.readHumidity();       
  float c = dht.readTemperature();        // Read temperature as Celsius (the default)
  float f = dht.readTemperature(true);    // Read temperature as Fahrenheit (isFahrenheit = true)
  float hif = dht.computeHeatIndex(f, h);       // Compute heat index in Fahrenheit (the default)
  float hic = dht.computeHeatIndex(c, h, false);     // Compute heat index in Celsius (isFahreheit = false)
  
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(c);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
}

