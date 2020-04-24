int duurtijd;
int afstand;
int echo = 11;
int trigger = 12;

int latchPin = 5;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 6; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 4;  // Data pin of 74HC595 is connected to Digital pin 4

int value = 0;

void setup() {
    //set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //clear shift register
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, distanceToByte(readDistance()));

  //put latchpin on HIGH
  digitalWrite(latchPin, HIGH);
  delay(100);
}

int readDistance(){
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  duurtijd = pulseIn(echo, HIGH);
  afstand = duurtijd / 29;
  afstand = afstand / 2;
  Serial.print(afstand);
  Serial.println("cm");
  return afstand;
}

int distanceToByte(int afstand){

  if(afstand <= 1){
    return 1;
  }
  else if(afstand <= 4){
    return 2;
  }
  else if(afstand <= 8){
    return 4;
  }
  else if(afstand <= 10){
    return 8;
  }
   else if(afstand <= 13){
    return 16;
  }
   else if(afstand <= 16){
    return 32;
  }
   else if(afstand <= 20){
    return 64;
  }
   else if(afstand >= 25){
    return 128;
  }
}
