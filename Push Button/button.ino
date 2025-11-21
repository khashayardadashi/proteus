int button = 7;
int led = 13;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  digitalWrite(led,LOW);
}

void loop() {
  int r = digitalRead(button); // HIGH when not pressed, LOW when pressed

  if (r == LOW) {       // button pressed
    digitalWrite(led, HIGH);
  } else {                // button released
    digitalWrite(led, LOW);
  }

  delay(1000);
   }