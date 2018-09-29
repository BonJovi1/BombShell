#include "../headers.h"

void execute_jobs(char **args)
{
	printf("NUMBER  ");
	printf("PID  ");
	printf("NAME  ");
	printf("STATUS");
	printf("\n");
	int count=0;
	for(int i=0; i<process_count; i++)
	{
		if(strcmp(process_list[i].status, "killed")==0)
			continue;
		printf("[%d]  ", count);
		count++;
		printf("%d  ", process_list[i].pid);
		printf("%s  ", process_list[i].pname);
		printf("%s  ", process_list[i].status);
		printf("\n");
	}
}