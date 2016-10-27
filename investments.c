#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>


double minPayInvest(double totalMoney, double owedLoan, double annualInterest, double minLoanPay, double currentAge,double retireAge,double investRate){
    double monthlyInterest = annualInterest/12;
    double monthlyInvestRate = investRate/12;
    int n = 0;
    int i = 0;
    double investReturn = 0;

    do {

        owedLoan = (owedLoan + owedLoan * monthlyInterest - minLoanPay);
        investReturn = investReturn + investReturn * monthlyInvestRate + totalMoney - minLoanPay;
        n++;
    } while (owedLoan > 0 && n != (retireAge - currentAge)*12);
    if (owedLoan<0){
        investReturn -= owedLoan;
    }
    while (i<(retireAge - currentAge)*12-n) {
        investReturn = investReturn + investReturn*monthlyInvestRate + totalMoney;
        i++;
    }
    if (owedLoan > 0){
        printf("Warning! After you retire you will still have $%.2lf in loans left.\n",owedLoan);
    }
    return investReturn;
}
double loanFirstInvest(double totalMoney, double owedLoan, double annualInterest, double minLoanPay, double currentAge,double retireAge,double investRate){
    double monthlyInterestRate = annualInterest/12;
    double monthlyInvestRate = investRate/12;
    int n = 0;
    int i = 0;
    double investReturn = 0;

    do {
        owedLoan = (owedLoan + owedLoan * monthlyInterestRate - totalMoney);
        n++;
    } while (owedLoan > 0);
    investReturn -= owedLoan;
    do {
        investReturn = investReturn + investReturn*monthlyInvestRate +totalMoney;
        i++;
    } while (i<(retireAge - currentAge)*12-n);
    return investReturn;
}
bool is_valid_formatting(int num_args_read, int num_args_needed){
	/* check if the format on the entered input is correct
		@num_args_read: the number of format specifiers filled in by scanf
		@num_args_needed: the number of format specifiers you expected to be filled in
		@returns: true if the format is correct and false otherwise
		@side effects: consumes all characters on the standard input
		*/
	char new_line = '\n';
	bool is_valid = true; //assume the format is correct
	if(num_args_read != num_args_needed){ //didn't fill in all the format specifiers
		is_valid = false;//format is not correct
	}


	do{
		scanf("%c", &new_line); //read the next character from the standard input
		if(!isspace(new_line)){ //if it isn't white space
			is_valid = false; //extra stuff there so format isn't valid
		}
	}while(new_line != '\n'); //keep reading characters until you reach the new line character
	return is_valid;
}

int main(){
    //variable
    int vrf = 0;
    double totalMoney = 0;
    double owedLoan = 0;
    double annualInterest = 0;
    double minLoanPay = 0;
    int currentAge = 0;
    int retireAge = 0;
    double annualInvestRate = 0;

    double numMinPayInvest = 0;
    double numLoanFirstInvest = 0;



    //user's input
    do {
        printf("Enter how much money you will be putting towards loans/retirement each month: ");
        vrf=scanf("%lf",&totalMoney);
    } while (!(is_valid_formatting(vrf, 1))||totalMoney<0);

    do {
        printf("Enter how much you owe in loans: ");
        vrf=scanf("%lf",&owedLoan);
    } while (!(is_valid_formatting(vrf, 1))||owedLoan<0);

    do {
        printf("Enter the annual interest rate of the loans: ");
        vrf=scanf("%lf",&annualInterest);

    } while (!(is_valid_formatting(vrf, 1))||annualInterest<0);

    do {
        printf("Enter your minimum monthly loan payment: ");
        vrf=scanf("%lf",&minLoanPay);

    } while (!(is_valid_formatting(vrf, 1))||minLoanPay<0);
    if (minLoanPay > totalMoney){
        printf("You didn't set aside enough money to pay off our loans. Ending program.\n");
        exit(0);
    }

    do {
        printf("Enter your current age: ");
        vrf=scanf("%d",&currentAge);

    } while (!(is_valid_formatting(vrf, 1))||currentAge<0);

    do {
        printf("Enter the age you plan to retire at: ");
        vrf=scanf("%d",&retireAge);

    } while (!(is_valid_formatting(vrf, 1))||retireAge<currentAge||retireAge<0);

    do {
        printf("Enter the annual rate of return you predict for your investments: ");
        vrf=scanf("%lf",&annualInvestRate);
    } while (!(is_valid_formatting(vrf, 1))||annualInvestRate<0);

    //calculating
    numMinPayInvest = minPayInvest(totalMoney,owedLoan,annualInterest,minLoanPay,currentAge,retireAge,annualInvestRate);
    numLoanFirstInvest = loanFirstInvest(totalMoney,owedLoan,annualInterest,minLoanPay,currentAge,retireAge,annualInvestRate);
    //user's output
    if (annualInterest > annualInvestRate){
        printf("You should apply all $%.2lf towards your loan before making any investments.\n",totalMoney);
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you only made minimum payments.\n",numLoanFirstInvest,numMinPayInvest);
    }
    else {
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf("If you do you will have $%.2lf when you retire as opposed to $%.2lf if you payed off your loan before investing.\n",numMinPayInvest,numLoanFirstInvest);
    }
    return 0;
}
