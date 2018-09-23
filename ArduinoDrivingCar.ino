//Names: Caroline Liu, Mehak Shah, Tiffany Tran

//Variable initialization:
//Assignment of analog pins - LDR sensors
int left = A2;
int mid = A1;
int right = A0;

//Initialization of LDR values
unsigned int senseLeft = 0;
unsigned int senseMid = 0;
unsigned int senseRight = 0;

//Assignment of digital pins - left motor
const int enablePin1 = 7;
const int motor1 = 6; //Forwards
const int motor2 = 5; //Backwards

//Assignment of digital pins - right motor
const int enablePin2 = 8;
const int motor3 = 9; //Forwards
const int motor4 = 10; //Backwards

//Initialization of variables
const int MAX_SPEED = 100; //can be 0-255

//This method sets up the digital pins
void setup()
{
  //Motor pins
  pinMode (motor1, OUTPUT);
  pinMode (motor2, OUTPUT);
  pinMode (motor3, OUTPUT);
  pinMode (motor4, OUTPUT);

  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);

  Serial.begin(9600);
}

void moveForward(int durationInMilliSec)
{
  analogWrite (motor1, 80);
  analogWrite (motor2, 0);
  analogWrite (motor3, 80);
  analogWrite (motor4, 0);

  delay(durationInMilliSec);
}

void moveBack (int durationInMilliSec)
{
  analogWrite (motor1, 0);
  analogWrite (motor2, 80);
  analogWrite (motor3, 0);
  analogWrite (motor4, 80);

  delay(durationInMilliSec);

  turnLeft(80);
  loop();
}

void moveBack2 (int durationInMilliSec)
{
  turnRight(950);
  loop();
}

void turnRight(int durationInMilliSec)
{
  analogWrite (motor1, 70);
  analogWrite (motor2, 0);
  analogWrite (motor3, 0);
  analogWrite (motor4, 80); //80

  delay(durationInMilliSec);
}

void turnLeft(int durationInMilliSec)
{
  analogWrite (motor1, 0);
  analogWrite (motor2, 80);
  analogWrite (motor3, 40);
  analogWrite (motor4, 0);

  delay(durationInMilliSec);
}

void loop()
{
  delay(30);

  //Reading in of LDR sensor values
  senseLeft = analogRead (left);
  senseMid = analogRead (mid);
  senseRight = analogRead (right);

  if (senseLeft < 550 || senseMid < 750)// If left is on black or middle  
  {
    if (senseRight < 580)
    {
     moveBack2(20);//turn right until line is reached
    }
    else
    {
      moveForward (20); //Go STRAIGHT
    }
  }
  else //If nothing is on black
  {
   moveBack(20); //Move back to readjust and turn LEFT (L, M, and R = WHITE);
  }
}

