#include <stdio.h>
#include <stdlib.h>


void print_lines(char** lines, int num_lines,int num){
	int i;
	for(i = num_lines-num ; i < num_lines; ++i){
		printf("%s", lines[i]);
	}
}

void free_lines(char** lines, int num_lines){
	int i;

	for(i = 0 ; i < num_lines; ++i){
		free(lines[i]);
	}

	if(lines != NULL && num_lines > 0){
		free(lines);
	}

}
void read_lines(FILE* fp, char*** lines, int* num_lines){
	char ch;
	int i=0;
	char** line;

	ch = fgetc(fp);

	while (ch != EOF){
		if(ch=='\n'){
			*num_lines += 1;
		}
		ch = fgetc(fp);
	}

	line = (char**) malloc (sizeof(char*)*1000);
	for (i = 0;i<*num_lines;i++){
		line[i] = (char*)malloc(sizeof(char)*1000);
	}

	rewind(fp);
	for (i = 0; i <*num_lines;i++){
		fgets(line[i],1000,fp);
        //fseek(fp,1,SEEK_CUR);
	}
    for (i = 0; i<*num_lines;i++){

    }
	*lines = line;
}
FILE* validate_input(int argc, char* argv[]){

	FILE* fp = NULL;

	if(argc < 3){
		printf("Not enough arguments entered.\nEnding program.\n");
		exit(0);
	}
	else if(argc > 3){
		printf("Too many arguments entered.\nEnding program.\n");
		exit(0);
	}

	fp = fopen(argv[1], "r");

	if(fp == NULL){
		printf("Unable to open file: %s\nEnding program.\n", argv[1]);
		exit(0);
	}

	return fp;

}


int main(int argc, char* argv[]){
	char** lines = NULL;
	int num_lines = 0;
    int num = atoi(argv[2]);
	FILE* fp = validate_input(argc, argv);

	read_lines(fp, &lines, &num_lines);
    if (num>num_lines){
        num = num_lines;
    }
	print_lines(lines, num_lines,num);
	free_lines(lines, num_lines);
	fclose(fp);

	return 0;
}
