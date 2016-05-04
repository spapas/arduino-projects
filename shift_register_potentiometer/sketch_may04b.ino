//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;

int potPin = 2;

//holders for infromation you're going to pass to shifting function
int  data;
int dataArray[17];

void setup() {
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);

  dataArray[0] = 1;
  dataArray[1] = 3;
  dataArray[2] = 6;
  dataArray[3] = 12;
  dataArray[4] = 24;
  dataArray[5] = 48;
  dataArray[6] = 96;
  dataArray[7] = 192;
  dataArray[8] = 128;
  dataArray[9] = 192;
  dataArray[10] = 96;
  dataArray[11] = 48;
  dataArray[12] = 24;
  dataArray[13] = 12;
  dataArray[14] = 6;
  dataArray[15] = 3;
  dataArray[16] = 1;
  
  //function that blinks all the LEDs
  //gets passed the number of blinks and the pause time
  blinkAll_2Bytes(5,100); 
}

void loop() {
  
  for (int j = 0; j < 17; j++) {
    int val = analogRead(potPin);
    Serial.println(val);
    
    data = dataArray[j];

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, data);  

    digitalWrite(latchPin, HIGH);
    delay(val/10);
  }
}




//blinks the whole register based on the number of times you want to 
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.

void blinkAll_2Bytes(int n, int d) {
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, LSBFIRST,0);
  shiftOut(dataPin, clockPin, LSBFIRST,0);
  digitalWrite(latchPin, 1);
  delay(100);
  for (int x = 0; x < n; x++) {
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, LSBFIRST,255);
    shiftOut(dataPin, clockPin, LSBFIRST,255);
    digitalWrite(latchPin, 1);
    delay(d);
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, LSBFIRST,0);
    shiftOut(dataPin, clockPin,LSBFIRST, 0);
    digitalWrite(latchPin, 1);
    delay(d);
  }
}