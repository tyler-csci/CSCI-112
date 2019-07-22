/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"

//function for printing the structure
void printOutput(Class class[], int size, char header[], char day[]) {
    FILE * output;
    output = fopen("output.txt", "a");
    fprintf(output, "%s", header);    
    char *tkn1; 
    char *tkn2;
    int i;
    
    //start print
    if (strcmp(day, "print") == 0)  {
        for (i = 0; i < size; i++) {
            print(class, output, i);
        }
    } 
    //print MWF or TR data
    else if (strcmp(day, "MWF") == 0 || (strcmp(day, "TR") == 0)) {
        for (i = 0; i < size; i++) {
            if(strcmp(class[i].classDay, day) == 0) {
                print(class, output, i);
            }

        }
    }
    //print year data
    else if (strcmp(day, "1")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 1) {
                print(class, output, i);
            }
        }
    } 
    else if (strcmp(day, "2")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 2) {
                print(class, output, i);
            }
        }
    } 
    else if (strcmp(day, "3")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 3) {
                print(class, output, i);
            }
        }
    } 
    else if (strcmp(day, "4") == 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 4) {
                print(class, output, i);
            }
        }
    }
    //print time data
    else {
        tkn1 = strtok(day, "-");
        for (i = 0; i < size; i++) {
            tkn2 = strtok(class[i].classTime, "-");
            if(strcmp(tkn1, tkn2) == 0) {
                print(class, output, i);
            }
        }
    }
    fclose(output);
}

//function for printing data
void print(Class class[], FILE *output, int i) {
    //print format
    fprintf(output, "%-50s", class[i].className);
    fprintf(output, "%-10s", class[i].classNum);
    
    char grade[10];

    switch (class[i].classYear) {
        case 1:
            strcpy(grade, "Freshman");
            break;
        case 2:
            strcpy(grade, "Sophomore");
            break;
        case 3:
            strcpy(grade, "Junior");
            break;
        case 4:
            strcpy(grade, "Senior");
            break;
        default:
            strcpy(grade, "Error");
    }
    fprintf(output, "%-10s", grade);
    fprintf(output, "%-5s", class[i].classDay);
    fprintf(output, "%5s", class[i].classTime);
    fprintf(output, "\n");
}
