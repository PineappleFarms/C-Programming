/**
    @file sorts_ints.c
    @author Diego Lopez 

    This program asks the user to enter 10 integers separated by a space. The
   program then sorts the integers into ascending order and diplays the order.
*/
#include <stdio.h>
#include <stdlib.h>

void swap(int, int);

int numArray[10];

int main(void) {
  // asking user to enter 10 integers & put in array
  printf("Please enter 10 integers separated by a space:\n");
  for (int i = 0; i < 10; i++) {
    scanf("%d", &numArray[i]);
  }

  // sorting
  for (int i = 0; i < 10; i++) {
    int j = i;
    while (j > 0 && numArray[j - 1] > numArray[j]) {
      swap(j, (j - 1));
      j--;
    }
  }

  // display array after sorting
  printf("\n\nThe list after sorting:\n");
  for (int i = 0; i < 10; i++) {
    printf("%d ", numArray[i]);
  }
  printf("\n");

  return 0;
}

// swap elements function
void swap(int x, int y) {
  int number = numArray[x];
  numArray[x] = numArray[y];
  numArray[y] = number;
  return;
}
// to compile: gcc -Wall -std=c99 sorts_ints.c -o start
// to run: ./start