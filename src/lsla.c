#include "../headers.h"

void execute_lsla()
{
	struct dirent **fileList;
	int count = scandir(".", &fileList, NULL, alphasort);
	struct stat f_stat;
	char timer[1000];

	if(count >= 0)
	{
		for(int i=0;i<count;i++)
		{
			// if(fileList[i]->d_name[0]=='.')
			// 	continue;
			if(stat(fileList[i]->d_name, &f_stat)==0)
			{
				if(S_ISDIR(f_stat.st_mode)!=0)
						printf("%1s","d");
				else
					printf("%1s","-");
				
				if((f_stat.st_mode & S_IRUSR)!=0)
					printf("%1s","r");
				else
					printf("%1s","-");
				
				if((f_stat.st_mode & S_IWUSR)!=0)
					printf("%1s","w");
				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IXUSR)!=0)
					printf("%1s","x");
				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IRGRP)!=0)
					printf("%1s","r");
				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IWGRP)!=0)
					printf("%1s","w");
				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IXGRP)!=0)
					printf("%1s","x");

				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IROTH)!=0)
					printf("%1s","r");
				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IWOTH)!=0)
					printf("%1s","w");

				else
					printf("%1s","-");

				if((f_stat.st_mode & S_IXOTH)!=0)
					printf("%1s","x");

				else
					printf("%1s","-");
			}
			printf("%2ld ",(unsigned long)(f_stat.st_nlink));
            printf("%s ",(getpwuid(f_stat.st_uid))->pw_name);
            printf("%s ",(getgrgid(f_stat.st_gid))->gr_name);
            printf("%10lld ",(unsigned long long)f_stat.st_size);
            strftime (timer,14,"%h %d %H:%M",localtime(&f_stat.st_mtime));
            printf("%s ",timer);
            printf("%s ",fileList[i]->d_name);
			printf("\n");


			free(fileList[i]);
		}

	}
	printf("\n");
	free(fileList);

}