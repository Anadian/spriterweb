//magictoy.c

#include <stdio.h> //printf
#include <stdlib.h> //atoi
#include <string.h> //strcmp, strlen, strstr

int main(int argc, char *argv[]){
	printf("Magictoy v1\n");
	int n;
	for(n = 0; n < argc; n++){
		printf("%d: %s\n", argc, argv[n]);
	}
	char *function;
	int lines;
	int cols;
	lines = 0;
	cols = 0;
	char *srcdir;
	char *incdir;
	char *objdir;
	if(argc < 1){
		printf("No arguments (use -h for help).\n");
	} else{
		int i;
		for(i = 1; i < argc; i++){
			if((strcmp(argv[i],"-h") == 0) || (strcmp(argv[i],"--help") == 0)){
				function = "help";
			} else if( (strcmp(argv[i], "-s") == 0) || (strcmp(argv[i], "--sep") == 0) ){
				function = "sep";
			} else
		