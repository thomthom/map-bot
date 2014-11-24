#include <SharpGP2D120X.h>

SharpGP2D120X ir_sensor(1);

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  delay(1000);
  Serial.println(" ");
  
  // Get the sensor value in mm.
  int distance = ir_sensor.read();
  
  Serial.print(distance);
  Serial.println("mm");
  
  // Check if the returned value is within the valid range or the sensor.
  if (!ir_sensor.isValidDistance(distance)) {
    if (distance < ir_sensor.minDistance()) {
      Serial.println(") Out of range - Too small");
    } else if (distance > ir_sensor.maxDistance()) {
      Serial.println(") Out of range - Too large");
    } else {
      Serial.println(") In range");
    }
  }
}
