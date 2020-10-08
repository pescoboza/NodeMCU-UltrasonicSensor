#include <Arduino.h>

#define D2 4
#define D1 5
#define D5 14

#define PIN_SENSOR_TRIG D2
#define PIN_SENSOR_ECHO D1
#define PIN_LED D5

#define DISTANCE_TO_TURN_LED 200
#define DELAY 200

unsigned calcDist(){
    // Make sure trigger pin is low
    digitalWrite(PIN_SENSOR_TRIG, LOW);
    delayMicroseconds(2);

    // Send 10 ms sensor trigger
    digitalWrite(PIN_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_SENSOR_TRIG, LOW);

    // Measure the duration of the pulse sent by echo
    unsigned long duration{pulseIn(PIN_SENSOR_ECHO, HIGH)};
    return duration * 0.1715;
}

void setup() {
    pinMode(PIN_SENSOR_TRIG, OUTPUT);
    pinMode(PIN_SENSOR_ECHO, INPUT);
    pinMode(PIN_LED, OUTPUT);

    Serial.begin(9600);

}

void loop() {
    unsigned dist{calcDist()};
    digitalWrite(PIN_LED, dist < DISTANCE_TO_TURN_LED ? HIGH : LOW);
    Serial.print("Distance: ");
    Serial.println(dist);
    delay(DELAY);
}