// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für Steuerung des Robots auf der "Straße"
//              Hier müssen die Motoren entsprechend der Sensorwerte
//              gesteuert werden, damit der Roboter auf dem gewünschten Kurs bleibt
//              Die Reoutine driveCar(boolean go) steuert die Motoren wird
//              kontinuierlich aus der Loop aufgerufen.
//           
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: motorcontrol.h
// ==========================================================================
#ifndef motorcontrol_h
#define motorcontrol_h

#include <Arduino.h>
#include "motor.h"
#include "hupe.h"
#include "liniensensor.h"
#include "entfernungssensor.h"

// RobotCar Dyvelbot - Motorsteuerung
void driveCar(boolean drive)
{
    if (drive == true) {
        
        float distance = getDistance();

        Serial.println("Distance: " + String(distance));
        if (getLineSensorLeft() == 0 && getLineSensorRight() == 1)
        {
            motorDrive(50, 50); 
            setFahrlicht(true);
            setBlinker(false, false);
        
        } else if(getLineSensorLeft() == 0 && getLineSensorRight() == 0){
            motorDrive(40,15);
            setFahrlicht(false);
            setBlinker(false, true);

        }  else if(getLineSensorLeft() == 1 && getLineSensorRight() == 1){
            motorDrive(15,40);
            setFahrlicht(false);
            setBlinker(true, false);
        }
  
        if(distance < 1){
            motorStop();
            delay(300);
            motorDrive(25,25);
            Serial.println("motor 0");
        } else if(distance < 3){
            motorDrive(25,25);
            delay(300);
            motorDrive(25,25);
            Serial.println("motor 5");
        } else if(distance < 5){
            motorDrive(25,25);
            delay(300);
            motorDrive(25,25);
            Serial.println("motor 10");
        } else if(distance < 7){
            motorDrive(25,25);
            delay(300);
            motorDrive(25,25);
            Serial.println("motor 20");
        } else if(distance < 10){
            motorDrive(25,25);
            delay(300);
            motorDrive(25,25);
            Serial.println("motor 30");
        } else {
            
        }
    } else {
        motorStop(); // Motoren anhalten
    }

}
         // HIER KOMMT DIE STEUERUNG DER MOTOREN HIN.
         // Dabei müssen die Motoren enstsprechend der Sensorwerte
         // gesteuert werden, damit der Roboter auf dem gewünschten Kurs bleibt
         // und nicht von der Linie abkommt.
         // Nutze die Methoden aus 
         // - motor.h: setMotorSpeed(int lineLeft, int lineRight)  0..255 als Parameterwerte
         // - liniensensor.h: getLineSensorValueLeft() und getLineSensorValueRight()
         // - entfernungssensor.h: getDistanceSensorValue() um Hindernisse zu erkennen
#endif