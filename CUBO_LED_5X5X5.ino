int layerPin[5]={13,12,11,10,9};
int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};


void setup() {
  
for(int i=0;i<5;i++)
{
  pinMode(layerPin[i],OUTPUT);
}
for(int i=0;i<25;i++)
{
  pinMode(columnPin[i],OUTPUT);
}
for(int i=0;i<5;i++)
{
  digitalWrite(layerPin[i],HIGH);
}

}

void loop() {
  Animation1();
}

void clearPin(){
  for(int i=0;i<5;i++)
  {
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++)
  {
    digitalWrite(columnPin[i],LOW);
  }
}

void Animation1(){
  //apagar todos
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
    delay(100);
    digitalWrite(columnPin[i+1],HIGH);
    delay(100);
    digitalWrite(columnPin[i],LOW);
    delay(100);
  }
  //INVERTER
  for(int i=25;i>-1;i--){
    digitalWrite(columnPin[i],HIGH);
    delay(100);
    digitalWrite(columnPin[i-1],HIGH);
    delay(100);
    digitalWrite(columnPin[i],LOW);
    delay(100);
  }
  
}

void Animation2(){
  
}
