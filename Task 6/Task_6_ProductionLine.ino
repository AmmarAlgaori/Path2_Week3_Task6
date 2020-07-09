#include <Servo.h>

#define IR1 4 //for the 10cm boxes
#define IR2 5 //for the 20cm boxes
#define IR3 6 //for the 30cm boxes

Servo servo;

void setup() {
  //set the mode of the pins
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  //set the pins of the servo motors
  servo.attach(3);
  //initialize the angle of the servo motors
  servo.write(0);
}

void loop() {
  //if the first and second and third IR sensors detect a box the servo motor will go to position three
  if (digitalRead(IR1) == 1 && digitalRead(IR2) == 1 && digitalRead(IR3) == 1){
    servo.write(180);
  }
  //if the first and second IR sensors are the ones that detect a box the servo motor will go to position two
  else if (digitalRead(IR1) == 1 && digitalRead(IR2) == 1){
    servo.write(93); // this will make the servo motor in proteus go to 90 degrees  
  }
  //if the first IR sensor is the only one that detect a box the servo motor will go to position one
  else if (digitalRead(IR1) == 1){
    servo.write(0);    
  }
}
