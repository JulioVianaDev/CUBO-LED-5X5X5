void ZIGZAG(int columnPinA3[]){
  for(int i=0;i<25;i++){
    digitalWrite(columnPinA3[i],HIGH);
    delay(20);
  }
  //voltar na ordem
  for(int i=24;i>=0;i--){
    digitalWrite(columnPinA3[i],LOW);
  }
}
