/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:54:13 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/26 04:35:15 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	searchnewline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*to_alloc(int fd, char *str, int *r1)
{
	char	*tmp;
	int		r;

	r = 1;
	while (searchnewline(str) == -1 && r)
	{
		tmp = ft_callocgt(1 + 1, sizeof(char));
		if (!tmp)
			return (NULL);
		r = read(fd, tmp, 1);
		if (r <= 0)
		{
			free(tmp);
			tmp = NULL;
			if (r < 0)
				return (NULL);
		}
		str = ft_strjoingt(str, tmp);
		if (tmp)
			free(tmp);
		tmp = NULL;
	}
	*r1 = r;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str[10240];
	char		*tmp;
	int			r1;
	int			stock;
	char		*toswitch;

	if (fd < 0 || 1 <= 0)
		return (NULL);
	stock = 0;
	str[fd] = to_alloc(fd, str[fd], &r1);
	toswitch = str[fd];
	stock = searchnewline(str[fd]);
	if (r1 <= 0)
		stock = ft_strlengt(str[fd]);
	tmp = ft_substrgt(str[fd], 0, stock + 1);
	if (!tmp)
		return (NULL);
	str[fd] = ft_substrgt(str[fd], stock + 1, ft_strlengt(str[fd]));
	free(toswitch);
	if (r1 <= 0)
	{
		free(str[fd]);
		str[fd] = NULL;
	}

	return (tmp);
}
