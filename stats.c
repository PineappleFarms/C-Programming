/*********************************************************
 * Diego Lopez
 *
 * stats.c - This program reads in a set of numbers into an
 * array, and then computes some standard statistics on the numbers.
 *********************************************************/
#include <stdio.h>
#include <stdlib.h>

int main();
double sum(double array[]);
double maxOrMin(double array[], int n, int k);
double arithmeticOrHarmonicMean(double a, double b, int x);
double var(double array[], double a, double b);

double num[] = {};
double numbers;
static int count = 0;
double *p = &num[0];

int main() {

  double sumFinal, max, min, arithmeticMean, harmonicMean, variance;
  double holder;

  // Read in the numbers and assign to array
  // Read till EOF
  scanf(" %lf ", &holder);
  while (holder != EOF) {
    int i = 0;

    // ignore values of 0
    if (holder != 0) {

      // input into array using pointers
      *(p + i) = holder;
      i++;

      scanf(" %lf ", &holder);

      // Test each input
      // printf("%lf\n",holder);
    }
  }

  // set count to size of array
  count = sizeof(num);

  // Test count and array
  // printf("***%d****\n",count);
  // for(int i = 0; i < count; i++){
  // printf(" %lf ", num[i]);
  //   }

  // Function calls for all statistics
  sumFinal = sum(num);
  max = maxOrMin(num, count, 0);
  min = maxOrMin(num, count, 1);
  arithmeticMean = arithmeticOrHarmonicMean(count, sumFinal, 0);
  harmonicMean = arithmeticOrHarmonicMean(count, sumFinal, 1);
  variance = var(num, sumFinal, count);

  // output for all statistics
  printf("The count of numbers read from the input is %9d\n", count);
  printf("The sum of these numbers is %20.10f\n", sumFinal);
  printf("The max and the min of these numbers are %20.10f and %20.10f\n", max,
         min);
  printf("The arithmetic and harmonic means are %20.10f and %20.10f\n",
         arithmeticMean, harmonicMean);
  printf("The variance is %20.10f\n", variance);

  return 0;
}

/*
 * This function returns the sum of all values in the array.
 */
double sum(double array[]) {
  double x = 0;

  for (int i = 0; i < count; i++) {
    x += num[i];
  }
  // Test sum
  // printf("%f\n", x);

  return (x);
}

/*
 * This function returns the max or min of the array values.
 */

double maxOrMin(double array[], int n, int k) {

  int count = n;
  int maxOrMin = k;
  double holder = array[0];
  double max = 0.0, min = 0.0;

  if (maxOrMin == 0) {
    for (int i = 1; i < count; i++) {
      if (array[i] > holder) {
        max = array[i];
      }
    }
    return max;
  }

  if (maxOrMin == 1) {
    for (int i = 1; i < count; i++) {
      if (array[i] < holder) {
        min = array[i];
      }
    }
    return min;
  }

  return 0;
}

/*
 * This function returns the arithmetic or harmonic mean.
 */
double arithmeticOrHarmonicMean(double a, double b, int x) {

  double count = a;
  double sum = b;
  int arithOrHarmMean = x;

  if (arithOrHarmMean == 0) {
    double arithmeticMean = (1.0 / a) * sum;
    return arithmeticMean;
  }

  static double total;
  if (arithOrHarmMean == 1) {

    for (int i = 0; i < count; i++) {
      total = total + (1.0 / num[i]);
    }

    double harmonicMean = 0.0;
    harmonicMean = count / total;
    return harmonicMean;
  }
  return 0;
}

/*
 * This function returns the variance.
 */
double var(double array[], double a, double b) {

  double mean = a / b;

  double sd;
  double squareSd;
  double sumSquareSd = 0.0;

  for (int i = 0; i < count; i++) {

    sd = (num[i] - mean);
    squareSd = sd * sd;
    sumSquareSd = sumSquareSd + squareSd;
  }

  return (sumSquareSd / b);
}

// Used to Test Program on Replit:
// to compile: gcc -Wall -std=c99 stats.c -o start3
// to run: ./start3
  //Then type       ./start3 < Input_stats.txt 
