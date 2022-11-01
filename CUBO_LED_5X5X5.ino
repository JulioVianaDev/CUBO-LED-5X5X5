int layerPin[5]={13,12,11,10,9};
int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
//layer 0 = cima 
//layer 4 = ultima de baixo
//coluna 00= 53    coluna 01= 52   coluna 02= 51   coluna 03= 50   coluna 04= 49
//coluna 05= 48    coluna 06= 47   coluna 07= 46   coluna 08= 45   coluna 09= 44
//coluna 10= 43    coluna 11= 42   coluna 12= 41   coluna 13= 40   coluna 14= 39
//coluna 15= 38    coluna 16= 37   coluna 17= 36   coluna 18= 35   coluna 19= 34
//coluna 20= 33    coluna 21= 32   coluna 22= 31   coluna 23= 30   coluna 24= 29
//int columnPinA2[25]={53,52,51,50,59,44,39,34,29,30,31,32,33,38,43,48,47,46,45,40,35,36,37,42,41};

void setup() {
  //setando os valores das layer como saida
  for(int i=0;i<5;i++){
    pinMode(layerPin[i],OUTPUT);
  }
  //setando os valores das colunas como saida
  for(int i=0;i<25;i++){
    pinMode(columnPin[i],OUTPUT);
  }
  //ativando as 5 colunas
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
}

void loop() {
 Animation4();
}

void clearPin(){
  //colocando as layers como LOW
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],LOW);
  }
  //ascendendo os LEDS
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
}

void Animation1(){
  //apagar todos
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  //INDO NA DIREÇÃO POSITIVA
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);//LIGA O LED DO FOR
    delay(100);
    digitalWrite(columnPin[i+1],HIGH);// ASCENDE O PRÓXIMO LED
    delay(100);
    digitalWrite(columnPin[i],LOW);//APAGA O LED
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
  // LIGANDO AS 5 COLUNAS
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  //LIGANDO OS LEDS EM SEQUENCIA
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
    delay(100);
  }
  //VOLTANDO DE TRÁS PRA FRENTE
  for(int i=25;i>-1;i--){
    digitalWrite(columnPin[i],LOW);
    delay(100);
  }
}

void Animation3(){
  //Criar coluna nova pro zig zag
  int columnPinA3[25]={53,52,51,50,49,44,39,34,29,30,31,32,33,38,43,48,47,46,45,40,35,36,37,42,41};
  //setar nova coluna 
  for(int i=0;i<25;i++){
    pinMode(columnPinA3[i],OUTPUT);
  }
  //desativar as layer
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
  //CHAMANDO A FUNÇÃO ZIG ZAG PARA PODER EXECUTAR O CÓDIGO
  for (int j=0; j<5;j++){
    digitalWrite(layerPin[j],LOW);
    ZIGZAG(columnPinA3);
    digitalWrite(layerPin[j],HIGH);
  }

  int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
  for(int i=0;i<25;i++){
    pinMode(columnPinA3[i],OUTPUT);
  }
}

void Animation4(){
    digitalWrite(layerPin[2],LOW);
    digitalWrite(columnPin[12],HIGH);
}
void ZIGZAG(int columnPinA3[]){
  for(int i=0;i<25;i++){
    digitalWrite(columnPinA3[i],HIGH);
    delay(50);
  }
  //voltar na ordem
  for(int i=24;i > -1;i--){
    digitalWrite(columnPinA3[i],LOW);
  }
 
}
