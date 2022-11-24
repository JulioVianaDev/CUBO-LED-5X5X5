void Limpar(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],LOW);
  }
}
