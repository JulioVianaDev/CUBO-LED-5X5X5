void Animation3(){
  //Criar coluna nova pro zig zag
  int columnPinA3[25]={53,52,51,50,49,44,39,34,29,30,31,32,33,38,43,48,47,46,45,40,35,36,37,42,41};
  //setar nova coluna 
  for(int i=0;i<25;i++){
    pinMode(columnPinA3[i],OUTPUT);
  }
  //desativar as layer
  for(int i=0;i<5;i++){
    digitalWrite(layerPin[i],LOW);
  }
  //CHAMANDO A FUNÇÃO ZIG ZAG PARA PODER EXECUTAR O CÓDIGO
  for (int j=0; j<5;j++){
    digitalWrite(layerPin[j],HIGH);
    ZIGZAG(columnPinA3);
    digitalWrite(layerPin[j],LOW);
  }
}
