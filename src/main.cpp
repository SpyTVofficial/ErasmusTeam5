// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Hauptprogramm für das Smart Car
//              - Initialisierung der Sensoren und Aktoren
//              - Hauptprogrammschleife
//
//              SIEHE AUCH die Datei "_readme_.h" für eine kurze Beschreibung
//
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: main.cpp
// ==========================================================================
#include <Arduino.h>
#include "entfernungssensor.h" // Entfernungssensor.h (Ultraschallsensor HCSR04)
#include "batterie.h"          // batterie.h (Batteriespannung)
#include "lampen.h"            // neoPixel.h (Leuchtstreifen WS2841)
#include "motor.h"             // motor.h (L298N Motor)
#include "hupe.h"              // hupe.h (Buzzer)
#include "motorcontrol.h"      // motorregelung.h (PID-Regler)
#include "helligkeitssensor.h" // helligkeitssensor.h (Lichtsensor)
#include "liniensensor.h"      // LlinienSensor.h (Lichtsensor)


void setup()
{
  Serial.begin(9600);
  initBatterie();
  initHupe();
  initLampen();
  initMotor();
  initDistanceSensor();
  initBrightnessSensor();
  initLineSensor();
  Serial.println("Setup completed");
  Serial.println("Battery voltage: " + String(getBatterieVoltage()) + " V");
//  if(checkBatterie() < ) TODO: Check Battery Charge
}

void loop(){
  // Motorsteuerung
  driveCar(true); // Motoren einschalten und der "Straße" folgen (siehe motorcontrol.h)

  // Weiterhin kann hier 
  // - die Rounitne checkBatterie() oder getBatterieVoltage() aufgerufen werden, um die 
  //   Batterieriespannung zu prüfen und ggf. eine Warnung auszugeben.
  // - die Routine checkDistanceSensor() aufgerufen werden, um den 
  //   Abstand zu einem Hindernis zu prüfen umd ggf. auszuweichen
  // - die Routine checkHelligkeitSensor() aufgerufen werden, um die 
  //   Helligkeit zu prüfen und ggf. das Licht einzuschalten
  // - die Routine hupe() aufgerufen werden, um den Buzzer zu aktivieren
  //   falls der Roboter auf ein Hindernis zufährt oder Gefahr läuft
  //   von der Straße abzukommen.
  // - die Reoutine setBlinker(boolean links, boolean rechts) aufgerufen werden, 
  //   um die Blinker ein/auszuschalten.
  // - die Routine setFahrlicht(boolean on) aufgerufen werden, um das
  //   Fahrlicht ein/auszuschalten.
  //
  // WICHTIG: Die Routinen dürfen nicht blockierend sein, d.h. sie dürfen
  //          KEINE (!!!) delay() enthalten, da sonst die Motoren nicht mehr
  //          zeitnah angesteuert werden können.
  //
  // DER FANTASIE SIND KEINE GRENZEN GESETZT!  -  SEI KREATIV   ;-)
  //

  delay(100); // 100ms warten - einzige (!!!) Verzögerung im ganzen Programm

}