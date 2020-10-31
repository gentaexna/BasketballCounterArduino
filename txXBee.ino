//Tx

#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'7','8','9', '/'},
  {'4','5','6','x'},
  {'1','2','3','-'},
  {'*','0','#','+'}
};
byte rowPins[ROWS] = {13, 12, 11, 10}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int xB = 0;

void setup() 
{
  Serial.begin(9600);  
  Serial.println("Press 1 for 2 pts to Home Team"); 
  Serial.println("Press 4 for 3 pts to Home Team");
  Serial.println("Press 3 for 2 pts to Away Team");
  Serial.println("Press 6 for 3 pts to Away Team");
}
void loop() 
{
  char pts = keypad.getKey();
    if (pts)
  {
    if(pts == '1'){xB = 1; Serial.println("2pts to Home Team");}
    if(pts == '3'){xB = 1; Serial.println("2pts to Away Team");}
    if(pts == '4'){xB = 1; Serial.println("3pts to Home Team");}
    if(pts == '6'){xB = 1; Serial.println("3pts to Away Team");}
    if(xB == 0){Serial.println(pts);}
    xB = 0; 
  }
}
