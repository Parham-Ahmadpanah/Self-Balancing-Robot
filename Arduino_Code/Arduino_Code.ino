const int numOfReadings = 10; //maghadiri k sensor daryaft mikne b dalil noise o beyne 10 meghdar miangin migirim matris 10 araye ei tarif miknim
float readings[numOfReadings]; //maghadir sesor hara dar matris mirizim
int arrayIndex = 0; //araye hara tarif minim o dar ebteda 0 mizrim
float total = 0; //majmoo araye ha
//ultrasonic
int echoPin = 12;
int initPin = 13;
float pulseTime = 0; //zaman raft o bargasht
float distance = 0; //fasele b cm
//motor
int dir1 = 9;
int dir2 = 10;
// PID Parameters
float Actual = 0; //miangin fasele mohasebe shde
float Setpoint=19.3; //fasele mabna
float Error=0; //khataye mohasebe shode
float Integral=0; //khataye antegrali
float Derivative=0; //khataye moshtaghg
float Drive=0; //meghdar PID mohasebe shode
float Previous_error=0; //khateye ghabli
//Coefficients PID
float kp=90;
float ki=2;
float kd=1;
float dt=0.01; //baze zamani moshtagh giri


void setup() {
  // put your setup code here, to run once:
  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(initPin,OUTPUT);
  pinMode(echoPin,INPUT);
  //tarif matris 10 araye
  for(int thisReading=0;thisReading<numOfReadings;thisReading++){
    readings[thisReading]=0;
  }
  Serial.begin(9600);//namayesh maghadir  
}

void loop() {
  // put your main code here, to run repeatedly:
    int i=0;
    while(i<numOfReadings){
    digitalWrite(initPin,LOW);
    delayMicroseconds(2);//dar catalog
    digitalWrite(initPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(initPin,LOW);
    pulseTime=pulseIn(echoPin,HIGH);//zaman daryaft moj
    distance=pulseTime/58; //Distance=pulse time/29/2;
    
    //readings[arrayIndex]=distance; //fasele hara dar matris ezafe miknim
    total=total+distance; //readings[arrayIndex]; //,ohasebe majmoo fasele ha
    arrayIndex=arrayIndex+1;
    i=i+1;
    if(arrayIndex>=numOfReadings){
      arrayIndex=0;
      break;
    }
  }
  Actual=total/numOfReadings; // mohasebe fasele miangin
  Error=Setpoint-Actual;
  Integral=(Error*dt);
  Derivative=(Error-Previous_error)/dt;
  Drive=(Error*kp)+(Integral*ki)+(Derivative*kd);
  Previous_error=Error;
  total=0;
  if (Drive>0){
    //forward
    digitalWrite(dir2,LOW); // set direction motor
    digitalWrite(dir1,HIGH); // send PWM command motor 
  }

  else if (Drive<0){
    //backward
    digitalWrite(dir1,LOW); // set direction motor
    digitalWrite(dir2,HIGH); // send PWM command motor 
  }
 // else if (Drive<5 && Drive>-5){
   // digitalWrite(dir1,LOW); // set direction motor
    //digitalWrite(dir2,LOW); // send PWM command motor 
 // }
  Serial.println(Actual,DEC); // print out the average distance to the debugger
  
  if(pulseTime==0){
   Serial.println("Warning: no pulse from sensor");
   } 
  else{
      Serial.println(distance);
     
  }
 // Serial.println("error");
 // Serial.println(Error);
 // Serial.println("drive");
 // Serial.println(Drive);
  delay(1); // wait 1 milli seconds before looping again
}
