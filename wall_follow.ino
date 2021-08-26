#include <Servo.h>
#include <Ultrasonic.h>
#include <Motors.h>

unsigned long last_looked = 0;

Servo servo;
Ultrasonic ultrasonic (A5, A4);
Motors motors;

void setup() {
  servo.attach(3);
  servo.write(15);
  motors.go(150, 150);
}

void loop() {
  if (millis() > last_looked + 1500) {
    motors.stop();
    servo.write(90);
    delay(200);
    if (ultrasonic.distance() < 30) {
      motors.go(-255,255);
      delay(250);
      motors.go(0,0);
    }
    last_looked = millis();
    servo.write(15);
  }
  int dist = ultrasonic.distance();
  if (dist < 10) {
    motors.go(50, 255);
  } else if (dist > 20) {
    motors.go(255, 50);
  } else {
    motors.go(150, 150);
  }
}