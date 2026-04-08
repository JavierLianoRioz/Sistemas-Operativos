// Papa crea un hijo.
// Papa tiene un buffer de 100 bytes de caracteres. Un array de 100 caracteres
// char. El usuario introduce una cadena. El padre envia al hijo la cadena. El
// hijo cuenta el número de vocales que hay en la cadena. Y le devuelve al padre
// ese número.
// El padre saca el número por pantalla.
// Y nos vamos de paseo.
// Papa crea un hijo.
// Papa tiene un buffer de 100 bytes de caracteres. Un array de 100 caracteres
// char. El usuario introduce una cadena. El padre envia al hijo la cadena. El
// hijo cuenta el número de vocales que hay en la cadena. Y le devuelve al padre
// ese número.
// El padre saca el número por pantalla.
// Y nos vamos de paseo.
// Papa crea un hijo.
// Papa tiene un buffer de 100 bytes de caracteres. Un array de 100 caracteres
// char. El usuario introduce una cadena. El padre envia al hijo la cadena. El
// hijo cuenta el número de vocales que hay en la cadena. Y le devuelve al padre
// ese número.
// El padre saca el número por pantalla.
// Y nos vamos de paseo.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char buffer[100];

char *preguntarPorString()
{
	puts("Enviame un texto");
	fgets(buffer, sizeof(buffer), stdin);
	return buffer;
}

int esVocal(char letra)
{
	letra = tolower(letra);
	if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' ||
	    letra == 'u')
	{
		return EXIT_SUCCESS;
	}
	return EXIT_FAILURE;
}

int contarVocales(char *unBuffer)
{
	int contador = 0;
	for (int i = 0; i < strlen(unBuffer) - 1; i++)
	{
		char letra = unBuffer[i];
		if (esVocal(letra) == 0)
		{
			contador++;
		}
	}
	return contador;
}

int main(void)
{
	int tuberiaPadreAHijo[2];
	int tuberiaHijoAPadre[2];
	int numeroDeVocales;

	pipe(tuberiaPadreAHijo);
	pipe(tuberiaHijoAPadre);

	pid_t pid = fork();

	errorCreandoHijo(pid);
	if (isPadre(pid))
	{
		char *buffer = preguntarPorString();

		close(tuberiaPadreAHijo[0]);
		write(tuberiaPadreAHijo[1], buffer, strlen(buffer) + 1);
		close(tuberiaPadreAHijo[1]);

		close(tuberiaHijoAPadre[1]);
		read(tuberiaHijoAPadre[0], &numeroDeVocales,
		     sizeof(numeroDeVocales));
		close(tuberiaHijoAPadre[0]);

		printf("hay %i vocales.\n", numeroDeVocales);

		wait(NULL);
	}
	if (isHijo(pid))
	{
		close(tuberiaPadreAHijo[1]);
		read(tuberiaPadreAHijo[0], buffer, sizeof(buffer));
		close(tuberiaPadreAHijo[0]);

		numeroDeVocales = contarVocales(buffer);

		close(tuberiaHijoAPadre[0]);
		write(tuberiaHijoAPadre[1], &numeroDeVocales,
		      sizeof(numeroDeVocales));
		close(tuberiaHijoAPadre[0]);

		exit(EXIT_SUCCESS);
	}
	return EXIT_SUCCESS;
}
