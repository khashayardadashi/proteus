#define pwm_pin 6 
int pot;
int duty;
void setup(){
  Serial.begin(9600);
  pinMode(pwm_pin , OUTPUT);
}
void loop(){
  pot = analogRead(A1);
  Serial.println(pot);
  duty = map(pot , 0 , 1023 , 0 , 255);
  Serial.println(duty);
  analogWrite(pwm_pin , duty);
}