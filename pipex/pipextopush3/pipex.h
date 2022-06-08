/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ylamraou <ylamraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:45:04 by ylamraou          #+#    #+#             */
/*   Updated: 2022/06/08 11:45:05 by ylamraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/errno.h>

typedef struct s_cp
{
	char			**cmd;
	char			*cmdp;
	char			**splitedp;
	int				files[2];
	int				fd[2];
	int				fd2;
	char			*pathj;
	char			*tmp;
	int				nbrcmd;
	int				her_exist;
}					t_cp;

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
void	tofork(t_cp *cmd, char **env, int i, int fd2);
size_t	ft_strlengt(const char *str);
char	*ft_callocgt(size_t count, size_t size);
char	*ft_strcatgt(char *dst, char *src);
char	*ft_strjoingt(char *s1, char *s2);
char	*ft_substrgt(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
int		ft_strcmp(const char *s1, const char *s2);
t_cp	*checkheredoc(t_cp *cmdp, int ac, char **av, char **env);
char	**splitpath(char **env);
int		accs(char *path);
void	splitav(char **av, t_cp *cmdp);
void	joinpath(t_cp *cmd);
void	frfr(char *str, char *ptr);
void	freeing(t_cp *cmdp);

#endif