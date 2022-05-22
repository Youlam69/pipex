#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

// #include "../libft.h"


// int	ft_strcmp(const char *s1, const char *s2)
// {
// 	unsigned char	*c1;
// 	unsigned char	*c2;

// 	c1 = (unsigned char *)s1;
// 	c2 = (unsigned char *)s2;
// 	while ((*c1 || *c2))
// 	{
// 		if (*c1 != *c2)
// 			return (*c1 - *c2);
// 		c1++;
// 		c2++;
// 	}
// 	return (0);
// }

int	ft_strcmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while ((*c1 || *c2) && n--)
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

char	*joinheredoc(char **av)
{
	int		i = 1;
	int h = strlen(av[1]) + 2 ;
	char	*hd_content;
	char	*limiter;
	char	*tmp;
	char	*avlim;
	avlim = 
	printf("@%s@\n", av[1]);
	hd_content = NULL;
	while (1)
	{
		// exit(1);
		if (i != 0)
		{
			limiter = get_next_line(0);
			printf("contnt = |%s| .. LIMITER = #%s# .. av[1] = [%s]\n", hd_content, limiter, av[1]);
			i = ft_strcmp(av[1], limiter, (strlen(av[1])) + 1);
			printf("i = %i\n", i);
			tmp = hd_content;
			hd_content = ft_strjoin(hd_content, limiter);
			// if(tmp)
			// 	free(tmp);
		}
		else
		{
			// free(limiter);
			break;
		}
		
		// if (limiter)
		// 	free(limiter);
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
