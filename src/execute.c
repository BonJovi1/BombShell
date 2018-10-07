#include "../headers.h"

void execute_kjob(char **args)
{
    if(ctr_arg == 1)
        printf("No arguments are given :( Please specify the ID of the process ");
    
    else if(ctr_arg > 3 || ctr_arg == 2)
        printf("Invalid Syntax!! Usage: kjob [ID] [signal] ");

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
            kill(bgid, atoi(args[2]));
            
            return;
        }
    }
}

void execute_bg(char **args)
{
    if(ctr_arg == 1)
        printf("No arguments are given :( Please specify the ID of the process ");
    
    else if(ctr_arg > 2)
        printf("Invalid Syntax!! Usage: bg [ID]");
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
            if(strcmp(process_list[i].pname, "running")==0)
                return;
            int bgid = process_list[i].pid;
            kill(bgid, SIGCONT);
            strcpy(process_list[i].status, "running");
            return;
        }

    }
}

int execute_command(char **args, int in, int out)
{
    if(args[0]!='\0')
    	strcpy(curPROCESS, args[0]);
    bg = 0;
    int lol = 0;
    ctr_arg = 0;

    while(args[lol] != NULL) // Counting number of arguments in the command
    {
        ctr_arg++;
        lol++;
    }
    
    for(int j=0; args[j]!=NULL; j++) // Checking if it is a background process
    {
        if(strcmp(args[j], "&") == 0)
        {
            bg = 1;
            args[j] = NULL;
            break;
        }
    }
    if (in != 0)
  	{
  	    dup2 (in, 0);
  	    close (in);
  	}

  	if (out != 1)
  	{
  	    dup2 (out, 1);
  	    close (out);
  	}

    if(bg == 1)
        return launch_command(args, in, out);

    if (args[0] == NULL) 
  	{
    	// An empty command was entered.
    	return 1;
  	}

  	if(strcmp(args[0], "cd") == 0)
  	{
  		int lol;
  		lol = execute_cd(args);
  		return 1;
  	}
  	
  	if(strcmp(args[0], "help") == 0)
  	{
  		execute_help(args);
  		return 1;
  	}
  	if(strcmp(args[0], "exit") == 0)
  	{
  		execute_exit(args);
  		return 0;
  	}

  	if(strcmp(args[0], "pwd") == 0)
  	{
  		execute_pwd();
  		return 1;
  	}

    if(strcmp(args[0], "overkill") == 0)
    {
        for(int i=0;i<process_count;i++)   
            kill(process_list[i].pid, SIGKILL);
        return 1;

    }
  	if (strcmp(args[0], "echo") == 0)
  	{
  		execute_echo(args);
  		return 1;
  	}

  	if (strcmp(args[0], "ls") == 0)
  	{
  		execute_ls(args);
  		return 1;
  	}

  	if (strcmp(args[0], "pinfo") == 0)
	{
		if (args[1] == NULL)
			pinfo(getpid());
		else
			pinfo(atoi(args[1]));
		return 1;
	}

	if (strcmp(args[0], "clock") == 0)
	{
		execute_clock(args);
		return 1;
	}
	
    if (strcmp(args[0], "remindme") == 0)
	{
		remindme(args);
		return 1;
	}
    
    if (strcmp(args[0], "setenv") == 0)
    {
        execute_setenv(args);
        return 1;
    }
        
    if (strcmp(args[0], "unsetenv") == 0) 
    {
        execute_unsetenv(args);
        return 1;
    }
    if (strcmp(args[0], "jobs") == 0) 
    {
        execute_jobs(args);
        return 1;
    }
    if (strcmp(args[0], "kjob") == 0) 
    {
        execute_kjob(args);
        return 1;
    }

    if (strcmp(args[0], "fg") == 0) 
    {
        execute_fg(args);
        return 1;
    }

    if (strcmp(args[0], "bg") == 0) 
    {
        execute_bg(args);
        return 1;
    }

    return launch_command(args, in, out); // we use execvp!
}

int launch_command(char **args, int in, int out)
{

	int pid, wpid;
  	int status;

  	pid = fork();
    
  	if (pid == 0) 
  	{
  		if(bg==1)
            setpgid(0,0);
        
        if (execvp(args[0], args) == -1) 
      		perror("shell");
    	exit(EXIT_FAILURE);
  	} 
  	
    else if (pid < 0) 
  	{
   		// Error forking
    	perror("Error forking!");
  	} 
  	
    else 
  	{

        if(bg==0)
    	{
            curPID = pid;
            // do 
            // {
            wpid = waitpid(pid, &status, WUNTRACED);
            // } while (!WIFEXITED(status) && !WIFSIGNALED(status));
            // curPID = -1;
            
	    }

	    else 
	    {
	    	printf("Process with Pid: %lld has started.\n",(long long int)pid);

	    	process_list[process_count].pid = (long long int) pid;
            strcpy(process_list[process_count].pname, args[0]);
            strcpy(process_list[process_count++].status, "running");

	    }

  	}
  	return 1;
}