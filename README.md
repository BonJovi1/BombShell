# Bombshell
## by Abhinav Gupta

bombshell:
/ˈbɒmʃɛl/
__noun__
* an unexpected and surprising event, especially an unpleasant one.
* a very attractive woman
* the most awesome shell implementation ever 

## Running the code:
* run make
* execute ./bombshell
* type 'exit' to exit the shell

## FILES
* main.c : main file which contains shell loop and parses commands and calls appropriate functions. 
* cd.c : Changes directory
* remindme.c : displays message on terminal after given time
* clock.c : displays time
* echo.c : echoes whatever is typed
* ls.c : Lists all directories. Flags taken care of with lsa.c, lsl.c and lsla.c
* others.c : 'help' and 'exit' commands
* pinfo.c : prints information about the process whose pid is entered
* prompt.c : Generates the prompt!
* pwd.c : displays present working directory. 
* setenv.c :
* unsetenv.c :
:sparkles: :sparkles:
* fg : brings running or stopped background process to foreground
* bg : changes a stopped background job to a running background job

Special Thanks to [Stephen Brennan](https://brennan.io/2015/01/16/write-a-shell-in-c/) for his amazing tutorial on how to get started! 
