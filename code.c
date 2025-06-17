/* 
 * Created by Julianne Leblanc-Peltier
 * Created on June 2025
 * This program uses two 7 segment displays (7SD) to count up to 99 continuously in for loop
*/


// first 7 segment display
// unsigned int & LED functions retrieved from https://www.tinkercad.com/things/jHnKkUAsyFg-arduino-7-segment-display
unsigned const int AA = 13;
unsigned const int AB = 12;
unsigned const int AC = 11;
unsigned const int AD = 10;
unsigned const int AE = 9;
unsigned const int AF = 8;
unsigned const int AG = 7;

// second 7 segment display
unsigned const int BA = 6;
unsigned const int BB = 5;
unsigned const int BC = 4;
unsigned const int BD = 3;
unsigned const int BE = 2;
unsigned const int BF = 1;
unsigned const int BG = 0;

// switch var
unsigned const int SWITCH = 15;

// set up
void setup(void)
{
  pinMode(AA, OUTPUT);
  pinMode(AB, OUTPUT);
  pinMode(AC, OUTPUT);
  pinMode(AD, OUTPUT);
  pinMode(AE, OUTPUT);
  pinMode(AF, OUTPUT);
  pinMode(AG, OUTPUT);
  pinMode(BA, OUTPUT);
  pinMode(BB, OUTPUT);
  pinMode(BC, OUTPUT);
  pinMode(BD, OUTPUT);
  pinMode(BE, OUTPUT);
  pinMode(BF, OUTPUT);
  pinMode(BG, OUTPUT);
  pinMode(SWITCH, INPUT);
}

// functions for 1st 7SD

// turns on/off certain LEDs on 1st 7SD to display '0'
void zero(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], LOW);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], HIGH);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '1'
void one(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], LOW);
  digitalWrite(arrayOfPins[1], LOW);
  digitalWrite(arrayOfPins[2], LOW);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], LOW);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '2'
void two(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], LOW);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], HIGH);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], LOW);
}

// turns on/off certain LEDs on 1st 7SD to display '3'
void three(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], LOW);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '4'
void four(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], LOW);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], LOW);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '5'
void five(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], LOW);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '6'
void six(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], LOW);
  digitalWrite(arrayOfPins[4], HIGH);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '7'
void seven(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], LOW);
  digitalWrite(arrayOfPins[1], LOW);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], LOW);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '8'
void eight(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], HIGH);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '9'
void nine(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], HIGH);
  digitalWrite(arrayOfPins[1], HIGH);
  digitalWrite(arrayOfPins[2], HIGH);
  digitalWrite(arrayOfPins[3], HIGH);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], HIGH);
  digitalWrite(arrayOfPins[6], HIGH);
}

// turns all LEDs on 1st 7SD off
void off(int arrayOfPins[]) {
  digitalWrite(arrayOfPins[0], LOW);
  digitalWrite(arrayOfPins[1], LOW);
  digitalWrite(arrayOfPins[2], LOW);
  digitalWrite(arrayOfPins[3], LOW);
  digitalWrite(arrayOfPins[4], LOW);
  digitalWrite(arrayOfPins[5], LOW);
  digitalWrite(arrayOfPins[6], LOW);
}

// gets counter (decasecond OR seconds) and determines state of LED (calling other functions)
void numberDisplayed(int counter, int arrayOfPins[]) {
  if (counter == 0) {
    zero(arrayOfPins);
  } else if (counter == 1) {
    one(arrayOfPins);
  } else if (counter == 2) {
    two(arrayOfPins);
  } else if (counter == 3) {
    three(arrayOfPins);
  } else if (counter == 4) {
    four(arrayOfPins);
  } else if (counter == 5) {
    five(arrayOfPins);
  } else if (counter == 6) {
    six(arrayOfPins);
  } else if (counter == 7) {
    seven(arrayOfPins);
  } else if (counter == 8) {
    eight(arrayOfPins);
  } else if (counter == 9) {
    nine(arrayOfPins);
  }
}

void loop(void) {
  // creates loop counting up using both 7SDs

  // var to read state of switch
  int switchValue = digitalRead(SWITCH);
  
  // declare counters
  int decasecondsCounter;
  int secondsCounter;

  // will start loop/counting only IF the switch is switched to power
  if (switchValue == HIGH) {
    // nested loops, counts + displays seconds first then decaseconds
    for (decasecondsCounter = 0; decasecondsCounter < 10; decasecondsCounter ++) {
      int decasecondsPins[] = {AA, AB, AC, AD, AE, AF, AG};
      switchValue = digitalRead(SWITCH);
      if (switchValue == HIGH) {
        numberDisplayed(decasecondsCounter, decasecondsPins);
        for (secondsCounter = 0; secondsCounter < 10; secondsCounter ++) {
          int secondsPins[] = {BA, BB, BC, BD, BE, BF, BG};
          switchValue = digitalRead(SWITCH);
          if (switchValue == HIGH) {
            numberDisplayed(secondsCounter, secondsPins);
            delay(1000);
          } else {
            // this else statement checks value of switch throughout loop, allows 7SDs to turn off at any point during program
            secondsCounter = 0;
            off(secondsPins);
            break;
          }
        }
      } else {
        // resets all counters and turns decaseconds LEDs off
        decasecondsCounter = 0;
        secondsCounter= 0;
        off(decasecondsPins);
        break;
      }
    }
  }
}
