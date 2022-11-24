void MeuSetup(){
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
