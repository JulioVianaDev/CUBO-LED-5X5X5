void Animation5(){
  for(int i=0;i<5;i++)  {
    digitalWrite(layerPin[i],LOW);
  }
  for(int i=0;i<25;i++)  {
    digitalWrite(columnPin[i],HIGH);
  }
  delay(400);
  digitalWrite(layerPin[4],HIGH);
  delay(400);
  digitalWrite(layerPin[0],HIGH);
  delay(400);
  digitalWrite(layerPin[3],HIGH);
  delay(400);
  digitalWrite(layerPin[1],HIGH);
  delay(400);
  digitalWrite(layerPin[2],HIGH);
  delay(400);
  //ascendendo os LEDS
}
