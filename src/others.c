#include "../headers.h"

int execute_help(char **args)
{
  int i;
  printf("Abhinav's Shell\n");
  printf("Type commands, and hit enter! \n");
  return 1;
}

int execute_exit(char **args)
{
	printf("Exiting Shell\n");
	return 0;
}