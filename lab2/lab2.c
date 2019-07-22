/*
* Tyler Ewald
* CSCI 112 lab 2
* 1 February 2019
*/

#include <stdio.h>
#include <math.h>
#define NUMBER 703

double bmi(double wt_lb, double ht_in) //use double weight and height arguments
{
    //bmi formula, conversion factor is set from NUMBER, power function used from math.h
    double bmi = ((NUMBER * wt_lb) / pow(ht_in, 2));

    if (bmi < 0)
    {
        printf("Error. Please try again. \n");
    }
    else if (bmi < 18.5) //first if statement to find if user is underweight
    {
        printf("Having a height of %.0f inches and a weight of %.0f lbs\n", ht_in, wt_lb);
        printf("will put your bmi at %0.1f. \n", bmi);
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi <= 24.9) //second if statement to find if user is normal
    {
        printf("Having a height of %.0f inches and a weight of %.0f lbs\n", ht_in, wt_lb);
        printf("will put your bmi at %0.1f. \n", bmi);
        printf("You are normal. \n");
    }
    else if (bmi >= 25.0 && bmi <= 29.9) //third if statement to find if user is overweight
    {
        printf("Having a height of %.0f inches and a weight of %.0f lbs\n", ht_in, wt_lb);
        printf("will put your bmi at %0.1f. \n", bmi);
        printf("You are overweight. \n");
    }
    else if (bmi >= 30.0) //final if statement to find if user is obese
    {
        printf("Having a height of %.0f inches and a weight of %.0f lbs\n", ht_in, wt_lb);
        printf("will put your bmi at %0.1f. \n", bmi);
        printf("You are obese. \n");
    }
    return 0;
}

int main() //driver for user input
{
    int wt_lb, ht_in; //user parameters

    printf("Please enter your height in inches: ");
    scanf("%d", (&ht_in));
    printf("Please enter your weight in pounds: ");
    scanf("%d", &wt_lb);
    bmi(wt_lb, ht_in);

    return 0;
}
