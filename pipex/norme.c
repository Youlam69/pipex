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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
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
			close(fd2);
			dup2(fdof, 1);
			close(fdof);
		}
		execve(cmd[i].cmdp, cmd[i].cmd, env);
	}