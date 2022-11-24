void Animation1(){
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
  for(int i=24;i>-1;i--){
    digitalWrite(columnPin[i],HIGH);
    delay(50);
    digitalWrite(columnPin[i-1],HIGH);
    delay(50);
    digitalWrite(columnPin[i],LOW);
    delay(50);
  }
}
