void Animation6(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],HIGH);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
}
