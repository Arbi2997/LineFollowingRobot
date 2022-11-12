// Black Line Follower 
const int IR1=A1;      //Right sensor
const int IR2=A0;    //left Sensor
// motor one
int enA = 3;    //Right motor
int MotorAip1=5;
int MotorAip2=6;
// motor two
int enB = 7;    //Left motor
int MotorBip1=8;
int MotorBip2=9;

/*
//Ultrasound Sensor
#define echoPin 3
#define trigPin 2

long duration;
int distance;
*/
int TopSpeed = 100;

void setup() 
{
  Serial.begin(9600);

  // put your setup code here, to run once:
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(MotorAip1,OUTPUT);
  pinMode(MotorAip2,OUTPUT);
  pinMode(MotorBip1,OUTPUT);
  pinMode(MotorBip2,OUTPUT);

  /*
  //Ultrasound Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  */

}
void loop() 
{
  int dataAnalog0 = digitalRead(IR2);
  int dataAnalog1 = digitalRead(IR1);
  Serial.print("SensorA0: ");
  Serial.print(dataAnalog0);
  Serial.println("SensorA1: ");
  Serial.print(dataAnalog1);
  
  if(dataAnalog0==1 && dataAnalog1==1) //IR will not glow on black line
  {
    //Stop both Motors
    digitalWrite(MotorAip1,HIGH);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
   digitalWrite (enA, TopSpeed);
   digitalWrite (enB, TopSpeed);
  }

  else if(dataAnalog0==0 && dataAnalog1==0)  //IR not on black line
  {
    //Move both the Motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    digitalWrite (enA, TopSpeed);
    digitalWrite (enB, TopSpeed);
  }

  else if(dataAnalog0==1 && dataAnalog1==0)
  {
    //Tilt robot towards left by stopping the left wheel and moving the right one
    digitalWrite(MotorAip1,LOW);     
    digitalWrite(MotorAip2,HIGH);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,HIGH);
    digitalWrite (enA, TopSpeed);
    digitalWrite (enB, TopSpeed);
  }

  else if(dataAnalog0==0 && dataAnalog1==1)
  {
    //Tilt robot towards right by stopping the right wheel and moving the left one
     digitalWrite(MotorAip1,HIGH);     // If I want to turn right then the speed of the right wheel should be less than that of the left wheel, here, let a be the right wheel
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,HIGH);
    digitalWrite(MotorBip2,LOW);
    digitalWrite (enA, TopSpeed);
   digitalWrite (enB, TopSpeed);
  }

  /*
  else
  {
    //Stop both the motors
    digitalWrite(MotorAip1,LOW);
    digitalWrite(MotorAip2,LOW);
    digitalWrite(MotorBip1,LOW);
    digitalWrite(MotorBip2,LOW);
    digitalWrite (enA, TopSpeed);
   digitalWrite (enB, TopSpeed);
  }
  */
}

