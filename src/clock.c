#include "../headers.h"

void execute_clock(char **args)
{
	while(1)
	{
		char str1[1000];
		strcpy(str1, "/sys/class/rtc/rtc0/time");

		char str2[1000];
		strcpy(str2, "/sys/class/rtc/rtc0/date");

		FILE * f1=fopen(str2,"r");
		char date[100];
		fscanf(f1,"%s", date);
		printf("%s ", date);

		fclose(f1);

		FILE * f2=fopen(str1,"r");
		char time[100];
		fscanf(f2,"%s",time);
		printf("%s\n",time);

		sleep(atoi(args[2]));
	}
}