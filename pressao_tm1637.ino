#include <Arduino.h>

#include <TM1637Display.h>
//Pinos de controle do modulo
#define CLK 4  //seleciona pino clock tm1637
#define DIO 5// seleciona pino dados tm1637
#define pressao A0  //define A0 como entrada do sinal sensor pressão

//Inicializa o display
TM1637Display display(CLK, DIO);
float valor, vall;  //variavel
void setup()
{
  pinMode(A0, INPUT); //define pino A0 como entrada
}
void loop()
{
  pinMode(13, OUTPUT);
  //Define o brilho do display
  display.setBrightness(3);//controle brilho do display tm1637
  
  //Le o valor do sensor pressão
  
  valor=(vall*700/970)-110;// converte o sinal recebido em leitura pressão
 //alterar somente o valor 700 para o valor maximo em KPA do seu sensor
  
  //onde é 700 colocar o valor maximo do seu sensor em KPA em 4,7 volts,
  //onde é 970 resolução da porta ad do arduino.//Não mudar
  //onde é 110 desconto da pressão atmosférica //Não mudar
  
  vall = analogRead(pressao);// converte o sinal recebido em leitura pressão;
  //Mostra o valor no display
  if(valor>5){
  display.showNumberDec(valor, true,3,1);// exibe valor obtido no display
    }else{
   display.showNumberDec(0, true,3,1);//estabiliza o valor em zero
   
  }
  if(valor>50){  //valor acima de 50 alarme pausado
    digitalWrite(13, HIGH);
  delay(50);
  digitalWrite(13, LOW);
  }
  if(valor>100){ //valor acima de 100 alarme continuo
   digitalWrite(13, HIGH); 
  }
  else{  //valor abaixo de 50 sem alarme
    digitalWrite(13, LOW);
  }
  delay(300);
  
}
