// Header Files
#include<stdio.h>
#include <sys/wait.h> //waitpid
#include <unistd.h> //chdir, fork, exec, pid_t
#include <stdlib.h> //malloc, realloc, free, exit, execvp
#include <string.h> //strcmp, strtok
#include <sys/utsname.h> //uname 
#include <dirent.h> // scandir
#include<fcntl.h>
#include<sys/types.h> // stat
#include<sys/stat.h> // stat
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <signal.h>

#define LSH_TOK_BUFSIZE 64
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//Global Variables
char addr[256];
char directory[1000];
struct utsname unameData;
char home_addr[256];
int a,b;

typedef struct 
{
	int pid;
	char pname[100];
	char status[100];
}processes;

int shellPID;
int curPID;
char curPROCESS[100];
int process_count;
processes process_list[1000];

int bg;
int ctr_arg;
int is_pipe;
int no_of_pipes;

char input_file[100];
char output_file[100];
char append_file[100];

int inp_redir;
int op_redir;
int app_redir;
int fd1, fd2, fd3;

int ctrlZ;

//Function Declarations
void remindme(char **args);
void execute_ls(char **args);
void execute_pwd();
void execute_lsl();
void execute_lsa();
void execute_lsla();
void execute_simple_ls();
int execute_cd(char **args);
void execute_ls(char **args);
int execute_help(char **args);
int execute_exit(char **args);
int execute_command(char **args, int in, int out);
int launch_command(char **args, int in, int out);
int execute_help(char **args);
void execute_echo(char **args);
void pinfo(int number);
void execute_clock(char **args);
void execute_setenv(char **args);
void execute_unsetenv(char **args);
void execute_jobs(char **args);
int execute_pipes(char *args2);
char **split_command(char *line, char *DELIM);
char *read_command(void);
void shell_loop();
void redirection(char **args);
void execute_fg(char **args);
