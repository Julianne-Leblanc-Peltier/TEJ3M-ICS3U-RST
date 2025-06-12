/* 
 * Created by Julianne Leblanc-Peltier
 * Created on June 2025
 * This program uses two 7 segment displays (7SD) to count up to 99 continuously in for loop
*/


// first 7 segment display
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
void zero(void) {
  digitalWrite(AA, LOW);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, HIGH);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '1'
void one(void) {
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(AC, LOW);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, LOW);
  digitalWrite(AF, LOW);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '2'
void two(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, HIGH);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, LOW);
}

// turns on/off certain LEDs on 1st 7SD to display '3'
void three(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, LOW);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, LOW);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '4'
void four(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, LOW);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, LOW);
  digitalWrite(AF, LOW);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '5'
void five(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, LOW);
  digitalWrite(AE, LOW);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '6'
void six(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, LOW);
  digitalWrite(AE, HIGH);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '7'
void seven(void) {
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, LOW);
  digitalWrite(AF, LOW);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '8'
void eight(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, HIGH);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns on/off certain LEDs on 1st 7SD to display '9'
void nine(void) {
  digitalWrite(AA, HIGH);
  digitalWrite(AB, HIGH);
  digitalWrite(AC, HIGH);
  digitalWrite(AD, HIGH);
  digitalWrite(AE, LOW);
  digitalWrite(AF, HIGH);
  digitalWrite(AG, HIGH);
}

// turns all LEDs on 1st 7SD off
void off(void) {
  digitalWrite(AA, LOW);
  digitalWrite(AB, LOW);
  digitalWrite(AC, LOW);
  digitalWrite(AD, LOW);
  digitalWrite(AE, LOW);
  digitalWrite(AF, LOW);
  digitalWrite(AG, LOW);
}

void loop(void) {
  // creates loop counting up using both 7SDs

  // var to read state of switch
  int switchValue = digitalRead(SWITCH);
  
  // declare counters
  int secondsCounter;
  int decasecondCounter;
  
  // will start loop/counting only IF the switch is switched to power
  if (switchValue == HIGH) {
    // nested loops, counts + displays seconds first then decaseconds
    for (decasecondCounter = 0; decasecondCounter < 10; decasecondCounter ++) {
      switchValue = digitalRead(SWITCH);
      if (switchValue == HIGH) {
        if (decasecondCounter == 0) {
          a_zero();
        } else if (decasecondCounter == 1) {
          a_one();
        } else if (decasecondCounter == 2) {
          a_two();
        } else if (decasecondCounter == 3) {
          a_three();
        } else if (decasecondCounter == 4) {
          a_four();
        } else if (decasecondCounter == 5) {
          a_five();
        } else if (decasecondCounter == 6) {
          a_six();
        } else if (decasecondCounter == 7) {
          a_seven();
        } else if (decasecondCounter == 8) {
          a_eight();
        } else if (decasecondCounter == 9) {
          a_nine();
        }
        for (secondsCounter = 0; secondsCounter < 10; secondsCounter ++) {
          switchValue = digitalRead(SWITCH);
          if (switchValue == HIGH) {
            if (secondsCounter == 0) {
                b_zero();
            } else if (secondsCounter == 1) {
                b_one();
            } else if (secondsCounter == 2) {
                b_two();
            } else if (secondsCounter == 3) {
                b_three();
            } else if (secondsCounter == 4) {
                b_four();
            } else if (secondsCounter == 5) {
                b_five();
            } else if (secondsCounter == 6) {
                b_six();
            } else if (secondsCounter == 7) {
                b_seven();
            } else if (secondsCounter == 8) {
                b_eight();
            } else if (secondsCounter == 9) {
                b_nine();
            }
            delay(1000);
          } else {
            // this else statement checks value of switch throughout loop, allows 7SDs to turn off at any point during program
            secondsCounter = 0;
            a_off();
            b_off();
            break;
          }
        }
      } else {
        decasecondCounter = 0;
        secondsCounter = 0;
        a_off();
        b_off();
        break;
      }
    }
  }
}
