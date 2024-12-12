#ifndef "PIPEX_H"
# define "PIPEX_H"

# include <unistd.h>
# include <stdlib.h>

int		main(int argc, char **argv, char **envp);
void	ft_error1(char *str);
void	ft_error2(char *str, int fd);
int		ft_openin(char *file);
int		fd_openout(char *file);

#endif