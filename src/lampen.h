// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ansteuerung der Lampen (Neopixel)
//              - Fahrlicht - Funktion
//              - Blinker - Funktion (links, rechts)
//              - Neopixel Einzelansteuerung
//
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: lampen.h
// ==========================================================================
#ifndef lampen_h
#define lampen_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h> // Neopixel einbinden

// Neopixel Konfiguration
#define PIN 6
#define NUMPIXELS 8
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Blinker Konfiguration
boolean blinkerLinksOn = false;
int blinkerLinksLEDNr = 0;
boolean blinkerRechtsOn = false;
int blinkerRechtsLEDNr = 7;

// Fahrlicht Konfiguration
boolean fahrlicht = false;
int fahrLichtLEDNr1 = 1;
int fahrLichtLEDNr2 = 2;
int fahrLichtLEDNr3 = 5;
int fahrLichtLEDNr4 = 6;

// Blinker Intervall
unsigned int blinkInterval = 500; // Blinkintervall in Millisekunden

// forward declaration der Methoden
void initLampen();
void setBlinker(boolean links, boolean rechts);
void blinker();
void setFahrlicht(boolean on);
void setPixelColor(int pin, int r, int g, int b);
void setPixelClear();
void setPixelColorAll(int r, int g, int b);

// ========================================================================

// noepixel initialisieren
void initLampen()
{
  // Neopixel initialisieren
  pixels.begin();
  pixels.clear();
  pixels.show();
  Serial.println("Neopixel initialized");
}

// Fahrlicht einschalten
void setFahrlicht(boolean on)
{
  fahrlicht = on;
  if (fahrlicht)
  {
    setPixelColor(fahrLichtLEDNr1, 255, 255, 255);
    setPixelColor(fahrLichtLEDNr2, 255, 255, 255);
    setPixelColor(fahrLichtLEDNr3, 255, 255, 255);
    setPixelColor(fahrLichtLEDNr4, 255, 255, 255);
  }
  else
  {
    setPixelColor(fahrLichtLEDNr1, 0, 0, 0);
    setPixelColor(fahrLichtLEDNr2, 0, 0, 0);
    setPixelColor(fahrLichtLEDNr3, 0, 0, 0);
    setPixelColor(fahrLichtLEDNr4, 0, 0, 0);
  }
}

// Blinker setzen
void setBlinker(boolean links, boolean rechts)
{
  Serial.println("setBlinker" + links + rechts);
  blinkerLinksOn = links;
  blinkerRechtsOn = rechts;
  blinker(); // Blinker sofort ansteuern
}

// Blinken, wird von setBlinker() aufgerufen
void blinker()
{
  Serial.println("Blinker- Routine...");
  static boolean blinkerLinks = false;  // speichert den Zustand des Blinkers
  static boolean blinkerRechts = false; // speichert den Zustand des Blinkers

  static unsigned long currentMillis = 0;       // speichert die aktuelle Zeit
  static unsigned long previousMillisBlink = 0; // speichert die Zeit des letzten Blinkens

  boolean changeState = false; // speichert den Zustand des Blinkers

  // Statusänderungen nur alle 500ms (blinkInterval) ausführen
  currentMillis = millis(); // aktuelle Zeit ermitteln
  if (currentMillis - previousMillisBlink >= blinkInterval)
  {
    previousMillisBlink = currentMillis;
    changeState = true;
  }

  // Blinker links ansteuern
  if (blinkerLinksOn) // falls Blinker lins aktiv ist
  {
    if (changeState) // falls Zeit von 500 ms abgelaufen ist
    {

      if (blinkerLinks)
      {
        Serial.println("BlinkerLinksOn");
        setPixelColor(blinkerLinksLEDNr, 0, 0, 0);
        blinkerLinks = false;
      }
      else
      {
        Serial.println("BlinkerLinksOff");
        setPixelColor(blinkerLinksLEDNr, 255, 255, 0);
        blinkerLinks = true;
      }
    }
  }
  else
  {
    setPixelColor(blinkerLinksLEDNr, 0, 0, 0);
  }

  // Blinker rechts ansteuern
  if (blinkerRechtsOn) // falls Blinker rechts aktiv ist
  {
    if (changeState) // falls Zeit von 500 ms abgelaufen ist
    {

      if (blinkerRechts)
      {
        Serial.println("BlinkerRechtsOn");
        setPixelColor(blinkerRechtsLEDNr, 0, 0, 0);
        blinkerRechts = false;
      }
      else
      {
        Serial.println("BlinkerRechtsOff");
        setPixelColor(blinkerRechtsLEDNr, 255, 255, 0);
        blinkerRechts = true;
      }
    }
  }
  else
  {
    setPixelColor(blinkerRechtsLEDNr, 0, 0, 0);
  }
}

// Einzelpixel ansteuern (0-7) mit Farbe (r,g,b)
void setPixelColor(int pin, int r, int g, int b)
{
  pixels.setPixelColor(pin, pixels.Color(r, g, b));
  pixels.show();
}

// alle Pixel ausschalten
void setPixelClear()
{
  pixels.clear();
  pixels.show();
}

// alle Pixel mit Farbe (r,g,b) ansteuern
void setPixelColorAll(int r, int g, int b)
{
  for (int i = 0; i < NUMPIXELS; i++)
  {
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }
  pixels.show();
}

#endif