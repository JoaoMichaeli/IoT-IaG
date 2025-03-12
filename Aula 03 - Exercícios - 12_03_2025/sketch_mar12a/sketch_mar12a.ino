/*
bool statusBt1

statusBt1 = digitalRead(Bt1);
delay(100);

if(statusBt1 == 1 && flag1 == 0){
  flag1 = 1;
  delay(300);
  Serial.println("O botao foi pressionado");
}

if(statusBt1 == 0 && flag1 == 1){
  flag1 = 0;
  delay(300);
  Serial.printls("O botao foi despressionado");
}
*/

#define Bt1 8
#define Bt2 9
#define Bt3 10

#define ledGreen 2
#define ledRed 4
#define ledYellow 6



void setup() {
  Serial.begin(9600);

  pinMode(Bt1, INPUT);
  pinMode(Bt2, INPUT);
  pinMode(Bt3, INPUT);

  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);

  //Q3();
}

void loop() {
  //Q4();
  //Q5();
}

/*
  for(int i=0; i<10; i++){
    Serial.println(i);
    piscaR();
    delay(2000);
  }
*/

void piscaR(){
  digitalWrite(ledRed, HIGH);
  delay(200);
  digitalWrite(ledRed, LOW);
  delay(200);
}

//Todos os LEDs devem acender na inicialização e, após 3 segundos, devem apagar.
void Q3(){
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledRed, HIGH);
  digitalWrite(ledYellow, HIGH);

  delay(3000);

  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, LOW);
}

//Os LEDs acendem em sequência, em intervalos de 1 segundo, da direita para a esquerda (LEDs anteriores permanecem acesos)
void Q4(){
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledYellow, HIGH);
  delay(1000);

  digitalWrite(ledRed, HIGH);
  delay(1000);

  digitalWrite(ledYellow, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(1000);
}

//Os LEDs acendem em sequência, em intervalos de 1 segundo, da esquerda para a direita (LEDs anteriores devem apagar) Após 3 segundos, a sequência se reinicia.
void Q5(){
  digitalWrite(ledGreen, HIGH);
  delay(1000);
  digitalWrite(ledGreen, LOW);

  digitalWrite(ledRed, HIGH);
  delay(1000);
  digitalWrite(ledRed, LOW);

  digitalWrite(ledYellow, HIGH);
  delay(1000);
  digitalWrite(ledYellow, LOW);

  delay(3000);
}

