#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 11, 10, 7, 9, 8);


int reply;
char *notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
int i = random(11); //random array index for notes
  int o = random(7); //random array index for octaves


void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(8,0);
  
  lcd.print(notes[i]);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 
  delay(1500);
  
  lcd.setCursor(9,0);
  lcd.print(" ");
  lcd.setCursor(8,0);
  int i = random(11);
  lcd.print(notes[i]);
  
  lcd.setCursor(4,1);
  int o = random(7);
  lcd.print("Octave:");
  lcd.setCursor(13,1);
  lcd.print(o);
  
  
 
  
  
}
