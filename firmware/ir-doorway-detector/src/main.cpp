#include <Arduino.h>

const int irPin = 4;
const unsigned long TIEMPO_ESTADO_MS = 10000;  // 10 segundos

void setup() {
    pinMode(irPin, OUTPUT);
}

void loop() {
    // Salida encendida durante 10 segundos
    digitalWrite(irPin, HIGH);
    delay(TIEMPO_ESTADO_MS);

    // Salida apagada durante 10 segundos
    digitalWrite(irPin, LOW);
    delay(TIEMPO_ESTADO_MS);
}
