#include "../headers.h"

void pinfo(int number)
{
	char stats[100];
	char exec[100];
	char * line_buffer = malloc(1002 * sizeof(char)); //for reading file
	
	long unsigned int virtual_mem = 0;
	char ch;
	int pid;
	char p_name[30];
	
	sprintf(stats, "/proc/%d/stat", number);
	sprintf(exec, "/proc/%d/exe", number);

	FILE* f1 = fopen(stats, "r");
	if(!f1) 
        perror("Error: Process doesn't exist\n");
    else
    {
    	printf("PID -- %d\n",number);
		fscanf(f1, "%d", &pid);
		fscanf(f1, "%s", p_name);
		fscanf(f1," %c", &ch);
		fscanf(f1, "%lu", &virtual_mem);

        printf("Process Status -- %c\n", ch);
		virtual_mem *= 1024;
		printf("Virtual memory -- %lu\n", virtual_mem);

		fclose(f1);
    }

    long long int len = readlink(exec, line_buffer, 1000);
    if (len < 0)
        perror("Error: Permission Denied\n");
    else 
    {
        line_buffer[len] = '\0';
        printf("Executable Path -- %s\n", line_buffer);
	}
}