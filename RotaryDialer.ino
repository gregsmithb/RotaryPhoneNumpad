#include "Keyboard.h"

//pin3 blue wire from dialer (pulses for each number)
#define counterButton   3
//pin4 white wire from dialer (high while dialing number)
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
  //check if dialing has started
  if (digitalRead(openButton) == LOW) {
    delay(1);          
    //count each pulse only once
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
  //dialing is over, if we were counting then send keystroke
  else if (count > 0) {
    //zero is actually 10, check for it here
    if (count >= 10) {
      count = 0;
    }
    //type the number dialed

    //added switch case to make it easier to do different keystrokes for each number dialed
    switch (count) {
      case 1:
       Keyboard.print(String(count));
        break;
      case 2:        
       Keyboard.print(String(count));
        break;
      case 3:
       Keyboard.print(String(count));
        break;
      case 4:
       Keyboard.print(String(count));
        break;
      case 5:
       Keyboard.print(String(count));
        break;
      case 6:
       Keyboard.print(String(count));
        break;
      case 7:
        Keyboard.print(String(count));
        break;
      case 8:
        Keyboard.print(String(count));
        break;
      case 9:
        Keyboard.print(String(count));
        break;
      case 0:
        Keyboard.print(String(count));
        break;
      default:
        Keyboard.print(String(count));
        break;
    }
    

    count = 0;
  }
}
