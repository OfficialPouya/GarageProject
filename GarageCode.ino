// This #include statement was automatically added by the Spark IDE.

/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social groups:              http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************


#include "blynk/blynk.h"
//#include <SPI.h>
//#include <Ethernet.h>
//#include <BlynkSimpleEthernet.h>

//
char auth[] = "YOU THOUGHT I WILL GIVE U MY AUTH CODE?! ;)";
int sensorPin=0;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth);
  pinMode(D0, OUTPUT);

  // You can also specify server.
  // For more options, see Transports/Advanced/CustomEthernet example
  //Blynk.begin(auth, "server.org", 8442);
  //Blynk.begin(auth, IPAddress(192,168,1,100), 8888);
}



void loop()
{
    Blynk.run();  
    int reading = analogRead(sensorPin);  
 
 	// converting that reading to voltage, for 3.3v arduino use 3.3
 	float voltage = reading * 5.0;
	voltage /= 1024.0; 
 	Serial.print(voltage); Serial.println(" volts");
 	float temperatureC = (voltage - 0.5) * 100 ;  
 	//converting from 10 mv per degree wit 500 mV offset
    //to degrees ((voltage - 500mV) times 100)
 	Serial.print(temperatureC); Serial.println(" degrees C");
 
 	//converting to Fahrenheit
 	float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
	Serial.print(temperatureF); Serial.println(" degrees F");
 	delay(1000);                                     //waiting a second  
}

