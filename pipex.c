#include "pipex.h"

void	ft_pipe2(char *cmd, int *pipefd, char **envp, int outfd, int infd)
{
	char	**s_cmd;

	close(pipefd[1]);
	if (dup2(outfd, 1) == -1)
		ft_error2("Error: Dup2 failed at the output\n", infd, outfd);
	close(outfd);
	if (dup2(pipefd[0], 0) == -1)
		ft_error2("Error: Dup2 failed at the input\n", infd, outfd);
	close(pipefd[0]);
	s_cmd = ft_split(cmd, ' ');
	if (execve(s_cmd[0], s_cmd, envp) == -1)
		ft_error3("Command not found", s_cmd, infd, outfd);
}

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
	outfd = ft_openout(argv[4]);
	if (infd > 0)
	{
		if (dup2(infd, 0) == -1)
			ft_error2("Error: Dup2 failed\n", infd, outfd);
		close(infd);
		ft_pipes(argv, pipefd, envp, outfd, infd);
	}
	else if (infd == -1)
		ft_pipe2(argv[3], pipefd, envp, outfd, infd);
	return (0);
}
