/*
This program is used to calculste the monthly payment on a loan and the cost of borrowing the loan.
*/
#include <stdio.h>
#include <math.h>
int main() {
	//char _author_[4] = "Ning";
//identify the variables
	double amountBorrowed = 0;
	double interestRate = 0;
	int paymentNum = 0;
	double totalPayment = 0;
	double monthlyAmount = 0;
	double loanCost = 0;
//get user's input
	printf("Please enter the amount of money you borrowed: $");
	scanf("%lf",&amountBorrowed);
	printf("Please enter the annual interest rate: ");
	scanf("%lf",&interestRate);
	printf("Please enter the number of payments to be made: ");
	scanf("%d",&paymentNum);
//calculating
	monthlyAmount = interestRate/12*amountBorrowed/(1-pow((1+interestRate/12),-paymentNum));
	totalPayment = paymentNum * monthlyAmount;
	loanCost = totalPayment - amountBorrowed;
//output the result
	printf("A loan of $%.2lf with an annual interest of %.2lf payed off over %d months will have monthly payments of $%.2lf. \nIn total you will pay $%.2lf, making the cost of your loan $%.2lf.\n",amountBorrowed,interestRate,paymentNum,monthlyAmount,totalPayment,loanCost);



	return 0;
}
