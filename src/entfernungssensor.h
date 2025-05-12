// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ermittlung der Werte des Entfernungssensors
//              - initialisierung des sensors
//              - getDistance
//
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: entfernungssensor.h
// ==========================================================================
#ifndef enternungssensor_h
#define enternungssensor_h

#include <Arduino.h>
#include <HCSR04.h>

// initialisierung des sensors
#define TRIG_PIN 3
#define ECHO_PIN 2
UltraSonicDistanceSensor distanceSensor(TRIG_PIN, ECHO_PIN);

// initialisierung des sensors
void initDistanceSensor()
{
  // keine initialisierung notwendig
}

// get Distance
int getDistance()
{
  return distanceSensor.measureDistanceCm();
}


#endif