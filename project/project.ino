#include "Metro.h"

Metro metro1 = Metro(500);

//Enderecos Elevador A
int a0 = 38;
int a1 = 39;
int a2 = 40;
int ia = 0;


// botões
int a = 5;
int b = 6;
int c = 7;
int s = 8;
int fila1[20];
int nfila1 = 0;
void setup() {
  Serial.begin(9600);
  //Enderecos Elevador A
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  // botões
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(s, INPUT);
}


void loop() {

  int a00, a01, a02, b00, b01, b02;

  if (metro1.check()) {
    if (fila1[0] == -1) {
      Serial.print("deu -1");
    } else if (ia < fila1[0]) {
      ia++;
    }
    else if (ia > fila1[0]) {
      ia--;
    } else {
      realocamento(fila1);
    }
    changePosition(ia, a00, a01, a02);
    digitalWrite(a0, a00);
    digitalWrite(a1, a01);
    digitalWrite(a2, a02);
  }



  // botões
  int a1, b1, c1;
  for (int i = 0; i <= 7; i++) {
    verifica(i, a1, b1, c1);
    digitalWrite(a, a1);
    digitalWrite(b, b1);
    digitalWrite(c, c1);
    if (digitalRead(s) == HIGH) {
      int arr[3] = {c1, b1, a1};
      if (arr[0] == LOW && arr[1] == LOW && arr[2] == LOW) {
        //        Serial.print("0");
        addFila(fila1, nfila1, 1);
        break;
      } else if (arr[0] == LOW && arr[1] == LOW && arr[2] == HIGH) {
        //        Serial.print("1");
        addFila(fila1, nfila1, 2);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == LOW) {
        //        Serial.print("2");
        addFila(fila1, nfila1, 3);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == HIGH) {
        //        Serial.print("3");
        addFila(fila1, nfila1, 4);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == LOW) {
        //        Serial.print("4");
        addFila(fila1, nfila1, 5);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == HIGH) {
        //        Serial.print("5");
        addFila(fila1, nfila1, 6);
        break;
      } else if (arr[0] == HIGH && arr[1] == HIGH && arr[2] == LOW) {
        //        Serial.print("6");
        addFila(fila1, nfila1, 7);
        break;
      } else
        //        Serial.print("7");
        addFila(fila1, nfila1, 0);
      break;
    }
  }

}





