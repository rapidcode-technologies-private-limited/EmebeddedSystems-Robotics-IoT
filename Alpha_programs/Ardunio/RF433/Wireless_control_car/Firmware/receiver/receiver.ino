// Motor control receiver.pde
// Simple example of how to use VirtualWire to receive message
// Implements a simplex receiver(one way) with an Rx-B1 module
// Author: Susheel kumar (susheelkm2@gmail.com)
// $ID: Motor control receiver.pde, v 1.4 09/06/2019 6:30:00 PM
#include <VirtualWire.h>
#define ledpin= 13;
#define rmHIGHpin=3;
#define rmLOWpin=5;
#define lmHIGHpin=9;
#define lmLOWpin=6;

boolean printS= false, printF=false, printR = false, printB= false, printL= false;

void setup()
{
    pinMode(ledpin,OUTPUT); // Initialising objective of the pin
    pinMode(rmHIGHpin,OUTPUT);  // Initialising objective of the pin
    pinMode(rmLOWpin,OUTPUT);  // Initialising objective of the pin
    pinMode(lmLOWpin,OUTPUT);  // Initialising objective of the pin
    pinMode(lmHIGHpin,OUTPUT);  // Initialising objective of the pin
    Serial.begin(9600); // Debugging only
    Serial.println("setup");

    // Initialise the IO and ISR
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);  // Bits per sec

    vw_rx_start();       // Start the receiver PLL running
}

void forward()           // Function defintion
{
  if(!printF){
    Serial.println("For Fn");
    // For the foward movement of the wheels
    digitalWrite(rmHIGHpin, HIGH);

    digitalWrite(rmLOWpin, LOW);

    digitalWrite(lmLOWpin, LOW);

    digitalWrite(lmHIGHpin, HIGH);
  }
  printB= false;
  printF= true;
  printL= false;
  printS= false;
  printR= false;

}

void backward()          // Function defintion
{
  if(!printB){
    Serial.println("Bac Fn");
    // For the backward movement of the wheels
    digitalWrite(rmHIGHpin, LOW);

    digitalWrite(rmLOWpin, HIGH);

    digitalWrite(lmLOWpin, HIGH);

    digitalWrite(lmHIGHpin, LOW);
  }
  printB= true;
  printF= false;
  printL= false;
  printS= false;
  printR= false;

}

void right()              // Function defintion
{
  if(!printR){
    Serial.println("R Fn");
    // For the right movement of the wheels
    digitalWrite(rmHIGHpin, LOW);

    digitalWrite(rmLOWpin, LOW);

    digitalWrite(lmLOWpin, LOW);

    digitalWrite(lmHIGHpin, HIGH);
  }
  printB= false;
  printF= false;
  printL= false;
  printS= false;
  printR= true;

}

void left()               // Function defintion
{
 if(!printL){
    Serial.println("L Fn");
    // For the left movement of the wheels
    digitalWrite(rmHIGHpin, HIGH);

    digitalWrite(rmLOWpin, LOW);

    digitalWrite(lmLOWpin, LOW);

    digitalWrite(lmHIGHpin, LOW);
 }
  printB= false;
  printF= false;
  printL= true;
  printS= false;
  printR= false;

}
void calm()                // Function defintion
{
  if(!printS){
    Serial.println("St Fn");
    // To stop the wheels
    digitalWrite(rmHIGHpin, LOW);

    digitalWrite(rmLOWpin, LOW);

    digitalWrite(lmLOWpin, LOW);

    digitalWrite(lmHIGHpin, LOW);

    printB= false;
    printF= false;
    printL= false;
    printS= true;
    printR= false;
  }
}



void loop()
{
    void forward();    // declaring function
    void right();      // declaring function
    void left();       // declaring function
    void backward();   // declaring function
    void calm();       // declaring function
    int i;
    char a[100],b[100];

    uint8_t buf[VW_MAX_MESSAGE_LEN];
    uint8_t buflen = VW_MAX_MESSAGE_LEN;

    if (vw_get_message(buf, &buflen)) // Non-blocking
    {


      digitalWrite(ledpin, true); // Flash a light to show received good message
      // Message with a good checksum received, dump it.
      Serial.print("Got: ");
      for (i = 0; i < buflen; i++)
      {

          a[i]=buf[i]; // Receiving the transmitted value
          Serial.print("Data  ");
          Serial.print(i);
          Serial.print(": ");
          Serial.print(a[i]);
          Serial.println(" ");

          if(a[i]=='f'||a[i]=='F')  /*if boolean expression evaluates to true,
                  then the block of code inside the if statement will execute*/
          forward();                    // calling of function
          if(a[i]=='r'||a[i]=='R')
          right();                      // calling of function
          if(a[i]=='l'||a[i]=='L')
          left();                       // calling of function
          if(a[i]=='b'||a[i]=='B')
          backward();                   // calling of function
          if(a[i]=='s'||a[i]=='S')
          calm();                       // calling of function
    }
      }
}
