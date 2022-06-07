/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:33:21 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/25 23:02:41 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = -1;
	s = malloc(count * size);
	if (!s)
		return (0);
	while (++i < count * size)
		s[i] = '\0';
	return (s);
}
