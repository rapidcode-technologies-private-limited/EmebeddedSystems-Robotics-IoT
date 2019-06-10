// using serial monitor to transmitt message to control the motor remotely
// F= forward direction
// B= backward direction
// R= right direction
// L= left direction
// S= to calm the motor 
#include <VirtualWire.h>
char *msg = ".";
boolean Transmit = false;


void setup()
{
    Serial.begin(9600);           // Debugging only
    Serial.println("Transmitter Begins...........");
    

     vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec
}

void loop()
{
    
    String data;
    
    if(Serial.available()>0){
      data=Serial.readString();
      
      if(data == "F"||data == "f")  {Transmit = true;msg = "F";}
      if(data == "R"||data == "r")  {Transmit = true;msg = "R";}
      if(data == "L"||data == "l")  {Transmit = true;msg = "L";}
      if(data == "B"||data == "b")  {Transmit = true;msg = "B";}
      if(data == "S"||data == "s")  {Transmit = true;msg = "S";}

      if(Transmit){
        Serial.println(msg);
        digitalWrite(13, true); // Flash a light to show transmitting  
        vw_send((uint8_t *)msg, strlen(msg));
        vw_wait_tx(); // Wait until the whole message is gone
        digitalWrite(13, false);
        Transmit = false;
        delay(200);      
      }          
    }
    
}

  
  
  
