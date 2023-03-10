void Animation4(){
  lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
  lcd.print("Animation 4"); //Exibe a mensagem na primeira linha do display
  lcd.setCursor(0, 1); //Coloca o cursor do display na coluna 1 e linha 2
  lcd.print("Ass: Tomate");  //Exibe a mensagem na segunda linha do display
  int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
  int layerPin[5]={13,12,11,10,9};
  //acender o miolo
  digitalWrite(layerPin[2],HIGH);
  digitalWrite(columnPin[12],HIGH);
  delay(300);
  //acender os 3 do meio
  int colunas3[8]={13,11,17,16,18,8,7,6};
  for(int i=0;i<9;i++){
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
