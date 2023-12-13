#include "main.h"

/**
 * main - Entry point of the program
 *
 * Return: returns 0 in success
 */
int main(void)
{
char *line;
size_t len = 0;
ssize_t read;

while (1)
{
write(1, "#cisfun$ ", 9);
read = getline(&line, &len, stdin);
line[strcspn(line, "\n")] = '\0';
executeCommand(line);
if (read == -1)
{
perror("./shell");
break;
}
}
free(line);
return (0);
}
