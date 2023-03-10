void Animation1(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 1"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
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
  for(int i=24;i>0;i--){
    digitalWrite(columnPin[i],HIGH);
    delay(50);
    digitalWrite(columnPin[i-1],HIGH);
    delay(50);
    digitalWrite(columnPin[i],LOW);
    delay(50);
  }
}
