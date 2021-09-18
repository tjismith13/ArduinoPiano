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
    rawOctave = analogRead(octavePin);
    //Serial.println(rawOctave);

    tone(soundPin, 500);
    rawVol = analogRead(volPin);
    Serial.println(rawVol);
    delay(500);
}
