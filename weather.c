/**
    @file weather.c
    @author Diego Lopez 

    This program reads 10 temperatures from the console. Stores the temperatures in an array, each representing a day in a 10-day period. Displays the highest temperature and day recorded. If more than one day ties for highest temperature both days are displayed. 
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  int temp[10];
  static int highestTemp;
 
// prompt user about program
  printf("You will be asked to enter the daily high temperature for 10 consecutive days.\n");
  
  // user enter temperature for day
  for (int i = 0; i < 10; i++){
  printf("Enter a high temperature:\n ");
  scanf("%d", &temp[i]);
    if (temp[i] > highestTemp){
      highestTemp = temp[i];
    }
    }
  // display highest temperature & days it appeared
  printf("The highest recorded temperature in the 10-day period was: %d degrees\n",highestTemp);
  printf("Recorded on the following days:");
    for (int i = 0; i < 10; i++){
      if (temp[i] == highestTemp){
      printf("\nDay %d", (i+1));
        }
    }
  
  return 0;
}

// to compile: gcc -Wall -std=c99 weather.c -o start
// to run: ./start
