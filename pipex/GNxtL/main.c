#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

// #include "../libft.h"


int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while ((*c1 || *c2))
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

// int	ft_strcmp(const char *s1, const char *s2, size_t n)
// {
// 	unsigned char	*c1;
// 	unsigned char	*c2;

// 	c1 = (unsigned char *)s1;
// 	c2 = (unsigned char *)s2;
// 	while ((*c1 || *c2) && n--)
// 	{
// 		if (*c1 != *c2)
// 			return (*c1 - *c2);
// 		c1++;
// 		c2++;
// 	}
// 	return (0);
// }

char	*joinheredoc(char **av)
{
	char	*hd_content;
	char	*limiter;

	hd_content = NULL;
	while (1)
	{
		limiter = get_next_line(0);
		if(ft_strcmp(av[1], limiter) != -10) 
			hd_content = ft_strjoin(hd_content, limiter);
		else
			break;
		free(limiter);
	}
	free(limiter);
	return (hd_content);
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	printf("%s", joinheredoc(av));
	return 0;
}
