#define DIG4 10
#define DIG3 13
#define DIG2 12
#define DIG1 8

#define DOT 11

#define SEGA 6
#define SEGB 7
#define SEGC 5
#define SEGD 4
#define SEGE 3
#define SEGF 2
#define SEGG 9



float tempC;
float tempF;

int reading;
float referenceVoltage;

int tempPin = 0; //Analog pin connected to LM35

void showDigit(int digit, int dot) {
  if(digit==0) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, HIGH);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
  } else if (digit==1) {
    digitalWrite(SEGA, HIGH);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, HIGH);
    digitalWrite(SEGG, HIGH);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, HIGH);
  } else if (digit==2) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, HIGH);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, HIGH);
    digitalWrite(SEGD, LOW);
  } else if (digit==3) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, HIGH);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
  } else if (digit==4) {
    digitalWrite(SEGA, HIGH);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, HIGH);
  } else if (digit==5) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, HIGH);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
 } else if (digit==6) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, HIGH);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
  } else if (digit==7) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, HIGH);
    digitalWrite(SEGG, HIGH);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, HIGH);
  } else if (digit==8) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW);
  } else if (digit==9) {
    digitalWrite(SEGA, LOW);
    digitalWrite(SEGB, LOW);
    digitalWrite(SEGE, HIGH);
    digitalWrite(SEGF, LOW);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, LOW);
    digitalWrite(SEGD, LOW); 
  } else if (digit == 0xC) {
    digitalWrite(SEGA, HIGH);
    digitalWrite(SEGB, HIGH);
    digitalWrite(SEGE, LOW);
    digitalWrite(SEGF, HIGH);
    digitalWrite(SEGG, LOW);
    digitalWrite(SEGC, HIGH);
    digitalWrite(SEGD, LOW); 
  
  }

  if(dot==0) {
    digitalWrite(DOT, HIGH);
  } else {
    digitalWrite(DOT, LOW);
  }
  
}


void setup()
{
  
 Serial.begin(9600);

 // Set Analog reference to 1.1V this gives more accuracy since the sensor will output 0-1 V
 // This only available on ATmega168 or ATmega328)
 // For more information see: http://arduino.cc/en/Reference/AnalogReference
 analogReference(INTERNAL);
 referenceVoltage = 1.1; //Set to 5, 3.3, 2.56 or 1.1 depending on analogReference Setting

 pinMode(DIG1, OUTPUT);
 pinMode(DOT, OUTPUT);
 pinMode(DIG2, OUTPUT); 
 pinMode(DIG3, OUTPUT); 
 pinMode(DIG4, OUTPUT); 
 pinMode(SEGA, OUTPUT); 
 pinMode(SEGB, OUTPUT); 
 pinMode(SEGC, OUTPUT); 
 pinMode(SEGD, OUTPUT); 
 pinMode(SEGE, OUTPUT); 
 pinMode(SEGF, OUTPUT); 
 pinMode(SEGG, OUTPUT); 
}

int i = 0;

void loop()
{

/*
digitalWrite(DOT, LOW);
digitalWrite(SEGA, LOW);
digitalWrite(SEGB, LOW);
digitalWrite(SEGE, LOW);
digitalWrite(SEGF, HIGH);
digitalWrite(SEGG, LOW);
digitalWrite(SEGC, HIGH);
digitalWrite(SEGD, LOW);*/



showDigit( ((int)tempC)/10, 0);
digitalWrite(DIG1, HIGH);
digitalWrite(DIG2, LOW);
digitalWrite(DIG3, LOW);
digitalWrite(DIG4, LOW);  
delay(4);
showDigit( (int)tempC - 10*((int)tempC/10), 1);
//Serial.println((int)tempC - 10*((int)tempC/10));
digitalWrite(DIG1, LOW);
digitalWrite(DIG2, HIGH);
digitalWrite(DIG3, LOW);
digitalWrite(DIG4, LOW);  
delay(4);
showDigit( (tempC- (int)tempC)*10, 0);
digitalWrite(DIG1, LOW);
digitalWrite(DIG2, LOW);
digitalWrite(DIG3, HIGH);
digitalWrite(DIG4, LOW);  
delay(4);
showDigit( 0xC, 0);
digitalWrite(DIG1, LOW);
digitalWrite(DIG2, LOW);
digitalWrite(DIG3, LOW);
digitalWrite(DIG4, HIGH);  
delay(4);
/*
if(i%4==0) {
  digitalWrite(DIG1, HIGH);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, LOW);  
} else if(i%4==1) {
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, HIGH);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, LOW);    
} else if(i%4==2) {
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, HIGH);
  digitalWrite(DIG4, LOW);    
} else {
  digitalWrite(DIG1, LOW);
  digitalWrite(DIG2, LOW);
  digitalWrite(DIG3, LOW);
  digitalWrite(DIG4, HIGH);  
}
*/
  i++;
  
  

  reading += analogRead(tempPin); 
  
  delay(5);
  if(i==80) { //400 MS
    
    
    
    // A lot of examples divide the sensor reading by 1024. This is incorrect and should be 1023. There are 1024 values including 0 so this should be 1023.
    tempC =  (referenceVoltage * reading * 10) / 1023 / 8; 
    
    Serial.print(tempC, 1); //Print one decimal, it's not accurate enough for two
    Serial.println(" C");

    reading = 0;
    i=0;
  }
  
}
