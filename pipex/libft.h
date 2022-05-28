/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 01:30:57 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/28 01:14:53 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_printf(const char *str, ...);

size_t	ft_strlen(const char *s);

size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);



char	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);


#endif