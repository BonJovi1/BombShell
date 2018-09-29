#include "../headers.h"

void redirection(char **args)
{
    for(int j=0; args[j]!=NULL; j++)
    {
        if(strcmp(args[j], "<") == 0)
        {
            args[j] = NULL;
            strcpy(input_file, args[j+1]);
            // args[j+1] = NULL;
            inp_redir=1;
        }

        else if(strcmp(args[j], ">") == 0)
        {
            args[j] = NULL;
            // strcpy(args[j], "\0");
            strcpy(output_file, args[j+1]);
            // args[j+1] = NULL;
            op_redir=1;
        }

        else if(strcmp(args[j], ">>") == 0)
        {
            args[j] = NULL;
            strcpy(append_file, args[j+1]);
            // args[j+1] = NULL;
            app_redir=1;
        }

    }

    if(inp_redir == 1)
    {
        fd1 = open(input_file, O_RDONLY, 0);
        // dup2(a,0);
        
        if(fd1 < 0) 
            perror("Error opening input file");
        // printf("%s", input_file);
        // a = dup(0);
        // b = dup(1);
        dup2(fd1, 0);
        close(fd1);
        inp_redir=0;

    }

    if(op_redir == 1)
    {
        // dup2(b,1);
        fd2 = open(output_file, O_WRONLY | O_TRUNC | O_CREAT , 0644);
        
        if(fd2 < 0) 
            perror("Error opening output file");
        // a = dup(0);
        // b = dup(1);
        dup2(fd2, 1);
        close(fd2);
        op_redir=0;

    }

    if(app_redir == 1)
    {
        // dup2(b,1);
        fd3 = open(append_file, O_WRONLY | O_APPEND);
        
        if(fd3 < 0) 
            perror("Error opening output file");
        // a = dup(0);
        // b = dup(1);
        dup2(fd3, 1);
        close(fd3);
        app_redir=0;
     
    }
}