void addFila(int *arr2, int narra2, int n) {
  if (narra2 < 20) {
    if (arr2[narra2] != n) {
      narra2++;
      arr2[narra2]  = n;
      Serial.print("array: \n");
      for (int i = 0; i < 20; i++) {
        int xz = arr2[i];
        Serial.print(xz);
      }        
      Serial.print("\n");
    }
  }
}


void realocamento(int * vetor, int i) {
  apagaInd(i);
  if (vetor[0] != -1) {
    for (int i = 0; i <= 7; i++) {
      vetor[i] = vetor[i + 1];
    }
  }
}
