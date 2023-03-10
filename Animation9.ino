void Animation9(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 9"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
  for(int i=0;i<40;i++)  {
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
}
