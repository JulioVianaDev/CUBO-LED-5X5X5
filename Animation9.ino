void Animation9(){
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
