#include "pipex.h"

void	ft_free(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

void	ft_error1(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error2(char *str, int infd, int outfd)
{
	perror(str);
	close(infd, outfd);
	exit(1);
}

void	ft_error3(char *str, char **cmd, int infd, int outfd)
{
	perror(str);
	close(infd, outfd);
	ft_free(cmd);
	exit(1);
}
