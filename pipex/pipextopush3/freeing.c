/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:45:46 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/08 11:45:47 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
