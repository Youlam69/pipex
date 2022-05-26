/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:54:25 by ylamraou          #+#    #+#             */
/*   Updated: 2022/05/26 03:52:08 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlengt(const char *str);
char	*ft_callocgt(size_t count, size_t size);
char	*ft_strcatgt(char *dst, char *src);
char	*ft_strjoingt(char *s1, char *s2);
char	*ft_substrgt(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);


#endif
