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

int output;

//Frequency converter

extern Converter converter;

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

// Used to 
//  output = converter.getFrequency(Converter::A5);
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
//  Serial.println("A " + digitalRead(pinA));
//  Serial.println("B " + digitalRead(pinB));
//  Serial.println("C " + digitalRead(pinC));
//  Serial.println("D " + digitalRead(pinD));
//  Serial.println("E " + digitalRead(pinE));
//  Serial.println("F " + digitalRead(pinF));
//  Serial.println("G " + digitalRead(pinG));
//  Serial.println("Sharp " + digitalRead(pinSharp));
 // rawOctave = analogRead(octavePin);
 // Serial.println(rawOctave);
    
    
    int output = converter.getFrequency(Converter::A4);
    tone(soundPin, output);
    Serial.println(output);
    delay(2000);

    noTone(soundPin);
    delay(2000);

    int output2 = converter.getFrequency(Converter::C6);
    tone(soundPin, output2);
    Serial.println(output2);
    delay(2000);
}
