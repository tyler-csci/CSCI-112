/*
* Tyler Ewald
* CSCI 112 - extra credit
* 22 April 2019
*/

#include <stdio.h>
#include <string.h>
#include "structure.h"

//method for getting IP tokens and scanning thru till '0 0 0 0 none'
int scan_address(address_t length[100]) {
    FILE *input = fopen("ipaddresses.txt", "r");
	int i = 0;

	while (input != NULL) {
		int compare = fscanf(input, "%d.%d.%d.%d %s", &length[i].xxOne, &length[i].xxTwo, &length[i].xxThree, &length[i].xxFour, length[i].nickname);
		if (compare != 0) {
            if(compare == 5) {
                if(length[i].xxOne == 0 && length[i].xxTwo == 0 && length[i].xxThree == 0 && length[i].xxFour == 0)
            	break;
				i++;
            }
			else {
				return 0;
			}
        }
		else {
			printf("Error. Try again\n");
		}
    }
    fclose(input);
    return(i--);
}

//returns true if IP's are on the same local network
int local_address(address_t current, address_t next) {
    int match = 0;
    if (current.xxOne == next.xxOne) {
        match = 1;
    }
	if (current.xxTwo == next.xxTwo){
		match = 1;
	}
    return match;
}

//print IP address
void print_address(address_t add) {
    printf("%d.%d.%d.%d %s\n", add.xxOne, add.xxTwo, add.xxThree, add.xxFour, add.nickname);
}

//main method
int main(void) {
	address_t length[10];
	int count = scan_address(length);
	int i;
	int j;
	//2d array for element display
    for(i = 0; i < count; i++) {
        for(j = i + 1; j < count; j++) {
            int result = local_address(length[i], length[j]);
            if(result) {
                printf("\nMachines %s and %s are on the same local network.\n", length[i].nickname, length[j].nickname);
                print_address(length[i]);
                print_address(length[j]);
            }
        }
    }
return(0);
}