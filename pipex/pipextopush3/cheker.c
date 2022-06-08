/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:45:49 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/08 11:45:50 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		if (ft_strcmp(tmp, limiter) != 0)
		{
			free(tmp);
			tmp = hd_content;
			hd_content = ft_strjoin(hd_content, limiter);
			frfr(tmp, limiter);
		}
		else
		{
			frfr(tmp, limiter);
			break ;
		}
	}
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
	cmdp = malloc((ac - 4) * sizeof(t_cp));
	cmdp->nbrcmd = ac - 4;
	cmdp->her_exist = 1;
	if (cmdp->nbrcmd > 1)
	{
		checkfile(cmdp, av);
		cmdp->files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	}
	return (cmdp);
}

t_cp	*alloctoelse(t_cp *cmdp, char **av, int ac)
{
	cmdp = malloc((ac - 3) * sizeof(t_cp));
	cmdp->nbrcmd = ac - 3;
	cmdp->her_exist = 0;
	if (cmdp->nbrcmd > 1)
	{
		checkfile(cmdp, av);
		cmdp[0].files[1] = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	}
	return (cmdp);
}

t_cp	*checkheredoc(t_cp *cmdp, int ac, char **av, char **env)
{
	if (!ft_strcmp("here_doc", av[1]))
		cmdp = allocheredoc(cmdp, av, ac);
	else
		cmdp = alloctoelse(cmdp, av, ac);
	if (cmdp->nbrcmd > 1)
	{
		splitav(av, cmdp);
		cmdp->splitedp = splitpath(env);
	}
	return (cmdp);
}
