#include "pipex.h"

void	ft_error1(char *str)
{
	perror(str);
	exit(1);
}

void	ft_error2(char *str, int fd)
{
	perror(str);
	close(fd);
	exit(1);
}
