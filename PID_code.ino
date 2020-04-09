    %#include <PID_v1.h>
#include <CurieIMU.h>
#define PIN_IMU 0
#define PIN_OUTPUT 3

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
 
//Specify the links and initial tuning parameters
double Kp=2 ; // kp =0.6 *ku;
double Ki=1 ; 
double Kd=3;
// ki = 2kp/Tu ; 
// kd = kp *Tu / 8;

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);


void setup()
{
 //initialize the variables we're linked to
 Input = analogRead(PIN_IMU);
 Setpoint = 180; // angle of IMU..
 //turn the PID on
 myPID.SetMode(AUTOMATIC);
}
 
void loop()
{
  
 Input = analogRead(PIN_IMU);
 myPID.Compute();
 analogWrite(PIN_OUTPUT, Output);

}
