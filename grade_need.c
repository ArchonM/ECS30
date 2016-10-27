/*
This program is used for calculating students' grades and give a result of what grade students shall get in order to get their target
*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
bool verifyGradeWanted(char targetGrade);
bool verifyDigits(char *str);


int main() {
	//char _author_[4] = "Ning";
//define the variables
	char targetGrade = 'A';
	double targetPercent = 0;
	double currentPercent = 0;
	char stringPercent[10] = "";
	double finalWeight = 0;
	char stringWeight[10] = "";
	double neededPercent = 0;
	bool result = true;
	char strTargetGrade[10] = "";
	char extra[10] ="";
//print and scan the input
	printf("Enter the grade you want in the class: ");
	scanf("%s",strTargetGrade);
	if (strlen(strTargetGrade)>1) {
		printf("Invalid formatting. Ending program.");
		exit(0);
	}
	else {
		targetGrade = strTargetGrade[0];
	}
	result = verifyGradeWanted(targetGrade);

	/*printf("Enter the percent in the class you need in the class to get that grade: "); 
	scanf("%lf",&targetPercent);*/
	if (result) {
		printf("Enter your current percent in the class: ");
		scanf("%s",stringPercent);
		result = verifyDigits(stringPercent);
		if (result){
			currentPercent = atof(stringPercent);
			if (currentPercent<0) {
				printf("The number you last entered should have been positive. Ending program.\n");
				exit(0);
			}
			printf("Enter the weight of the final: ");
			scanf("%s %s",stringWeight,extra);
			if (strlen(extra) != 0) {
				printf("Invalid formatting. Ending program.\n");
				exit(0);
			}
			result = verifyDigits(stringWeight);
			if (result) {
				finalWeight = atof(stringWeight);
				if (finalWeight < 0) {
					printf("The number you last entered should have been positive. Ending program.\n");
					exit(0);
				}
			}
			else {
				printf("Invalid formatting. Ending program.\n");
				exit(0);
			}
		}
		else {
			printf("Invalid formatting. Ending program.\n");			
			exit(0);
		}	
	}
	else {
		printf("Unknown Grade Received: %c. Ending program.\n", targetGrade);
		exit(0);
	}
//calculating
	switch (targetGrade) {
		case 'A':
		case 'a':
			targetPercent = 90;
			break;
		case 'B':
		case 'b':
			targetPercent = 80;
			break;
		case 'C':
		case 'c':
			targetPercent = 70;
			break;
		case 'D':
		case 'd':
			targetPercent = 60;
			break;
		case 'F':
		case 'f':
			targetPercent = 0;
			break;
	}
	if ((targetPercent+10)<(currentPercent-finalWeight)){
		printf("You cannot score low enough on the final to get a %c in the class.\n", targetGrade);
		exit(0);
	}
	neededPercent = (targetPercent - (100.00-finalWeight)/100.00*currentPercent)/finalWeight*100.00;
//output of result
	if (neededPercent>100) {
		printf("You cannot get a A in the class because you would need to score at least %.2lf%% on the final.", neededPercent);
		exit(0);
	}
	printf("\nYou need a grade of at least %.2lf%% on the final to get a %c in the class.\n", neededPercent, targetGrade);
	

	return 0;
}

bool verifyGradeWanted(char targetGrade) {
	bool result = true;
	switch (targetGrade) {
		case 'A':
		case 'a':
		case 'B':
		case 'b':
		case 'C':
		case 'c':
		case 'D':
		case 'd':
		case 'F':
		case 'f':
			break;
		default:
			result = false;
	}

	return result;
}
bool verifyDigits(char str[]){
	bool result = true;
	for (int i=0; i<10; ++i) {
		if (isalpha(str[i])) {
			result = false;
		}
		if (isspace(str[i])) {
			result = false;
		}
	}
	return result;
}







