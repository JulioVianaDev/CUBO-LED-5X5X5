//BIBLIOTECAS PARA O LCD
#include <Wire.h> //Biblioteca utilizada gerenciar a comunicação entre dispositicos através do protocolo I2C
#include <LiquidCrystal_I2C.h> //Biblioteca controlar display 16x2 através do I2C
//INFORMAÇÕES PARA USAR O I2C NO MEGA 
#define col  16 //Define o número de colunas do display utilizado
#define lin   2 //Define o número de linhas do display utilizado
#define ende  0x27 //Define o endereço do display
byte btSubir=3; // botão decremento (esquerda)
byte btDescer=2; // botão incremento (direita
int number = 0;
int numberR = 0;
LiquidCrystal_I2C lcd(ende, col, lin); //Cria o objeto lcd passando como parâmetros o endereço, o nº de colunas e o nº de linhas

//#define  transistor1  13
//#define  transistor2  12
//#define  transistor3  11
//#define  transistor4  10
//#define  transistor5  9
int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
int layerPin[5]={13,12,11,10,9};
void setup() {
  lcd.init(); //Inicializa a comunicação com o display já conectado
  lcd.clear(); //Limpa a tela do display
  lcd.backlight(); //Aciona a luz de fundo do display
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Bora animar?"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
  //LEDS
  for(int i=0;i<5;i++){
    (layerPin[i],OUTPUT);
  }
  for(int i=0;i<5;i++){
    pinMode(layerPin[i],OUTPUT);
  }
  for(int i=0;i<25;i++){
    pinMode(columnPin[i],OUTPUT);
  }
  
  pinMode(btSubir, INPUT_PULLUP);
  pinMode(btDescer, INPUT_PULLUP);
}
void loop() {
  Gota();
  if (digitalRead(btSubir) == 0 ){ // verifica se o botão direito foi acionado     
    number += 1;    
    while (digitalRead(btSubir) == 0) {} // loop vazio - aguarda soltar o botão (evita a númeração constante
  }

  if (!digitalRead(btDescer)){ // verifica se o esquerdo foi acionado    
    number -= 1;             
    while (!digitalRead(btDescer)) {} // loop vazio - aguarda soltar o botão (evita a númeração constante
  }
  if (number == 1){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 1"); //Exibe a mensagem na primeira linha do display
    Animation1();
  }else if (number == 2){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 2"); //Exibe a mensagem na primeira linha do display
    Animation2();
  }else if (number == 3){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 3"); //Exibe a mensagem na primeira linha do display
    Animation3();
  }else if (number == 4){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 4"); //Exibe a mensagem na primeira linha do display
    Animation4();
  }
  // reseta em caso de estouro (<0 ou >9)
  if (number < 0) {number = 8;}  
  if (number > 8) {number = 0;}
  
}

void Animation0(){
  ResetarColunas();
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
  }
  delay(100);
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
  delay(100);
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  delay(100);
  
}
void Animation1(){
  ResetarColunas();
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);//LIGA O LED DO FOR
    delay(50);
    digitalWrite(columnPin[i+1],HIGH);// ASCENDE O PRÓXIMO LED
    delay(50);
    digitalWrite(columnPin[i],LOW);//APAGA O LED
    delay(50);
  }
  for(int i=24;i>-1;i--){
    digitalWrite(columnPin[i],HIGH);
    delay(50);
    digitalWrite(columnPin[i-1],HIGH);
    delay(50);
    digitalWrite(columnPin[i],LOW);
    delay(50);
  }
}

