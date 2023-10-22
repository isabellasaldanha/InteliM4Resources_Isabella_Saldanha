const int pin13out = 13;
void setup() {
  // Define o pino 13 como SAIDA
  pinMode(pin13out,OUTPUT);
}
void loop() {
  digitalWrite(pin13out, HIGH);
  delay(800);
  digitalWrite(pin13out, LOW);
  delay(800);
}

/* Para calcular o valor correto do resistor pela lei de Ohm, irei utilizar a seguinte fórmula:


R = V / I


Em que:


R = o valor do resistor que queremos encontrar
V = tensão (nesse caso, considerando o Arduino (tensão da fonte de alimentação) e o LED (tensão direta))
I = a corrente (nesse caso, do LED)


Substituindo:


R = (5V (tensão do Arduino UNO) - 2V(tensão LED)) / 20mA (corrente do LED)
R = 3V / 0,02A
R = 150Ω


Logo, o valor correto do resistor para esse circuito é de 150Ω.

*/





