#include "../headers.h"

void generate_commandline()
{
	uname(&unameData);
    char *hai;
    hai = "USER";
    char hostname[1024];
    gethostname(hostname, 1024);
    printf(ANSI_COLOR_RED "%s@", getenv(hai));
    // printf("%s:", unameData.machine);
    printf(ANSI_COLOR_CYAN " %s:", hostname);
    printf(ANSI_COLOR_RESET);
    printf("%s ", addr);
}