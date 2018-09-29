#include "../headers.h"

void execute_fg(char **args)
{
	if(ctr_arg == 1)
		printf("No arguments are given :( Please specify the ID of the process ");
	
	else if(ctr_arg > 2)
		printf("Invalid Syntax!! Usage: fg [ID]");

	else
	{
		int job_id = atoi(args[1]);
		int count=0;
		
		for(int i=0; i<process_count; i++)
		{
			if(strcmp(process_list[i].status, "killed")==0)
				continue;
			count++;

		}
		if(job_id > count)
			printf("Invalid JOB ID, please use command jobs to refer to correct ID");
		else
		{
			int count=0;
			int i;
			for(i=0; i<process_count; i++)
			{
				if(strcmp(process_list[i].status, "killed")==0)
					continue;
				if(job_id == count)
					break;
				count++;

			}
			printf("%d %s", process_list[i].pid, process_list[i].pname);
			
			int bgid = process_list[i].pid;
			curPID = bgid;
			// printf(typeof(bgid));
			// pid_t wpid;
			kill(bgid, SIGSTOP);
			kill(bgid, SIGCONT);
			int vari;
			waitpid(bgid, &vari, WUNTRACED);
	        
	    	return;
	    }
	}
	return;
}