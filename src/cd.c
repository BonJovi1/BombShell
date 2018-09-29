#include "../headers.h"

int execute_cd(char **args)
{
	char temp[1000];
	int j = 0;

  	if (args[1] == NULL) 
    	fprintf(stderr, "lsh: expected argument to \"cd\"\n");
  	else 
  	{
    	if(strcmp(args[1],"~") == 0)
	    {
	    	chdir(home_addr);
	    	strcpy(addr, "~");
	    	return 1;

	    }
    	if (chdir(args[1]) != 0) 
      		perror("shell");
  	}
  	
  	getcwd(directory, 1000);

  	if(strcmp(args[1],".") == 0)
    	return 1;

    if (strcmp(directory, home_addr) == 0)
    	strcpy(addr, "~");
    
    else 
  	{
    	int check =0;
    	if(strlen(directory) >= strlen(home_addr))
    	{
      		for(int i = 0; i < strlen(home_addr); i++)
      		{
      			if(directory[i] != home_addr[i])
      			{
      				check=1;
      				break;
      			}
      		}
      		if(check == 0)
      		{
      			for (int i = strlen(home_addr); i < strlen(directory); i++)
      				temp[j++] = directory[i];
      	
      			strcpy(addr, "");
      			addr[0] = '~';
      			strcat(addr, temp);
      		}
      		else
      			strcpy(addr,directory);
  		}
  		else
  			strcpy(addr,directory);
  	}
  	return 1;
}