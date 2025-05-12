// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ansteuerung der Hupe
//              - initialisierung der Hupe
//              - hupen
//           
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: hupe.h
// ==========================================================================
#ifndef hupe_h
#define hupe_h

#include <Arduino.h>

#define HUPE_PIN 5


// initialize Hupe
void initHupe()
{
    pinMode(HUPE_PIN, OUTPUT);
    digitalWrite(HUPE_PIN, LOW);
    Serial.println("Hupe initialized");
}

// hupen (100ms)
void hupen()
{
    digitalWrite(HUPE_PIN, HIGH);
    delay(500);
    digitalWrite(HUPE_PIN, LOW);
}


#endif