/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:54:36 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/08 09:55:35 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strcatgt(char *dst, char *src)
{
	size_t	i;
	size_t	lendst;

	if (!src)
		return (dst);
	i = -1;
	lendst = ft_strlen(dst);
	while (src[++i])
		dst[lendst + i] = src[i];
	dst[lendst + i] = '\0';
	return (dst);
}

char	*ft_strjoingt(char *s1, char *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	str = ft_calloc(l1 + l2 + 1, sizeof(char));
	str[l1 + l2] = '\0';
	if (!str)
		return (NULL);
	ft_strcatgt(str, s1);
	ft_strcatgt(str, s2);
	return (str);
}

char	*ft_substrgt(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	str = (char *)malloc((sizeof(char) * len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	if (str[0] == '\0')
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	return (str);
}
