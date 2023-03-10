void Animation7(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 7"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
  for(int i=0;i<250;i++)  {
    int randomColumn = random(25);
    int randomLayer = random(5);
    AcenderUnico(randomColumn,randomLayer);
    delay(5);
    ApagarUnico(randomColumn,randomLayer);
    delay(5);
  }
   
  
 
}
