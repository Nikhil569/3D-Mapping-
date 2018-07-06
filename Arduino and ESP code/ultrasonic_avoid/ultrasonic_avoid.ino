///Left Motor  Pins
#define INA_1 30
#define INB_1 31
#define PWM_1 4

///Right Motor Pins
#define INA_2 24
#define INB_2 25
#define PWM_2 5

int echo_front=6;
int trig_front=7;
int echo_left=8;
int trig_left=9;
int echo_right=10;
int trig_right=11;

long time_front,distance_front,minimum_front,distance_left,minimum_left,minimum_left_only,time_left,distance_right,minimum_right,minimum_right_only,time_right;

void setup()
{
  Serial.begin(9600);
  pinMode(trig_front,OUTPUT);
  pinMode(echo_front,INPUT);
  pinMode(trig_left,OUTPUT);
  pinMode(echo_left,INPUT);
  pinMode(trig_right,OUTPUT);
  pinMode(echo_right,INPUT);
  pinMode(INA_1,OUTPUT); 
  pinMode(INB_1,OUTPUT);
  pinMode(PWM_1,OUTPUT);

  //Setting Right Motor pin as OUTPUT
  pinMode(INA_2,OUTPUT);
  pinMode(INB_2,OUTPUT);
  pinMode(PWM_2,OUTPUT);
  minimum_right_only=15;
  minimum_left_only=15;
}
char inp='0';
char k='1';

void loop() 
{
  
  if(k=='6') {
    while(inp !='7'){
      
      //Move forward for 5 sec
      if(inp=='1')
        forward_robot();
      else if(inp=='2')
        backward_robot();
      else if(inp=='3')
        tern_left();
      else if(inp=='4')
        tern_right();
      else if(inp=='5')
        stop_robot();
        
      inp=Serial.read();
    }
    k='2';
  }
  while(k!='6'){
    sensor_front();
    sensor_left();
    sensor_right();
    //printultra();
    forward_robot();
    //Serial.println("Robot Forward");


    if(distance_front<=minimum_front)
    {
      tern_left();

    }
    if(distance_left<=minimum_left_only){
      tern_right();
    }
    if(distance_right<=minimum_right_only){
      tern_left();
    }
    if(distance_front<=minimum_front && distance_left<=minimum_left)
    {
      tern_right();

    }
    if(distance_front<=minimum_front && distance_right<=minimum_right)
    {
      tern_left();
    }
    if(distance_front<=minimum_front && distance_left<=minimum_left && distance_right<=minimum_right)
    {
      backward_robot();

      tern_left();
    }
    delay(50);
    k=Serial.read();
    inp='0';
  }
 
}
void printultra(){
  Serial.print("front ultra: ");
  Serial.println(distance_front);
  Serial.print("right ultra: ");
  Serial.println(distance_right);
  Serial.print("left ultra: ");
  Serial.println(distance_left);

}
void sensor_front()
{
  digitalWrite(trig_front, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig_front, HIGH); 
  delayMicroseconds(20);
  digitalWrite(trig_front, LOW);

  time_front=pulseIn(echo_front,HIGH);
  distance_front=time_front/58.2;
  minimum_front=35;  
}

void sensor_left()
{
  digitalWrite(trig_left, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig_left, HIGH); 
  delayMicroseconds(20);
  digitalWrite(trig_left, LOW);

  time_left=pulseIn(echo_left,HIGH);
  distance_left=time_left/58.2;
  minimum_left=35;    
}

void sensor_right()
{
  digitalWrite(trig_right, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig_right, HIGH); 
  delayMicroseconds(20);
  digitalWrite(trig_right, LOW);

  time_right=pulseIn(echo_right,HIGH);
  distance_right=time_right/58.2;
  minimum_right=35; 
}

void forward_robot()
{
  //Left motor
  digitalWrite(INA_1,LOW);
  digitalWrite(INB_1,HIGH);
  analogWrite(PWM_1,138);

  //Right Motor 
  digitalWrite(INA_2,HIGH);
  digitalWrite(INB_2,LOW);
  analogWrite(PWM_2,100);  

}
void backward_robot(){

  digitalWrite(INA_1,HIGH);
  digitalWrite(INB_1,LOW);
  analogWrite(PWM_1,138);

  //Right Motor 
  digitalWrite(INA_2,LOW);
  digitalWrite(INB_2,HIGH);
  analogWrite(PWM_2,200);  

}

void stop_robot()
{
  //Left Motor 
  digitalWrite(INA_1,HIGH);
  digitalWrite(INB_1,HIGH);
  analogWrite(PWM_1,0);

  //Right Motor 
  digitalWrite(INA_2,HIGH);
  digitalWrite(INB_2,HIGH);
  analogWrite(PWM_2,0);  
}

void tern_left()
{
  digitalWrite(INA_2,HIGH);
  digitalWrite(INB_2,LOW);
  analogWrite(PWM_2,90);

  //Left Motor 
  digitalWrite(INA_1,HIGH);
  digitalWrite(INB_1,LOW);
  analogWrite(PWM_1,80);  

}

void tern_right()
{
  //RightMotor 
  digitalWrite(INA_2,LOW);
  digitalWrite(INB_2,HIGH);
  analogWrite(PWM_2,70);

  //Left Motor 
  digitalWrite(INA_1,LOW);
  digitalWrite(INB_1,HIGH);
  analogWrite(PWM_1,90);  
}


