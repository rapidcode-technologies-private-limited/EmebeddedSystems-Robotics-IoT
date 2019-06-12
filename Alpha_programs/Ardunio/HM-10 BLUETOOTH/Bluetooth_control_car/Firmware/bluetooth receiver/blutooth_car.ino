// bluetooth_control_car.pde
// simple example of how to control bot with bluetooth.
// BLE joystick Application used to give data, can be downloaded from Playstore.
// Implemented simplex bluetooth HM-10 module.
// Author: Susheel kumar (susheelkm2@gmail.com)
// $ID: bluetooth_control_car.pde, v 1.o 12/06/2019 10:31 PM
#define IN1 6   // Defining input pin 1
#define IN2 9   // Defining input pin 2
#define IN3 10  // Defining input pin 3
#define IN4 11  // Defining input pin 4
void setup() {
  pinMode(IN1,OUTPUT); // Initialising objective of the pin
  pinMode(IN2,OUTPUT); // Initialising objective of the pin
  pinMode(IN3,OUTPUT); // Initialising objective of the pin
  pinMode(IN4,OUTPUT); // Initialising objective of the pin
  Serial.begin(9600);  // Only Debugging
  // put your setup code here, to run once:

}

void loop() {
  char t;
  if(Serial.available()){
  t = Serial.read();       // Acquiring transmitted data
  Serial.println(t);}      // Simply printing the data in serial monitor

  if(t=='a'||t=='A')       // if the boolean expression inside the code block is true then the given statement will execute
  forward();               // Function calling
  if(t=='b'||t=='B')
  right();                 // Function calling
  if(t=='c'||t=='C')
  backward();              // Function calling
  if(t=='d'||t=='D')
  left();                  // Function calling
  if(t=='g'||t=='G')
  calm();                  // Function calling
  // put your main code here, to run repeatedly:
}
void forward()             // Function defintion for forward movement
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  }
void right()               // Function defintion for right movement
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
void backward()            // Function defintion for backward movement
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}
void left()                // Function defintion for left movement
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}
void calm()                // Function defintion to calm the bot
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
