#include "main.h"

/**
 * main - Entry point of the program.
 *
 * Return: returns 0 On success.
 */
int main(void)
{
char *line;
size_t len = 0;
ssize_t read;

while (1)
{
if (isatty(STDIN_FILENO))
write(1, "#cisfun$ ", 9);
read = getline(&line, &len, stdin);
if (read == -1)
{
if (isatty(STDIN_FILENO))
perror("./shell");
break;
}
line[read - 1] = '\0';
executeCommand(line);
}
free(line);
return (0);
}
