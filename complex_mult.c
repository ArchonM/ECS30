/*
This program is used to multiply two complex number.
*/

#include <stdio.h>
int main () {
	//char _author_ = [4]"Ning";
//identify the variables
	int complexNumA1 = 0;
	int complexNumB1 = 0;
	int complexNumA2 = 0;
	int complexNumB2 = 0;
	int answerA = 0;
	int answerB = 0;
//get input
	printf("Enter the first complex number in the form ai + b: ");
	scanf("%di + %d",&complexNumA1,&complexNumB1);
	printf("Enter the second complex number in the form ai + b: ");
	scanf("%di + %d",&complexNumA2,&complexNumB2);
//calculating
	answerA = complexNumA1*complexNumB2+complexNumA2*complexNumB1;
	answerB = complexNumB2*complexNumB1-complexNumA1*complexNumA2;
//output
	printf("(%di + %d) * (%di + %d) = %di + %d\n",complexNumA1,complexNumB1,complexNumA2,complexNumB2,answerA,answerB);



	return 0;
}
