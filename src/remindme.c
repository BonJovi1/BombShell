#include "../headers.h"

void remindme(char **args)
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		sleep(atoi(args[1]));
		printf("Reminder: ");
		for (int j = 2; args[j] != NULL; j++)
		{
			for (int k = 0; k < strlen(args[j]); k++)
				if (args[j][k] != '"')
					printf("%c",args[j][k]);
			printf(" ");
		}
		printf("\n");
	}
	else if (pid < 0)
		perror("Error in forking");
}