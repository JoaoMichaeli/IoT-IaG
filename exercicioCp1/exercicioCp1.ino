/*
Sinal analógico: de 0.00 a 5.00v

Conversor Analógico Digital (Analog to Digital Converter - ADC)
(módulo dentro do chip ATMEGA328P)
Converte o valor de tensão dos pinos de A0 a A5 em um valor
decimal de 0 a 1023, por meio da função analogRead()
*/

// Variável que armazenará o valor convertido pelo ADC
int valor;

// Questão 1
#define Bt1 8
#define Bt2 9
#define Bt3 10
#define LedRedV 2
#define LedYellowV 3
#define LedGreenV 4
#define LedRedP 5
#define LedGreenP 6


void setup() {
  Serial.begin(9600); // Habilita comunicação serial do Arduino
  // Baud Rate 9600 bits/s

  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);

  pinMode(LedRedV, OUTPUT);
  pinMode(LedYellowV , OUTPUT);
  pinMode(LedGreenV , OUTPUT);
  pinMode(LedRedP , OUTPUT);
  pinMode(LedGreenP, OUTPUT);
}

void loop() {
  Serial.println("RM555678");

  fasesJuntas();
}

// Utilizando potenciometro
void exemploPotenciometro(){
  valor = analogRead(A2); // Ligação do potenciometro

  if(valor > 950) digitalWrite(LedGreenP, HIGH);
  else digitalWrite(LedGreenP, LOW);
    
  Serial.println(valor);
  delay(1000);
}

// Questão 2
void fase01(){
  digitalWrite(LedGreenV, HIGH);
  digitalWrite(LedRedP, HIGH);

  delay(5000);

  digitalWrite(LedGreenV, LOW);
  digitalWrite(LedRedP, LOW);
}

void fase02(){
  digitalWrite(LedYellowV, HIGH);
  digitalWrite(LedRedP, HIGH);

  delay(2000);

  digitalWrite(LedYellowV, LOW);
  digitalWrite(LedRedP, LOW);
}

void fase03(){
  digitalWrite(LedRedV, HIGH);
  digitalWrite(LedGreenP, HIGH);

  delay(5000);

  digitalWrite(LedRedV, LOW);
  digitalWrite(LedGreenP, LOW);
}

void fase04(){
  digitalWrite(LedRedV, HIGH);
  
  for(int i=0; i<10; i++){
    digitalWrite(LedRedP, HIGH);
    delay(200);
    digitalWrite(LedRedP, LOW);
    delay(200);
  }

  delay(3000);

  digitalWrite(LedRedV, LOW);
}

void fasesJuntas(){
  fase01();
  fase02();
  fase03();
  fase04();
}

// Questão 3
