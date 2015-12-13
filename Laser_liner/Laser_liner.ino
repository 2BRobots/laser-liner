#include <Servo.h> 
#define laser 7
 
Servo servox;              
Servo servoy;

void cartesian_coordinate(int x, int y, int laser_en);
 
int draw_x[4] = {0,0,10,-10};
int draw_y[4] = {10,-10,0,0};
int laser_con[4] = {1,1,1,1};


void setup() 
{ 
  servox.attach(9);  // attaches the servo on pin 9 to the servo object 
  servoy.attach(10);
  pinMode(laser,OUTPUT);
  digitalWrite(laser,LOW);
} 
 
void loop() 
{
  
for (int i = 0; i<=3; i++)
{
cartesian_coordinate(draw_x[i],draw_y[i],laser_con[i]);
delay(800);
}

} 

void cartesian_coordinate(int x, int y, int laser_en)
{
int h,v;
h = map(x,-10,10,120,60);
v = map(y,-10,10,120,60);

if (laser_en == 1)
{
  digitalWrite(laser,LOW);
}
else
{
  digitalWrite(laser,HIGH);
}

servox.write(h);
servoy.write(v);
}


