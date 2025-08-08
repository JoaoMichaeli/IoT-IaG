/*
Exemplo 1: Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.

Exemplo 2: Os LEDs vermelhos e verdes deverão piscar alternadamente em intervalos de 400ms.

Exemplo 3: Crie um código para simular um semáforo: Verde -> 4seg | Amarelo -> 1 seg | Vermelho -> 6 seg

*/

// Atribuição de nomes aos pinos dos LEDs
#define LedRed 12
#define LedYel 10
#define LedGre 8


void setup() {
  // Configuração dos pinos dos LEDs
  // Como saída (OUTPUT)
  pinMode(LedRed, OUTPUT);
  pinMode(LedYel, OUTPUT);
  pinMode(LedGre, OUTPUT);
}

void loop() {
  //ex1();
  //ex2();
  ex3();

}

void ex1(){
//Exemplo 1: Os três LEDs deverão piscar simultaneamente em intervalos de 300ms.
digitalWrite(LedRed, HIGH);
digitalWrite(LedYel, HIGH);
digitalWrite(LedGre, HIGH);
delay(300);
digitalWrite(LedRed, LOW);
digitalWrite(LedYel, LOW);
digitalWrite(LedGre, LOW);
delay(300);
}

void ex2(){
//Exemplo 2: Os LEDs vermelhos e verdes deverão piscar alternadamente em intervalos de 400ms.
digitalWrite(LedRed, HIGH);
digitalWrite(LedGre, LOW);
delay(400);
digitalWrite(LedRed, LOW);
digitalWrite(LedGre, HIGH);
delay(400);
}

void ex3(){
//Exemplo 3: Crie um código para simular um semáforo: Verde -> 4seg | Amarelo -> 1 seg | Vermelho -> 6 seg
digitalWrite(LedRed, LOW);
digitalWrite(LedGre, HIGH);
delay(4000);
digitalWrite(LedGre, LOW);
digitalWrite(LedYel, HIGH);
delay(1000);
digitalWrite(LedYel, LOW);
digitalWrite(LedRed, HIGH);
delay(6000);
}
