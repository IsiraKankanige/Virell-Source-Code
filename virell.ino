// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_DHT_Particle.h>



// DHT parameters

#define DHTPIN D7    // DHTPIN D7 gpio19 on the Raspberry pI

#define DHTTYPE DHT11    // Type of the DHT11 Sensor 


int temperature = 0;

int humidity;


DHT dht(DHTPIN, DHTTYPE);

 

void setup() {

    Particle.variable("temperature", temperature);   // Temperature Variable

    dht.begin();

}

 

void loop() {


    temperature = dht.getTempFarenheit(); // Converting the measurement into Farenheit 
    
     Particle.publish ("temperature", String(temperature) + " °F"); // Publishing data to the web 

     delay(500);

     String temp = String(temperature);

     Particle.publish("temp", temp, PRIVATE);

 delay(30000);

  if( 20 <temperature < 25) {

 // Checking the temperature which should be in the healthy margin 

  Particle.publish("Temperature is unhealthy", "True");

} else {

 // else statement 

  Particle.publish("Temperature is high", "True");

}

}