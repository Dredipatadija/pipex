/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arenilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:17:53 by arenilla          #+#    #+#             */
/*   Updated: 2024/12/21 13:17:55 by arenilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <libft.h>
# include <sys/wait.h>
# include <fcntl.h>

int		main(int argc, char **argv, char **envp);
void	ft_execute(char *cmd, char **envp);
void	ft_parent(char **argv, int *pipefd, char **envp);
void	ft_child1(char **argv, int *pipefd, char **envp);
void	ft_child2(char **argv, int *pipefd, char **envp, int outfd);
int		ft_openin(char *file);
int		ft_openout(char *file, int *pipefd, int bool);
char	*ft_getpath(char *cmd, char **envp);
char	*ft_getenv(char *str, char **envp);
void	*ft_freearray(char **array);
void	ft_error1(char *str);
void	ft_error2(char *str, int fd, int *pipefd);
void	ft_error3(char *str, char *cmd, char *s);
void	ft_error4(char *str, char *file, char *s);
void	ft_endparent(int *pipefd, int outfd, int pid1, int pid2);

#endif
