/*
 * Tyler Ewald
 * 5 March 2019
 * CSCI 112 - lab5
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function to create string as a character pointer
char* fact_calc(int input, char* string) {
    //using dynamic memory allocation to initialize memory
    char* output = (char*)malloc(sizeof(char) * 100);
    char* number = (char*)malloc(sizeof(char) * 100);
    char* symbol = (char*)malloc(sizeof(char) * 100);
    int expression = 1;

    if (input == 1) { //special case if 1 is executed as input
        strcat(output, "**************\n");
        strcat(output, "* 1! = 1 = 1 *\n");
        strcat(output, "**************\n");
        return(output);
    }
    else if (input >= 2 && input <= 9 ) { //main case for 2 thru 9
        sprintf(string, "* %d! = ", input);
        for (int prev = input; prev > 0; prev--){ //for loop for last iteration of the expression
            //gets the last factor in the expression as well the answer
            if (prev == 1){
                sprintf(number, "%d = %d *\n", prev, expression);
                strcat(string, number);
                break;
            }
            //calculates each factor and concatenate the string and number
            expression *= prev;
            sprintf(number, "%d X ", prev);
            strcat(string, number);
        }
        //prints symbol length with association to string length
        memset(symbol, '*', strlen(string) - 1);
        strcat(symbol, "\n");
        //nests symbols with strings for output
        strcat(output, symbol);
        strcat(output, string);
        strcat(output, symbol);
        return(output);
    }
    else { //special case if 0 is executed as input
    strcat(output, "**********\n");
    strcat(output, "* 0! = 1 *\n");
    strcat(output, "**********\n");
    return(output);
    }

}

//initiates the program
int main(void){
    int input;
    char* output = (char*)malloc(sizeof(char) * 100);
    //while loop for input commands, while(1) runs til explicit break
    while (1){
        printf("Enter an integer between 0 and 9 or -1 to quit => ");
        scanf("%d",&input);
        if (input >= 0 && input <=9){
            printf("%s \n", fact_calc(input, output));
        }
        //break while(1), exit command
        else if (input == -1) {
            printf("Thank you, come again.\n\n");
            break;
        }
        else {
            printf("Invalid Input, try again.\n\n");
        }
    }
}
