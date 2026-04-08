// Creamos un hijo.
// Papa va a crear 10 numeros aleatorios.
// Se los envia uno a uno al hijo por un pipe.
// El hijo va a averiguar cuales de estos numeros son primos y lo va imprimiendo
// por pantalla "Este es primo"//"Este no es primo" Y devuelve al padre el
// número de primos que ha encontrado.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

int isPadre(pid_t pid)
{
	return pid > 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

int isHijo(pid_t pid)
{
	return pid == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}

void errorCreandoHijo(pid_t pid)
{
	if (pid < 0)
	{
		exit(EXIT_FAILURE);
		perror("Error creando hijo");
	}
}

int generarNumeroAleatorio()
{
	int numero;
	srand(time(NULL));
	numero = rand() % 100 + 1;
	return numero;
}

int main(void)
{
	int tuberia[2];
	int numero;

	pipe(tuberia);

	pid_t pid = fork();

	errorCreandoHijo(pid);
	if (isPadre(pid))
	{
		close(tuberia[0]);

		for (int i = 0; i < 10; i++)
		{
			numero = generarNumeroAleatorio();
			write(tuberia[1], &numero, sizeof(numero));
		}

		close(tuberia[1]);
		wait(NULL);
	}
	if (isHijo(pid))
	{
		close(tuberia[1]);

		for (int i = 0; i < 10; i++)
		{
			read(tuberia[0], &numero, sizeof(numero));
			printf("numeros: %i \n", numero);
		}

		close(tuberia[0]);
		exit(EXIT_SUCCESS);
	}
	return EXIT_SUCCESS;
}