void Animation2(){
  // LIGANDO AS 5 COLUNAS
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
  //LIGANDO OS LEDS EM SEQUENCIA
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
    delay(100);
  }
  //VOLTANDO DE TRÁS PRA FRENTE
  for(int i=24;i>-1;i--){
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
    digitalWrite(layerPin[i],LOW);
  }
  //CHAMANDO A FUNÇÃO ZIG ZAG PARA PODER EXECUTAR O CÓDIGO
  for (int j=0; j<5;j++){
    digitalWrite(layerPin[j],HIGH);
    ZIGZAG(columnPinA3);
    digitalWrite(layerPin[j],LOW);
  }
}
void Animation4(){
  //acender o miolo
  digitalWrite(layerPin[2],HIGH);
  digitalWrite(columnPin[12],HIGH);
  delay(300);
  //acender os 3 do meio
  int colunas3[9]={13,12,11,17,16,18,8,7,6};
  for(int i=0;i<10;i++){
    digitalWrite(columnPin[colunas3[i]],HIGH);   
  }
  digitalWrite(layerPin[1],HIGH);
  digitalWrite(layerPin[3],HIGH);
  //acender tudo
  delay(300);
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
  }
  digitalWrite(layerPin[0],HIGH);
  digitalWrite(layerPin[4],HIGH);
  delay(300);
  //reverter a partir de agora
  digitalWrite(layerPin[0],LOW);
  digitalWrite(layerPin[4],LOW);
  int colunas5Apagar[16]={0,1,2,3,4,9,14,19,24,23,22,21,20,15,10,5};
  for(int i=0;i<16;i++){
    digitalWrite(columnPin[colunas5Apagar[i]],LOW);
  }
  delay(300);
  //reverter os 3
  int colunas3Apagar[8]={6,7,8,13,18,17,16,11};
  digitalWrite(layerPin[1],LOW);
  digitalWrite(layerPin[3],LOW);
  for(int i=0;i<8;i++){
    digitalWrite(columnPin[colunas3Apagar[i]],LOW);
  }
  delay(300);
  //apagar o que sobrou
  digitalWrite(layerPin[2],LOW);
  digitalWrite(columnPin[7],LOW);
  delay(300);
}

void Animation5(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
  delay(400);
  digitalWrite(layerPin[4],HIGH);
  delay(400);
  digitalWrite(layerPin[0],HIGH);
  delay(400);
  digitalWrite(layerPin[3],HIGH);
  delay(400);
  digitalWrite(layerPin[1],HIGH);
  delay(400);
  digitalWrite(layerPin[2],HIGH);
  delay(400);
  //ascendendo os LEDS
}

void Animation6(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],HIGH);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
}
void Animation7(){
  int randomColumn = random(25);
  int randomLayer = random(5);
  AcenderUnico(randomColumn,randomLayer);
  delay(5);
  ApagarUnico(randomColumn,randomLayer);
  delay(5);
}
void Animation8(){
  //parte 1 
  AcenderUnico(0,0);
  delay(300);
  //parte 2
  digitalWrite(columnPin[1],HIGH);
  digitalWrite(columnPin[5],HIGH);
  digitalWrite(columnPin[6],HIGH);
  digitalWrite(layerPin[1],HIGH);
  delay(300);
  //parte 3
  digitalWrite(layerPin[2],HIGH);
  digitalWrite(columnPin[2],HIGH);
  digitalWrite(columnPin[7],HIGH);
  digitalWrite(columnPin[12],HIGH);
  digitalWrite(columnPin[11],HIGH);
  digitalWrite(columnPin[10],HIGH);
  delay(300);
  //parte 4
  digitalWrite(layerPin[3],HIGH);
  digitalWrite(columnPin[3],HIGH);
  digitalWrite(columnPin[8],HIGH);
  digitalWrite(columnPin[13],HIGH);
  digitalWrite(columnPin[18],HIGH);
  digitalWrite(columnPin[17],HIGH);
  digitalWrite(columnPin[16],HIGH);
  digitalWrite(columnPin[15],HIGH);
  delay(300);
  digitalWrite(layerPin[4],HIGH);  
  for(int i=24;i>=0;i--){
    digitalWrite(columnPin[i],HIGH);
  }
  delay(300);
  Limpar();
}
void ZIGZAG(int columnPinA3[]){
  for(int i=0;i<25;i++){
    digitalWrite(columnPinA3[i],HIGH);
    delay(50);
  }
  //voltar na ordem
  for(int i=24;i>=0;i--){
    digitalWrite(columnPinA3[i],LOW);
  }
}
void ResetarColunas(){
  int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
  for(int i=0;i<25;i++){
    pinMode(columnPin[i],OUTPUT);
  }
}
void Limpar(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],LOW);
  }
}
void Gota(){
  Limpar();
  int randomColumn = random(0,24);
  int randomLayer = 0;
  
  while(randomLayer < 5){
    digitalWrite(columnPin[randomColumn],HIGH);
    digitalWrite(layerPin[randomLayer],HIGH);
    digitalWrite(layerPin[randomLayer - 1],LOW);
    delay(300);
    randomLayer++;
  }
  
}
void AcenderUnico(int ledColumn,int ledLayer){
  digitalWrite(columnPin[ledColumn],HIGH);
  digitalWrite(layerPin[ledLayer],HIGH);
}
void ApagarUnico(int ledColumn,int ledLayer){
  digitalWrite(columnPin[ledColumn],LOW);
  digitalWrite(layerPin[ledLayer],LOW);
}
