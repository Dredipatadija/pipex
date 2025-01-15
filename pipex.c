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

void	ft_parent(char **argv, int *pipefd, char **envp, int outfd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		MSJ ERROR, CLOSE OUTFD Y EXIT
	if (pid1 == 0)
		ft_child1(argv, pipefd, envp, outfd);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			MENSAJE DE ERROR, CLOSE OUTFD Y EXIT
		close(pipefd[1]);
		if (pid2 == 0)
			ft_child2(argv, pipefd, envp, outfd);
		else
		{
			close_fds(pipefd[0], outfd);
			waitpid(pid1, NULL, 0);
			waitpid(pid2, NULL, 0);
		}
	}
}

void	ft_child1(char **argv, int *pipefd, char **envp, int outfd)
{
	close(pipefd[0]);
	close(outfd);
	if (dup2(pipefd[1], 1) == -1)
		MSJ ERROR Y SALIDA;
	close(pipefd[1]);
	ft_execute(argv[2], envp);
}

void	ft_child2(char *cmd, int *pipefd, char **envp, int outfd)
{
	char	**s_cmd;
	char	*path;

	close(pipefd[1]);
	if (dup2(outfd, 1) == -1)
		MSJ ERROR, CLOSE OUTFD Y SALIDA;
	close(outfd);
	if (dup2(pipefd[0], 0) == -1)
		MSJ ERROR Y SALIDA.
	close(pipefd[0]);
	ft_execute(argv[3], envp);
}
void	ft_execute(char *cmd, char **envp)
{
	char	**str_cmd;
	char	*path;

	str_cmd = ft_split(cmd, ' ');
	if (str_cmd[0][0] != '.' && str_cmd[0][0] != '/')
		path = ft_getpath(envp);
	else
	{
		if (access(cmd, F_OK) == 0)
			path = str_cmd[0];
	}
	if (path != NULL && access(path, X_OK) == 0)
		execve(path, str_cmd, envp);
	else
		MSJ ERROR, LIBERAR STR_CMD Y SALIDA;
}

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	infd;
	int	outfd;

	if (argc != 5)
		MSJ ERROR Y SALIDA!!!
	if (pipe(pipefd) == -1)
		MSJ ERROR Y SALIDA!!!
	infd = ft_openin(argv[1]);
	if (infd > 0)
	{
		if (dup2(infd, 0) == -1)
			MSJ ERROR, CLOSE INTFD Y SALIDA!!!
		close(infd);
	}
	outfd = ft_openout(argv[4]);
	if (infd == -1)
		ft_child2(argv[3], pipefd, envp, outfd);
	else
		ft_parent(argv, pipefd, envp, outfd);
	return (0);
}
