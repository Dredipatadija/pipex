#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infd;
	int	outfd;

	if (argc != 5)
		ft_error1("Error: Invalid number of arguments\n");
	if (pipe(pipefd) == -1)
		ft_error1("Error: Pipe failed\n");
	infd = ft_openin(argv[1]);
	if (infd > 0)
	{
		if (dup2(infd, 0) == -1)
			ft_error2("Error: Dup2 failed\n", infd);
		close(infd);
	}
	outfd = ft_openout(argv[4]);
	if (infd == -1)
		ft_pipe2(argv[3], pipefd, envp, outfd);
	else
		ft_pipes(argv, pipefd, envp, outfd);
	return (0);
}
