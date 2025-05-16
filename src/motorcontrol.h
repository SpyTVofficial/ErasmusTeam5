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
        // Create a combined value for both sensors to use in switch-case
        int sensorState = (getLineSensorLeft() << 1) | getLineSensorRight();

        switch (sensorState) {
            case 1:  // Left = 0, Right = 1
                motorDrive(80, 80);
                setFahrlicht(true);
                setBlinker(false, false);
                break;
                
            case 0:  // Left = 0, Right = 0
                motorDrive(40, 15);
                setFahrlicht(false);
                setBlinker(false, true);
                break;
            case 2:  // Left = 1, Right = 0
                motorDrive(50, -50);
                delay(500);
                setFahrlicht(false);
                setBlinker(true, true);
                break;
            case 3:  // Left = 1, Right = 1
                motorDrive(15, 40);
                setFahrlicht(false);
                setBlinker(true, false);
                break;
            // Optional default case if needed
            // default:
            //   // Handle any unexpected sensor state
            //   break;
        }
        
        // If distance is -1 (sensor sees >2m), ignore distance and drive normally
        if (distance == -1) {
            // Do nothing, allow normal line following logic above to control motors
        } else {
            int distanceCase = 0;

            if (distance < 1) {
                distanceCase = 0;
            } else if (distance < 3) {
                distanceCase = 1;
            } else if (distance < 5) {
                distanceCase = 2;
            } else if (distance < 7) {
                distanceCase = 3;
            } else if (distance < 10) {
                distanceCase = 4;
            } else {
                distanceCase = 5;
            }

            switch (distanceCase) {
                case 0:
                    motorStop();
                    break;
                case 1:
                    motorDrive(25, 25);
                    delay(300);
                    motorDrive(25, 25);
                    break;
                case 2:
                    motorDrive(25, 25);
                    delay(300);
                    motorDrive(25, 25);
                    break;
                case 3:
                    motorDrive(25, 25);
                    delay(300);
                    motorDrive(25, 25);
                    break;
                case 4:
                    motorDrive(25, 25);
                    delay(300);
                    motorDrive(25, 25);
                    break;
                default:
                    // No action for distance >= 10
                    break;
            }
        }
    } else {
        motorStop(); // Motoren anhalten
    }
    
    // HIER KOMMT DIE STEUERUNG DER MOTOREN HIN.
    // Dabei müssen die Motoren enstsprechend der Sensorwerte
    // gesteuert werden, damit der Roboter auf dem gewünschten Kurs bleibt
    // und nicht von der Linie abkommt.
    // Nutze die Methoden aus 
    // - motor.h: setMotorSpeed(int lineLeft, int lineRight)  0..255 als Parameterwerte
    // - liniensensor.h: getLineSensorValueLeft() und getLineSensorValueRight()
    // - entfernungssensor.h: getDistanceSensorValue() um Hindernisse zu erkennen
}

#endif