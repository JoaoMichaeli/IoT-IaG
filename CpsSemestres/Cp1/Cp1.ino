// Placa Esquerda
#define LedRedV1 13
#define LedYellowV1 12
#define LedGreenV1 11
#define LedRedP1 10
#define LedGreenP1 9

// Placa Direita
#define LedRedV2 8
#define LedYellowV2 7
#define LedGreenV2 6
#define LedRedP2 5
#define LedGreenP2 4

// Botoes
#define Bt1 14
#define Bt2 2
#define Bt3 3

// Variaveis globais
int valor;
bool flag1, statusBt1;
bool flag2, statusBt2;
bool flag3, statusBt3;


void setup() {
  Serial.begin(9600);

  for (int i = 4; i <= 13; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);

  Serial.println("Rm555678 | Rm554456");
}


void loop() {
  // REMOVA O COMENTÁRIO DA QUESTÃO QUE QUER TESTAR

  //questao2();
  // questao3();
  // questao4();
  questao5();
}

void questao2() {
  desligaLeds();
  //Fase 01
  // Sem1
  digitalWrite(LedGreenV1, HIGH);
  digitalWrite(LedRedP1, HIGH);
  // Sem 2
  digitalWrite(LedRedV2, HIGH);
  digitalWrite(LedGreenP2, HIGH);

  delay(5000);
  digitalWrite(LedGreenV1, LOW);
  digitalWrite(LedRedP1, LOW);

  digitalWrite(LedRedV2, LOW);
  digitalWrite(LedGreenP2, LOW);
  // Fase 02
  // Sem1
  digitalWrite(LedYellowV1, HIGH);
  digitalWrite(LedRedP1, HIGH);
  // Sem2
  digitalWrite(LedYellowV2, HIGH);
  for (int i = 0; i < 4; i++) {
    digitalWrite(LedRedP2, HIGH);
    delay(400);
    digitalWrite(LedRedP2, LOW);
    delay(400);
  }
  digitalWrite(LedRedP2, HIGH);
  // delay(2000); SUBSTITUI O DELAY PELO LED PISCANDO 10X
  digitalWrite(LedYellowV1, LOW);
  digitalWrite(LedRedP1, LOW);

  digitalWrite(LedYellowV2, LOW);
  // digitalWrite(LedRedP2, LOW);

  // Fase 03
  // Sem 1
  digitalWrite(LedRedV1, HIGH);
  digitalWrite(LedGreenP1, HIGH);
  // Sem 2
  digitalWrite(LedGreenV2, HIGH);
  digitalWrite(LedRedP2, HIGH);

  delay(5000);
  digitalWrite(LedRedV1, LOW);
  digitalWrite(LedGreenP1, LOW);
  // Fase 04
  // Sem 1
  digitalWrite(LedRedV1, HIGH);

  for (int i = 0; i < 4; i++) {
    digitalWrite(LedRedP1, HIGH);
    delay(400);
    digitalWrite(LedRedP1, LOW);
    delay(400);
  }
  digitalWrite(LedRedV1, LOW);
  digitalWrite(LedGreenV2, LOW);
  digitalWrite(LedRedP2, LOW);
}

