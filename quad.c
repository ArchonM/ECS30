/*this program is used to solve the roors for a quadratic equation*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool verify(double a, double b, double c);
double solveForX_1(double a,double b,double c);
double solveForX_2(double a,double b,double c);

int main(void)
{
	double a = 0;
	double b = 0;
	double c = 0;
	double x_1 = 0;
	double x_2 = 0;
	double resultDouble = 0;	
	printf("Given a quadratic equation of the form a*x^2 + b * x + c\nPlease enter a: ");\
	scanf("%lf", &a);
	printf("Please enter b: ");
	scanf("%lf", &b);
	printf("Please enter c: ");
	scanf("%lf", &c);
	resultDouble = b*b-4*a*c;
	if (verify(a,b,c)) {
		if  (resultDouble == 0) {
			x_1=solveForX_1(a,b,c);
			printf("There is one real solution: %.2lf\n", x_1);
		}
		else {
			x_1=solveForX_1(a,b,c);
			x_2=solveForX_2(a,b,c);			
			printf("There are 2 real solutions\nSolution 1: %.2lf\nSolution 2: %.2lf\n",x_1,x_2);
		}

	}	
	else {
		printf("There are no real solutions\n");
	}
	return 0;
}

double solveForX_1(double a,double b,double c) {
	double resultDouble;
	resultDouble = b*b-4*a*c;	
	return ((0-b)+sqrt(resultDouble))/2/a;
}
double solveForX_2(double a,double b,double c) {
	double resultDouble;
	resultDouble = b*b-4*a*c;	
	return ((0-b)-sqrt(resultDouble))/2/a;
}
bool verify(double a,double b,double c) {
	bool resultBool = false;
	double resultDouble;
	resultDouble = b*b-4*a*c;
	resultBool=(resultDouble<0)?false:true;
	return resultBool;
}

