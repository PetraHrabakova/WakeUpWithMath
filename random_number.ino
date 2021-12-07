int random_number(int n) {       // Function that returns random number (4 types of random numbers that are used in "math_problem" function to create the problems"
  if (n == 1) {
    int a = random(1, 10);
    return a;
  }

  if (n == 2) {
    int b = random(1, 20);
    return b;
  }

  if (n == 3) {
    int c = random(1, 50);
    return c;
  }

  if (n == 4) {
    int d = random(1, 100);
    return d;
  }
}