void desligaLeds() {
  for (int i = 4; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}

void questao3() {
  valor = analogRead(A4);
  Serial.println(valor);

  if (valor < 200) {
    digitalWrite(LedYellowV1, LOW);
    digitalWrite(LedRedP1, LOW);
    digitalWrite(LedGreenP1, HIGH);
  } else if (valor >= 200 & valor < 650) {
    digitalWrite(LedRedP1, LOW);
    digitalWrite(LedGreenP1, LOW);
    digitalWrite(LedYellowV1, HIGH);
  } else if (valor >= 650 & valor < 950) {
    digitalWrite(LedYellowV1, LOW);
    digitalWrite(LedRedP1, HIGH);
  } else if (valor > 950 & valor < 1000) {
    digitalWrite(LedRedP1, LOW);
    for (int i = 0; i < 3; i++) {
      digitalWrite(LedRedV1, HIGH);
      digitalWrite(LedRedP1, HIGH);
      digitalWrite(LedYellowV1, HIGH);
      digitalWrite(LedGreenV1, HIGH);
      digitalWrite(LedGreenP1, HIGH);

      delay(200);

      digitalWrite(LedRedV1, LOW);
      digitalWrite(LedRedP1, LOW);
      digitalWrite(LedYellowV1, LOW);
      digitalWrite(LedGreenV1, LOW);
      digitalWrite(LedGreenP1, LOW);

      delay(200);
    }
  } else if (valor > 1000) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(LedRedV1, HIGH);
      digitalWrite(LedRedP1, HIGH);

      delay(200);

      digitalWrite(LedRedV1, LOW);
      digitalWrite(LedRedP1, LOW);

      delay(200);
    }
    Serial.print("ALARME!!!");
  }
}

void questao4() {
  int limite_inf = 100;
  int limite_sup = 950;

  valor = analogRead(A4);
  Serial.println(valor);

  if (valor > limite_sup) {
    digitalWrite(LedRedV1, HIGH);
    digitalWrite(LedYellowV1, HIGH);
  } else if (valor == limite_inf) {
    digitalWrite(LedRedV1, LOW);
    digitalWrite(LedYellowV1, LOW);
  } else if (valor > limite_sup) {
    digitalWrite(LedRedV1, HIGH);
    digitalWrite(LedYellowV1, HIGH);
  } else if (valor < limite_inf) {
    digitalWrite(LedRedV1, LOW);
    digitalWrite(LedYellowV1, LOW);
  }
}

/*
  Questao 5
 
• Etapa 1: Quando o Arduino detectar que o estado do botão 1 passou de ligado para desligado (PULSO),
  os dois LEDs verdes devem acender.
• Etapa 2: Quando o Arduino detectar que o estado do botão 2 passou de ligado para desligado (PULSO),
  os LEDs vermelhos começam a piscar. Os verdes apagam.
• Etapa 3: Quando o Arduino detectar que o estado do botão 3 passou de ligado para desligado (PULSO),
  os LEDs vermelhos apagam. Ciclo reinicia.
*/

void questao5() {
  // Insira aqui o código da questão 05
  // Etapa 01
  statusBt1 = digitalRead(Bt1);
  delay(100);

  if (statusBt1 == 1 && flag1 == 0) {
    Serial.println("Botão 1 foi pressionado");
    flag1 = 1;
  }
  if (statusBt1 == 0 && flag1 == 1) {
    Serial.println("Botão 1 foi desligado");
    flag1 = 0;
    digitalWrite(LedGreenV1, HIGH);
    digitalWrite(LedGreenP1, HIGH);
  }

  // Etapa 2
  statusBt2 = digitalRead(Bt2);

  delay(100);

  if (statusBt2 == 1 && flag2 == 0) {
    Serial.println("Botão 2 foi pressionado");
    flag2 = 1;
  }
  if (statusBt2 == 0 && flag2 == 1) {
    Serial.println("Botão 2 foi desligado");
    flag2 = 0;
    digitalWrite(LedGreenV1, LOW);
    digitalWrite(LedGreenP1, LOW);
    while (flag3 == 0 && statusBt3 == 0) {
      statusBt3 = digitalRead(Bt3);
      delay(100);
      if (statusBt3 == 1 && flag3 == 0) {
        Serial.println("Botão 3 foi pressionado");
        flag3 = 1;
      }
      if (statusBt3 == 0 && flag3 == 1) {
        Serial.println("Botão 3 foi desligado");
        flag3 = 0;
      }
      digitalWrite(LedRedP1, HIGH);
      digitalWrite(LedRedV1, HIGH);
      delay(500);
      digitalWrite(LedRedP1, LOW);
      digitalWrite(LedRedV1, LOW);
      delay(500);
    }
  }

}