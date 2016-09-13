// cli.h

#ifndef CLI_H
#define CLI_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

int CLIGetInt(char *arg, char *flag, int *pint);
int CLIGetString(char *arg, char *flag, char *pstring);
int CLIDoFunction(char *arg, char *flag, void (*pfunction)());

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //CLI_H