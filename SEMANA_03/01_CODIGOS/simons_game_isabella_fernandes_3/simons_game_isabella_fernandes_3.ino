#define buzzer 21
#define sequencia 4
const byte leds[] = { 27, 32, 33, 25 };
const byte botoes[] = { 4, 2, 17, 5, 22 };
const byte botaoReset = 22;
const int tons[] = { 262, 294, 330, 349 };

byte sequenciaAtual[sequencia] = { 0 };
byte jogadaAtual = 0;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
const long intervalo = 300;

void setup() {
  for (byte i = 0; i < 4; i++) {
    pinMode(leds[i], OUTPUT);
    pinMode(botoes[i], INPUT_PULLUP);
  }
  pinMode(botaoReset, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(A0));
}

void ligarLed(byte posicaoLed) {
  digitalWrite(leds[posicaoLed], HIGH);
  tone(buzzer, tons[posicaoLed]);
  unsigned long ledInicio = millis();
  while (millis() - ledInicio < 300) {
  }
  digitalWrite(leds[posicaoLed], LOW);
  noTone(buzzer);
}

void ligarSequencia() {
  for (int i = 0; i < jogadaAtual; i++) {
    byte ledAtual = sequenciaAtual[i];
    ligarLed(ledAtual);
    unsigned long inicioSequencia = millis();
    while (millis() - inicioSequencia < 50) {
    }
  }
  if (digitalRead(botaoReset) == HIGH) {
    Serial.print("Botão reset pressionado");
  }
}

byte verificarBotao() {
  unsigned long inicioVerificacaoBotao = millis();
  while (true) {
    for (byte i = 0; i < 5; i++) {
      byte botaoPressionado = digitalRead(botoes[i]);
      if (botaoPressionado == LOW) {
        return i;
      }
    }
    if (millis() - inicioVerificacaoBotao >= 1) {
    }
  }
}

void game_over() {
  Serial.print("Você perdeu, sua pontuação foi:");
  Serial.println(jogadaAtual - 1);
  jogadaAtual = 0;
  unsigned long inicioGameOver = millis();
  while (millis() - inicioGameOver < 200) {
  }

  tone(buzzer, 70);
  unsigned long inicioBuzzer = millis();
  while (millis() - inicioBuzzer < 300) {
  }

  noTone(buzzer);
  unsigned long inicioAtraso = millis();
  while (millis() - inicioAtraso < 500) {
  }
}

bool verificacao() {
  for (int i = 0; i < jogadaAtual; i++) {
    byte botaoCorreto = sequenciaAtual[i];
    byte botaoPressionado = verificarBotao();
    ligarLed(botaoPressionado);
    if (botaoCorreto != botaoPressionado) {
      return false;
    }
  }
  return true;
}

void musicaJogo() {
  tone(buzzer, 262);
  unsigned long inicioTone = millis();
  while (millis() - inicioTone < 150) {
  }
  tone(buzzer, 294);
  inicioTone = millis();
  while (millis() - inicioTone < 150) {
  }
  tone(buzzer, 330);
  inicioTone = millis();
  while (millis() - inicioTone < 150) {
  }
  tone(buzzer, 349);
  inicioTone = millis();
  while (millis() - inicioTone < 150) {
  }
  noTone(buzzer);
}

void loop() {
  currentMillis = millis();

  if (digitalRead(botaoReset) == LOW) {
    jogadaAtual = 0;
    previousMillis = currentMillis;
  }

  if (currentMillis - previousMillis >= intervalo) {
    previousMillis = currentMillis;
    sequenciaAtual[jogadaAtual] = random(0, 4);
    ligarSequencia();
    if (!verificacao()) {
      game_over();
    }
    jogadaAtual++;
  }

  if (jogadaAtual > 0) {
    musicaJogo();
    unsigned long inicioMusica = millis();
    while (millis() - inicioMusica < 300) {
    }
  }
  
  if (jogadaAtual == 5) {
    game_over();
  }
}