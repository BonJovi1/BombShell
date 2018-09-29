#include "../headers.h"

void execute_lsl()
{
	struct dirent **fileList;
	int count = scandir(".", &fileList, NULL, alphasort);
	struct stat f_stat;
	char timer[1000];

	if(count >= 0)
	{
		for(int i=0;i<count;i++)
		{
			if(fileList[i]->d_name[0]=='.')
				continue;
			if(stat(fileList[i]->d_name, &f_stat)==0)
			{
				if(S_ISDIR(f_stat.st_mode)!=0)
						fprintf(stdout, "%1s","d");
				else
					fprintf(stdout, "%1s","-");
				
				if((f_stat.st_mode & S_IRUSR)!=0)
					fprintf(stdout, "%1s","r");
				else
					fprintf(stdout, "%1s","-");
				
				if((f_stat.st_mode & S_IWUSR)!=0)
					fprintf(stdout, "%1s","w");
				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IXUSR)!=0)
					fprintf(stdout, "%1s","x");
				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IRGRP)!=0)
					fprintf(stdout, "%1s","r");
				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IWGRP)!=0)
					fprintf(stdout, "%1s","w");
				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IXGRP)!=0)
					fprintf(stdout, "%1s","x");

				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IROTH)!=0)
					fprintf(stdout, "%1s","r");
				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IWOTH)!=0)
					fprintf(stdout, "%1s","w");

				else
					fprintf(stdout, "%1s","-");

				if((f_stat.st_mode & S_IXOTH)!=0)
					fprintf(stdout, "%1s","x");

				else
					fprintf(stdout, "%1s","-");
			}
			fprintf(stdout, "%2ld ",(unsigned long)(f_stat.st_nlink));
            fprintf(stdout, "%s ",(getpwuid(f_stat.st_uid))->pw_name);
            fprintf(stdout, "%s ",(getgrgid(f_stat.st_gid))->gr_name);
            fprintf(stdout, "%10lld ",(unsigned long long)f_stat.st_size);
            strftime (timer,14,"%h %d %H:%M",localtime(&f_stat.st_mtime));
            fprintf(stdout, "%s ",timer);
            fprintf(stdout, "%s ",fileList[i]->d_name);
			fprintf(stdout, "\n");


			free(fileList[i]);
		}

	}
	fprintf(stdout, "\n");
	free(fileList);

}