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
			cmd[j].cmdp = ft_strjoin(tmp, (const char *)(cmd[j].cmd[0]));
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
	int fdpp[2];

	pid = -2;
	if(pipe(fdpp) < 0)
	{
		perror("Error");
		return ;
	}
	if (cmd->nbrcmd > i) //nbrcmnd
	{
		
		pid = fork();
		// printf("l9lawi m3aslin\n");

		if (pid == -1)
			return ;
	}
	else
	{

		// printf("l9lawi m3asli4444n\n");

		return ;
	}
	if (pid == 0)
	{
		// close(fdpp[0]);

		if (i == 0 && cmd->nbrcmd > 0)
		{
			dup2(cmd->files[0], 0);
			
			if (cmd->nbrcmd == 1)
			{
				dup2(cmd->files[1], 1);
				close(cmd->files[1]);
			}
			else
			{
			dup2(fdpp[1], 1);
			close(fdpp[1]);
			}
		}
		else if(i + 1 < cmd->nbrcmd ) // normalement khas maydkkhalch la kan ghir cmnd 1
		{
			dup2(fd2, 0);
			dup2(fdpp[1], 1);
			close(fd2);
			close(fdpp[1]);
		}
		else if (i + 1 == cmd->nbrcmd) // normalement khas maydkkhalch la kan ghir cmnd 1 oui effectivement a3chiry
		{
			dup2(fd2, 0);

			dup2(cmd[0].files[1], 1);
			close(cmd[0].files[1]);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
		exit(1);
	}
	else
	{
		// printf("check %d \n", cmd->her_exist);
		if((accs(cmd[i].cmdp)))
			ft_printf("command not found: %s\n", cmd[i].cmd[0]);
		i++;
		printf("hadi i = %d w nbr de cmnd = %d\n", i, cmd->nbrcmd);
		if(cmd->nbrcmd > i)
		{

		// printf("hadi i = %d w nbr de cmnd = %d\n dkhal1 \n", i, cmd->nbrcmd);

			/**to modified cuz i will read from pipe not in put**/
			if (pid == -2)
			{
				close(fdpp[1]);
				// fdp.fd2 = 0;
			}
			/*****************************************************/
			else if(pid == -1)
				return ;
			if (cmd->files[0] < 0 )
			// 	exit(1);
			close(fdpp[1]);
			tofork(cmd, env, i, fdpp[0]);
			// printf("anihna\n");
		}
		wait(NULL);
	}
}
// pipex here_doc LIMITER cmd cmd1 file
t_cp	*checkheredoc(t_cp *cmdp, int ac, char **av, char **env)
{
	if (!strcmp("here_doc", av[1]))
	{
		cmdp = malloc((ac - 4) * sizeof(t_cp) );
		cmdp->nbrcmd = ac - 4;
		cmdp->her_exist = 1;
		cmdp->files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		splitav(av, cmdp);
	}
	else
	{
		cmdp = malloc((ac - 3) * sizeof(t_cp) );
		cmdp->nbrcmd = ac - 3;
		cmdp->her_exist = 0;
		cmdp[0].files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		splitav(av, cmdp);
	}
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
	cmdp = checkheredoc(cmdp, ac, av, env);	//malloc(nbrcmd * sizeof(t_cp) );

	// splitav(av, nbrcmd, cmdp);
	// splitedp = splitpath(env);

	joinpath(cmdp, cmdp->nbrcmd);
	cmdp[0].files[0] = open(av[1], O_RDONLY, 0644);
	if (cmdp[0].files[0] < 0)
	{
		// cmdp[0].files[0] = open("/dev/null", O_RDONLY, 0644);
		printf("%s %s WWWW %d\n", strerror(errno), av[1], cmdp[0].files[0]);
		fflush(stdout);
	}
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