/**
    @file volume_of_cylinder.c
    @author Diego Lopez 

    This program asks the user to input the radius and height of a cylinder
    then uses the inputs to calculate the volume of the cylinder.
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float radius, height, volume;
  const double pi = 3.14159;

  // asking user to input radius and height
  printf("Enter radius: ");
  scanf("%f", &radius);

  printf("\nEnter height: ");
  scanf("%f", &height);

  // calculate volume of cylinder
  volume = (pi * ((radius * radius) * height));

  // output volume
  printf("\nVolume: %g", volume);

  return 0;
}

// to compile: gcc -Wall -std=c99 volume_of_cylinder.c -o start
// to run: ./start
