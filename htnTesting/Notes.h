#ifndef Notes_h
#define Notes_h

#include "Arduino.h"

class Converter {
    public:
        Converter();
        enum Note {
            C0 = -57,
            C0s = -56,
            D0 = -55,
            D0s = -54,
            E0 = -53,
            F0 = -52,
            F0s = -51,
            G0 = -50,
            G0s = -49,
            A0 = -48,
            A0s = -47,
            BZero = -46,
            C1 = -45,
            C1s = -44,
            D1 = -43,
            D1s = -42,
            E1 = -41,
            F1 = -40,
            F1s = -39,
            G1 = -38,
            G1s = -37,
            A1 = -36,
            A1s = -35,
            BOne = -34,
            C2 = -33,
            C2s = -32,
            D2 = -31,
            D2s = -30,
            E2 = -29,
            F2 = -28,
            F2s = -27,
            G2 = -26,
            G2s = -25,
            A2 = -24,
            A2s = -23,
            B2 = -22,
            C3 = -21,
            C3s = -20,
            D3 = -19,
            D3s = -18,
            E3 = -17,
            F3 = -16,
            F3s = -15,
            G3 = -14,
            G3s = -13,
            A3 = -12,
            A3s = -11,
            B3 = -10,
            C4 = -9,
            C4s = -8,
            D4 = -7,
            D4s = -6,
            E4 = -5,
            F4 = -4,
            F4s = -3,
            G4 = -2,
            G4s = -1,
            A4 = 0,
            A4s = 1,
            B4 = 2,
            C5 = 3,
            C5s = 4,
            D5 = 5,
            D5s = 6,
            E5 = 7,
            F5 = 8,
            F5s = 9,
            G5 = 10,
            G5s = 11,
            A5 = 12,
            A5s = 13,
            B5 = 14,
            C6 = 15,
            C6s = 16,
            D6 = 17,
            D6s = 18,
            E6 = 19,
            F6 = 20,
            F6s = 21,
            G6 = 22,
            G6s = 23,
            A6 = 24,
            A6s = 25,
            B6 = 26,
            C7 = 27,
            C7s = 28,
            D7 = 29,
            D7s = 30,
            E7 = 31,
            F7 = 32,
            F7s = 33,
            G7 = 34,
            G7s = 35,
            A7 = 36,
            A7s = 37,
            B7 = 38,
            C8 = 39,
            C8s = 40,
            D8 = 41,
            D8s = 42,
            E8 = 43,
            F8 = 44,
            F8s = 45,
            G8 = 46,
            G8s = 47,
            A8 = 48,
            A8s = 49,
            B8 = 50
        };
        enum NoteClass {
          A,
          B,
          C,
          D,
          E,
          F,
          G,
          As,
          Cs,
          Ds,
          Fs,
          Gs,
          NOT_SELECTED
        };
        int getFrequency(Note note);
        int getFrequency(NoteClass noteClass, int octave);
};

class FullNoteWrapper {
  public:
    FullNoteWrapper(Converter::NoteClass noteClass, int pin);
    Converter::NoteClass getNoteClass();
    void setNoteClass(Converter::NoteClass noteClass);
    void setPin(int pin);
    int getPin();

  private:
    Converter::NoteClass note;
    int pinNum;
};
#endif
