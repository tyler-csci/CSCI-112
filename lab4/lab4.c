/* Tyler Ewald
 * CSCI 112 Lab 4
 * 22 February 2019
*/

#include <stdio.h>
#include <math.h>

//using data from the file for the array
int get_corners(int size){
  double X[size];
  double Y[size];
  int i= 0;
  for(i = 0; i < size; i++){
    scanf("%lf %lf\n", &X[i], &Y[i]);
  }
  printf("\n");
  output_corners(X, Y, size);
  polygon_area(X, Y, size);
  return(0);
}

//outputs to the file the two double arrays' contents
int output_corners(double X[], double Y[], int size){
  //value table print statement to screen
  printf("X\t Y\n");
  printf("---------------\n");
  //prints the values of the arrays
  int i;
  for(i = 0; i < size; i++){
    if((int)X[i] != 0){
      printf("\n%.2lf\t%.2lf\n", X[i], Y[i]);
    }
  }
  return(0);
}

//polygon function for calculating both X and Y arrays
int polygon_area(double X[], double Y[], int size){
  double area = 0;
  int i;
  for(i = 0; i < (size - 2); i++){
      double valueX = (X[i + 1] + X[i]);
      double valueY = (Y[i + 1] - Y[i]);
      area += (valueX * valueY);
  }
  area = fabs((0.5 * area)); //used floating point abs
  printf("---------------\n");
  printf("\nPolygon area is: %.2lf square units.\n", area);
  return(0);
}

//initiates the program, size 20 array buffer, left open for redirection
int main(void){
  get_corners(20);
  return(0);
}
