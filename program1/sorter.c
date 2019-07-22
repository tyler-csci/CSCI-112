/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"


//swap function for class order
void swap(Class *prev, Class *next) {
    Class tmp;
    tmp = *prev;
    *prev = *next;
    *next = tmp;
}

//function for sorting and swapping classes 
void courseNum(Class class[], int size) {
    char header[100] = "\n\nAll CSCI classes available at MSU:\n\n";
    int i;
    int j;

    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(class[i].classNum, class[j].classNum) > 0) {
                swap(&class[i], &class[j]);
            }
        }
    }
    printFile(class, size, header, "print");
}

//function for getting classes available on MWF or TR
void getDay(Class class[], int size) {
    char input[10];
    printf("Show classes on MWF or TR? (e.g. MWF or TR):  ");
    scanf("%s", input);
    char header[100] = "\n\nClasses available on these days:\n\n";
    int i;
    int j;
    
    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(class[i].classTime, class[j].classTime) > 0) {
                swap(&class[i], &class[j]);
            }
        }
    }
    if ((strcmp(input, "MWF") == 0 || strcmp(input, "TR") == 0)) {
        printFile(class, size, header, input);
    } 
    else {
        printf("Error. Try again.\n");
        exit(1);
    }
}

//function for getting both the class time and day
void getTimeDay(Class class[], int size) {
    FILE * fp;
    fp = fopen("output.txt", "a");
    char header[100] = "\n\nClasses available at this time and day:\n\n";
    char classTime[10];
    char classDay[10];
    char tmp[10];
    char *token;
    int i = 0; 
    int j;
    int k = 0;

    //user input
    printf("What time and day would you like classes to start? (e.g: 1100 MWF):  ");
    scanf("%s %s", classTime, classDay);
    fprintf(fp, "%s", header);
    if (classDay[0] > 48 && classDay[0] < 57) {
        strcpy(tmp, classDay);
        strcpy(classDay, classTime);
        strcpy(classTime, tmp);
    }
    //print array
    for (i=0; i < size; i++) {
        token = strtok(class[i].classTime, "-");
        if (strcmp(token, classTime) == 0 && strcmp(class[i].classDay, classDay) == 0) {
            print(&class[i], fp, 0);
            k = 1;
        }
    }
    //sort and swap the array
    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(class[i].classTime, class[j].classTime) > 0) {
                swap(&class[i], &class[j]);
            }
        }
    }
    if (k==0) {
        printf("%s", "Error. Try again.\n");
		exit(1);
    }
    fclose(fp);
}

//function for getting the classes available for a given year
void getYear(Class class[], int size) {
    char header[100] = " ";
    char input[10];

    printf("What year would you like to see? (1, 2, 3, 4): ");
    scanf("%s", input);
    if (strcmp(input, "1") == 0) {
        strcpy(header, "\nClasses available for Freshmen:\n\n");
    } 
    else if (strcmp(input, "2") == 0) {
        strcpy(header, "\nClasses available for Sophomores:\n\n");
    } 
    else if (strcmp(input, "3") == 0) {
        strcpy(header, "\nClasses available for Juniors:\n\n");
    } 
    else if (strcmp(input, "4") == 0) {
        strcpy(header, "\nClasses available for Seniors:\n\n");
    } 
    else {
        printf("Error.Try again.\n");
        exit(1);
    }
    printFile(class, size, header, input);
}
