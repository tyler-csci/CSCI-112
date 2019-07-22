/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include "structure.h"


//print menu
int menu(){
  int input;
  printf("\nPlease choose from one of the following: \n\n");
  printf("1.) Print all classes by CSCI number in order of CSCI number\n");
  printf("2.) Print all classes available on MWF or available on TR in order of times\n");
  printf("3.) Print the class available at a specific time\n");
  printf("4.) Print classes available to freshman, sophomore, junior or senior \n");
  printf("5.) Quit\n");
  printf("Choose: ");
  scanf("%d", &input);
  return input;
}

//main method
int main(int argc, char **argv){
  Class arr[100];
  int output = 0;
  int length = parse(arr);
  
  //while loop with nested switch statement for choice selector 
  while(1)
  {
    output = menu();
    switch(output) {
      case 1:
        courseNum(arr, length);
        break;
      case 2:
        getDay(arr, length);
        break;
      case 3:
        getTimeDay(arr, length);
        break;
      case 4:
        getYear(arr, length);
        break;
      case 5:
        return 0;
        break;
      default:
        printf("default");
    }
  }
}


