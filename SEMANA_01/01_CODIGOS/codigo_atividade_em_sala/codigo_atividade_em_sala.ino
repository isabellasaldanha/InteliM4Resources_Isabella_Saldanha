const int pin25out = 25;
const int pin33out = 33;
const int pin27out = 27;
void setup() {
  // Define o pino 25 como SAIDA
  pinMode(pin25out,OUTPUT);
  pinMode(pin33out,OUTPUT);
  pinMode(pin27out,OUTPUT);
  // Inicializa a porta serial de com. com o ESP32
  Serial.begin(115200);
  Serial.println("Iniciando a serial");
}
void loop() {
  digitalWrite(pin25out, HIGH);
  delay(100);
  digitalWrite(pin33out, HIGH);
  delay(100);
  digitalWrite(pin27out, HIGH);
  delay(100);
  digitalWrite(pin25out, LOW);
  delay(100);
  digitalWrite(pin33out, LOW);
  delay(100);
  digitalWrite(pin27out, LOW);
  delay(100);
}









