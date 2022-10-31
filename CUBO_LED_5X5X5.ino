int layerPin[5]={13,12,11,10,9};
int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
//layer 0 = cima 
//layer 4 = ultima de baixo
//coluna 00= 53    coluna 01= 52   coluna 02= 51   coluna 03= 50   coluna 04= 49
//coluna 05= 48    coluna 06= 47   coluna 07= 46   coluna 08= 45   coluna 09= 44
//coluna 10= 43    coluna 11= 42   coluna 12= 41   coluna 13= 40   coluna 14= 39
//coluna 15= 38    coluna 16= 37   coluna 17= 36   coluna 18= 35   coluna 19= 34
//coluna 20= 33    coluna 21= 32   coluna 22= 31   coluna 23= 30   coluna 24= 39
//int columnPinA2[25]={53,52,51,50,59,44,39,34,39,30,31,32,33,38,43,48,47,46,45,40,35,36,37,42,41};

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
  Animation2();
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
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
    delay(100);
  }
  for(int i=25;i>-1;i--){
    digitalWrite(columnPin[i],LOW);
    delay(100);
  }
}
