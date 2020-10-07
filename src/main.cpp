#include <Arduino.h>

#define D2 4
#define D1 5
#define D5 14

#define PIN_SENSOR_TRIG D2
#define PIN_SENSOR_ECHO D1
#define PIN_LED D5

unsigned long duration{0U};
unsigned distance{0U};

void setup() {
    pinMode(PIN_SENSOR_TRIG, OUTPUT);
    pinMode(PIN_SENSOR_ECHO, INPUT);
    pinMode(PIN_LED, OUTPUT);

    Serial.begin(9600);

}

void loop() {
    // Make sure trigger pin is low
    digitalWrite(PIN_SENSOR_TRIG, LOW);
    delayMicroseconds(2);

    // Send 10 ms sensor trigger
    digitalWrite(PIN_SENSOR_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PIN_SENSOR_TRIG, LOW);

    // Measure the duration of the pulse sent by echo
    duration = pulseIn(PIN_SENSOR_ECHO, HIGH);
    distance = duration * 0.1715;

    // Output the distance
    Serial.print("Distance: ");
    Serial.println(distance);

    // Delay the reading
    delay(200);
}