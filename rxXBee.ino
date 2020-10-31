//Rx

int ptsCheck = 0;
int homePts;
int awayPts;
int homeSpk = 13;
int awaySpk = 12;

void setup() 
{
  pinMode(homeSpk, OUTPUT);
  pinMode(awaySpk, OUTPUT);
  Serial.begin(9600);
  Serial.print("Basketball Counter Using XBee:");
  Serial.println();  
}

void loop() 
{
  if(Serial.available())
  {
    char point = Serial.read(); 
    if(point == '1'){ptsCheck = 1;  
    Serial.println("2 pts to Home Team!"); homePts = homePts + 2; Serial.print("Home team : "); Serial.println(homePts); Serial.print("Away team : "); Serial.println(awayPts); digitalWrite(homeSpk, HIGH); delay(3000); digitalWrite(homeSpk, LOW); digitalWrite(awaySpk, LOW);}

    if(point == '3'){ptsCheck = 1; 
    Serial.println("2 pts to Away Team!"); awayPts = awayPts + 2; Serial.print("Home team : "); Serial.println(homePts); Serial.print("Away team : "); Serial.println(awayPts); digitalWrite(homeSpk, LOW); digitalWrite(awaySpk, HIGH); delay(3000); digitalWrite(awaySpk, LOW);} 
    
    if(point == '4'){ptsCheck = 1; 
    Serial.println("3 pts to Home Team!"); homePts = homePts + 3; Serial.print("Home team : "); Serial.println(homePts); Serial.print("Away team : "); Serial.println(awayPts); digitalWrite(homeSpk, HIGH); delay(3000); digitalWrite(homeSpk, LOW); digitalWrite(awaySpk, LOW);}

    if(point == '6'){ptsCheck = 1;  
    Serial.println("3 pts to Away Team!"); awayPts = awayPts + 3; Serial.print("Home team : "); Serial.println(homePts); Serial.print("Home team : "); Serial.println(awayPts); digitalWrite(homeSpk, LOW); digitalWrite(awaySpk, HIGH); delay(3000); digitalWrite(awaySpk, LOW);}
    
    if(ptsCheck == 0){Serial.println("Try pressing another key");}
    Serial.println();
    ptsCheck = 0;
  }
}
