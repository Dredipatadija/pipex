/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   pipex.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: arenilla <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/12/21 14:25:39 by arenilla		  #+#	#+#			 */
/*   Updated: 2024/12/21 14:25:40 by arenilla		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int	main(int argc, char **argv, char **envp)
{
	int	pipefd[2];
	int	fdin;
	int	fdout;

	if (argc != 5)
	{
		perror("Invalid number of arguments");
		exit(1);
	}
	if (pipe(pipefd) == -1)
		ERROR;
	fdin = ft_open_in();
}
