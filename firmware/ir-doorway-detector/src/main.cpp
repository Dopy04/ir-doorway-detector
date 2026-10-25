
#include <Arduino.h>

const int irEmisor = 4;
const int irReceptor = 5;

int medirReceptor() {
    long suma = 0;

    for (int i = 0; i < 10; i++) {
        suma += analogRead(irReceptor);
        delay(10);
    }

    return suma / 10;
}

void setup() {
    Serial.begin(115200);

    pinMode(irEmisor, OUTPUT);
    digitalWrite(irEmisor, LOW);

    analogReadResolution(12);
}

void loop() {
    digitalWrite(irEmisor, LOW);
    delay(200);
    int sinIR = medirReceptor();

    digitalWrite(irEmisor, HIGH);
    delay(200);
    int conIR = medirReceptor();

    int diferencia = sinIR - conIR;

    Serial.print("Sin IR: ");
    Serial.print(sinIR);

    Serial.print(" | Con IR: ");
    Serial.print(conIR);

    Serial.print(" | Diferencia: ");
    Serial.println(diferencia);

    delay(1000);
}
