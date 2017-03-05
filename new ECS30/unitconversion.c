//
//  unitconversion.c
//
//
//  Created by Vincent on 1/18/17.
//
//

#include <stdio.h>
#include <string.h>

int Conversion(int num1, char unit1, double num2, char unit2){
    if (unit1 == 'g') {
        num1 = num1 * 4 * 2 * 2 * 8;
    }
    if (unit1 == 'q') {
        num1 = num1 * 2 * 2 * 8;
    }
    if (unit1 == 'p') {
        num1 = num1 * 2 * 8;
    }
    if (unit1 == 'c') {
        num1 = num1 * 8;
    }
    if (unit1 == 'o') {
        num1 = num1;
    }
    if (unit2 == 'o') {
        num2 = num1;
        if (num2 > 1) {
            printf("You have %lf ounces of liquid.\n", num2);
        }else{
            printf("You have %lf ounce of liquid.\n", num2);
        }
    }
    if (unit2 == 'c') {
        num2 = num1 / 8.0;
        if (num2 > 1) {
            printf("You have %lf cups of liquid.\n", num2);
        }else{
            printf("You have %lf cup of liquid.\n", num2);
        }
    }
    if (unit2 == 'p') {
        num2 = num1 / 16.0;
        if (num2 > 1) {
            printf("You have %lf pints of liquid.\n", num2);
        }else{
            printf("You have %lf pint of liquid.\n", num2);
        }
    }
    if (unit2 == 'q') {
        num2 = num1 / 32.0;
        if (num2 > 1) {
            printf("You have %lf quarts of liquid.\n", num2);
        }else{
            printf("You have %lf quart of liquid.\n", num2);
        }
    }
    if (unit2 == 'g') {
        num2 = num1 / 128.0;
        if (num2 > 1) {
            printf("You have %lf gallons of liquid.\n", num2);
        }else{
            printf("You have %lf gallon of liquid.\n", num2);
        }
    }
    return 0;
}

int main(void){
    int currentMeasurement;
    double desiredMeasurement = 0.0;
    char currentUnit = 'g';
    char desiredUnit = 'c';

    printf("Enter your current measurement and unit of volume:");
    scanf("%d %c", &currentMeasurement, &currentUnit);

    if (currentMeasurement <=0 ) {
        printf("Error! You entered a negative number.\n");
        if (!(currentUnit == 'g'|| currentUnit == 'q' || currentUnit == 'p' || currentUnit == 'c' || currentUnit == 'o') ){
        printf("Error! Enter one of ’g’ for gallons, ’q’ for quarts, ’p’ for pints, ’c’ for cups, or ’o’ for ounces.\n");
        }
    }
    else if (!(currentUnit == 'g'|| currentUnit == 'q' || currentUnit == 'p' || currentUnit == 'c' || currentUnit == 'o') ){
            printf("Error! Enter one of ’g’ for gallons, ’q’ for quarts, ’p’ for pints, ’c’ for cups, or ’o’ for ounces.\n");
    }
    else {
        printf("Enter your desired unit of volume:");
        scanf("\n%c", &desiredUnit);
        if (desiredUnit == 'g'|| desiredUnit == 'q' || desiredUnit == 'p' || desiredUnit == 'c' || desiredUnit == 'o'){
            Conversion(currentMeasurement, currentUnit, desiredMeasurement, desiredUnit);
        }
        else {
            printf("Error! Enter one of ’g’ for gallons, ’q’ for quarts, ’p’ for pints, ’c’ for cups, or ’o’ for ounces.\n");
        }


    }

    return 0;
}
