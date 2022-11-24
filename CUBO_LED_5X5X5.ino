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
  MeuSetup();
}
void loop() {
  MeuLoop();
}
