void setup() {
  // put your setup code here, to run once:

  //declare PWM pins as output
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(9600);
}

int fadeAmount = 0; // value read from the potentiometer.
int brightness = 0; // controls the brightness of the LEDs

void loop() {
  // put your main code here, to run repeatedly:

  // read value from potentiometer
  fadeAmount = analogRead(A0);

  /*
  PWM pins have an 8-bit resolution (0 - 255) 
  analogRead return a value range (0 - 1023)
  */
  brightness = fadeAmount / 4; // scale value dividing by 4

  // at full brightness?
  if (brightness > 220) {
    // all off
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    delay(500); // half a second delay
    // all on
    digitalWrite(11, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(9, HIGH);
  }
  else {
    analogWrite(11, brightness);
    analogWrite(10, brightness);
    analogWrite(9, brightness);
  }

  Serial.print(fadeAmount);
  Serial.print(" : ");
  Serial.println(brightness);
}
