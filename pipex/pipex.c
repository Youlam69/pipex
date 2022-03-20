#include <stdlib.h>
#include "pipex.h"

char	**splitpath(char **env)
{
	char *path;
	char **splited;
	int i = 0;

	while (env[i])
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
	int i;
	i = -1;

	while(++i < nbrcmd)
		cmdp[i].cmd = ft_split(av[i + 2], ' ');
}

int	accs(char *path)
{
	int opn;
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

void	joinpath(char **splitedp, t_cp **cmd, int nbrcmd)
{
	int i;
	int j;
	char *pathj;
	char *tmp;
	i = 0;
	j = 0;
	while(j < nbrcmd && (*cmd)[j].cmd[0])
	{
		i = 0;
		while(splitedp[i])
		{
			tmp = ft_strjoin(splitedp[i], "/");
			pathj = ft_strjoin(tmp, (const char *)((*cmd)[j].cmd[0]));
			free(tmp);
			if(accs(pathj) == 0)
			{
				(*cmd)[j].cmdp = pathj;
				break;
			}
			free(pathj);
			i++;
		}
		if(!splitedp[i])
			(*cmd)[j].cmdp = strdup("\0");
		j++;
	}
}
int checkpath(char *path)
{
	if(path[0] == '\0')
		return(-1);
	return 0;
}
void tofork(t_cp *cmd, int fdof, int nbrcmd, char **env, char *name, int i, int fd2)
{
	pid_t pid;
	t_pipe fdp;

	pid = -2;
	if(pipe(fdp.fd) < 0)
	{
		perror("Error");
		return;
	}
	if (nbrcmd > i)
	{
		pid = fork();
		if (pid == -1)
			return ;
	}
	else
		return ;
	if (pid == 0)
	{
		close(fdp.fd[0]);
		if(i + 1 < nbrcmd )
		{
			dup2(fdp.fd[1], 1);
			close(fdp.fd[1]);
			if(i > 0)
				dup2(fd2,0);
		}
		else if (i + 1 == nbrcmd)
		{
			dup2(fd2, 0);
			dup2(fdof, 1);
			close(fdof);
			close(fd2);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
	}
	else
	{
		wait(NULL);
		i++;
		if(nbrcmd > i)
		{
			if (pid == -2)
			{
				printf("hi makayn walo - 2\n");
				close(fdp.fd[1]);
				fdp.fd2[0] = 0;
			}
			else if(pid == -1)
				return ;
			close(fdp.fd[1]);
			tofork(cmd, fdof, nbrcmd, env, name, i, fdp.fd[0]);
			// close(fdp.fd[0]);
		}
	}
}

int	main(int ac, char **av, char **env)
{
	char	**splitedp;
	int		nbrcmd = ac - 3;
	t_cp	*cmdp;
	int		fdof;
	int i = 0;
	int j = 0;
	if (ac < 4)
		return 0;
	if(!env)
		return 0;
	cmdp = malloc(nbrcmd * sizeof(t_cp) );
	splitedp = splitpath(env);
	splitav(av, nbrcmd, cmdp);
	joinpath(splitedp, &cmdp, nbrcmd);
	fdof = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	tofork(cmdp, fdof, nbrcmd, env, av[nbrcmd + 2], i, 0);
	while(i < nbrcmd)
	{
		j = 0;
		while(cmdp[i].cmd[j])
		{
			free(cmdp[i].cmd[j]);
			j++;
		}
		free(cmdp[i].cmd);

		free(cmdp[i].cmdp);
		i++;
	}
	free(cmdp);
	i = 0;
	while (splitedp[i])
	{
		free(splitedp[i]);
		i++;
	}
	free(splitedp);
	

/****************************************************/
/**********************FOR_TEST**********************/
	// printf("hada libghit  = %s\n", cmdp[0].cmd[0]);
	// int j,f;
	// j = 0;

	// while(cmdp[j].cmd && j < nbrcmd)
	// {
	// 		printf("cmd %d daz\n", j+1);
	// 		fflush(stdout);
	// 		write(1,"C\n",2);
	// 	f=0;
	// 	while( cmdp[j].cmd && cmdp[j].cmd[f]) 			
	// 	{
	// 		printf("hada prm  = %s\n", cmdp[j].cmd[f]);
	// 		fflush(stdout);
	// 		f++;
	// 	}
	// 	printf("hada lien r9m : %d \n", j);
	// 	printf("hada lien  = %s\n", cmdp[j].cmdp);
	// 		fflush(stdout);
	// 	j++;
	// }
	// printf("hada ln2  = %s\n", cmdp[1].cmd[0]);

	// while(cmdp[j].cmdp && j < nbrcmd)
	// {
	// 	printf("cmd %d daz\n", j+1);
	// 	fflush(stdout);
	// 	write(1,"O\n",2);			
	// 	fflush(stdout);
	// 	j++;
	// }
		// f =0;
		// while(cmdp[].cmd[f])			
		// {
		// 	printf("hada prm  = %s\n", cmdp[j].cmd[f]);
		// 	fflush(stdout);
		// 	f++;
		// }
	// printf("hi");
	// 		fflush(stdout);
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