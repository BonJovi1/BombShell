#include "../headers.h"

void execute_echo(char **args)
{
	int i = 1;
	while(args[i]!=NULL)
	{
		printf("%s ", args[i]);
		i++;
	}
	printf("\n");
}
