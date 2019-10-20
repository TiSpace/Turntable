
#include "settings.h"
#include <AccelStepper.h> //http://www.airspayce.com/mikem/arduino/AccelStepper/index.html



AccelStepper stepper1(HALFSTEP, mtrPin1, mtrPin3, mtrPin2, mtrPin4);

byte readyToGo = 0;

int statusRadar = 0;
int statusHall  = 0;

void setup() {
  Serial.begin(baudRate);
  delay(1000);
  Serial.print("Stepper V1 ");
  Serial.println(__TIME__);

  // Port declaration
  pinMode(pinRadar, INPUT);
  pinMode(pinHall, INPUT);
  digitalWrite(pinHall, HIGH); // turn on PullUp resistance
  pinMode(pinLED, OUTPUT);
  digitalWrite(pinLED, LOW);

  //Motor setup
  stepper1.setMaxSpeed(motorMaxSpeed);
  stepper1.setAcceleration(motoAccSpeed);  //Make the acc quick
  stepper1.setSpeed(motorSpeed);


  // find initial position
  while (digitalRead(pinHall) == 1) {
    stepper1.runSpeed();
  }
  stepper1.setCurrentPosition(0);  // set HomePosition as new reference

  stepper1.moveTo(motorEndPosition); // define target position initially
}

void loop() {
  // if end position has been reached, make a turn into the opposite direction to other end point
  // end point is either <0> or <motorEndPosition>
  if (stepper1.distanceToGo() == 0) {
    readyToGo = 0;
    if (stepper1.currentPosition() > 0) {
      stepper1.moveTo(0);
    } else {
      stepper1.moveTo(motorEndPosition);
    }

  }


// only turn if radar detects something
if (digitalRead(pinRadar) != 0) {
  readyToGo = 1;
}


//enable turning is allowed
if (readyToGo != 0) {
  stepper1.run();  //Start
}


// simply display the status of the Radar sensor
digitalWrite(pinLED, !digitalRead(pinRadar));


}
