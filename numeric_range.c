/**
    @file numeric_range.c
    @author Diego Lopez 

    This program asks the user to enter two number for the begining and end
    value of a range. The program varifies that the first number is smaller than
    the second number before continuing. The program then iterates through all
    the integers in the range, determines and displays the number of integers in
    the range, displays the number of integers that are divisible by 5 OR 6 (but
    not both), displays the sum of the integers from the perivious condition as
    well as the sum of all the itegers, displays the largest integer and the
    smallest integer that satisfy the divisible by 5 or 6 condiiton, and
    calculates the average of the largest and smallest integer.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // variable declaration
  int lowNumber, highNumber, range, divisible, lowNumberSum, sumDivisible,
      sumAll, largestInt, smallestInt;
  float average;

  // do while loop to keep asking for proper input
  do {
    printf("\nEnter the low number: ");
    scanf("%d", &lowNumber);

    printf("\nEnter the high number: ");
    scanf("%d", &highNumber);
  } while (highNumber < lowNumber);
  // calclate the range (using abs to account for possible negative numbers)
  range = (abs(abs(highNumber) - abs(lowNumber)) + 1);

  printf("\n\nThe number of integers between the two numbers is %d", range);

  // calculate integers divisible by 5 or 6 but not both and sum of those
  // integers if range smaller than 6
  if (range < 6) {
    divisible = (range / 5);
    for (lowNumberSum = ((lowNumber + 1) + (range % 5));
         lowNumberSum < (range + 1); lowNumberSum += 5) {
      sumDivisible += lowNumberSum;
    }
  } else {
    // calculate integers divisible by 5 or 6 but not both and sum of those
    // integers if range larger than 5
    divisible =
        (range / 5) + (range / 6) - (range / 30) - (range / 5 && range / 6);
    for (lowNumberSum = ((lowNumber + 1) + (range % 5));
         lowNumberSum < (highNumber + 1); lowNumberSum += 5) {
      sumDivisible += lowNumberSum;
    }
    for (lowNumberSum = ((lowNumber + 1) + (range % 6));
         lowNumberSum < (highNumber + 1); lowNumberSum += 6) {
      sumDivisible += lowNumberSum;
    }
    for (lowNumberSum = ((lowNumber + 1) + (range % 30));
         lowNumberSum < (highNumber + 1); lowNumberSum += 30) {
      sumDivisible -= lowNumberSum;
    }
    for (lowNumberSum = (lowNumber + 80); lowNumberSum < (highNumber + 1);
         lowNumberSum += 80) {
      sumDivisible -= lowNumberSum;
    }
  }
  // calculate largest and smallest int based on range size
  if (range < 6) {
    largestInt = (highNumber + 1) - (range % 5);
    smallestInt = (lowNumber - 1) + (range % 5);
  } else if ((range % 5) < (range % 6)) {
    largestInt = (highNumber + 1) - (range % 5);
    smallestInt = (lowNumber - 1) + (range % 5);
  } else {
    largestInt = (highNumber + 1) - (range % 6);
    smallestInt = (lowNumber - 1) + (range % 6);
  }
  // sum of all integers
  sumAll += smallestInt;
  for (lowNumberSum = (lowNumber + 1); lowNumberSum < (highNumber + 1);
       lowNumberSum++) {
    sumAll += lowNumberSum;
  }
  // calculate average
  average = (largestInt + smallestInt) / 2.0;

  // print statments for all values
  printf("\nThere are %d integers that are divisible by 5 or 6 but not both",
         divisible);
  printf("\nThe sum of the integers that are divisible by 5 or 6 but not both "
         "is %d",
         sumDivisible);
  printf("\nThe sum of all the integers is %d", sumAll);
  printf("\nThe largest integer divisible by 5 or 6 but not both is %d",
         largestInt);
  printf("\nThe smallest integer divisible by 5 or 6 but not both is %d",
         smallestInt);
  printf("\nThe average of %d and %d is %.2f", largestInt, smallestInt,
         average);

  return 0;
}
// to compile: gcc -Wall -std=c99 numeric_range.c -o start
// to run: ./start
