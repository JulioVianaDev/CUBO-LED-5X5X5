void Animation8(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 8"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
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
