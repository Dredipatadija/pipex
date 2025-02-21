void	ft_check_cmds(t_pipe *data, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(av[1])) == 0)
	{
		data->hered = 1;
		data->n_cmds = argc - 4;
	}
	else
	{
		data->hered = 0;
		data->n_cmds = argc - 3;
	} 
}