//cno_options.c
#include "cno_options.h"

#include "cno_build.h"
#if CNO_HAVE_STRING
#include <string.h> //strcpy
#endif //CNO_HAVE_STRING
#if CNO_HAVE_GETOPT
#include <getopt.h> //getopt_long
#endif //CNO_HAVE_GETOPT
#if CNO_HAVE_STDIO
#include <stdio.h> //printf
#endif //CNO_HAVE_STDIO
#if CNO_HAVE_STDLIB
#include <stdlib.h> //exit, atoi
#endif //CNO_HAVE_STDLIB

cno_s8_type CNO_Options_GetOpt(int argc, char *argv[]){
#if CNO_HAVE_STRING && CNO_HAVE_GETOPT
	strcpy(CNO_Options_Plus[CNO_Option_Version].hint,NULL);
	strcpy(CNO_Options_Plus[CNO_Option_Version].description,"Prints version information and exits.");
	strcpy(CNO_Options_Plus[CNO_Option_Help].hint,NULL);
	strcpy(CNO_Options_Plus[CNO_Option_Help].description,"Prints this help text and exits.");
	CNO_Options_Plus[CNO_Option_Verbose].flag = 0;
	strcpy(CNO_Options_Plus[CNO_Option_Verbose].hint,"(UINT)");
	strcpy(CNO_Options_Plus[CNO_Option_Verbose].description,"Overrides the verbosity, set in config.ini, to UINT (which defaults to 5 if unspecified) with 0 being silent (no output to STDOUT) and 5 being maximum verbosity which offers more debug info than you could ever want!");
	CNO_Options_Plus[CNO_Option_Config].flag = 0;
	strcpy(CNO_Options_Plus[CNO_Option_Config].hint,"[FILE]");
	strcpy(CNO_Options_Plus[CNO_Option_Config].description,"Uses FILE for configuration instead of searching for config.ini in the directories listed above.");
	CNO_Options_Plus[CNO_Option_Actions].flag = 0;
	strcpy(CNO_Options_Plus[CNO_Option_Actions].hint,"[FILE]");
	strcpy(CNO_Options_Plus[CNO_Option_Actions].description,NULL);

	char c;
	int long_option_index;
	long_option_index = 0;
	while( ((c = getopt_long(argc,argv,"Vhv::c:a:", long_options, &long_option_index)) != -1) && (c != 255)){
#if CNO_ALLOW_PRINTF
		printf("%d: %c \n", long_option_index, c);
#endif //CNO_ALLOW_PRINTF
		switch(c){
			case 'V':
#if CNO_ALLOW_PRINTF
				printf("\n");
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
				exit(EXIT_SUCCESS);
#endif //CNO_ALLOW_EXIT
				break;
			case 'h':
#if CNO_ALLOW_PRINTF
				printf("Basic Usage:\n\t %s [OPTIONS]\nOptions:\t Note: (argument) means the argument(s) is/are optional while [argument] means the option is required.\n", CNO_BUILD_NAME);
				int i;
				for(i = 0; i < Number_of_CNO_Options; i++){
					printf("\t%c %s %s: %s\n", long_options[i].val, long_options[i].name, CNO_Options_Plus[i].hint, CNO_Options_Plus[i].description);
				}
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
				exit(EXIT_SUCCESS);
#endif //CNO_ALLOW_EXIT
				break;
			case 'v': 
				CNO_Options_Plus[CNO_Option_Verbose].flag = 1;
				CNO_Options_Argument_Verbose = (optarg == NULL)?(5):(atoi(optarg));
				break;
			case 'c':
				if(optarg == NULL){
#if CNO_ALLOW_PRINTF
					printf("Error '-c' invoked without an argument\n");
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
					exit(EXIT_FAILURE);
#endif //CNO_ALLOW_EXIT
				} else{
					CNO_Options_Plus[CNO_Option_Config].flag = 1;
					CNO_Options_Argument_Confg = optarg;
				}
				break;
			case 'a':
				if(optarg == NULL){
#if CNO_ALLOW_PRINTF
					printf("Error '-a' invoked without an argument\n");
#endif //CNO_ALLOW_PRINTF
#if CNO_ALLOW_EXIT
					exit(EXIT_FAILURE);
#endif //CNO_ALLOW_EXIT
				} else{
					CNO_Options_Plus[CNO_Option_Actions].flag = 1;
					CNO_Options_Argument_Actions = optarg;
				}
				break;
		}
	}
	return 0;
}
#endif //CNO_HAVE_GETOPT
