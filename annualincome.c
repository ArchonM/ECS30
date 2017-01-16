#include <stdio.h>

int main(void){
    printf("What is your hourly wage? ");

    double income;
    scanf("%lf", &income);
    double temp;
    int annualdollars = income * 40 * 52 * 100;
    temp = income * 40 * 52;
    annualdollars = temp*100;
    int an = temp;
    double ac = (temp - an)*100;

    printf("\nYour total income over a year is %d dollars and %.0lf cents\n", an , ac);

    return 0;
}
