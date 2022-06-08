#include "pipex.h"

void	frfr(char *str, char *ptr)
{
	if (str)
		free(str);
	if (ptr)
		free(ptr);
}

void	freeing(t_cp *cmdp)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (cmdp->splitedp[i])
	{
		free(cmdp->splitedp[i]);
		i++;
	}
	free(cmdp->splitedp);
		i = 0;
	while (i < cmdp->nbrcmd)
	{
		j = 0;
		while (cmdp[i].cmd[j])
		{
			free(cmdp[i].cmd[j]);
			j++;
		}
		free(cmdp[i].cmd);
		free(cmdp[i].cmdp);
		i++;
	}
	free(cmdp);
}
