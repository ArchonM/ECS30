#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
//these functions need to calculate and prin answers
//temperatures
double fahrenheitToCelsius(double x);
double fahrenheitToKelvin(double x);
double celsiusToFahrenheit(double x);
double celsiusToKelvin(double x);
double kelvinToCelsius(double x);
double kelvinToFahrenheit(double x);
//distances
double inchesToFeet(double x);
double inchesToYards(double x);
double inchesToMiles(double x);
double feetToInches(double x);
double feetToYards(double x);
double feetToMiles(double x);
double yardsToInches(double x);
double yardsToFeet(double x);
double yardsToMiles(double x);
double milesToInches(double x);
double milesToFeet(double x);
double milesToYards(double x);
//type chhosing
int temperatures();
int distances();
//verifying
bool isRightUnit(char str[]);
int main() {
	char strTypeChoice[10] = "";
	char typeChoice = 't';
	printf("Pick the type of conversion that you would like to do.\n");
	printf("T or t for temperature\nD or d for distance\nEnter your choice: ");
	scanf("%s", strTypeChoice);
	if (strlen(strTypeChoice) == 1) {
		typeChoice = strTypeChoice[0];
		switch (typeChoice) {
			case 'T':
			case 't':
				temperatures();
				break;
			case 'D':
			case 'd':
				distances();
				break;
			default:
				printf("Unknown conversion type %c chosen. Ending Program.\n",typeChoice);
				break;
		}
	}
	else {
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}
	return 0;
}
int temperatures() {
	//variables
	char strOldUnit[10] = "";
	char oldUnit = 'F';
	double oldTemp = 0;
	char newUnit = 'f';
	char strNewUnit[10] = "";
	double newTemp = 0;
	//print and scan
	//choose old temp and unit
	printf("Enter the temperature followed by its suffix (F, C, or K): ");
	scanf("%lf %s", &oldTemp, strOldUnit);
	//test if the input is legal
	//if unit is too long
	isRightUnit(strOldUnit);
	//get old unit as character
	oldUnit=strOldUnit[0];
	oldUnit=toupper(oldUnit);
	//if unit is preidentified? yes: get new unit
	switch(oldUnit) {
		case 'f':
		case 'F':
		case 'c':
		case 'C':
		case 'k':
		case 'K':
			printf("Enter the new unit type (F, C, or K): ");
			scanf("%s", strNewUnit);
			break;
		default:
			printf("%c is not a valid temperature type. Ending program.\n", oldUnit);
			exit(0);
	}
	//test if new unit is too long
	isRightUnit(strNewUnit);
	//get new unit as character
	newUnit=strNewUnit[0];
	newUnit=toupper(newUnit);
	//if new unit is preidentified? yes: calculate and call new function
	switch (newUnit) {
		case 'f':
		case 'F':
		switch (oldUnit) {
			case 'c':
			case 'C':
				newTemp=celsiusToFahrenheit(oldTemp);
				break;
			case 'k':
			case 'K':
				newTemp=kelvinToFahrenheit(oldTemp);
				break;
			case 'f':
			case 'F':
				printf("%.2lf%c is %.2lf%c\n",oldTemp,oldUnit,oldTemp,oldUnit);
				exit(0);
			default:
				printf("%c is not a valid temperature type. Ending program.\n", newUnit);
				exit(0);
		}
			break;
		case 'c':
		case 'C':
			switch (oldUnit) {
				case 'f':
				case 'F':
					newTemp=fahrenheitToCelsius(oldTemp);
					break;
				case 'k':
				case 'K':
					newTemp=kelvinToCelsius(oldTemp);
					break;
				case 'c':
				case 'C':
					printf("%.2lf%c is %.2lf%c\n",oldTemp,oldUnit,oldTemp,oldUnit);
					exit(0);
				default:
					printf("%c is not a valid temperature type. Ending program.\n", newUnit);
					exit(0);
			}
			break;
		case 'k':
		case 'K':
		switch (oldUnit) {
			case 'f':
			case 'F':
				newTemp=fahrenheitToKelvin(oldTemp);
				break;
			case 'c':
			case 'C':
				newTemp=celsiusToKelvin(oldTemp);
				break;
			case 'k':
			case 'K':
				printf("%.2lf%c is %.2lf%c\n",oldTemp,oldUnit,oldTemp,oldUnit);
				exit(0);
			default:
				printf("%c is not a valid temperature type. Ending program.\n", newUnit);
				exit(0);
		}
			break;
		default:
			printf("%c is not a valid temperature type. Ending program.\n", newUnit);
			exit(0);
	}
	printf("%.2lf%c is %.2lf%c\n",oldTemp,oldUnit,newTemp,newUnit);


	return 0;
}
int distances() {
	//variables
	char strOldUnit[10] = "";
	char oldUnit = 'i';
	double oldDis = 0;
	char newUnit = 'i';
	char strNewUnit[10] = "";
	double newDis = 0;
	//print and scan
	//choose old distance and unit
	printf("Enter the distance followed by its suffix (I,F,Y,M): ");
	scanf("%lf %s",&oldDis, strOldUnit);
	//test if the input is legal
	//if unit is too long
	isRightUnit(strOldUnit);
	//get old unit as character
	oldUnit=strOldUnit[0];
	if (oldUnit == 'a') {
		printf("Invalid formatting. Ending program.");
		exit(0);
	}
	oldUnit=toupper(oldUnit);
	//if unit is preidentified? yes: get new unit
	switch(oldUnit) {
		case 'F':
		case 'I':
		case 'Y':
		case 'M':
			printf("Enter the new unit type (I,F,Y,M): ");
			scanf("%s", strNewUnit);
			break;
		default:
			printf("%c is not a valid distance type. Ending program.\n", oldUnit);
			exit(0);
	}
	//test if new unit is too long
	isRightUnit(strNewUnit);
	//get new unit as character
	newUnit=strNewUnit[0];
	newUnit=toupper(newUnit);
	//if new unit is preidentified? yes: calculate and call new function
	switch (newUnit) {
		case 'I':
			switch (oldUnit) {
				case 'F':
				case 'f':
					newDis=feetToInches(oldDis);
					break;
				case 'Y':
				case 'y':
					newDis=yardsToInches(oldDis);
					break;
				case 'I':
				case 'i':
					printf("%.2lf%c is %.2lf%c\n",oldDis,oldUnit,oldDis,oldUnit);
					exit(0);
				case 'M':
				case 'm':
					newDis=milesToInches(oldDis);
					break;
				default:
					printf("%c is not a valid distance type. Ending program.\n", newUnit);
					exit(0);
			}
			break;
		case 'F':
			switch (oldUnit) {
				case 'I':
				case 'i':
					newDis=inchesToFeet(oldDis);
					break;
				case 'Y':
				case 'y':
					newDis=yardsToFeet(oldDis);
					break;
				case 'F':
				case 'f':
					printf("%.2lf%c is %.2lf%c\n",oldDis,oldUnit,oldDis,oldUnit);
					exit(0);
				case 'M':
				case 'm':
					newDis=milesToFeet(oldDis);
					break;
				default:
					printf("%c is not a valid distance type. Ending program.\n", newUnit);
					exit(0);
			}
			break;
		case 'Y':
			switch (oldUnit) {
				case 'F':
				case 'f':
					newDis=feetToYards(oldDis);
					break;
				case 'I':
					newDis=inchesToYards(oldDis);
					break;
				case 'Y':
					printf("%.2lf%c is %.2lf%c\n",oldDis,oldUnit,oldDis,oldUnit);
					exit(0);
				case 'M':
					newDis=milesToYards(oldDis);
					break;
				default:
					printf("%c is not a valid distance type. Ending program.\n", newUnit);
					exit(0);
			}
			break;
		case 'M':
			switch (oldUnit) {
				case 'F':
					newDis=feetToMiles(oldDis);
					break;
				case 'Y':
					newDis=yardsToMiles(oldDis);
					break;
				case 'M':
					printf("%.2lf%c is %.2lf%c\n",oldDis,oldUnit,oldDis,oldUnit);
					exit(0);
				case 'I':
					newDis=inchesToMiles(oldDis);
					break;
				default:
					printf("%c is not a valid distance type. Ending program.\n", newUnit);
					exit(0);
			}
			break;
		default:
			printf("%c is not a valid distance type. Ending program.\n", newUnit);
			exit(0);
	}
	printf("%.2lf%c is %.2lf%c\n",oldDis,oldUnit,newDis,newUnit);


	return 0;
}
bool isRightUnit(char str[]){
	if (strlen(str)>1) {
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}
	if (strlen(str)==0) {
		printf("Invalid formatting. Ending program.\n");
		exit(0);
	}
	return true;
}

