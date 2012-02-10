    #include <Max3421e.h>
    #include <Usb.h>
    #include <AndroidAccessory.h>
    #define LED_PIN 3
    AndroidAccessory acc("Manufacturer",
    "Model",
    "Description",
    "1.0",
    "http://yoursite.com",
    "0000000012345678");
    
    int pitch;
   
    void setup()
    {
      // set communiation speed
      Serial.begin(9600);
      pinMode(LED_PIN, OUTPUT);
      acc.powerOn();
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
          }
          else if (msg[0] == 255) {
            digitalWrite(LED_PIN, LOW);
            Serial.print("negative ");
            Serial.println(pitch);
          }   
        }
      }
    }
