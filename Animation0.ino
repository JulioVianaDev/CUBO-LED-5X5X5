void Animation0(){
  ResetarColunas();
  for(int i=0;i<25;i++){
    digitalWrite(columnPin[i],HIGH);
  }
  delay(100);
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],HIGH);
  }
  delay(100);
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  delay(100);
}
