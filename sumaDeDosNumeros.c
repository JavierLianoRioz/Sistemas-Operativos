// Creamos un pipe, creamos un hijo.
// Papa lee un numero y se lo envia al hijo.
// Papa lee un segundo numero y se lo envia al hijo.
// Se los pasa al hijo por la tubería, el hijo saca por la pantalla la suma.
// El padre espera a que termine el hijo.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
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

int preguntarPorNumero()
{
	int numero;
	puts("Dime un número");
	scanf("%i", &numero);
	return numero;
}

int main(void)
{
	int tuberia[2];
	int numero1, numero2;

	pipe(tuberia);

	pid_t pid = fork();

	errorCreandoHijo(pid);
	if (isPadre(pid))
	{
		close(tuberia[0]);

		numero1 = preguntarPorNumero();
		write(tuberia[1], &numero1, sizeof(numero1));

		numero2 = preguntarPorNumero();
		write(tuberia[1], &numero2, sizeof(numero2));

		close(tuberia[1]);
		wait(NULL);
	}
	if (isHijo(pid))
	{
		close(tuberia[1]);

		read(tuberia[0], &numero1, sizeof(numero1));
		read(tuberia[0], &numero2, sizeof(numero2));

		int suma;
		suma = numero1 + numero2;

		printf("Suma: %i + %i = %i\n", numero1, numero2, suma);

		close(tuberia[0]);
		exit(EXIT_SUCCESS);
	}
	return EXIT_SUCCESS;
}
