int SW_pin=2;
int X=0;
int Y=1;
int B=13;
int G=12;
int R=11;
int Buzz=7;
int BJP=0;
int cong=0;
int AAP=0;
int BSP=0;
void setup(){
  pinMode(SW_pin,INPUT);
  digitalWrite(SW_pin,HIGH);
  Serial.begin(9600);
  pinMode(R,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(Buzz,OUTPUT);
}
void loop()
{
  Serial.print("SW_pin: ");
  Serial.println(digitalRead(SW_pin));
  Serial.print("X: ");
  Serial.println(analogRead(X));
  Serial.print("Y: ");
  Serial.println(analogRead(Y));
  Serial.print("\n");

 if(analogRead(X)>1000)
{
  BJP++;
  digitalWrite(G,HIGH);
  delay(100);
  digitalWrite(G,LOW);
  }

 if(analogRead(Y)>1000)
{
  cong++;
  digitalWrite(R,HIGH);
  delay(100);
  digitalWrite(R,LOW);
  }
 if(analogRead(X)<50)
{
  AAP++;
  digitalWrite(B,HIGH);
  delay(100);
  digitalWrite(B,LOW);
  }
 if(analogRead(Y)<50)
{
  BSP++;
  
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
  delay(100);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
  }
if(digitalRead(SW_pin)==0)
{
  digitalWrite(Buzz,HIGH);
  if((BJP>cong)&&(BJP>AAP)&&(BJP>BSP))
 { digitalWrite(G,HIGH);
  delay(500);
  digitalWrite(G,LOW);
  digitalWrite(Buzz,LOW);
}
  if((cong>AAP)&&(cong>BSP))
  {digitalWrite(R,HIGH);
  delay(500);
  digitalWrite(R,LOW);
  digitalWrite(Buzz,LOW);
  }
  if(AAP>BSP){
  digitalWrite(B,HIGH);
  delay(500);
  digitalWrite(B,LOW);
  digitalWrite(Buzz,LOW);
  }
  else
  {
  digitalWrite(G,HIGH);
  digitalWrite(B,HIGH);
  delay(500);
  digitalWrite(G,LOW);
  digitalWrite(B,LOW);
  digitalWrite(Buzz,LOW);
  
  }
}
  delay(500);
  
  }
