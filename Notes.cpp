#include "Arduino.h"
#include "Notes.h"

Converter::Converter() {
    Serial.println("Converter Active");
}

int Converter::getFrequency(Note note) {
    return 440 * pow(pow(2, 1/12), note);
}