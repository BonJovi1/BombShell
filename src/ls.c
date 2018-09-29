#include "../headers.h"

void execute_ls(char **args)
{
	
	if(args[1] == NULL)
		execute_simple_ls();

	else if(strcmp(args[1], "-a") == 0 && args[2] == NULL)
		execute_lsa();
	else if(strcmp(args[1], "-l") == 0 && args[2] == NULL)
		execute_lsl();
	
	else if(strcmp(args[1], "-a") == 0 && strcmp(args[2], "-l") == 0)
		execute_lsla();
	else if(strcmp(args[1], "-l") == 0 && strcmp(args[2], "-a") == 0)
		execute_lsla();
	else if(strcmp(args[1], "-al") == 0)
		execute_lsla();
	else if(strcmp(args[1], "-la") == 0)
		execute_lsla();

	else
		printf("ERROR: Command not found");

}

void execute_simple_ls()
{
	struct dirent **fileList;
	int count = scandir(".", &fileList, NULL, alphasort);

	if(count >= 0)
	{
		for(int i=0;i<count;i++)
		{
			if(fileList[i]->d_name[0]!='.')
				printf("%s\n",fileList[i]->d_name);
			free(fileList[i]);
		}
		printf("\n");

	}
	
	free(fileList);
}