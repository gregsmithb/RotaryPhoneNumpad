#include "Keyboard.h"

#define counterButton   3
#define openButton      4
byte count = 0;
bool lastIsOpen = false;

void setup()
{
  pinMode(counterButton, INPUT_PULLUP);
  pinMode(openButton, INPUT_PULLUP);
  Keyboard.begin();
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(openButton) == LOW) {
          delay(1);          
    if (digitalRead(counterButton) == HIGH) {
      if (!lastIsOpen) {
        lastIsOpen = true;
        count++;          
          delay(1);                  
      }
    }
    else {
      lastIsOpen = false;
    }
  }
  else if (count > 0) {
    if (count >= 10) {
      count = 0;
    }
    //type the number dialed
    Keyboard.print(String(count));
    count = 0;
  }
}
