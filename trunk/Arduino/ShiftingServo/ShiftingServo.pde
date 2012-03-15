//This code will shift gears from 1 to 8 and back down based on a calibration
//by Dan Kern and Greg Shimonov done on 3/14 (pi day)


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
const int upshift[7] = {34, 50, 64, 83, 99, 115, 129}; //servo positions for each gear (calibrated)
const int downshift[7] = {10, 24, 40, 56, 73, 91, 107};
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  for(int i = 0; i <= 6; i++)
  {
    myservo.write(upshift[i]);
    Serial.println(myservo.read());
    delay(1000);
  }
  delay(2000);
  for(int i = 6; i >= 0; i--)
  {
    myservo.write(downshift[i]);
    Serial.println(myservo.read());
    delay(1000);
  }
  delay(2000);
}
