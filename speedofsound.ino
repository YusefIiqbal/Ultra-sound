int trigpin=10;
int ecopin=9;
int utime;
float sspeed;
float target=5.0; // keeping it at 5 inches away from the target
void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(ecopin,INPUT);
}

void loop() {
  digitalWrite(trigpin,LOW);
  delayMicroseconds(200);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin,LOW);

  utime= pulseIn(ecopin,HIGH); // Use to recieve the ultrasouncd wave  
  sspeed= 2*target/utime;  // Multiplying it with 2 because the waves is going and bouncing back from the target,
  sspeed= sspeed/63360*1000000*3600;  // calculation for converting inches into miles. Since 1 mile = 63360 inches
  Serial.print("Speed of the sound is ");
  Serial.println(sspeed);
  delay(3000);
}
