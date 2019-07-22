
/*
 * Tyler Ewald
 * CSCI 112 - Lab 6
 * 13 March 2019
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//method for element subsets, made one single function instead of three for runtime efficiency
void get_ele_subs(char *input, int start, int length, char *result) {
    int inputString = strlen(input);

    //prints subset results
    if(strlen(result) == length) {
        printf("{%s}\n", result);
    }
    else {
        // if start is greater than string, terminate
        if(start >= inputString) {
            return;
        }
        //recursive call for picking each character in the string
        for(int i = start; i < inputString; i++) {
            char newResult[10];
            strcpy(newResult, result);
            newResult[strlen(result)] = input[i];
            newResult[strlen(result) + 1] = '\0';
            get_ele_subs(input, i + 1, length, newResult);
        }
    }
}


//main method prints to terminal
int main(void) {
    char userInput[100]; //memory size


    //gets user input, throws error if not length 4
    printf("Please enter a string: ");
    scanf("%s", userInput);

    if(strlen(userInput) != 4) {
        printf("Error. Try again\n");
        exit(0);
    }
    else {
        //prints single element subsets
        printf("one_ele_subs: \n");
        printf("( \"%s\" ) \n", userInput);
        get_ele_subs(userInput, 0, 1, "");

        //prints double element subsets
        printf("two_ele_subs: \n");
        printf("( \"%s\" ) \n", userInput);
        get_ele_subs(userInput, 0, 2, "");

        //prints triple element subsets
        printf("three_ele_subs: \n");
        printf("( \"%s\" ) \n", userInput);
        get_ele_subs(userInput, 0, 3, "");
    }
    return 0;
}
