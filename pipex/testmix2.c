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

void	joinpath(t_cp *cmd)
{
	int		i;
	int		j;
	char	*tmp;

	j = -1;
	while (++j < cmd->nbrcmd && cmd[j].cmd[0])
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

int	dup_close(int in, int out)
{
	int dup_;

	dup_ = dup2(in, 0);
	if (dup_ < 0)
		return (dup_);
	dup_ = dup2(out, 1);
	if (dup_ < 0)
		return (dup_);
	return (0);
}
void	child(t_cp *cmd, int *fdp, int fd2, int i)
{
	close(fdp[0]);
	if (i + 1 < cmd->nbrcmd )
	{
		if (i == 0)
		{
			if(cmd->files[0] < 0)
			exit(1);
			dup_close(cmd->files[0], fdp[1]);
		}
		else
			dup_close(fd2, fdp[1]);
	}
	else
		dup_close(fd2, cmd->files[1]);
}

void	parent(t_cp *cmd, int *fdp, int *r, char **env)
{
	int	i;
	
	i = *r;
	if(accs(cmd[i].cmdp))
		ft_printf("command not found: %s\n", cmd[i].cmd[0]);
	i = ++*r;
	if(cmd->nbrcmd > i)
	{
		close(fdp[1]);
		tofork(cmd, env, i, fdp[0]);
	}
}

void	tofork (t_cp *cmd, char **env, int i, int fd2)
{
	pid_t pid;
	int fdp[2];

	if(pipe(fdp) < 0)
	{
		perror("Error");
		return ;
	}
	pid = fork();
	if (pid == -1)
		return ;
	if (pid == 0)
	{
		child(cmd, fdp, fd2, i);
		execve(cmd[i].cmdp, cmd[i].cmd, env);
		exit(1);
	}
	else
	{
		if(pid == -1)
			return ;
		parent(cmd, fdp, &i, env);
		wait(NULL);
	}
}

char	*joinheredoc(char **av)
{
	char	*hd_content;
	char	*limiter;
	char	*tmp;

	hd_content = NULL;
	while (1)
	{
		ft_printf("> ");
		limiter = get_next_line(0);
		tmp = ft_strjoin(av[2], "\n");
		if(strcmp(tmp, limiter) != 0)
		{
			free(tmp);
			tmp = hd_content;
			hd_content = ft_strjoin(hd_content, limiter);
			if (tmp)
				free(tmp);
		}
		else
			break;
		if (limiter)
			free(limiter);
	}
	free(limiter);
	return (hd_content);
}

void	checkfile(t_cp *cmdp, char **av)
{
	int		pp[2];
	char	*hd_content;

	if (cmdp->her_exist == 0)
	{
		cmdp->files[0] = open(av[1], O_RDONLY, 0644);
		if (cmdp->files[0] < 0)
			ft_printf("%s: %s\n", strerror(errno), av[1]);
	}
	else
	{
		hd_content = joinheredoc(av);
		pipe(pp);
		if (hd_content)
		{
			write(pp[1], hd_content, ft_strlen(hd_content));
			free(hd_content);
		}
		close(pp[1]);
		cmdp->files[0] = pp[0];
	}
}

t_cp	*allocheredoc(t_cp *cmdp, char **av, int ac)
{
	cmdp = malloc((ac - 4) * sizeof(t_cp) );
	cmdp->nbrcmd = ac - 4;
	cmdp->her_exist = 1;
	if(cmdp->nbrcmd > 1)
	{
		checkfile(cmdp, av);
		cmdp->files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	return (cmdp);
}

t_cp	*alloctoelse(t_cp *cmdp, char **av, int ac)
{
	cmdp = malloc((ac - 3) * sizeof(t_cp) );
	cmdp->nbrcmd = ac - 3;
	cmdp->her_exist = 0;
	if(cmdp->nbrcmd > 1)
	{
		checkfile(cmdp, av);
		cmdp[0].files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	return (cmdp);
}

t_cp	*checkheredoc(t_cp *cmdp, int ac, char **av, char **env)
{
	if (!ft_strcmp("here_doc", av[1])) // ft_strcmp khqs tkun qzbi
		cmdp = allocheredoc(cmdp, av, ac);
	else
		cmdp = alloctoelse(cmdp, av, ac);
	if(cmdp->nbrcmd > 1)
	{
		splitav(av, cmdp);
		cmdp->splitedp = splitpath(env);
	}
	return(cmdp);
}

void	freeing(t_cp *cmdp)
{
	int i = 0;
	int j = 0;
	while (cmdp->splitedp[i])
	{
		free(cmdp->splitedp[i]);
		i++;
	}
	free(cmdp->splitedp);
		i = 0;
	while(i < cmdp->nbrcmd)
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
}

int	main(int ac, char **av, char **env)
{
	t_cp	*cmdp;

	cmdp = NULL;
	if (ac < 5)
		return 0;
	if(!*env)
		return 0;

	cmdp = checkheredoc(cmdp, ac, av, env);
	if(cmdp->nbrcmd < 2)
	{
		if(cmdp)
			free(cmdp);
		return 0;
	}
	joinpath(cmdp);
	tofork(cmdp, env, 0, 0);
	freeing(cmdp);
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
