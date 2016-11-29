#include <stdio.h>
#include <stdlib.h>
#include <math.h>


FILE* validate_input(int argc, char* argv[]){

	FILE* fp = NULL;

	if(argc < 2){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 2){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}

	fp = fopen(argv[1], "rb");

	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}

	return fp;

}

int main(int argc, char* argv[]){
    int num_points = 0;
    int i = 0;
    double temp1 = 0;
    double temp2 =0;
    double temp3 = 0;
    double perimeter = 0;
    FILE* fp = validate_input(argc, argv);
    fread(&num_points,sizeof(int),1,fp);
    int x[num_points];
    int y[num_points];
    for (i = 0; i <num_points;i++){
        fread(&x[i],sizeof(int),1,fp);
        fread(&y[i],sizeof(int),1,fp);
    }
    for (i = 0; i < num_points; i++){
        if (i == num_points-1){
            temp1 = x[i] - x[0];
            temp2 = y[i] - y[0];
        }
        else {
            temp1 = (double)x[i] - x[i+1];

            temp2 = (double)y[i] - y[i+1];
        }

        temp3 = (double)sqrt(pow(temp1,2)+pow(temp2,2));
        perimeter += temp3;
    }

    fclose(fp);
    printf("The perimeter is %.2lf\n",perimeter);
    return 0;
}
