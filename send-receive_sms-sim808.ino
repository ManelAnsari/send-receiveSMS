void setup() {
  Serial.begin(9600); //initialize Serial(i.e. USB port)
  Serial1.begin(9600); //initialize Serial1
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW);
delay(10000);

Serial1.println("AT+CMGF=1"); // enable SMS
delay(400);
Serial1.println("AT+CMGS=\"+216xxxxxx\""); // send to this number
delay(400);
Serial1.println("Hello World");delay(400);
Serial1.write(0x1A); // end of SMS
digitalWrite(13,HIGH);
}

void loop() {
  //If Serial1 receive data, print out to Serial
  while (Serial.available()) {
    //Serial.write(Serial1.read());
  }
  //If Serial receive data, print out to Serial1
  while (Serial.available()) {
    Serial.write(Serial.read());
  }
  delay(1);  //delay for a short time to
  // avoid unstable USB communication
}
