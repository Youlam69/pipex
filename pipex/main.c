#include <stdlib.h>
#include "pipex.h"
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main(int ac, char ** av,char **env)
{
	int rtr;
	int fd[2];
	int pid;
	char *sort;
	sort = malloc(4444);
	if(ac < 1)
		return 0;
	if (pipe(fd) == -1)
		return 0;
	int in;
	pid = fork();
	if(pid == 0)
	{
		close(fd[0]);
		write(fd[1], "haliol", 6);
		close(fd[1]);
	}
	else
	{
		// close(fd[1]);
		rtr = read(fd[0], sort, sizeof(sort));
		// close(fd[0]);

		printf("hada rtr %d\n", rtr);
		fflush(stdout);
		printf("hada sort %s\n", sort);
		fflush(stdout);

		write(fd[1], "123", 3);
		// close(fd[1]);

		rtr = read(fd[0], sort, sizeof(sort));
		// close(fd[0]);
				printf("hada rtr 2 %d\n", rtr);
		fflush(stdout);
		printf("hada sort  1 %s\n", sort);
		fflush(stdout);

		wait(NULL);
	}
}