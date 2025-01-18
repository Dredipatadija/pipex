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
	perror(str);
	exit(1);
}

void	ft_error2(char *str, int fd)
{
	perror(str);
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
	if (status2 != 0)
		exit(WEXITSTATUS(status2));
}

void	ft_error3(char *str)
{
	perror(str);
	exit(127);
}
