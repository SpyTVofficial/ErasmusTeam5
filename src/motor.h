// ==========================================================================
// Projekt: Erasmus+ IoT - Smart Car
// ==========================================================================
// Description: Methoden für die Ansteuerung der Motoren
//              - initialisierung der Motoren
//              - Motor stoppen
//              - Motor fahren (speed_left, speed_right)
//           
// Creator:  S. Wintgen
// Date: 2025-03-11
// Version: 1.0
// File: motor.h
// ==========================================================================
#ifndef motor_h
#define motor_h

#include <Arduino.h>

// define motor pins
#define ENA 10 // PWM
#define IN1 A4 // direction
#define IN2 A5 // direction
#define ENB 9  // PWM
#define IN3 A3 // direction
#define IN4 A2 // direction

// offset for motor speed
#define OFFSET_LEFT 0
#define OFFSET_RIGHT 0

// maximum speed
#define MAX_SPEED 255

// forward declaration
void initMotor();
void motorStop();
void motorDrive(int speed_left, int speed_right);

// initialize motor
void initMotor()
{
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENB, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    motorStop();
    Serial.println("Motor initialized");
}

// stop motor
void motorStop()
{
    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENB, 0);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// drive (speed_left, speed_right)
void motorDrive(int speed_left, int speed_right)
{

    // limit speed left motor
    if (speed_left > 0)
    {
        speed_left += OFFSET_LEFT;
        if (speed_left > MAX_SPEED)
            speed_left = MAX_SPEED;
    }
    if (speed_left < 0)
    {
        speed_left -= OFFSET_LEFT;
        if (speed_left < -MAX_SPEED)
            speed_left = -MAX_SPEED;
    }

    // limit speed right motor 
    if (speed_right > 0)
    {
        speed_right += OFFSET_RIGHT;
        if (speed_right > MAX_SPEED)
            speed_right = MAX_SPEED;
    }
    if (speed_right < 0)
    {
        speed_right -= OFFSET_RIGHT;
        if (speed_right < -MAX_SPEED)
            speed_right = -MAX_SPEED;
    }

    // left motor
    if (speed_left > 0)  // forward
    {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    }
    if (speed_left < 0)  // backward
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
    }
    if (speed_left == 0)  // stop
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
    }
    analogWrite(ENA, abs(speed_left));

    // right motor
    if (speed_right > 0)  // forward
    {
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    }
    if (speed_right < 0) // backward
    {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    if (speed_right == 0) // stop
    {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, LOW);
    }
    analogWrite(ENB, abs(speed_right));
}

#endif