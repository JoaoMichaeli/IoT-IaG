/*
  Arduino UNO

  Linguagem Wiring (C++ adaptado para microcontroladores)

  Portas digitais(0-13): 
  0 - nivel lógico baixo (LOW - false) - 0 Volts
  1 - nivel lógico alto (HIGH - true) - 5 Volts
  Podem ser INPUT ou OUTPUT
*/

//Ex1: O LED ligado ao pino 5 deverá piscar em intervalos de meio segundo.
// Opção - const int LED = 5; | int LED = 5; | define LED 5;
#define LED 5


void setup() {
  // put your setup code here, to run once:

  // Configura o pino 5 como OUTPUT
  pinMode(5, OUTPUT);
  //pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Acende o LED em 5v
  digitalWrite(5, HIGH);
  //digitalWrite(LED, HIGH/1/true)
  delay(500); //500ms ou 0.5s


  // Apaga o LED em 0v
  digitalWrite(5, LOW);
  //digitalWrite(LED, LOW/0/false)
  delay(500); //500ms ou 0.5s

}
