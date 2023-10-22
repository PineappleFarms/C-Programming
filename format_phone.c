/**
    @file format_phone.c
    @author Diego Lopez 

    This program asks the user to enter a phone number, displays the entered
    phone number, and then determines if the number is a Charlotte number or
    not.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int firstThreeDigits = 000, middleThreeDigits = 000, lastfourDigits = 0000;

  // asking user to input phone number
  printf("Enter phone number using (xxx) xxx-xxxx format: ");
  scanf("(%3d) %3d-%4d", &firstThreeDigits, &middleThreeDigits,
        &lastfourDigits);
  // check for proper format
  if (firstThreeDigits == 0 || middleThreeDigits == 0 || lastfourDigits == 0) {
    printf("\nInvalid data and/or format");
    exit(1);
  } else {
    // return entered phone number
    printf("\nYou entered: %d.%d.%d\n", firstThreeDigits, middleThreeDigits,
           lastfourDigits);

    // determine if a Charlotte phone number or not
    if (firstThreeDigits == 704) {
      printf("This is a Charlotte phone number.");
    } else {
      printf("This is NOT a Charlotte phone number.");
    }
  }
  return 0;
}
// to compile: gcc -Wall -std=c99 format_phone.c -o start
// to run: ./start
