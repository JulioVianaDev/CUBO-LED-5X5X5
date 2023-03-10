void Animation6(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 6"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],HIGH);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
}
