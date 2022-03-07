#include <stdlib.h>
#include "pipex.h"

int main(int argc, char **argv, char **env)
{

	int i = 0;
	char ** splitedp;
	char *path1;
	char **cmnd;
	char **prm;
	char **tmp;
	int nbrcmd = argc - 4;
	t_cp	*cmdp;
	cmdp = malloc(nbrcmd * sizeof(t_cp));
	// if(argc < 5)
		// return 0;
	// printf("ana hna");
	while(env)
	{
		path1 = ft_strnstr(env[i], "PATH=", 5);
		if (path1)
		{
			path1 = ft_strtrim(path1, "PATH=");
			break;
		}
		env++;
		i++;
	}
	splitedp = ft_split(path1, ':');
		// printf("%s\n", splitedp[1]);

	free(path1);
	i = -1;
	while (splitedp[++i])
	{
		printf("%s\n", splitedp[i]);
		fflush(stdout);
		
	}

	i = 0;
	int j,f;
	// printf("ana hna");

	while(i <= nbrcmd)
	{
		cmdp[i].cmd = ft_split(argv[i + 2], ' ');

		i++;
	}
	j = 0;

	// while(cmdp[j].cmd)
	// {
	// 	f=0;
	// 	while(cmdp[j].cmd[f])			
	// 	{
	// 		printf("hada prm  = %s\n", cmdp[j].cmd[f]);
	// 		fflush(stdout);
	// 		f++;
	// 	}
	// 		printf("cmd %d daz\n", j);
	// 		fflush(stdout);

	// 	j++;
	// }

	// i = 2;
	// int j = 0;
	// int t;
	// while(i < argc)
	// {
	// 	tmp = ft_split(argv[i++], ' ');
	// 	cmnd[j++] = tmp[0];
	// 	t=0;
	// 	while(++tmp)
	// 	{
	// 		prm[t] = 

	// 	}
	// 	// cmnd = ft_split(argv[i], ' ');
	// 	// if(i = 2)
	// 		cmdp->cmd = ft_lstnew(cmnd[0]);
	// 	// else
	// 	// 	anjoute node akhra
	// 	// 	lstback wa9ila
	// 	// 	zn3amrha

	// 	// while(cmnd[j + 1])
	// 	// {
	// 	// 	cmdp->prm[j] = cmnd[j + 1];
	// 	// 	j++;
	// 	// }
	// }

	// while(cmnd->next)
	// {
	// 	pipex()
	// }
	// dup( 0;fd)
	
}