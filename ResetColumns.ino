void ResetarColunas(){
  int columnPin[25]={53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30,29};
  for(int i=0;i<25;i++){
    pinMode(columnPin[i],OUTPUT);
  }
}
