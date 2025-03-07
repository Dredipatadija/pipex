/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:17:09 by arenilla          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:11 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error1(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error2(char *str, int fd, int *pipefd)
{
	ft_putstr_fd(str, 2);
	close(pipefd[0]);
	close(pipefd[1]);
	close(fd);
	exit(1);
}

void	ft_endparent(int *pipefd, int outfd, int pid1, int pid2)
{
	int	status1;
	int	status2;

	close(pipefd[0]);
	close(pipefd[1]);
	close(outfd);
	waitpid(pid1, &status1, 0);
	waitpid(pid2, &status2, 0);
	if (status1 == 1)
		exit(WEXITSTATUS(status1));
	if (status2 != 0)
		exit(WEXITSTATUS(status2));
}

void	ft_error3(char *str, char *cmd, char *s)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
	exit(127);
}

void	ft_error4(char *str, char *file, char *s)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(s, 2);
	ft_putchar_fd('\n', 2);
}