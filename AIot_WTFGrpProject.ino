
const int buttonPin = 13;
uint btnCount = 0;
bool onceFlag = false;
UART mySerial(A6, A7, NC, NC);


void setup() {
  delay(200);
  Serial.begin(9600);
  while (!Serial);
  pinMode(LEDR, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  digitalWrite(LEDR, HIGH);
  attachInterrupt(digitalPinToInterrupt(buttonPin), btnCount, FALLING);
  onceFlag = false;
  mySerial.begin(9600); 


}

void loop() {
  if (onceFlag) {
    digitalWrite(LEDR, LOW);

    // put your main code here, to run repeatedly:
  if (APDS.proximityAvailable()) {
    // read the proximity
    // - 0   => close
    // - 255 => far
    // - -1  => error
    int proximity = APDS.readProximity();
    Serial.println(proximity);
    digitalWrite(LEDR, HIGH);


    if(proximity < 10)
    {
      int myNum = random(0,100);
      if(myNum > 50)
      {
        myservo.write(90);
        delay(2000);
        myservo.write(0);
        mySerial.println(myNum);
      }

    }  
  }
}
}

void button_interrupt() {
  onceFlag = true;
}