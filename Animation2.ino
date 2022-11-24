void Animation2(){
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
