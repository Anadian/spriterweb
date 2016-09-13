// cli.h

#ifndef CLI_H
#define CLI_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

#define CLI_VERBOSE
#define CLI_AUTO_BUFFER
#define CLI_AUTO_EXPAND
#define CLI_AUTO_EXIT
/*#define CLI_ENFORCE_HYPHEN*/
#define CLI_USE_SYNONYMS
#define CLI_SYNONYM_SEPERATOR ','
#define CLI_MAX_TERM_LENGTH 64
#define CLI_USE_UTF8

typedef struct CLI_Dictionary_struct {unsigned char type;
	char term[CLI_MAX_TERM_LENGTH];
	union {
		char *pvariable;
		void *(pfunction)(char *arg, char *value);
	}
} CLI_Dictionary_type;
typedef struct CLI_Dictionary_struct CLI_Dictionary;

#ifdef CLI_VERBOSE
#include <stdio.h>
#endif

#ifdef CLI_AUTO_BUFFER
#include <stdlib.h>
CLI_Dictionary *CLI_AutoDictionary;
unsigned char CLI_AutoDictionaryInitFlag = 0;
#endif

#define CLI_AUTO_EXIT
#include <stdlib.h>
#endif

int CLIAddVariable(CLI_Dictionary *dictionary, char *argument, char *variable);
int CLIAddFunction(CLI_Dictionary *dictionary, char *argument, void (*function)(char *arg, char *value));
int CLIParse();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CLI_H