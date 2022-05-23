/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:54:36 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/23 00:07:26 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

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

char	*ft_strcat(char *dst, char *src)
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

char	*ft_strjoin(char *s1, char *s2)
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
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
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
