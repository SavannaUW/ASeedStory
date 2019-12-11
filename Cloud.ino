int cloud = A2;
int snow = 6;

void setup() {
  pinMode(cloud, INPUT_PULLUP); //wasn't sure about the resistance
  pinMode(snow, OUTPUT);
}

void loop() {
  int sensorValue = analogRead(cloud);
  delay(1);        // delay in between reads for stability
  int scale = map(sensorValue, 1023, 0, 0, 255); //map squishedness to light
  //Only light up if squished above a certain amount
  if(sensorValue < 1000) {
    analogWrite(snow, scale);
  } else {
    analogWrite(snow, 0);  
  }
}
