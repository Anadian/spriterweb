// cli.c

/*#include "cli.h"

#ifdef CLI_IMPLEMENTATION

int CLIAddString(CLI_Dictionary *dictionary, char *argument, char *variable){
	if(dictionary == NULL){
#ifdef CLI_AUTO_BUFFER
		if(CLI_AutoDictionaryInitFlag == 0){
			CLI_AutoDictionary = calloc(1*sizeof(CLI_Dictionary);
		} else {
			CLI_AutoDictionary = realloc(sizeof(CLI_AutoDictionary)+sizeof(CLI_Dictionary));
		}
		dictionary = CLI_AutoDictionary;
#else //if(!CLI_AUTO_BUFFER)
#ifdef CLI_VERBOSE
		printf("No CLI_Dictionary provided; either send the address of a CLI_Dictionary variable or consider enabling CLI_AUTO_BUFFER\n");
#endif //CLI_VERBOSE
#ifdef CLI_AUTO_EXIT
		exit(EXIT_FAILURE);
#endif //CLI_AUTO_EXIT
#endif //CLI_AUTO_BUFFER
	}
	int i;
	for(i = 0; i < (sizeof(dictionary)/sizeof(CLI_Dictionary)); i++){
		if(dictionary->type == 0){
			dictionary->type == 1;
			dictionary*/
		