void verifica(int pos, int & a, int & b, int & c) {
  switch (pos) {
    case 0:
      a = LOW;
      b = LOW;
      c = LOW;
      break;
    case 1:
      a = LOW;
      b = LOW;
      c = HIGH;
      break;
    case 2:
      a = LOW;
      b = HIGH;
      c = LOW;
      break;
    case 3:
      a = LOW;
      b = HIGH;
      c = HIGH;
      break;
    case 4:
      a = HIGH;
      b = LOW;
      c = LOW;
      break;
    case 5:
      a = HIGH;
      b = LOW;
      c = HIGH;
      break;
    case 6:
      a = HIGH;
      b = HIGH;
      c = LOW;
      break;
    case 7:
      a = HIGH;
      b = HIGH;
      c = HIGH;
      break;
    default:
      a = LOW;
      b = HIGH;
      c = HIGH;
  }
}
