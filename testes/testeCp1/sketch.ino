#define ledRed 2
#define ledGreen 3
#define ledBlue 4
#define ledYellow 5
#define botao1 6

//bool statusBt;

void setup() {
  Serial.begin(9600);

  pinMode(botao1, INPUT);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop() {
 bool statusBt1 = digitalRead(botao1);
 
 if(statusBt1 == HIGH){
  ligarSemaforo();
 }else if(statusBt1 == LOW){
  ligarLedAzul();
 }

}

void ligarSemaforo(){
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledRed, HIGH);
  delay(300);
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, HIGH);
  delay(300);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, HIGH);
}

void ligarLedAzul(){
  digitalWrite(ledRed, LOW);
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledYellow, LOW);
  digitalWrite(ledBlue, HIGH);
}