double fahrenheitToCelsius (double x) {
	double newTemp = 0;
	newTemp = (x-32)*5/9;
	return newTemp;
}
double fahrenheitToKelvin (double x) {
	double newTemp =0;
	newTemp = (x-32)*5/9+273.15;
	return newTemp;
}
double celsiusToKelvin (double x) {
	double newTemp = 0;
	newTemp = x+273.15;
	return newTemp;
}
double celsiusToFahrenheit (double x) {
	double newTemp = 0;
	newTemp = x*9/5+32;
	return newTemp;
}
double kelvinToCelsius (double x) {
	double newTemp = 0;
	newTemp = x-273.15;
	return newTemp;
}
double kelvinToFahrenheit (double x) {
	double newTemp = 0;
	newTemp = (x-273.15)*9/5+32;
	return newTemp;
}
double inchesToFeet(double x){
	double newDis = 0;
	newDis = x/12;
	return newDis;
}
double inchesToYards(double x){
	double newDis = 0;
	newDis = x/36;
	return newDis;
}
double inchesToMiles(double x){
	double newDis = 0;
	newDis = x/63360;
	return newDis;
}
double milesToYards(double x){
	double newDis = 0;
	newDis = x*1760;
	return newDis;
}
double milesToInches(double x){
	double newDis = 0;
	newDis = x*63360;
	return newDis;
}
double milesToFeet(double x){
	double newDis = 0;
	newDis = x*5280;
	return newDis;
}
double yardsToInches(double x){
	double newDis = 0;
	newDis = x*36;
	return newDis;
}
double yardsToMiles(double x){
	double newDis = 0;
	newDis = x/1760;
	return newDis;
}
double yardsToFeet(double x){
	double newDis = 0;
	newDis = x*3;
	return newDis;
}
double feetToInches(double x){
	double newDis = 0;
	newDis = x*12;
	return newDis;
}
double feetToMiles(double x){
	double newDis = 0;
	newDis = x/5280;
	return newDis;
}
double feetToYards(double x){
	double newDis = 0;
	newDis = x/3;
	return newDis;
}
