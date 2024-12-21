int main(int argc, char **argv, char **envp)
{
    int pipefd[2];
    int fdin;
    int fdout;

    if (argc != 5)
    {
        perror("Invalid number of arguments");
        exit(1);
    }
    if (pipe(pipefd) == -1)
        ERROR;
    fdin = ft_open_in();
}