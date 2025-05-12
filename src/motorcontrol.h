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
    if (drive == true)
    {
        /**
        if(getDistance() < 20)
        {
            motorStop();
            Serial.println("Obstacle detected in " + String(getDistance()));
            hupen();
            return;
        } else if(getDistance() > 20) { */
            if(getLineSensorLeft() == 0 && getLineSensorRight() == 1){
                motorDrive(100,100);
            }
            if(getLineSensorLeft() == 1 && getLineSensorRight() == 1){
                motorDrive(20,100);
            }
            if(getLineSensorLeft() == 0 && getLineSensorRight() == 0){
                motorDrive(100,20);
            }
            

  //          Serial.println("Motors turning");
//        }
//        Serial.write("Drive car\n");
         // HIER KOMMT DIE STEUERUNG DER MOTOREN HIN.
         // Dabei müssen die Motoren enstsprechend der Sensorwerte
         // gesteuert werden, damit der Roboter auf dem gewünschten Kurs bleibt
         // und nicht von der Linie abkommt.
         // Nutze die Methoden aus 
         // - motor.h: setMotorSpeed(int lineLeft, int lineRight)  0..255 als Parameterwerte
         // - liniensensor.h: getLineSensorValueLeft() und getLineSensorValueRight()
         // - entfernungssensor.h: getDistanceSensorValue() um Hindernisse zu erkennen

    }
    else
    {
        motorStop(); // Motoren anhalten
    }

}



#endif