#include <stdlib.h>
#include "pipex.h"

char	**splitpath(char **env)
{
	char *path;
	char **splited;
	int i = 0;
	while(env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		if (path)
		{
			path = ft_strtrim(path, "PATH=");
			break;
		}
		i++;
	}

	splited = ft_split(path, ':');
	free(path);
	return (splited);
}

void	splitav(char **av, int nbrcmd, t_cp *cmdp)
{
	int i = -1;
	while(++i < nbrcmd)
		cmdp[i].cmd = ft_split(av[i + 2], ' ');
}

int	accs(char *path)
{
	if (access(path, F_OK))
		return 1;
	if (open(path, O_DIRECTORY) < 0)
	{
		if (!(access(path, X_OK)))
			return (0);
		else
			return (2);
	}
	return (3);
}
char	*joinpath(char **splitedp, t_cp *cmd)
{
	int i;

	i = 0;
	while(s)
	{
		
	}
	i = 0
}
int main(int ac, char **av, char **env)
{

	int i = 0;
	char ** splitedp;
	int nbrcmd = ac - 3;
	t_cp	*cmdp;
	cmdp = malloc((nbrcmd) * sizeof(t_cp) );

	splitedp = splitpath(env);
	splitav(av, nbrcmd, cmdp);


	// while(i <= nbrcmd)
	// {
	// 	cmdp[i].cmd = ft_split(av[i + 2], ' ');
	// 	i++;
	// }
	int j,f;
	j = 0;

	while(cmdp[j].cmd && j < nbrcmd)
	{
			printf("cmd %d daz\n", j+1);
			fflush(stdout);
			write(1,"C\n",2);
		f=0;
		while( cmdp[j].cmd && cmdp[j].cmd[f]) 			
		{
			printf("hada prm  = %s\n", cmdp[j].cmd[f]);
			fflush(stdout);
			f++;
		}

		j++;
	}
				// f =0;
				// while(cmdp[].cmd[f])			
				// {
				// 	printf("hada prm  = %s\n", cmdp[j].cmd[f]);
				// 	fflush(stdout);
				// 	f++;
				// }
	printf("hi");
			fflush(stdout);
	// i = 2;
	// int j = 0;
	// int t;
	// while(i < argc)
	// {
	// 	tmp = ft_split(argv[i++], ' ');
	// 	cmnd[j++] = tmp[0];
	// 	t=0;
	// 	while(++tmp)
	// 	{
	// 		prm[t] = 

	// 	}
	// 	// cmnd = ft_split(argv[i], ' ');
	// 	// if(i = 2)
	// 		cmdp->cmd = ft_lstnew(cmnd[0]);
	// 	// else
	// 	// 	anjoute node akhra
	// 	// 	lstback wa9ila
	// 	// 	zn3amrha

	// 	// while(cmnd[j + 1])
	// 	// {
	// 	// 	cmdp->prm[j] = cmnd[j + 1];
	// 	// 	j++;
	// 	// }
	// }

	// while(cmnd->next)
	// {
	// 	pipex()
	// }
	// dup( 0;fd)
	
}