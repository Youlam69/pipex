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

void	splitav(char **av, t_cp *cmdp)
{
	int i;

	i = -1;
	while(++i < cmdp->nbrcmd)
		cmdp[i].cmd = ft_split(av[i + 2 + cmdp->her_exist], ' ');
}

int		accs(char *path)
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

void	joinpath(t_cp *cmd, int nbrcmd)
{
	int		i;
	int		j;
	char	*tmp;

	j = -1;
	while (++j < nbrcmd && cmd[j].cmd[0])
	{
		i = -1;
		while (cmd->splitedp[++i])
		{
			tmp = ft_strjoin(cmd->splitedp[i], "/");
			cmd[j].cmdp = ft_strjoin(tmp, (cmd[j].cmd[0]));
			free(tmp);
			if (accs(cmd[j].cmdp) == 0)
				break;
			free(cmd[j].cmdp);
		}
		if (!cmd->splitedp[i])
			cmd[j].cmdp = strdup(cmd[j].cmd[0]);
	}
}
void	tofork (t_cp *cmd, char **env, int i, int fd2)
{
	pid_t pid;
	int fdp[2];

	pid = -2;
	if(pipe(fdp) < 0)
	{
		perror("Error");
		return ;
	}
	if (cmd->nbrcmd > i)
	{
		pid = fork();
		if (pid == -1)
			return ;
	}
	else
		return ;
	if (pid == 0)
	{
		close(fdp[0]);
		if(i + 1 < cmd->nbrcmd )
		{
			if (i == 0)
			{
				if(cmd->files[0] < 0)
					exit(1);
				dup2(fdp[1], 1);
				close(fdp[1]);
				dup2(cmd->files[0], 0);
			}
			if(i > 0)
			{
				dup2(fdp[1], 1);
				dup2(fd2,0);
				close(fd2);
			}
		}
		else if (i + 1 == cmd->nbrcmd)
		{
			dup2(fd2, 0);
			close(fd2);
			dup2(cmd[0].files[1], 1);
			close(cmd[0].files[1]);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
		exit(1);
	}
	else
	{
		if(accs(cmd[i].cmdp))
			ft_printf("command not found: %s\n", cmd[i].cmd[0]);
		i++;
		if(cmd->nbrcmd > i)
		{
			//to modified cuz i will read from pipe not in put//
			if (pid == -2)
			{
				close(fdp[1]);
				// fdp2[0] = 0;
			}
			/*****************************************************/
			else if(pid == -1)
				return ;
			close(fdp[1]);
			tofork(cmd, env, i, fdp[0]);
		}
		wait(NULL);
	}
}

// pipex here_doc LIMITER cmd cmd1 file
// void	checkfile(t_cp *cmdp, char **av)
// {
// 	cmdp->files[0] = open(av[1], O_RDONLY, 0644);
// 	if (cmdp->files[0] < 0)
// 	{
// 		// cmdp[0].files[0] = open("/dev/null", O_RDONLY, 0644);
// 		ft_printf("%s: %s\n", strerror(errno), av[1]);
// 		printf("%s: %s |WWWW %d |\n", strerror(errno), av[1], cmdp->files[0]);
// 		// if (cmdp->nbrcmd == 1)
// 		// 	return (0);
// 	}
// }

char	*joinheredoc(char **av)
{
	char	*hd_content;
	char	*limiter;

	hd_content = NULL;
	while (1)
	{
		// printf("|hada hd_cntnt|%s|\n", hd_content);
		// fflush(stdout);
		limiter = get_next_line(0);
		if(ft_strcmp(av[2], limiter) != -10)
{

				printf("|hada hd_cntnt waaast|%s|\n", hd_content);
		fflush(stdout);
			hd_content = ft_strjoin(hd_content, limiter);
							printf("|hada hd_cntnt waaast|%s|\n", hd_content);
		fflush(stdout);
}
		else
			break;
		free(limiter);
	}
	free(limiter);
	return (hd_content);
}

void	checkfile(t_cp *cmdp, char **av)
{
	int		pp[2];
	char	*hd_content;
	char	*txt;

	if(cmdp->her_exist == 0)
	{
		cmdp->files[0] = open(av[1], O_RDONLY, 0644);
	
		if (cmdp->files[0] < 0)
		{
			// cmdp[0].files[0] = open("/dev/null", O_RDONLY, 0644);
			ft_printf("%s: %s\n", strerror(errno), av[1]);
			// printf("%s: %s |WWWW %d |\n", strerror(errno), av[1], cmdp->files[0]);
			// if (cmdp->nbrcmd == 1)
			// 	return (0);
		}
	}
	else
	{
		// printf("|raqm d file lmaleun = %d|\n", cmdp->files[0]);
		// fflush(stdout);
		
		hd_content = joinheredoc(av);
		
		printf("|hada hd_cntnt|%s|\n", hd_content);
		fflush(stdout);

		txt = ft_calloc(strlen(hd_content), sizeof(char));
		pipe(pp);
		write(pp[1], hd_content, strlen(hd_content));
		close(pp[1]);
		cmdp->files[0] = pp[0];
		close(pp[0]);

		
		printf("|raqm d file lmaleun 2 = %d|\n", cmdp->files[0]);
		fflush(stdout);

		// close(pp[0]);
		// exit(1);
	}
}

t_cp	*checkheredoc(t_cp *cmdp, int ac, char **av, char **env)
{
	if (!strcmp("here_doc", av[1])) //khzsni nbadal L ft_strcmp
	{
		cmdp = malloc((ac - 4) * sizeof(t_cp) );
		cmdp->nbrcmd = ac - 4;

		cmdp->her_exist = 1;
		checkfile(cmdp, av);
		// splitav(av, cmdp);
		cmdp->files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	else
	{
		cmdp = malloc((ac - 3) * sizeof(t_cp) );
		cmdp->nbrcmd = ac - 3;
		cmdp->her_exist = 0;
		checkfile(cmdp, av);
		// printf("hada raqm li khda infile : %d", cmdp->files[0]);
		// fflush(stdout);
		// splitav(av, cmdp);
		if(cmdp->nbrcmd > 1)
			cmdp[0].files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	splitav(av, cmdp);
	cmdp->splitedp = splitpath(env);
	return(cmdp);
}

int	main(int ac, char **av, char **env)
{
	// char	**splitedp;
	// int		nbrcmd = ac - 3;
	t_cp	*cmdp;
	int i = 0;
	int j = 0;
	if (ac < 4)
		return 0;
	if(!*env)
		return 0;

	cmdp = checkheredoc(cmdp, ac, av, env);
	if(cmdp->nbrcmd < 2)
		return 0;
	joinpath(cmdp, cmdp->nbrcmd);
	// cmdp[0].files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);

	tofork(cmdp, env, 0, 0);
	// while(i < cmdp->nbrcmd)
	// {
	// 	j = 0;
	// 	while(cmdp[i].cmd[j])
	// 	{
	// 		free(cmdp[i].cmd[j]);
	// 		j++;
	// 	}
	// 	free(cmdp[i].cmd);
	// 	free(cmdp[i].cmdp);
	// 	i++;
	// }
	// free(cmdp);
	// i = 0;
	// while (cmdp->splitedp[i])
	// {
	// 	free(cmdp->splitedp[i]);
	// 	i++;
	// }
	// free(cmdp->splitedp);
	return 0;
}

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