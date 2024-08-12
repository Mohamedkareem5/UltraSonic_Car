#define in1 10
#define in2 9
#define in3 8
#define in4 7
#define speedL 11
#define speedR 6
#define trig 2
#define echo 3
long duration , distance;
void setup() {
  pinMode(in1 , OUTPUT);
  pinMode(in2 , OUTPUT);
  pinMode(in3 , OUTPUT);
  pinMode(in4 , OUTPUT);
  pinMode(speedL , OUTPUT);
  pinMode(speedR , OUTPUT);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
}

void loop() {
  ultrasonic();
  if (distance < 20){
    Stop();
    delay(1000);
    back();
    delay(1200);
    left();
    delay(1300);
    
  }
  else{
    forward();
  }
}



void ultrasonic() {
  digitalWrite(trig , LOW);
  delayMicroseconds(2);
  digitalWrite(trig , HIGH);
  delayMicroseconds(10);
  digitalWrite(trig , LOW);
  duration = pulseIn(echo , HIGH);
  distance = duration * 0.0343 /2;
}

void forward(){
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(speedL , 120);
  analogWrite(speedR , 120);
}
void back(){
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
  analogWrite(speedL , 120);
  analogWrite(speedR , 120);
}
void left(){
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
  analogWrite(speedL , 120);
  analogWrite(speedR , 120);
}
void Stop(){
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , HIGH);
  analogWrite(speedL , 0);
  analogWrite(speedR , 0);
}