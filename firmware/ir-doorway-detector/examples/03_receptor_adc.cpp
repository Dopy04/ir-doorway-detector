#include <Arduino.h>

const int irEmisor = 4;
const int irReceptor = 5;

void setup() {
    Serial.begin(115200);
    pinMode(irEmisor, OUTPUT);
    digitalWrite(irEmisor, HIGH);
    analogReadResolution(12);
}

void loop() {
    int lectura = analogRead(irReceptor);
    Serial.print("ADC receptor: ");
    Serial.println(lectura);
    delay(500);
}
