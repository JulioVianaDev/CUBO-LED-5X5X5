void MeuLoop(){
  Animation7();
  if (digitalRead(btSubir) == 0 ){ // verifica se o botão direito foi acionado     
    number += 1;    
    while (digitalRead(btSubir) == 0) {} // loop vazio - aguarda soltar o botão (evita a númeração constante
  }

  if (!digitalRead(btDescer)){ // verifica se o esquerdo foi acionado    
    number -= 1;             
    while (!digitalRead(btDescer)) {} // loop vazio - aguarda soltar o botão (evita a númeração constante
  }
  if (number == 1){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 1"); //Exibe a mensagem na primeira linha do display
    Animation1();
  }else if (number == 2){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 2"); //Exibe a mensagem na primeira linha do display
    Animation2();
  }else if (number == 3){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 3"); //Exibe a mensagem na primeira linha do display
    Animation3();
  }else if (number == 4){
    lcd.setCursor(0, 0); //Coloca o cursor do display na coluna 1 e linha 1
    lcd.print("Animation 4"); //Exibe a mensagem na primeira linha do display
    Animation4();
  }
  // reseta em caso de estouro (<0 ou >9)
  if (number < 0) {number = 8;}  
  if (number > 8) {number = 0;}
  
}
