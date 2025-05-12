// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ermittlung der Werte des LinienSensors
//              - initialisierung des sensors
//              - getLineSensorLeft
//              - getLineSensorRight
//              - die Methoden liefern eine 1, falls die Linie erkannt wird
//                und eine 0, falls keine Linie erkannt/verlassen wird
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: linienSensor.h
// ==========================================================================
#ifndef linienSensor_h
#define linienSensor_h

#include <Arduino.h>

#define LINESENSORLeft_PIN 8
#define LINESENSORRight_PIN 7

// forward declaration
void initLineSensor();     // initialisierung des sensors
int getLineSensorLeft();   // get brightness left sensor
int getLineSensorRight();  // get brightness right sensor

// initialisierung des sensors
void initLineSensor()
{
    pinMode(LINESENSORLeft_PIN, INPUT_PULLUP);
    pinMode(LINESENSORRight_PIN, INPUT_PULLUP);   
}

// get brightness left sensor
int getLineSensorLeft()
{
    if (digitalRead(LINESENSORLeft_PIN) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// get brightness right sensor
int getLineSensorRight()
{
    if (digitalRead(LINESENSORRight_PIN) == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif