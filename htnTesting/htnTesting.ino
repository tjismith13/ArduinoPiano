#include "Notes.h"

// Define pin locations

const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = A4;
const int pinF = A2;
const int pinG = A3;
const int pinSharp = A5;
const int octavePin = A1;
const int volPin = A0;
const int soundPin = 6;

// Storage vars

int rawOctave;
int rawVol;
int octave;
boolean isSharp = false;
int startNoteTimeMillis = 0;
int lastItr = -1;
int thisItr = -1;

int output;

//Frequency converter

extern Converter converter;
extern FullNoteWrapper currentNote(Converter::NOT_SELECTED, -1);
extern FullNoteWrapper lastNote(Converter::NOT_SELECTED, -1);

extern FullNoteWrapper Aa(Converter::A, 2);
extern FullNoteWrapper Bb(Converter::B, 3);
extern FullNoteWrapper Cc(Converter::C, 4);
extern FullNoteWrapper Dd(Converter::D, 5);
extern FullNoteWrapper Ee(Converter::E, A4);
extern FullNoteWrapper Ff(Converter::F, A2);
extern FullNoteWrapper Gg(Converter::G, A3);

extern FullNoteWrapper noteList[7] = {Aa, Bb, Cc, Dd, Ee, Ff, Gg};

void setup() {
  //pin setup
  pinMode(pinA, INPUT);
  pinMode(pinB, INPUT);
  pinMode(pinC, INPUT);
  pinMode(pinD, INPUT);
  pinMode(pinE, INPUT);
  pinMode(pinF, INPUT);
  pinMode(pinG, INPUT);
  pinMode(pinSharp, INPUT);
  pinMode(octavePin, INPUT);
  pinMode(volPin, INPUT);
  pinMode(soundPin, OUTPUT);

  Serial.begin(9600);

  

// Used to test note conversion code
//  output = converter.getFrequency(Converter::B5);
//  Serial.println(output);
//
//  output = converter.getFrequency(Converter::B, 5, false);
//  Serial.println(output);
//
//  output = converter.getFrequency(Converter::B2);
//  Serial.println(output);
//
//  output = converter.getFrequency(Converter::C3);
//  Serial.println(output);
//
//  output = converter.getFrequency(Converter::G7);
//  Serial.println(output);
}

void loop() {

//Raw reads for debugging
//  Serial.println("A " + digitalRead(pinA));
//  Serial.println("B " + digitalRead(pinB));
//  Serial.println("C " + digitalRead(pinC));
//  Serial.println("D " + digitalRead(pinD));
//  Serial.println("E " + digitalRead(pinE));
//  Serial.println("F " + digitalRead(pinF));
//  Serial.println("G " + digitalRead(pinG));
//  Serial.println("Sharp " + digitalRead(pinSharp));
//  rawOctave = analogRead(octavePin);
//  Serial.println(rawOctave);

    // monitor current octave
    rawOctave = analogRead(octavePin);
    octave = map(rawOctave, 0, 1023, 8, 0);

   int i = -1;
   for(FullNoteWrapper currentNoteIter : noteList) {
     i++;
     if(digitalRead(currentNoteIter.getPin()) == HIGH) {
      Serial.println("Something pressed");
      thisItr = i;
        if(digitalRead(pinSharp) == HIGH) {
          currentNote.setNoteClass(currentNoteIter.getNoteClass());
          if(currentNote.getNoteClass() != lastNote.getNoteClass()) {
            startNoteTimeMillis = millis();
            if(lastNote.getNoteClass() != Converter::NOT_SELECTED) {
              Serial.println("list shifting");
              for(int j = lastItr; j < 7; j++) {
                if(j == 6) {
                  noteList[j] = lastNote;
                }
                else {
                  noteList[j] = noteList[j + 1];
                }
              }
            }
          }
          else {
            if(millis() - startNoteTimeMillis > 500) {
              Serial.println("list shifting");
              for(int j = lastItr; j < 7; j++) {
                if(j == 6) {
                  noteList[j] = lastNote;
                }
                else {
                  noteList[j] = noteList[j + 1];
                }
            }
          }
          switch (currentNoteIter.getNoteClass()) {
            case Converter::A:
              output = converter.getFrequency(Converter::As, octave);
              break;
            case Converter::C:
              output = converter.getFrequency(Converter::Cs, octave);
              break;
            case Converter::D:
              output = converter.getFrequency(Converter::Ds, octave);
              break;
            case Converter::F:
              output = converter.getFrequency(Converter::Fs, octave);
              break;
            case Converter::G:
              output = converter.getFrequency(Converter::Gs, octave);
              break;
            default:
              output = converter.getFrequency(currentNoteIter.getNoteClass(), octave);
              break;
          }
        }
        }
        else {
            output = converter.getFrequency(currentNoteIter.getNoteClass(), octave);
          }
        tone(soundPin, output);
        break;
     }
     else {
      noTone(soundPin);
     }
   }

   for(FullNoteWrapper toPrint : noteList) {
    Serial.print(toPrint.getNoteClass());
    Serial.print(", ");
    Serial.println();
   }
   Serial.println();
   lastNote.setNoteClass(currentNote.getNoteClass());
   lastItr = thisItr;

// Ugly:
//    //Determining output
//    if(digitalRead(pinA) == HIGH && digitalRead(pinSharp) == HIGH) {
//      output = converter.getFrequency(Converter::As, octave);
//      tone(soundPin, output);
//      currentNote = Converter::As;
//    }
//    else if(digitalRead(pinC) == HIGH && digitalRead(pinSharp) == HIGH) {
//      output = converter.getFrequency(Converter::Cs, octave);
//      tone(soundPin, output);
//      currentNote = Converter::Cs;
//    }
//    else if(digitalRead(pinD) == HIGH && digitalRead(pinSharp) == HIGH) {
//      output = converter.getFrequency(Converter::Ds, octave);
//      tone(soundPin, output);
//      currentNote = Converter::Ds;
//    }
//    else if(digitalRead(pinF) == HIGH && digitalRead(pinSharp) == HIGH) {
//      output = converter.getFrequency(Converter::Fs, octave);
//      tone(soundPin, output);
//      currentNote = Converter::Fs;
//    }
//    else if(digitalRead(pinG) == HIGH && digitalRead(pinSharp) == HIGH) {
//      output = converter.getFrequency(Converter::Gs, octave);
//      tone(soundPin, output);
//      currentNote = Converter::Gs;
//    }
//    else if(digitalRead(pinA) == HIGH) {
//      output = converter.getFrequency(Converter::A, octave);
//      tone(soundPin, output);
//      currentNote = Converter::A;
//    }
//    else if(digitalRead(pinB) == HIGH) {
//      output = converter.getFrequency(Converter::B, octave);
//      tone(soundPin, output);
//      currentNote = Converter::B;
//    }
//    else if(digitalRead(pinC) == HIGH) {
//      output = converter.getFrequency(Converter::C, octave);
//      tone(soundPin, output);
//      currentNote = Converter::C;
//    }
//    else if(digitalRead(pinD) == HIGH) {
//      output = converter.getFrequency(Converter::D, octave);
//      tone(soundPin, output);
//      currentNote = Converter::D;
//    }
//    else if(digitalRead(pinE) == HIGH) {
//      output = converter.getFrequency(Converter::E, octave);
//      tone(soundPin, output);
//      currentNote = Converter::E;
//    }
//    else if(digitalRead(pinF) == HIGH) {
//      output = converter.getFrequency(Converter::F, octave);
//      tone(soundPin, output);
//      currentNote = Converter::F;
//    }
//    else if(digitalRead(pinG) == HIGH) {
//      output = converter.getFrequency(Converter::G, octave);
//      tone(soundPin, output);
//      currentNote = Converter::G;
//    }
//    else {
//      noTone(soundPin);
//      currentNote = Converter::NOT_SELECTED;
//    }
    delay(50);
    
}
