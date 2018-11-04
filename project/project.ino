#include "Metro.h"

Metro metro1 = Metro(500);
Metro metro2 = Metro(500);
Metro metro3 = Metro(500);
Metro metro4 = Metro(500);


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
int c0 = 28;
int c1 = 29;
int c2 = 30;
int ic = 0;

//Enderecos Elevador D
int d0 = 31;
int d1 = 32;
int d2 = 33;
int id = 0;

//Indicadores
int i11 = 34;  int i21 = 37;  int i31 = 40;  int i41 = 43;
int i12 = 35;  int i22 = 38;  int i32 = 41;  int i42 = 44;
int i13 = 36;  int i23 = 39;  int i33 = 42;  int i43 = 45;

int i51 = 46;  int i61 = 49;  int i71 = 52;
int i52 = 47;  int i62 = 50;  int i72 = 53;
int i53 = 48;  int i63 = 51;  int i73 = 4;



// botões
int a = 5;
int b = 6;
int c = 7;
int s = 8;


int filaA[20];
int filaB[20];
int filaC[20];
int filaD[20];
int nfilaA = 0;
int nfilaB = 0;
int nfilaC = 0;
int nfilaD = 0;
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

  //Enderecos Elevador C
  pinMode(c0, OUTPUT);
  pinMode(c1, OUTPUT);
  pinMode(c2, OUTPUT);

  //Enderecos Elevador D
  pinMode(d0, OUTPUT);
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);

  // botões
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(s, INPUT);

  // botões
  pinMode(i11, OUTPUT);      pinMode(i21, OUTPUT);      pinMode(i31, OUTPUT);      pinMode(i41, OUTPUT);
  pinMode(i12, OUTPUT);      pinMode(i22, OUTPUT);      pinMode(i32, OUTPUT);      pinMode(i42, OUTPUT);
  pinMode(i13, OUTPUT);      pinMode(i23, OUTPUT);      pinMode(i33, OUTPUT);      pinMode(i43, OUTPUT);
  digitalWrite(i13, HIGH);   digitalWrite(i23, HIGH);   pinMode(i33, OUTPUT);      pinMode(i43, OUTPUT);

  pinMode(i51, OUTPUT);      pinMode(i61, OUTPUT);      pinMode(i71, OUTPUT); 
  pinMode(i52, OUTPUT);      pinMode(i62, OUTPUT);      pinMode(i72, OUTPUT); 
  pinMode(i53, OUTPUT);      pinMode(i63, OUTPUT);      pinMode(i73, OUTPUT); 
  digitalWrite(i53, HIGH);   digitalWrite(i63, HIGH);   pinMode(i73, OUTPUT); 



}


void loop() {

  int a00, a01, a02, b00, b01, b02, c00, c01, c02, d00, d01, d02;


  if (metro4.check()) {
    if (filaD[0] == -1) {
      Serial.print("deu -1");
    } else if (id < filaD[0]) {
      id++;
    }
    else if (id > filaD[0]) {
      id--;
    } else {
      realocamento(filaD, id);
    }
    changePosition(id, d00, d01, d02);
    digitalWrite(d0, d00);
    digitalWrite(d1, d01);
    digitalWrite(d2, d02);
  }


  if (metro3.check()) {
    if (filaC[0] == -1) {
      Serial.print("deu -1");
    } else if (ic < filaC[0]) {
      ic++;
    }
    else if (ic > filaC[0]) {
      ic--;
    } else {
      realocamento(filaC, ic);
    }
    changePosition(ic, c00, c01, c02);
    digitalWrite(c0, c00);
    digitalWrite(c1, c01);
    digitalWrite(c2, c02);
  }



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
        indica(1, i11, i12, i13);
        break;
      } else if (arr[0] == LOW && arr[1] == LOW && arr[2] == HIGH) {
        addFila(filaB, nfilaB, 2);
        indica(2, i21, i22, i23);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == LOW) {
        addFila(filaA, nfilaA, 3);
        indica(3, i31, i32, i33);
        break;
      } else if (arr[0] == LOW && arr[1] == HIGH && arr[2] == HIGH) {
        addFila(filaB, nfilaB, 4);
        indica(4, i41, i42, i43);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == LOW) {
        addFila(filaC, nfilaC, 5);
        indica(5, i51, i52, i53);
        break;
      } else if (arr[0] == HIGH && arr[1] == LOW && arr[2] == HIGH) {
        addFila(filaC, nfilaC, 6);
        indica(6, i61, i62, i63);
        break;
      } else if (arr[0] == HIGH && arr[1] == HIGH && arr[2] == LOW) {
        addFila(filaD, nfilaD, 7);
        indica(7, i71, i72, i73);
        break;
      } else
        //        Serial.print("7");
        addFila(filaA, nfilaA, 0);
      break;
    }
  }

}





