
#include <dht.h>
// Digital pin 8 will be called 'pin8'
int pin8 = 8;
// Analog pin 0 will be called 'sensor'
int sensor = A0;
// Set the initial sensorValue to 0
int sensorValue = 0;

#define dht_apin A1 // Analog Pin sensor is connected to
 dht DHT;
// The setup routine runs once when you press reset
void setup() {
  // Initialize the digital pin 8 as an output
 // pinMode(pin8, OUTPUT);
  // Initialize serial communication at 9600 bits per second
  Serial.begin(9600);
}

// The loop routine runs over and over again forever
void loop() {
  // Read the input on analog pin 0 (named 'sensor')
  sensorValue = analogRead(sensor);
  // Print out the value you read
  Serial.println(sensorValue, DEC);
  delay(1000);
  // If sensorValue is greater than 500
  if (sensorValue > 500) {
     Serial.println("Bohot phook raha hai!");
    // Activate digital output pin 8 - the LED will light up
  //  digitalWrite(pin8, HIGH);
  }
  else {
    // Deactivate digital output pin 8 - the LED will not light up
   // digitalWrite(pin8, LOW);
  }
 DHT.read11(dht_apin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity); 
    Serial.print("%  "); 
    Serial.print("temperature = "); 
    Serial.print(DHT.temperature);  
    Serial.println("C  "); 
  delay(5000);//Wait 5 seconds before accessing sensor again. 
  //Fastest should be once every two seconds.
}
