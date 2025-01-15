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

void	*ft_freearray(**array)
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
			perror("Permission denied:");
		else
			perror("File not found: ");
		write(2, file, ft_strlen(file));
	}
	return (fd);
}

int	ft_openout(char *file)
{
	int	fd;

	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT, 0644);
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
	}
	return (ft_freearray(wholepath));
}

ft_getenv()