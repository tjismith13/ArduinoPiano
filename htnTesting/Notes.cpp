#include "Arduino.h"
#include "Notes.h"

int Converter::getFrequency(Note note) {
    double root = 1.0 / 12.0;
    double a = pow(2, root);
    return 440 * pow(a, note);
}
int Converter::getFrequency(NoteClass noteClass, int octave, boolean isSharp) {
    double root = 1.0 / 12.0;
    double a = pow(2, root);
    int octDiff = octave - 4;
    int note;
    switch(noteClass) {
      case A:
        note = 0 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case B:
        note = 2 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case C:
        note = -9 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case D:
        note = -7 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case E:
        note = -5 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case F:
        note = -4 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case G:
        note = -2 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case As:
        note = 1 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case Cs:
        note = -8 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case Ds:
        note = -6 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case Fs:
        note = -3 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
      case Gs:
        note = -1 + (octDiff * 12);
        return 440 * pow(a, note);
        break;
    }
}
