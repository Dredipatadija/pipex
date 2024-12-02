#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];

	if (argc != 5)
		ft_error1("Error: Invalid number of arguments\n");
	if (pipe(pipefd) == -1)
		ft_error1("Error: Pipe failed\n");
}
