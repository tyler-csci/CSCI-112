/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"


//parse the incoming lines of the file into the Class array structure
int parse(Class class[]) {
    char str[80];
    char *token;
    int count = 0;
    FILE *input;
    //read file
    //input = fopen("../public/csci112sp19/pgm1/classes.txt", "r");
    input = fopen("classes.txt", "r");
    if ((input = fopen("classes.txt", "r")) == NULL){
        printf("Error opening file\n");
        exit(1);
    } else {
        while(fgets(str, 79, input) != NULL) {
            //parse first token, delimiter set to first space
            token = strtok(str, " ");
            strcpy(class[count].classNum, token);

            //parse second token, delimiter set to colon
            token = strtok(NULL, ":");
            strcpy(class[count].className, token);

            //parse third token, delimiter set to space after colon
            token = strtok(NULL, " ");
            strcpy(class[count].classDay, token);

            //parse fourth token, delimiter set to space after space
            token = strtok(NULL, " ");
            strcpy(class[count].classTime, token);

            //parse fifth token, delimiter set before last space
            token = strtok(NULL, " ");
            class[count].classYear = (int)*token -48;
            count++;
        }
	}
    fclose(input);
	return count;
}
