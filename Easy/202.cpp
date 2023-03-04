bool isHappy(int n){
  if (n == 1) {
    return true;
  }

  while (n > 6) {
    int sum = 0;
    int m = n;
    while (m > 0) {
      sum += pow(m % 10, 2);
      m /= 10;
    }

    n = sum;

    if (n == 1) {
      return true;
    }
  }

  return false;
}
