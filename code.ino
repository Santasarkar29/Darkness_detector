int lightpin = 0; 
int datapin = 4;
int clockpin = 6;
int latchpin = 5;

int leds = 0;



void setup() {
  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT); 
  pinMode(latchpin, OUTPUT);
}

void loop() {
  int reading = 1023 - analogRead(lightpin);
  int numLEDlit = reading / 57;
  if (numLEDlit > 8)
    numLEDlit = 8;

  leds = 0;

  for (int i = 0; i < numLEDlit; i++) {
    leds = leds + (1 << i);
  }
  updateshiftRegister();
  
}

void updateshiftRegister() {
  digitalWrite(latchpin, LOW);
  shiftOut(datapin, clockpin, LSBFIRST, leds); 
  digitalWrite(latchpin, HIGH); 
}
