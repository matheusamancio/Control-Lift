////

void  apagaInd(int pos) {
  switch (pos) {
    case 1:
      digitalWrite(i03, HIGH);
      break;
    case 2:
      digitalWrite(i03, HIGH);
      break;
    case 3:
      digitalWrite(i03, HIGH);
      break;
    case 4:
      digitalWrite(i03, HIGH);
      break;
    case 5:
      digitalWrite(i03, HIGH);
      break;
    case 6:
      digitalWrite(i03, HIGH);
      break;
    case 7:
      digitalWrite(i03, HIGH);
      break;
  }
}

  void indica(int pos, int & a, int & b, int & c) {
    switch (pos) {
      case 1:
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        break;
      case 2:
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        break;
      case 3:
        digitalWrite(a, LOW);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        break;
      case 4:
        digitalWrite(a, HIGH);
        digitalWrite(b, LOW);
        digitalWrite(c, LOW);
        break;
      case 5:
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        break;
      case 6:
        digitalWrite(a, LOW);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        break;
      case 7:
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
        break;
      default:
        digitalWrite(a, HIGH);
        digitalWrite(b, HIGH);
        digitalWrite(c, LOW);
    }
  }
