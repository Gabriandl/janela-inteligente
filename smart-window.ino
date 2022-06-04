#include <Stepper.h> //INCLUSÃO DE BIBLIOTECA

const int stepsPerRevolution = 65; //NÚMERO DE PASSOS POR VOLTA

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11); //INICIALIZA O MOTOR UTILIZANDO OS PINOS DIGITAIS 8, 9, 10, 11

const int pinoSensor = 3; //PINO DIGITAL UTILIZADO PELO SENSOR

int lastState = 0;

void setup() {
  pinMode(pinoSensor, INPUT); //DEFINE O PINO COMO ENTRADA
  myStepper.setSpeed(300); //VELOCIDADE DO MOTOR
}

void loop() {


  if (digitalRead(pinoSensor) == LOW && digitalRead(pinoSensor) != lastState ) { //SE A LEITURA DO PINO FOR IGUAL A LOW, FAZ
    lastState = digitalRead(pinoSensor);
    for (int i = 0; i < 10; i++) { //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 10 INCREMENTA "i"
      myStepper.step(-stepsPerRevolution); //GIRA O MOTOR NO SENTIDO HORÁRIO
    }
  } else if (digitalRead(pinoSensor) == HIGH && digitalRead(pinoSensor) != lastState) { //SENÃO, FAZ
    lastState = digitalRead(pinoSensor);
    //LAÇO "for" QUE LIMITA O TEMPO EM QUE O MOTOR GIRA NO SENTIDO ANTI-HORÁRIO
    for (int i = 0; i < 10; i++) { //PARA "i" IGUAL A 0, ENQUANTO "i" MENOR QUE 10 INCREMENTA "i"
      myStepper.step(stepsPerRevolution); //GIRA O MOTOR NO SENTIDO ANTI-HORÁRIO
    }
  }



}
