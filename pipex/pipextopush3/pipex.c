/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:45:10 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/08 15:00:32 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	dup_close(int in, int out)
{
	int	dup_;

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
	if (i + 1 < cmd->nbrcmd)
	{
		if (i == 0)
		{
			if (cmd->files[0] < 0)
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
	if ((accs(cmd[i].cmdp)))
		if (cmd->files[0] >= 0 || i != 0)
			ft_printf("command not found: %s\n", cmd[i].cmd[0]);
	i = ++*r;
	if (cmd->nbrcmd > i)
	{
		close(fdp[1]);
		tofork(cmd, env, i, fdp[0]);
	}
}

void	tofork(t_cp *cmd, char **env, int i, int fd2)
{
	pid_t	pid;
	int		fdp[2];

	if (pipe(fdp) < 0)
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
		if (pid == -1)
			return ;
		parent(cmd, fdp, &i, env);
	}
}

int	main(int ac, char **av, char **env)
{
	t_cp	*cmdp;

	cmdp = NULL;
	if (ac < 5)
		return (0);
	if (!*env)
		return (0);
	cmdp = checkheredoc(cmdp, ac, av, env);
	if (cmdp->nbrcmd < 2)
	{
		if (cmdp)
			free(cmdp);
		return (0);
	}
	joinpath(cmdp);
	tofork(cmdp, env, 0, 0);
	freeing(cmdp);
	return (0);
}
