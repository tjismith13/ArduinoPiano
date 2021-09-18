#include "Arduino.h"
#include "Notes.h"

int Converter::getFrequency(Note note) {
    double root = 1.0 / 12.0;
    double a = pow(2, root);
    return 440 * pow(a, note);
}
