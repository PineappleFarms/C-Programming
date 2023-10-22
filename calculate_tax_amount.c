/**
    @file calculate_tax_amount.c
    @author Diego Lopez 

    This program asks the user to enter their income and then calculates their
    taxes due as a floating-point number.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  // variable declaration
  int income, dependents, taxCredit;
  float taxRate, taxDue;

  // asking user to input income
  printf("Enter your income: ");
  scanf("%d", &income);
  // determine tax rate based on income bracket
  if (income >= 190150)
    taxRate = .35;
  else if (income <= 190150 && income >= 91150)
    taxRate = .30;
  else if (income <= 91150 && income >= 37650)
    taxRate = .27;
  else if (income <= 37650 && income >= 9275)
    taxRate = .17;
  else if (income <= 9275)
    taxRate = .12;

  // calculate tax due
  taxDue = income * taxRate;

  // print tax due
  printf("\nTax due = $%.2f", taxDue);

  // imput number of dependents for tax credit
  printf("\nEnter the number of dependents (0 for none) : ");
  scanf("%d", &dependents);
  // determine tax credit
  if (dependents >= 4)
    taxCredit = 2250;
  else if (dependents <= 0)
    taxCredit = 0;
  else {
    taxCredit = (450 * dependents);
  }
  // print tax credit
  printf("\nTax credit = $%d", taxCredit);

  // calcuate adjusted tax amount
  taxDue = (taxDue - taxCredit);
  // print adjusted tax amount
  printf("\nAdjusted Tax = $%.2f\n\n", taxDue);

  return 0;
}
// to compile: gcc -Wall -std=c99 calculate_tax_amount.c -o start
// to run: ./start
