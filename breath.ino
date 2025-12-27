void setup() {
  pinMode(6, OUTPUT);
}

void loop() {
 //2.5s دم
  for(int i = 0; i <= 255; i++) {
    analogWrite(6, i);
    delay(10); 
  }
  
  delay(200);

  //3.8s بازدم
  for(int i = 255; i >= 0; i--) {
    analogWrite(6, i);
    delay(15);
  }
  //1s بین دم  / بازدم
  delay(1000); 
}
