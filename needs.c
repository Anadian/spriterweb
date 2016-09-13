//needs.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h> //malloc, free
#include <glob.h>
#include "s/INCLUDE/cli.h"

typedef struct object_struct {
	int type;
	char name[256];
	char header[256];
	char source[256];
	char needs[256];
} object_type;

int main(int argc, char *argv[]){
	int dummy;
	CLIGetInt(argv[0], "-flag", &dummy);
	printf("Generating header list.\n");
	glob_t headerglob;
	glob("INCLUDE/*.h", NULL, NULL, &headerglob);
	printf("Headerglob found %d matches of %d pathnames.\n", headerglob.gl_matchc, headerglob.gl_pathc);
	printf("Headerglob matches:\n");
	int i;
	for(i = 0; i < headerglob.gl_matchc; i++){
		printf("\t%d: %s\n", i, headerglob.gl_pathv[i]);
	}
	printf("Creating .header file.\n");
	FILE *headerfile;
	headerfile = fopen(".header","w+");
	for(i = 0; i < headerglob.gl_matchc; i++){
		fprintf(headerfile, "%s\n", headerglob.gl_pathv[i]);
	}
	fclose(headerfile);
	printf("Adding them to \'objects\'");
	object_type *objects = malloc(headerglob.gl_matchc*sizeof(object_type));
	for(i = 0; i < headerglob.gl_matchc; i++){
		strcpy(objects[i].header, headerglob.gl_pathv[i]);
	}
	printf("Generating source list.\n");
	glob_t sourceglob;
	glob("SOURCE/*.c", NULL, NULL, &sourceglob);
	printf("Sourceglob found %d matches of %d pathnames.\n", sourceglob.gl_matchc, sourceglob.gl_pathc);
	printf("Sourceglob matches:\n");
	FILE *sourcefile;
	sourcefile = fopen(".source","w+");
	for(i = 0; i < sourceglob.gl_matchc; i++){
		printf("\t%d: %s (added to .source and finding place in objects)\n", i, sourceglob.gl_pathv[i]);
		fprintf(sourcefile, "%s\n", sourceglob.gl_pathv[i]);
		strcpy(objects[i].source, sourceglob.gl_pathv[i]);
	}
	fclose(sourcefile);
	printf("Looking for matches.\n");
	for(i = 0; i < headerglob.gl_matchc; i++){
		int j;
		for(j = 0; j < sourceglob.gl_matchc; j++){
			if(strncmp(objects[i].header, objects[j].source, (strchr(objects[i].header, '.') - objects[i].header)) == 0){
				char namebuf[256];
				strncpy(namebuf, objects[i].header, (strchr(objects[i].header, '.') - objects[i].header));
				strcat(namebuf, ".o");
				strcpy(objects[i].name, namebuf);
				j = (sourceglob.gl_matchc+1);
			}
		}
		if(j == sourceglob.gl_matchc){
			strcpy(objects[i].name, objects[i].header);
		}
		printf("Objects[%d] name: %s header: %s sour: %s\n", i, objects[i].name, objects[i].header, objects[i].source);
	}
	globfree(&headerglob);
	globfree(&sourceglob);
	free(objects);
	return 0;
}