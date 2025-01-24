#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipe	data;

	if (argc < 5)
		ERROR Y SALIR;
	ft_check_cmds(&data, argc, argv);
}