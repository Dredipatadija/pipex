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
