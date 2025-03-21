/*
   ADXL345 Accelerometer with Arduino
   ----------------------------------
   Features & Functionality:
   - This code interfaces the ADXL345 accelerometer with an Arduino using the I2C protocol.
   - It initializes the ADXL345 sensor and continuously reads acceleration values along the X, Y, and Z axes.
   - The readings are displayed in meters per second squared (m/s²) on the Serial Monitor.
   - If the sensor is not detected, an error message is printed, and the program halts.
   - The data refreshes every 500 milliseconds for real-time monitoring.

   Required Libraries:
   - Wire.h: For I2C communication
   - Adafruit_Sensor.h: Adafruit Unified Sensor driver
   - Adafruit_ADXL345_U.h: Library for ADXL345 accelerometer
*/


#include <Wire.h>                // Library for I2C communication
#include <Adafruit_Sensor.h>     // Adafruit Sensor Library
#include <Adafruit_ADXL345_U.h>  // Library for ADXL345 Accelerometer

// Create an ADXL345 sensor object
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();

void setup(void) 
{
   Serial.begin(9600);  // Initialize serial communication at 9600 baud rate

   // Initialize the ADXL345 sensor
   if (!accel.begin()) 
   {
      Serial.println("No valid sensor found");  // Print error message if sensor is not detected
      while (1);  // Halt the program if the sensor is not found
   }
}

void loop(void) 
{
   sensors_event_t event;  // Create a sensor event object to store accelerometer readings
   accel.getEvent(&event); // Get accelerometer data

   // Print X, Y, and Z-axis acceleration values to the Serial Monitor
   Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print("  ");
   Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print("  ");
   Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print("  ");
   Serial.println("m/s^2 "); // Display the unit of measurement

   delay(500);  // Wait for 500 milliseconds before taking the next reading
}
