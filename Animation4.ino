void Animation4(){
  //acender o miolo
  digitalWrite(layerPin[2],HIGH);
  digitalWrite(columnPin[12],HIGH);
  delay(300);
  //acender os 3 do meio
  int colunas3[9]={13,12,11,17,16,18,8,7,6};
  for(int i=0;i<10;i++){
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
