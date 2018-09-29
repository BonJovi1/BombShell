#include "../headers.h"

void execute_unsetenv(char **args)
{
	if(ctr_arg == 1)
		printf("No arguments are given :(");
	
	else if(ctr_arg > 2)
		printf("Invalid Syntax! Usage: unsetenv VAR");

	else
		unsetenv(args[1]);//easy peesy
}