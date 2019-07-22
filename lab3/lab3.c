/* Tyler Ewald
 * CSCI 112 Lab 3
 * 8 February 2019
 */


# include <stdio.h>     //needed for printing and scanning
# include <math.h>      //needed to use power function, to to include -lm at compile
//# include <ncurses.h>   //needed to write to output, need to include -lncurses at compile


double round(double); //global variable set for rounding to the nearest cent

//quick function for rounding numbers
double round(double number) {
    double rounded;
    rounded = floor(number * 100 + .5) / 100;
    return(rounded);
}

int main(void) {
    double principal,               // loan amount
            principalAmount,        // monthly payment for principal
            payment,                // monthly payment before rounding
            paymentFinal,           // amount of final payment
            paymentRounded,         // monthly payment after rounding
            interestMonthly,        // monthly interest
            interestAnnual,         // annual interest
            interestAmount,         // monthly interest on payment
            interestTotal = 0;      // amount paid for term of loan
    int paymentTotal,               // total number of payments
        i;                          // loop counter

    //file setup, pointer set to output file
    //FILE *output;
    //output = fopen("output.txt", "w");

    //User input
    printf("Please enter the required information pertaining to your loan:\n");
    printf("Amount borrowed (Principal): ");
    scanf("%lf", &principal);
    printf("Annual Interest(input as a decimal): ");
    scanf("%lf", &interestAnnual);
    printf("Term (number of months): ");
    scanf("%d", &paymentTotal);

    //Loan Calculations
    interestMonthly = interestAnnual / 12;
    payment = (interestMonthly * principal) / (1 - pow((1 + interestMonthly), -paymentTotal));
    paymentRounded = round(payment);

    //Loan summary that writes to the output file
    printf("Principal \t\t$%.2f\t Payment \t $%.2f", principal, paymentRounded);
    printf("\nAnnual interest \t%.1f%% \t\t Term \t\t %d months", (interestAnnual * 100), paymentTotal);

    //Loan header that writes to the output file
    printf("\n\nPayment\t\t\t\t  Interest\t\t Principal\t\t Principal Balance");
    printf("\n------------------------------------------------------------------------------------------------------");

    //for loop used to create the output table based on "i" payments, writes to output file
    for (i = 1; i < paymentTotal; ++i) {
        interestAmount = round(principal * interestMonthly);
        interestTotal += interestAmount;
        principalAmount = paymentRounded - interestAmount;
        principal -= principalAmount;
        printf("\n%5d\t\t\t\t%8.2f\t\t%8.2f\t\t%10.2f", i, interestAmount, principalAmount, principal);
    }
    //needed for final payment
    interestAmount = round(principal * interestMonthly);
    paymentFinal = interestAmount + principal;
    interestTotal += interestAmount;
    printf("\n%5d\t\t\t\t%8.2f\t\t%8.2f\t\t\t0.00", paymentTotal, interestAmount, principal);
    printf("\n\nFinal Payment\t%.2f", paymentFinal);
    printf("\n------------------------------------------------------------------------------------------------------\n");
    return(0);
}
