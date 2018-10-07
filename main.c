#include "headers.h"

void sigintHandler(int sig_num) 
{ 
    if(getpid() != shellPID)
        return; 

    printf("\n To exit shell, please type exit \n");
    if(curPID != -1)
    {
        kill(curPID, SIGINT);
        for (int k = 0; k < process_count; k++)
        {
            if (process_list[k].pid == curPID)
            {
                strcpy(process_list[k].status, "killed");
                break;
            }
        }

    }
    
    // generate_commandline();
    fflush(stdout); 
} 

void sigintHandler3(int sig_num) 
{ 
    if(getpid() != shellPID)
        return; 
    
    printf("Ctrl Z was pressed \n"); 
    if(curPID != -1)
    {
	   
        int flag =0;
        kill(curPID, SIGTSTP);
        for(int i=0; i<process_count; i++)
        {
            if(process_list[i].pid == curPID)
            {
                flag =1;
                break;
            }
        }
        if ( flag ==0 )
        {
            process_list[process_count].pid = curPID;
            strcpy(process_list[process_count].pname, curPROCESS);
            strcpy(process_list[process_count++].status, "stopped");
        }

    }
    curPID=-1;
    // generate_commandline();
    fflush(stdout); 
    return;
} 

char *read_command(void)
{
	char *line = NULL;
  	ssize_t bufsize = 0; // have getline allocate a buffer for us
  	getline(&line, &bufsize, stdin);

    for(int i =0; line[i]!='\0'; i++)
    {
        if(line[i]=='|')
        {
            is_pipe=1;
            break;
        }
    }
  	return line;
}

int execute_pipes(char *args2)
{
    char **args3;
    char **args;
    args3 = split_command(args2, "|");
    int m=0;
    
    //No of commands to be executed that are separated by pipes! save, split, redirect, exec, putback
    while(args3[m]!=NULL)
    {
        no_of_pipes++;
        m++;
    }

    int in = 0;
    int fd[2];
    int c,d;
    
    int i;

    for (i = 0; i < no_of_pipes-1; i++) //until the second last command
    {
        c = dup(0);
        d = dup(1);
        args = split_command(args3[i], "  \t\r\n\a");
        
        pipe(fd);
        redirection(args);

        execute_command(args, in, fd[1]); 
        close(fd[1]);
        
        dup2(c,0);
        dup2(d,1);
        in=fd[0];
    } 

    int e,f;

    e=dup(0);
    f=dup(1);

    args = split_command(args3[i], "  \t\r\n\a");
    redirection(args);

    execute_command(args, in, 1);

    dup2(e,0);
    dup2(f,1);
    return 1;
}

void shell_loop()
{
	char *line;
  	char **args;
    char **args2;
    char **args3;
  	int status;
  	process_count = 0;
  	pid_t pid;
  	int status2;
    inp_redir = 0;
    op_redir = 0;
    app_redir = 0;
    

  	do 
  	{
        is_pipe=0;
        no_of_pipes=0;
        
        generate_commandline();
    	line = read_command();
        args2 = split_command(line, ";");//semi colon separated
        int k = 0;
        while(args2[k] != NULL)
        {
            while((pid = waitpid(-1, &status2, WNOHANG)) > 0) 
    		{
    	     	//bg process has ended
    	     	char pname[100];
    			for (int k = 0; k < process_count; k++)
    				if (process_list[k].pid == pid)
    				{
    					// process_list[k].pid = -1;
    					strcpy(process_list[k].status, "killed");
    					break;
    				}

    			if (WEXITSTATUS(status2) == 0)
    				printf("Process with pid %d exited normally\n", pid);
    			else
    				printf("Process with pid %d exited abnormally\n", pid);

    	    }
            
            if(is_pipe==1)
                status = execute_pipes(args2[k]);
            
            else
            {
                //Saving stdin and stdout
                a = dup(0);
                b = dup(1);
                
                args = split_command(args2[k], " \t\r\n\a");//taking care of spaces, tabs etc.
                redirection(args);
                status = execute_command(args, 0, 1);
                //Putting stdin and stdout back, as it may have changed during redirection
                dup2(a,0);
                dup2(b,1);
            }
            k++;
        } // while(args2[k] != NULL)
        
    	free(line);
  	} while (status);
} // shell_loop

int main(int argc, char **argv)
{
	curPID = -1;
    shellPID = getpid();
    ctrlZ = 0;
    signal(SIGINT, sigintHandler);
    // signal (SIGQUIT, sigintHandler2);
    signal (SIGTSTP, sigintHandler3);
    
    strcpy(addr, "~");
	getcwd(home_addr, 1000);
	
    shell_loop();

 	return 0;
}