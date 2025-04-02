// Atribuir nomes aos pinos

// Botões
#define BT1 8
#define BT2 9

// LEDs
#define ledG 2
#define ledR 4
#define ledY 6

void setup() {
  // Habilitar porta serial
  // Baud Rate (9600 bits/s) padrão UNO
  Serial.begin(9600);
  // Configurar o sentido dos pinos de I/O
  pinMode(BT1, INPUT);
  pinMode(BT2, INPUT);

  pinMode(ledG, OUTPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);

}

void loop() {
  if(digitalRead(BT1) == HIGH){
    Serial.println("BT1 Ligado!!!");
    piscaGR();
  }
  else if(digitalRead(BT2) == HIGH){
    Serial.println("BT2 Ligado!!!");
    piscaAll();
  }
  else{
    piscaY();
  }
}

void piscaGR(){
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, LOW);
  delay(250);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  delay(250);
  
}

void piscaY(){
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
  digitalWrite(ledY, HIGH);
  delay(350);
  digitalWrite(ledY, LOW);
  delay(350);
}

void piscaAll(){
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, HIGH);
  digitalWrite(ledY, HIGH);
}