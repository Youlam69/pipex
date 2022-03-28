#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/errno.h>

typedef struct s_cp
{
	char			**cmd;
	char			*cmdp;
	char			**splitedp;\
	// int 			fdof[];
	int				files[2];
	int				fd[2];
	int 			fd2[1];
	char 			*pathj;
	char 			*tmp;
	int				nbrcmd[1];
}					t_cp;

typedef struct s_pipe
{
	struct s_pipe	*next;
}					t_pipe;
// char	*ft_strjoin(char const *s1, char const *s2);
// char	*ft_strtrim(char const *s1, char const *set);
// char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
// char	*ft_substr(char const *s, unsigned int start, size_t len);
// char	**ft_split(char const *s, char c);
// t_list	*ft_lstnew(void *content);
// void	ft_lstadd_front(t_list **lst, t_list *new);
// int		ft_lstsize(t_list *lst);
// t_list	*ft_lstlast(t_list *lst);
// void	ft_lstadd_back(t_list **lst, t_list *new);
// void	ft_lstdelone(t_list *lst, void (*del)(void*));
// void	ft_lstiter(t_list *lst, void (*f)(void *));
// t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
// void	ft_lstclear(t_list **lst, void (*del)(void*));

#endif