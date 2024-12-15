#include "pipex.h"

char	*ft_getpath(char *cmd, char **envp)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			j = 5;
			while (envp[i][j] != '\0')
			{
				if (envp[i][j] == ':')
					path = ft_strjoin(ft_strjoin(
								ft_strjoin(ft_substr(
										envp[i], 5, j - 5), "/"), cmd));
				j++;
			}
		}
		i++;
	}
	return (path);
}

void	ft_pipes(char **argv, int *pipefd, char **envp, int outfd)
{
	pid_t	pid;
	pid_t	pid_two;

	pid = fork();
	if (pid == -1)
		exit(1);
	if (!pid)
		ft_pipe1(argv, pipefd, envp, outfd);
	else
	{
		pid_two = fork();
		if (pid_two == -1)
			exit(1);
		close(pipefd[1]);
		if (!pid_two)
			ft_pipe2(argv, pipefd, envp, outfd);
		else
		{
			close_fds(pipefd, outfd);
			waitpid(pid, NULL, 0);
			waitpid(pid_two, NULL, 0);
		}
	}
}

void	ft_pipe1(char **argv, int *pipefd, char **envp, int outfd)
{
	char	**s_cmd;
	char	*path;

	close(pipefd[0]);
	close(outfd);
	if (dup2(pipefd[1], 1) == -1)
		ft_error4("Error: Dup2 failed at the output\n", outfd);
	close(pipefd[1]);
	s_cmd = ft_split(argv[3], ' ');
	if (s_cmd == NULL || s_cmd[0] == NULL)
		ft_error3("Error: Command not found", s_cmd, outfd);
	if (s_cmd[0][0] != '.' && s_cmd[0][0] != '/')
		path = ft_getpath(s_cmd[0], envp);
	else
	{
		if (access(argv[3], 0) == 0)
			path = s_cmd[0];
	}
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, s_cmd, envp);
	else
		ft_error5("Error: Command not found\n", s_cmd);
}

void	ft_pipe2(char *cmd, int *pipefd, char **envp, int outfd)
{
	char	**s_cmd;
	char	*path;

	close(pipefd[1]);
	if (dup2(outfd, 1) == -1)
		ft_error4("Error: Dup2 failed at the output\n", outfd);
	close(outfd);
	if (dup2(pipefd[0], 0) == -1)
		ft_error4("Error: Dup2 failed at the input\n", outfd);
	close(pipefd[0]);
	s_cmd = ft_split(cmd, ' ');
	if (s_cmd == NULL || s_cmd[0] == NULL)
		ft_error3("Error: Command not found", s_cmd, outfd);
	if (s_cmd[0][0] != '.' && s_cmd[0][0] != '/')
		path = ft_getpath(s_cmd[0], envp);
	else
	{
		if (access(cmd, 0) == 0)
			path = s_cmd[0];
	}
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, s_cmd, envp);
	else
		ft_error5("Error: Command not found\n", s_cmd);
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
		ft_pipes(argv, pipefd, envp, outfd);
	}
	else if (infd == -1)
		ft_pipe2(argv[3], pipefd, envp, outfd);
	return (0);
}
