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
  Animation7();
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
