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

int		main(int argc, char **argv, char **envp);
void	ft_error1(char *str);
void	ft_error2(char *str, int infd, int outfd);
void	ft_error3(char *str, char **cmd, int outfd);
void	ft_error4(char *str, int outfd);
int		ft_openin(char *file);
int		ft_openout(char *file);
void	ft_pipe2(char *cmd, int *pipefd, char **envp, int outfd);
void	ft_pipes(char **argv, int *pipefd, char **envp, int outfd);
void	ft_pipe1(char **argv, int *pipefd, char **envp, int outfd);
void	ft_free(char **cmd);
char	*ft_getpath(char *cmd, char **envp);


#endif
