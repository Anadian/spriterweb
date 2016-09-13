// delog.c

#include "delog.h"
#include "configuration.h"
#include <string.h>

signed short CreateNewLog(){
	if(Configuration.debug.savepreviouslogs == 0){
		FILE *previousLogName = fopen("previouslogname.txt","r");
		if(previousLogName != NULL){
			char previousLogFilename[32];
			fgets(previousLogFilename, sizeof previousLogFilename, previousLogName);
			fclose(previousLogName);
			remove(previousLogFilename);
		}
	}
	char dateandtime[32];
	Delog.starttime = time(NULL);
	strftime(dateandtime, sizeof dateandtime, "%Y%m%dT%H%M%SZ", gmtime(&(Delog.starttime)) );
	strcat(dateandtime, ".log");
	
	//printf("Loading log file: %s\n", dateandtime);
	char Buffer[256];
	FILE *logfile = fopen(dateandtime, "w");
	if(logfile != NULL){
		strcpy(&(Delog.filename),&dateandtime);
		sprintf(Buffer, "%s v%d.%d\nBuilt on %s at %s.\nOriginal filename: %s\nCurrent debug verbosity: %d\n", BUILD_NAME, VERSION_MAJOR, VERSION_MINOR, BUILD_DATE, BUILD_TIME, dateandtime, Configuration.debug.verbosity);
		//printf("Buffer: %s\n", Buffer);
		fputs( Buffer, logfile);
		fclose(logfile);
	}
	FILE *previousLogName = fopen("previouslogname.txt","w");
	sprintf(Buffer, "%s", dateandtime);
	fputs(Buffer, previousLogName);
	fclose(previousLogName);
	return 0;
}
signed short printl(unsigned short priority, char *fmt,...){
	if(priority <= Configuration.debug.verbosity){
		char Buffer[256];
		strcpy(&Buffer,fmt);
		//printf("%s\n", Buffer);
		FILE *logfile = fopen(&(Delog.filename), "a");
		/*if(logfile != NULL) printf("logfile open\n");
		else printf("logfile closed\n");*/
		va_list args;
		va_start(args, fmt);
		/*char format[256];
		unsigned short BufferIndex;
		BufferIndex = 0;*/
		unsigned short i;
		i = 0;
		while(Buffer[i] != '\0'){
			 if(Buffer[i] == '%'){
			 	i++;
			 	switch(Buffer[i]){
			 		case 'd':{
			 			int d = va_arg(args,int);
			 			char subBuffer[16];
			 			sprintf(subBuffer, "%d", d);
			 			fputs( subBuffer, logfile);
			 			break;
			 		}
			 		case 'c':{
			 			char c = va_arg(args,char);
			 			fputc(c, logfile);
			 			break;
			 		}
			 		case 's':{
			 			char *string = va_arg(args,char*);
			 			fputs( string, logfile);
			 			break;
			 		}
			 		case 'f':{
			 			double f = va_arg(args,double);
			 			char subBuffer[16];
			 			sprintf(subBuffer, "%lf", f);
			 			fputs( subBuffer, logfile);
			 			break;
			 		}
			 		case '%':{
			 			fputs( "%", logfile);
			 			break;
			 		}
			 		default:
			 			fputc( Buffer[i], logfile);
			 			break;
			 	}
			 } else{
			 	fputc( Buffer[i], logfile);
			 }
			 i++;
		}
		va_end(args);
		fputs("\n", logfile);
		fclose(logfile);
	}
	return 0;
}

signed short QuitDelog(){
	printl(1,"Quitting under normal circumstances and cleaning up properly.\n");
	if(Configuration.debug.savepreviouslogs == 0) printl(1,"This log file will be overwritten on next start up.\n");
	else printl(1,"This log file will not be overwritten on next start up.\n");
	return 0;
}