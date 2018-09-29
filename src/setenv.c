#include "../headers.h"

void execute_setenv(char **args)
{
	if(ctr_arg == 1)
		printf("No arguments are given :(");
	
	else if(ctr_arg > 3)
		printf("Invalid Syntax!! Usage: setenv VAR [VALUE]");

	else
	{
		if(ctr_arg == 3)
		{
			char string[1000];
			strcpy(string, args[2]);
			setenv(args[1] , string , 1); //1 is overwrite
		}
		else
			setenv(args[1], " ", 1);
	}
}