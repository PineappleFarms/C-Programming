/**
    @file calc_grades.c
    @author Diego Lopez 

    This program reads five assignment scores for 10 studnets. Calculates and
   displays: the average of every studnet, the class average, and the class'
   overall average.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  float grades[10][5];
  static float studentAvg, assignmentAvg, classAvg;

  // enter grades (fill in the array)
  for (int student = 0; student < 10; student++) {
    printf("\nEnter grades for student #%d: ", (student + 1));
    for (int i = 0; i < 5; i++) {
      scanf("%f", &grades[student][i]);
    }
  }
  // calc and display student average
  for (int student = 0; student < 10; student++) {
    printf("\nStudent #%d average: ", (student + 1));
    for (int i = 0; i < 5; i++) {
      studentAvg += grades[student][i];
     
    }
    studentAvg /= 5.0;
    printf("%.2f", studentAvg);
    studentAvg = 0;
  }
  printf("\n---------");
  // calc and display assignment average
  for (int assignment = 0; assignment < 5; assignment++) {
    printf("\nAssignment #%d average: ", (assignment + 1));
    for (int i = 0; i < 10; i++) {
      assignmentAvg += grades[i][assignment];
    }
    assignmentAvg /= 10.0;
    printf("%.2f", assignmentAvg);
    assignmentAvg = 0;
  }
  printf("\n---------");
  // calc and display class average
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 10; i++) {
      classAvg += grades[i][j];
    }
  }
  classAvg /= 50.0;
  printf("\nClass average: %.2f\n", classAvg);

  return 0;
}

// to compile: gcc -Wall -std=c99 calc_grades.c -o start
// to run: ./start