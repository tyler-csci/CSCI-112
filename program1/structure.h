/*
* Tyler Ewald
* CSCI 112 - program 1
* 12 April 2019
*/

#include <stdio.h>

typedef struct {
  char classNum[8];
  char className[50];
  char classDay[4];
  char classTime[10];
  int classYear;
} 
Class;

int printMenu();
int parse(Class classString[]);
void courseNum(Class strt[], int size);
void getDay(Class str[], int size);
void getTimeDay(Class strt[], int size);
void getYear(Class strt[], int size);
void swap(Class *a, Class *b);
void printFile(Class strt[], int size, char header[], char days[]);
void print(Class strt[], FILE *fP, int i);
