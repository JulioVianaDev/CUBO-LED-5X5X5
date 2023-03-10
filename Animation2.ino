void Animation2(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 2"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
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
