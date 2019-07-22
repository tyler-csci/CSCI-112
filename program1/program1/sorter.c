/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"


//swap function for a data structure
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
    printOutput(class, size, header, "print");
}
//function for getting classes available on MWF or TR
void getDay(Class class[], int size) {
    printf("Show classes on MWF or TR? (e.g. MWF or TR):  ");    
    char input[10];
    scanf("%s", input);
    int i;
    int j;
    //array for sorting classes based on time
    for (i = 0; i < size; i++) {
        for (j = i ; j < size; j++) {
            if (strcmp(class[i].classTime, class[j].classTime) > 0) {
                swap(&class[i], &class[j]);
            }
        }
    }
    //get mwf classes
    if (strcmp(input, "MWF") == 0) {
        char header[100] = "\n\nClasses available on MWF:\n\n";
        printOutput(class, size, header, input);
    } 
    //get tr classes
    else if(strcmp(input, "TR") ==0) {
        char header[100] = "\n\nClasses available on TR:\n\n";
        printOutput(class, size, header, input);
    }
    //print error
    else {
        printf("Error. Try again.\n");
        exit(1);
    }
}
//function for getting both the class time and day
void getTimeDay(Class class[], int size) {
    printf("What time and day would you like classes to start? (e.g: 1100 MWF):  ");    
    FILE * fp;
    fp = fopen("output.txt", "a");
    char header[100] = "\n\nClasses available at this time and day:\n\n";
    char classTime[20];
    char classDay[20];
    char tmp[20];
    char *token;
    int i = 0; 
    int j;
    int k = 0;

    //user input
    scanf("%s %s", classTime, classDay);
    fprintf(fp, "%s", header);
    if (classDay[0] > 48 && classDay[0] < 57) {
        strcpy(tmp, classDay);
        strcpy(classDay, classTime);
        strcpy(classTime, tmp);
    }
    //print array, using "-" token for classTime (only prints start time though)
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
    printf("What year would you like to see? (1, 2, 3, 4): ");
    char header[100] = " ";
    char input[20];
    scanf("%s", input);

    //printer for freshman
    if (strcmp(input, "1") == 0) {
        strcpy(header, "\nClasses available for Freshmen:\n\n");
    } 
    //printer for sophomore
    else if (strcmp(input, "2") == 0) {
        strcpy(header, "\nClasses available for Sophomores:\n\n");
    } 
    //printer for junior
    else if (strcmp(input, "3") == 0) {
        strcpy(header, "\nClasses available for Juniors:\n\n");
    } 
    //printer for senior
    else if (strcmp(input, "4") == 0) {
        strcpy(header, "\nClasses available for Seniors:\n\n");
    } 
    //print error
    else {
        printf("Error.Try again.\n");
        exit(1);
    }
    printOutput(class, size, header, input);
}
