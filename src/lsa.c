#include "../headers.h"

void execute_lsa()
{
	struct dirent **fileList;
	int count = scandir(".", &fileList, NULL, alphasort);

	if(count >= 0)
	{
		for(int i=0;i<count;i++)
		{
			printf("%s   ",fileList[i]->d_name);
			free(fileList[i]);
		}

	}
	printf("\n");
	free(fileList);
}