/*
* Tyler Ewald
* CSCI 112 lab 1
* 17 January 2018
*/

#include <stdio.h>
#define RB 0.35 //sets reimbursement rate at $0.35

int
main(void)
{
          double beginOdo,  //begin odometer reading
                 endOdo,    //end odometer reading
                 mileage,   //output mileage
                 rb;        //mileage reimbursement

      //gets beginning reading
      printf("Enter beginning odometer reading=> ");
      scanf("%lf", &beginOdo);

      //gets end reading
      printf("Enter ending odometer reading=> ");
      scanf("%lf", &endOdo);

      mileage = endOdo - beginOdo;  //caclulates total mileage
      rb = RB * mileage;            //calculates mileage reimbursement

      //prints miles traveled
      printf("You traveled %.2f miles.    At $0.35 per mile,\n", mileage);
      //prints mileage reimbursement
      printf("your reimbursement is $%.2f.\n", rb);

      return (0);
}

