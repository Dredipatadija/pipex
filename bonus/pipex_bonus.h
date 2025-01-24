#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

typedef struct	s_list
{
	char			*cmd;
	int				fd;
	struct s_list	*next;
}				  	t_list;

typedef struct	s_pipe
{
	int		n_cmds;
	t_list	*list;
}					t_pipe;