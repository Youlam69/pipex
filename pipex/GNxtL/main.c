#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*joinheredoc(char **av)
{
	int		i;
	char	*hd_content;
	char	*limiter;
	char	*tmp;

	limiter = NULL;
	hd_content = NULL;
	while (1)
	{
		exit(1);
		limiter = get_next_line(0);
		if (!strcmp(av[2], limiter))
		{
			tmp = hd_content;
			hd_content = ft_strjoin(hd_content, limiter);
			free(tmp);
			free(limiter);
		}
		else
		{
			free(limiter);
			break;
		}
	}
	return (hd_content);
	// hd_content = get
	// while (hd_content != delimiter)
	// {
	// 	//join (hd_content,'\n');
	// }
}
int main(int ac, char **av)
{
	int a = 0;
	a = ac;
	printf("%s", joinheredoc(av));
	return 0;
}
