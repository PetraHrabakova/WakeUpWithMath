int * math_problem(int j) {        // This function generates 5 types of math problems using 4 types of random numbers
  static int result[1];            // Holds the right result of the random numbers
  int number[3];                   // Hold the random number in an array

  if (j == 1) {
    number[0] = random_number(3);   // Saves first random number in an array
    number[1] = random_number(3);   // Saves seconds random number in an array

    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print(number[0]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" + ");
    gfx.print(number[1]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" =");
    int e = number[0] + number[1];  // Solves the math problem
    result[0] = e;                  // And saves it on the first position of the array
  }

  if (j == 2) {
    number[0] = random_number(4);   // Saves first random number in an array
    number[1] = random_number(4);   // Saves second random number in an array

    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print(number[0]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" + ");
    gfx.print(number[1]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" =");

    int e = number[0] + number[1];  // Solves the math problem
    result[0] = e;                  // And saves it on the first position of the array
  }

  if (j == 3) {
    number[0] = random_number(1);   // Saves first random number in an array
    number[1] = random_number(2);   // Saves second random number in an array
    number[2] = random_number(1);   // Saves third random number in an array


    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print("(");
    gfx.print(number[0]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" + ");
    gfx.print(number[1]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(")");
    gfx.print(" * ");
    gfx.print(number[2]);           // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" =");

    int e = (number[0] + number[1]) * number[2];  // Solves the math problem
    result[0] = e;                                // And saves it on the first position of the array
  }

  if (j == 4) {
    number[0] = random_number(2);     // Saves first random number in an array
    number[1] = random_number(5);     // Saves second random number in an array
    number[2] = random_number(1);     // Saves third random number in an array

    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print("(");
    gfx.print(number[0]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" + ");
    gfx.print(number[1]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(")");
    gfx.print(" * ");
    gfx.print(number[2]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" =");

    int e = (number[0] + number[1]) * number[2];    // Solves the math problem
    result[0] = e;                                  // And saves it on the first position of the array
  }

  if (j == 5) {
    number[0] = random_number(3);   // Saves first random number in an array
    number[1] = random_number(5);   // Saves second random number in an array
    number[2] = random_number(1);   // Saves third random number in an array

    gfx.TextSize(2);
    gfx.MoveTo(20, 20);
    gfx.print("(");
    gfx.print(number[0]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" + ");
    gfx.print(number[1]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(")");
    gfx.print(" * ");
    gfx.print(number[2]);   // Prints that random number from the array, this way I make sure the displayd random number is the same as the one used when calculating the result
    gfx.print(" =");

    int e = (number[0] + number[1]) * number[2];    // Solves the math problem
    result[0] = e;                                  // And saves it on the first position of the array
  }
}
