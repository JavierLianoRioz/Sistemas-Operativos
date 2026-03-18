#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 20

int main()
{
	char comando[20];

	do
	{
		scanf("%s", comando);
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("ERROR AL CREAR HIJO");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			if (strcmp(comando, "ls") == 0)
			{
				execlp("/bin/ls", "ls", "-l", NULL);
			}
			else if (strcmp(comando, "pwd") == 0)
			{
				execlp("/bin/pwd", "pwd", NULL);
			}
			exit(EXIT_SUCCESS);
		}
	} while (strcmp(comando, "exit") != 0);

	return EXIT_SUCCESS;
}
