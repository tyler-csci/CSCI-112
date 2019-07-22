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
void printFile(Class class[], int size, char header[], char day[]) {
    FILE * fp;
    fp = fopen("output.txt", "a");
    fprintf(fp, "%s", header);    

    char *time1; 
    char *time2;
    int i;
    
    //start print
    if (strcmp(day, "print") == 0)  {
        for (i = 0; i < size; i++) {
            print(class, fp, i);
        }
    } 
    //print MWF or TR data
    else if (strcmp(day, "MWF") == 0 || (strcmp(day, "TR") == 0)) {
        for (i = 0; i < size; i++) {
            if(strcmp(class[i].classDay, day) == 0) {
                print(class, fp, i);
            }

        }
    }
    //print year data
    else if (strcmp(day, "1")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 1) {
                print(class, fp, i);
            }
        }
    } 
    else if (strcmp(day, "2")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 2) {
                print(class, fp, i);
            }
        }
    } 
    else if (strcmp(day, "3")== 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 3) {
                print(class, fp, i);
            }
        }
    } 
    else if (strcmp(day, "4") == 0) {
        for (i = 0; i < size; i++) {
            if(class[i].classYear == 4) {
                print(class, fp, i);
            }
        }
    }
    //print time data
    else {
        time1 = strtok(day, "-");
        for (i = 0; i < size; i++) {
            time2 = strtok(class[i].classTime, "-");
            if(strcmp(time1, time2) == 0) {
                print(class, fp, i);
            }
        }
    }
    fclose(fp);
}

//function for printing data
void print(Class class[], FILE *fp, int i) {
    //print format
    fprintf(fp, "%-50s", class[i].className);
    fprintf(fp, "%-10s", class[i].classNum);
    
    char grade[30];

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
    fprintf(fp, "%-10s", grade);
    fprintf(fp, "%-4s", class[i].classDay);
    fprintf(fp, "%5s", class[i].classTime);
    fprintf(fp, "\n");
}
