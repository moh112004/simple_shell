#include "main.h"

/**
 * executeCommand - Execute a command provided as a string.
 * @command: The command to be executed.
 *
 * Return: On success 0
 */
int executeCommand(char *command)
{
pid_t pid = fork();
char *argv[] = {"", NULL};

if (pid == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(command, argv, NULL) == -1)
{
perror("./shell");
exit(EXIT_FAILURE);
}
}
else
wait(NULL);
return (0);
}
