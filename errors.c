#include "pipex.h"

void	ft_error1(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error2(char *str, int infd, int outfd)
{
	perror(str);
	close(infd);
	close(outfd);
	exit(1);
}

void	ft_error3(char *str, char **cmd, int outfd)
{
	perror(str);
	close(outfd);
	ft_free(cmd);
	exit(1);
}

void	ft_error4(char *str, int outfd)
{
	perror(str);
	close(outfd);
	exit(1);
}

void	ft_error5(char *str, char **cmd)
{
	perror(str);
	ft_free(cmd);
	exit(1);
}