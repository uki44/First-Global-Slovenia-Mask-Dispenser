#include<Servo.h>

const int trigPin = 6;
const int echoPin = 7;

long duration;
int distance;
Servo servo;
Servo servo2;
int magic = 0;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  servo.attach(9);
  servo2.attach(10);
}
void loop() {

  magic += Serial.parseInt();

  if(magic != 0 && digitalRead(4)){
    servo2.write(100);
    digitalWrite(13,HIGH);
    delay(500);
    digitalWrite(13,LOW);
    delay(500);
    servo2.write(160);
    delay(3000);
    servo2.write(90);
    while(!digitalRead(4)){
        //čičipačaki da en vzame vn kuferto
        //Serial.println(magic);
        
     }
    while(Serial.available() > 0){
      Serial.read();
      }
      delay(5000); //počivi da ti ne zmanka robe
      magic = 0;
    }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  if (distance <= 20) {
    servo.write(115);
    delay(200);
    servo.write(80);
    delay(250);
    servo.write(115);
    delay(200);
    servo.write(85);
    delay(2000);

  }
  else {
    servo.write(85);

  }
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("Magic: ");
  Serial.println(magic);

}
