#include <Servo.h>

Servo meuServo;               // Cria um objeto Servo
int pinoInterruptorServo = 2; // Pino onde o interruptor do servo está conectado
int pinoInterruptorMotor = 4; // Pino onde o interruptor do motor DC está conectado
int estadoInterruptorServoAnterior = LOW; // Estado anterior do interruptor do servo
int estadoInterruptorMotorAnterior = LOW; // Estado anterior do interruptor do motor
int motorSpeed = 255;         // Velocidade máxima do motor DC
int ledPinServo = 8;          // Pino do LED para o servo
int ledPinMotor = 10;          // Pino do LED para o motor DC

void setup() {
  meuServo.attach(9);         // Anexa o servo ao pino 9
  pinMode(pinoInterruptorServo, INPUT_PULLUP); // Configura o pino do interruptor do servo como entrada com resistor de pull-up interno
  meuServo.write(0);          // Define a posição inicial do servo para 0 graus
  pinMode(pinoInterruptorMotor, INPUT_PULLUP); // Configura o pino do interruptor do motor como entrada com resistor de pull-up interno
  pinMode(6, OUTPUT); // Configura o pino do motor DC como saída
  pinMode(ledPinServo, OUTPUT); // Configura o pino do LED para o servo como saída
  pinMode(ledPinMotor, OUTPUT); // Configura o pino do LED para o motor DC como saída
}

void loop() {
  int estadoInterruptorServo = digitalRead(pinoInterruptorServo); // Lê o estado atual do interruptor do servo
  int estadoInterruptorMotor = digitalRead(pinoInterruptorMotor); // Lê o estado atual do interruptor do motor

  // Verifica se o interruptor do servo foi ligado (passou de LOW para HIGH)
  if (estadoInterruptorServo == HIGH && estadoInterruptorServoAnterior == LOW) {
    meuServo.write(180);    // Gira o servo para 180 graus
    digitalWrite(ledPinServo, HIGH); // Liga o LED do servo
  }

  // Verifica se o interruptor do servo foi desligado (passou de HIGH para LOW)
  if (estadoInterruptorServo == LOW && estadoInterruptorServoAnterior == HIGH) {
    meuServo.write(0);      // Retorna o servo para 0 graus
    digitalWrite(ledPinServo, LOW); // Desliga o LED do servo
  }

  estadoInterruptorServoAnterior = estadoInterruptorServo; // Atualiza o estado anterior do interruptor do servo

  // Verifica o estado do interruptor do motor para controlar o motor DC
  if (estadoInterruptorMotor == HIGH) {
    digitalWrite(6, HIGH); // Liga o motor DC
    digitalWrite(ledPinMotor, HIGH); // Liga o LED do motor DC
  } else {
    digitalWrite(6, LOW); // Desliga o motor DC
    digitalWrite(ledPinMotor, LOW); // Desliga o LED do motor DC
  }
}
