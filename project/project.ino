#include "Metro.h"

Metro metro1 = Metro(500);
Metro metro2 = Metro(500);

//Enderecos Elevador A
int a0 = 22;
int a1 = 23;
int a2 = 24;
int ia = 0;

//Enderecos Elevador B
int b0 = 25;
int b1 = 26;
int b2 = 27;
int ib = 0;

//Enderecos Elevador C
int b0 = 28;
int b1 = 29;
int b2 = 30;
int ib = 0;

//Enderecos Elevador D
int b0 = 31;
int b1 = 32;
int b2 = 33;
int ib = 0;



//Indicadores
int i01 = 3;
int i02 = 2;
int i03 = 4;

// botões
int a = 5;
int b = 6;
int c = 7;
int s = 8;


int filaA[20];
int filaB[20];
int nfilaA = 0;
int nfilaB = 0;
void setup() {
  Serial.begin(9600);
  //Enderecos Elevador A
  pinMode(a0, OUTPUT);
  pinMode(a1, OUTPUT);
  pinMode(a2, OUTPUT);
  
  //Enderecos Elevador B
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  
  
  // botões
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(s, INPUT);

  // botões
  pinMode(i01, OUTPUT);
  pinMode(i02, OUTPUT);
  pinMode(i03, OUTPUT);
  digitalWrite(i03, HIGH);
}


void loop() {

  int a00, a01, a02, b00, b01, b02;
  
  
    if (metro2.check()) {
    if (filaB[0] == -1) {
      Serial.print("deu -1");
    } else if (ib < filaB[0]) {
      ib++;
    }
    else if (ib > filaB[0]) {
      ib--;
    } else {
      realocamento(filaB, ib);
    }
    changePosition(ib, b00, b01, b02);
    digitalWrite(b0, b00);
    digitalWrite(b1, b01);
    digitalWrite(b2, b02);
  }
  
  

  if (metro1.check()) {
    if (filaA[0] == -1) {
      Serial.print("deu -1");
    } else if (ia < filaA[0]) {
      ia++;
    }
    else if (ia > filaA[0]) {
      ia--;
    } else {
      realocamento(filaA, ia);
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
        addFila(filaA, nfilaA, 1);
        break;
      } else if (arr[0] == LOW && arr[1] == LOW && arr[2] == HIGH) {
        addFila(filaB, nfilaB, 2);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == LOW) {
        addFila(filaA, nfilaA, 3);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == HIGH) {
        addFila(filaB, nfilaB, 4);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == LOW) {
        addFila(filaA, nfilaA, 5);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == HIGH) {
        addFila(filaA, nfilaA, 6);
        break;
      } else if (arr[0] == HIGH && arr[1] == HIGH && arr[2] == LOW) {
        
        digitalWrite(i01, HIGH);
        digitalWrite(i02, HIGH);
        digitalWrite(i03, LOW);
        addFila(filaA, nfilaA, 7);

        break;
      } else
        //        Serial.print("7");
        addFila(filaA, nfilaA, 0);
      break;
    }
  }

}





