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
        if (getLineSensorLeft() == 1 && getLineSensorRight() == 1)
        {
            motorDrive(100, 100); 
            Serial.println("Left side on line");
            setBlinker(false, false);
            setFahrlicht(true);
            
        } else if(getLineSensorLeft() == 0 && getLineSensorRight() == 1){
            motorDrive(50,35);
            setFahrlicht(false);
            setBlinker(false, true);


        }  else if(getLineSensorLeft() == 1 && getLineSensorRight() == 0){
            motorDrive(35,50);
            setFahrlicht(false);
            setBlinker(true, false);
            

        }   else if(getLineSensorLeft() == 0 && getLineSensorRight() == 0){
            motorDrive(-30,-30);
            setFahrlicht(false);
           setBlinker(false, false);
        }
         /** else {et
            motorStop();
        }*/
       /**
       if(getLineSensorLeft() == 1){
        Serial.println("Left sensor 1");
       }
        if(getLineSensorRight() == 1){
            Serial.println("Right sensor 1");
        } */
    } else {
        motorStop(); // Motoren anhalten
    }

}
        
/**        if(getDistance() < 20 || getDistance() != -1) //Detect object ~ 20cm away from robot
        { 
            motorStop();
            Serial.println("Obstacle detected in " + String(getDistance()));
            hupen();
            return;
        } else if(getDistance() > 20) {  */
/**            if(getLineSensorLeft() == 1 && getLineSensorRight() == 1){ // If robot is on the line
                motorDrive(100, 100);
                Serial.println("Robot on line");
            } else if(getLineSensorLeft() == 1 && getLineSensorRight() == 0){ // If right side went off the line
                motorDrive(20,100);
                Serial.println("Right side off");
            } else if(getLineSensorLeft() == 0 && getLineSensorRight() == 1){ // If left side went off the line
                motorDrive(100,20);
                Serial.println("Left side off");
            } else if(getLineSensorLeft() == 0 && getLineSensorRight() == 0){ // if robot is off the line
                motorDrive(10, 50);
                Serial.println("Robot off line"); 
            } */
//        }
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
#endif