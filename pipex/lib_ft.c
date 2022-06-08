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

char	*ft_strdup(const char *s1)
{
	char			*str;
	unsigned int	i;

	str = (char *)malloc(ft_strlen((char *)s1) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *s1++;
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen((char *)s1);
	l2 = ft_strlen((char *)s2);
	str = ft_calloc(l1 + l2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcat(str, s1, l1 + 1);
	l2 = l2 + l1;
	ft_strlcat(str, s2, l2 + 1);
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
	str = (char *)malloc(len + 1 * (sizeof(char)));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start])
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	char			*tab;

	if (!s1 || !set)
		return (NULL);
	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	i = ft_strlen((char *)s1);
	while (i > 0)
		if (!ft_strchr(set, s1[--i]))
			break ;
	tab = ft_substr(s1, 0, i + 1);
	return (tab);
}
