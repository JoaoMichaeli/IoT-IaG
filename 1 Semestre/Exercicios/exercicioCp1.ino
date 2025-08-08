/*
Sinal analógico: de 0.00 a 5.00v

Conversor Analógico Digital (Analog to Digital Converter - ADC)
(módulo dentro do chip ATMEGA328P)
Converte o valor de tensão dos pinos de A0 a A5 em um valor
decimal de 0 a 1023, por meio da função analogRead()
*/

/*
Questão 01 (0.50 ponto) – Configuração de dispositivos
• Analise o diagrama proposto e utilize a diretiva #define para atribuir nomes aos pinos de I/O dos botões e dos 
LEDs.
• Utilize a função pinMode para configurar o sentido dos pinos (Utilize INPUT_PULLUP nos pinos dos botões).
• Habilite o monitor Serial com velocidade de 9600 bits/s.
• Escreva uma mensagem inicial no Monitor Serial, com os RMs dos integrantes do grupo.
*/
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

  Serial.println("RM555678");
}

void loop() {
  

  //fasesJuntas();
  Q3();
}

/*
Questão 02 (2.50 pontos)
Simule um semáforo, utilizando os cinco LEDs (três para veículos e dois para pedestres). 
• Fase 01 (duração de 5 segundos): Verde para veículos. Vermelho para pedestres.
• Fase 02 (duração de 2 segundos): Amarelo para veículos. Vermelho para pedestres.
• Fase 03 (duração de 5 segundos): Vermelho para veículos. Verde para pedestres.
• Fase 04 (duração de 3 segundos): Vermelho para veículos. Vermelho piscante para pedestres.
*/
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

/*
Questão 03 (2.00 pontos)
Leia o valor da entrada analógica e armazene em uma variável "int". Se o valor lido estiver:
• Abaixo de 300 ---> somente o LED verde da direita acende.
• Maior ou igual a 300, porém menor que 600 ---> somente o LED amarelo acende.
• Maior ou igual a 600, porém menor que 900 ---> somente o LED vermelho da direita acende.
• Maior ou igual a 900, porém menor que 1000 ---> LEDs vermelho, amarelo e verde piscam.
• Se o valor ultrapassar o 1000, os dois LEDs vermelhos piscam e o monitor Serial informa "Alarme!”
• O sistema só voltará a funcionar quando o botão RESET for pressionado ou o sistema for reiniciado.
• O monitor Serial deve apresentar o valor da variável monitorada.
*/
int valor;
void Q3(){
  valor = analogRead(A2);
  Serial.println(valor);

  if(valor < 300){
    digitalWrite(LedYellowV, LOW);
    digitalWrite(LedRedP, LOW);
    digitalWrite(LedGreenP, HIGH);
  }else if(valor >= 300 & valor < 600){
    digitalWrite(LedGreenP, LOW);
    digitalWrite(LedYellowV, HIGH);
  }else if(valor >= 600 & valor < 900){
    digitalWrite(LedYellowV, LOW);
    digitalWrite(LedRedP, HIGH);
  }else if(valor >= 900 & valor < 1000){
    for (int i = 0; i < 10; i++){
      digitalWrite(LedRedP, LOW);
      digitalWrite(LedRedV, HIGH);
      digitalWrite(LedYellowV, HIGH);
      digitalWrite(LedGreenV, HIGH);

      delay(200);

      digitalWrite(LedRedV, LOW);
      digitalWrite(LedYellowV, LOW);
      digitalWrite(LedGreenV, LOW);

      delay(200);
    }
  }else if(valor > 1000){
    digitalWrite(LedRedV, HIGH);
    digitalWrite(LedRedP, HIGH);

    Serial.println("ALARME!");
  }
}











/*
Questão 04 (2.00 pontos)
• Crie duas variáveis: limite_inf = 300 e limite_sup = 850
• Leia o valor da entrada analógica e armazene em uma variável int, chamada "VALOR" (0 a 1023).
• Condição 1 (inicial): Dois LEDs devem acender se VALOR ultrapassar o limite_sup.
• Condição 2: Uma vez ultrapassado o limite_sup, os dois LEDs só apagarão se o limite_inf for atingido.
• Condição 3: Os LEDs só voltam a acender, se o limite_sup for atingido novamente.
*/

















/*
Questão 05 (3.00 pontos)
• Quando o Arduino detectar que o estado do botão 1 passou de ligado para desligado, os dois LEDs verdes 
devem acender.
• Quando o Arduino detectar que o estado do botão 2 passou de ligado para desligado, os LEDs vermelhos 
começam a piscar. Os verdes apagam.
• Quando o Arduino detectar que o estado do botão 3 passou de ligado para desligado, os LEDs vermelhos 
apagam. Ciclo reinicia.
*/


















/*
  EXEMPLO EM SALA DO PROFESSOR SOBRE POTENCIOMENTRO
*/
void exemploPotenciometro(){
  valor = analogRead(A2); // Ligação do potenciometro

  if(valor > 950) digitalWrite(LedGreenP, HIGH);
  else digitalWrite(LedGreenP, LOW);
    
  Serial.println(valor);
  delay(1000);
}