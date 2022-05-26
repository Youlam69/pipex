/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:54:36 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/26 03:53:17 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*c1;
	unsigned char	*c2;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	while ((*c1 || *c2))
	{
		if (*c1 != *c2)
			return (*c1 - *c2);
		c1++;
		c2++;
	}
	return (0);
}

size_t	ft_strlengt(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_callocgt(size_t count, size_t size)
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

char	*ft_strcatgt(char *dst, char *src)
{
	size_t	i;
	size_t	lendst;

	if (!src)
		return (dst);
	i = -1;
	lendst = ft_strlengt(dst);
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
	l1 = ft_strlengt(s1);
	l2 = ft_strlengt(s2);
	str = ft_callocgt(l1 + l2 + 1, sizeof(char));
	str[l1 + l2] = '\0';
	if (!str)
		return (NULL);
	ft_strcatgt(str, s1);
	ft_strcatgt(str, s2);
	// if (s1)
	// {
	// 	free(s1);
	// 	s1 = NULL;
	// }
	return (str);
}

char	*ft_substrgt(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;

	if (!s)
		return (NULL);
	if (start > ft_strlengt(s))
		len = 0;
	if (len > ft_strlengt(s) - start)
		len = ft_strlengt(s) - start;
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
