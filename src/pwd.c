#include "../headers.h"

void execute_pwd()
{
	getcwd(directory, 1000);
	printf("%s\n", directory);
}