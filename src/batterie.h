// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Ermittlung der Batteriespannung einer 9V Blockbatterie
//              - Anschluss über Spannungsteiler an A0
//              - Spannungsteiler: 10kOhm und 10kOhm
//              - Spannungsbereich: 0,0V - 9,0V
//              - Spannungswerte des ADC: 0 - 1023
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: batterie.h
// ==========================================================================
//
#ifndef batterie_h
#define batterie_h

#include <Arduino.h>
#include <lampen.h>
#include <hupe.h>

#define BATTERY_SHOW_VOLTAGE true   // Spannung auf dem LED-Streifen anzeigen
#define BATTERY_NOISE_WARNING false // akustische Warnung bei niedriger Spannung

#define BATTERY A0
#define BATTERY_MAX 1023    // 1023 = 10bit ADC
#define BATTERY_MIN 0       // 0
#define BATTERY_OFFSET 0.0  // 0V

#define R1 10000.0
#define R2 10000.0

#define BATTERY_VOLTAGE_FULL 9.0     // 9V
#define BATTERY_VOLTAGE_WARNING 7.0  // 7V
#define BATTERY_VOLTAGE_LOW 6.0      // 6V
#define BATTERY_VOLTAGE_CRITICAL 5.0 // 5V

// Batterie initialisieren
void initBatterie()
{
    pinMode(BATTERY, INPUT);
    initHupe();
    initLampen();
    Serial.println("Batterie initialized");
}

// Batteriespannung ermitteln
float getBatterieVoltage()
{
    int value = analogRead(BATTERY);
    float voltage = map(value, BATTERY_MIN, BATTERY_MAX, 0, 90); // 00-90 -> 0,0-9,0
    voltage = voltage * 0.1;
    Serial.println("Batterie: " + String(value) + " -> " + String(voltage) + " V");
    return voltage;
}

// Batterie prüfen, Werte anzeigen und ggf. Warnung ausgeben
void checkBatterie()
{
    float voltage = getBatterieVoltage(); // Spannung ermitteln

    if (BATTERY_SHOW_VOLTAGE)
    {
        // Spannung auf dem LED-Strip anzeigen
        int leds = map(voltage, BATTERY_VOLTAGE_CRITICAL, BATTERY_VOLTAGE_FULL, 0, 8);
//        Serial.println("LEDs: " + String(leds));
        if (leds <= 0) // keine LED
        {
            setPixelClear();
            setPixelColor(0, 255, 0, 0); // rot
        }
        else
        {
            for (int i = 0; i < leds; i++)
            {
                if (voltage < BATTERY_VOLTAGE_WARNING)
                    setPixelColor(i, 255, 0, 0); // rot
                else
                    setPixelColor(i, 0, 255, 0); // grün
            }
            for (int i = leds; i < 8; i++)
            {
                setPixelColor(i, 0, 0, 0); // aus
            }
        }
    }

    if (voltage < BATTERY_VOLTAGE_CRITICAL)
    {
        if (BATTERY_NOISE_WARNING)
        {
            hupen();
        }
    }
}

#endif