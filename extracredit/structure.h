/*
* Tyler Ewald
* CSCI 112 - extra credit
* 22 April 2019
*/

#include <stdio.h>
#define MAX 100 //read list of up to 100 addresses and nicknames 

//struct declaration
typedef struct {
    int xxOne;
	int xxTwo;
	int xxThree;
	int xxFour;
    char nickname[10];
}address_t;

int scan_address(address_t add[]);
void print_address(address_t);
int local_address(address_t, address_t);
