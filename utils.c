/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:17:35 by arenilla          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:36 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_freearray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	ft_openin(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		if (access(file, F_OK) == 0)
			ft_putstr_fd("pipex: permission denied: ", 2);
		else
			ft_putstr_fd("pipex: no such file or directory: ", 2);
		ft_putendl_fd(file, 2);
	}
	return (fd);
}

int	ft_openout(char *file, int *pipefd, int bool)
{
	int	fd;

	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd < 0)
	{
		if (access(file, F_OK) == 0)
		{
			ft_putstr_fd("pipex: permission denied: ", 2);
			ft_putendl_fd(file, 2);
		}
		close(pipefd[0]);
		close(pipefd[1]);
		if (bool == 1)
			wait(NULL);
		exit(1);
	}
	return (fd);
}

char	*ft_getpath(char *cmd, char **envp)
{
	int		i;
	char	**wholepath;
	char	*path;
	char	*pathcmd;

	i = 0;
	if (ft_getenv("PATH", envp) == NULL && access(cmd, 0) == 0)
		return (cmd);
	if (ft_getenv("PATH", envp) == NULL)
		return (NULL);
	wholepath = ft_split(ft_getenv("PATH", envp), ':');
	while (wholepath[i] != NULL)
	{
		path = ft_strjoin(wholepath[i], "/");
		pathcmd = ft_strjoin(path, cmd);
		free(path);
		if (access(pathcmd, F_OK | X_OK) == 0)
		{
			ft_freearray(wholepath);
			return (pathcmd);
		}
		free(pathcmd);
		i++;
	}
	return (ft_freearray(wholepath));
}

char	*ft_getenv(char *str, char **envp)
{
	int		i;
	int		j;
	char	*var;

	i = 0;
	while (envp[i] != NULL)
	{
		j = 0;
		while (envp[i][j] != '\0' && envp[i][j] != '=')
			j++;
		var = ft_substr(envp[i], 0, j);
		if (ft_strncmp(var, str, ft_strlen(str)) == 0)
		{
			free(var);
			return (envp[i] + j + 1);
		}
		free(var);
		i++;
	}
	return (NULL);
}
