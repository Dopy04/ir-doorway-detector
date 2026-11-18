#include <Arduino.h>

// Estado fijo para poder medir el circuito con el multímetro.
const int irPin = 4;

void setup() {
    pinMode(irPin, OUTPUT);
    digitalWrite(irPin, HIGH);
}

void loop() {
}
