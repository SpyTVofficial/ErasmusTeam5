// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ermittlung der Werte des Helligkeitssensor (LDR)
//              - initialisierung des sensors
//              - getBrightness
//              Mit den Werten kann z.B. die Fahzeugbeleuchtung gesteuert werden.
//
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: helligkeitssensor.h
// ==========================================================================
#ifndef helligkeitssensor_h
#define helligkeitssensor_h

#include <Arduino.h>

#define SENSOR_PIN A0

// initialisierung des sensors
void initBrightnessSensor()
{
  // keine initialisierung notwendig
}

// get brightness
int getBrightness()
{
  return analogRead(SENSOR_PIN);
}


#endif