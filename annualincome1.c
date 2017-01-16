#include <stdio.h>

int main(void){
    printf("What is your hourly wage? ");

    double income;
    scanf("%lf", &income);

    double annualdollars = income * 40 * 52;
    int an = annualdollars;
    double ac = (annualdollars - (double)an)*100;

    printf("Your total income over a year is %d dollars and %.0lf cents\n", an , ac);

    return 0;
}
