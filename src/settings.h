

// -------------- Parameter setup -------------------------

#define   baudRate      38400  // baud rate for serial communication
#define   motorMaxSpeed 1000.0  //
#define   motoAccSpeed  1000    //
#define   motorSpeed    1000
#define   tableturn     1
#define   motorEndPosition  tableturn *(6*4096)   // calculated position change based on turns

// gear has transmission rate of 6:1, one motor turn requires according definition 4096 steps



// -------------- Hardware setup --------------------------

/* pinout on board tr044

  Motor In1:  C.1   A1  SV1-9
        In2:  C.0   A0  SV1-10
        In3:  C.3   A3  SV1-11
        In4:  C.2   A2  SV1-12
  LED:        B.2   D10  SV1-4
  Radar:      D.2   D2  SV1-13
  Hall:       B.5   D13 SV1-7
*/


// Motor pin definitions
#define mtrPin1  A1     // IN1 on the ULN2003 driver 1
#define mtrPin2  A0     // IN2 on the ULN2003 driver 1
#define mtrPin3  A3     // IN3 on the ULN2003 driver 1
#define mtrPin4  A2     // IN4 on the ULN2003 driver 1

// pin assignment
#define pinRadar  2    //radar sensor
#define pinLED    10   //LED
#define pinHall   13    // Hallsensor -> Signal=0 means Magnet is close

// stepper libraries setting
#define HALFSTEP 8  //Half-step mode (8 step control signal sequence)



/* 
 * Info files 
 *  http://cyaninfinite.com/tutorials/moving-the-28byj-48-stepper-motor/
 * http://www.airspayce.com/mikem/arduino/AccelStepper/classAccelStepper.html#abee8d466229b87accba33d6ec929c18f

 * 
 */
  
