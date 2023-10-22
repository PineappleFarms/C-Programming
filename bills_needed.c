/**
    @file bills_needed.c
    @author Diego Lopez 

    This program asks the user to enter an amount. The program then uses
    the input to calculate the number of USD bills needed to pay the amount.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int amount, runCount;
  const int twentyDollarBill = 20;
  const int tenDollarBill = 10;
  const int fiveDollarBill = 5;
  const int dollarBill = 1;

  // user enter dollar amount
  printf("Please enter dollar amount: ");
  scanf("%d", &amount);

  // calculate and output type and number of bills, using mod to        
  // calculate remainder
  if (amount != 0) {
    printf("\nYou need:\n");
    printf("   $20 dollar bills: %d\n", (amount / twentyDollarBill));
    amount = amount % twentyDollarBill;
    printf("   $10 dollar bills: %d\n", (amount / tenDollarBill));
    amount = amount % tenDollarBill;
    printf("    $5 dollar bills: %d\n", (amount / fiveDollarBill));
    amount = amount % fiveDollarBill;
    printf("    $1 dollar bills: %d\n\n", (amount / dollarBill));
  }

  return 0;
}

// to compile: gcc -Wall -std=c99 bills_needed.c -o start
// to run: ./start
