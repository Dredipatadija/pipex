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
