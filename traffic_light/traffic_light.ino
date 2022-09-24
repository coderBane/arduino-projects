
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

}

// what the singal was prevoiusly
unsigned char state = 1;

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(2) == LOW) {  //if the button is not pressed:
    if (state & 1){
      digitalWrite(4, HIGH);      // default green light for vehicles
    }
    else{
      // 
      delay(2000);
      digitalWrite(5, HIGH);
      delay(2000);
      digitalWrite(4, HIGH);
      digitalWrite(6, LOW);
      digitalWrite(5, LOW);
      state = 1;
    }
  }

  if (digitalRead(2) == HIGH) { //if the button is pressed:
    if (state & 1){ // light is green
      delay(3000);
      digitalWrite(5, HIGH);
      digitalWrite(4, LOW);
      delay(2000);
      digitalWrite(5, LOW);
      digitalWrite(6, HIGH);
      delay(2000);
    }
    state = 0;
    unsigned char i = 0;
    // toogle pedestrian signal
    while (i < 6){
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(3, LOW);
      delay(500);
      i++;
    }
  }

}
