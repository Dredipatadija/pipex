/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:17:42 by arenilla          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:44 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_parent(char **argv, int *pipefd, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		outfd;

	pid1 = fork();
	if (pid1 == -1)
		ft_error1("'fork' function failure to the 1st child\n");
	if (pid1 == 0)
		ft_child1(argv, pipefd, envp);
	else
	{
		outfd = ft_openout(argv[4], pipefd, 1);
		pid2 = fork();
		if (pid2 == -1)
			ft_error2("'fork' function failure to the 2nd child\n", outfd);
		close(pipefd[1]);
		if (pid2 == 0)
			ft_child2(argv, pipefd, envp, outfd);
		else
			ft_endparent(pipefd, outfd, pid1, pid2);
	}
}

void	ft_child1(char **argv, int *pipefd, char **envp)
{
	close(pipefd[0]);
	if (dup2(pipefd[1], 1) == -1)
		ft_error1("'dup2' function failure in the 1st child\n");
	close(pipefd[1]);
	ft_execute(argv[2], envp);
}

void	ft_child2(char **argv, int *pipefd, char **envp, int outfd)
{
	close(pipefd[1]);
	if (dup2(outfd, 1) == -1)
		ft_error2("'dup2' function failure with outfile fd\n", outfd);
	close(outfd);
	if (dup2(pipefd[0], 0) == -1)
		ft_error1("'dup2' function failure in the 2nd child\n");
	close(pipefd[0]);
	ft_execute(argv[3], envp);
}

void	ft_execute(char *cmd, char **envp)
{
	char	**str_cmd;
	char	*path;

	str_cmd = ft_split(cmd, ' ');
	if (str_cmd[0][0] != '.' && str_cmd[0][0] != '/')
		path = ft_getpath(str_cmd[0], envp);
	else
	{
		if (access(cmd, F_OK) == 0)
			path = str_cmd[0];
		else
			path = NULL;
	}
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, str_cmd, envp);
	else
	{
		ft_freearray(str_cmd);
		ft_error3("Command not found or not executable\n");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infd;
	int	outfd;

	if (argc != 5)
		ft_error1("Try with './pipex infile cmd cmd outfile'\n");
	if (pipe(pipefd) == -1)
		ft_error1("'pipe' function failure\n");
	infd = ft_openin(argv[1]);
	if (infd > 0)
	{
		if (dup2(infd, 0) == -1)
			ft_error2("'dup2' function failure with infile fd\n", infd);
		close(infd);
	}
	if (infd < 0)
	{
		outfd = ft_openout(argv[4], pipefd, 0);
		ft_child2(argv, pipefd, envp, outfd);
	}
	else
		ft_parent(argv, pipefd, envp);
	return (0);
}
