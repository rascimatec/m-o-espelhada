#include <Servo.h>

Servo servDedao, servIndicador, servMeio, servAnel, servMindinho;
int buttonPin = 2;
bool ordem;
char command[6];

void setup() {
  Serial.begin(9600);
  servDedao.attach(6);
  servIndicador.attach(7);
  servMeio.attach(8);
  servAnel.attach(9);
  servMindinho.attach(10);

}

void loop() {
  checkDedos();
  receberDados();
}

void receberDados() {
  for (int n = 0; n < 6; n++) {
    command[n] = Serial.read();
  }
}


void checkDedos() {
  bool i = digitalRead(buttonPin);                       //i -> Se está ligada.
  if (command[0] == '@') {
    ordem = true;
  } else if (command[0] == '&') {
    ordem = false;
  }
  if (i = true) {
    if (ordem = false) {                                 //Ordem -> Se tem algum comando para fechar/abrir dedos.
      servDedao.write(180);
      servIndicador.write(180);
      servMeio.write(180);                               //Abrir dedos.
      servAnel.write(180);
      servMindinho.write(180);
      delay(1000);
    } else {
      if (command[1] == '1') {                           //Movimentação DEDÃO.
        servDedao.write(180);
      } else {
        servDedao.write(0);
      }
      if (command[2] == '1') {                           //Movimentação INDICADOR.
        servIndicador.write(180);
      } else {
        servIndicador.write(0);
      }
      if (command[3] == '1') {                           //Movimentação MEIO.
        servMeio.write(180);
      } else {
        servMeio.write(0);
      }
      if (command[4] == '1') {                           //Movimentação ANEL.
        servAnel.write(180);
      } else {
        servAnel.write(0);
      }
      if (command[5] == '1') {                           //Movimentação MINDINHO.
        servMindinho.write(180);
      } else {
        servMindinho.write(0);
      }
    }
  } else {
    servDedao.write(0);
    servIndicador.write(0);                              //Fechar dedos.
    servMeio.write(0);
    servAnel.write(0);
    servMindinho.write(0);
    delay(1000);
  }
}
