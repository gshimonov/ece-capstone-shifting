    #include <Max3421e.h>
    #include <Usb.h>
    #include <AndroidAccessory.h>
    #include <Servo.h>
    #define LED_PIN 3
    
    AndroidAccessory acc("Manufacturer",
    "Model",
    "Description",
    "1.0",
    "http://yoursite.com",
    "0000000012345678");
    Servo myservo;
    
    int pitch;
    int pos = 0; // variable to store the servo position
   
    void setup()
    {
      // set communiation speed
      Serial.begin(9600);
      pinMode(LED_PIN, OUTPUT);
      acc.powerOn();
      myservo.attach(44); // attaches the servo on pin 9 to the servo object
    }
    
    void servo_up(int pitch)
    {
                 ///servo///
//     for (pos = 0; pos < 18; pos +=1) {
//       myservo.write(45);
//       delay(10);
//     }
       myservo.write(pitch);
    }
    
    void servo_down(int pitch)
    {
//      for (pos = 18; pos>=1; pos -+1)
//      {
//        myservo.write(135);
//      }
       myservo.write(pitch);
    }
     
     
    void loop()
    { 
     
      byte msg[1];
      if (acc.isConnected()) {
        int len = acc.read(msg, sizeof(msg), 1); // read data into msg variable
        if (len > 0) {
/*          pitch = msg[1];
          if(pitch > 45) {
            digitalWrite(LED_PIN, HIGH);
            Serial.print("greater than 45 degrees ");
            Serial.println(pitch);
          }
          else {
            digitalWrite(LED_PIN, LOW);
            Serial.print("less than 45 degrees ");
            Serial.println(pitch);
          }*/
          pitch = msg[1];
          if (msg[0] == 200) {
            digitalWrite(LED_PIN, HIGH);
            Serial.print("positive ");
            Serial.println(pitch);
            servo_up(pitch);
          }
          else if (msg[0] == 255) {
            digitalWrite(LED_PIN, LOW);
            Serial.print("negative ");
            Serial.println(pitch);
            servo_down(pitch);
          }   
        }
      }
      /*
           ///servo///
     for (pos = 0; pos < 180; pos +=1) {
       myservo.write(pos);
       delay(10);
     }
     for (pos = 180; pos>=1; pos -+1)
     {
       /myservo.write(pos);
     }*/
    }
