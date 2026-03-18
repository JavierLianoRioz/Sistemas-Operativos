#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void imprimir(int *numeros, int cantidadDeNumeros);
void buscarNumero(int *numeros, int cantidadDeNumeros, int numeroABuscar);

int posicionDeBusqueda = 0;

int main(void)
{
	int cantidadDeNumeros = 10;
	int numeros[cantidadDeNumeros];
	for (int i = 0; i < cantidadDeNumeros; i++)
	{
		numeros[i] = i + 1;
	}
	imprimir(numeros, cantidadDeNumeros);
	int numeroABuscar = 5;
	buscarNumero(numeros, cantidadDeNumeros, numeroABuscar);
	return EXIT_SUCCESS;
}

void imprimir(int *numeros, int cantidadDeNumeros)
{
	for (int i = 0; i < cantidadDeNumeros - 1; i++)
	{
		printf("%i, ", numeros[i]);
	}
	printf("%i\n", numeros[cantidadDeNumeros - 1]);
}

int iteracion = 0;

int buscar1Numero(int *numeros, int numeroABuscar);
void buscar5Numeros(int *numeros, int numeroABuscar);

void buscarNumero(int *numeros, int cantidadDeNumeros, int numeroABuscar)
{
	int indice = 0;
	while (indice < cantidadDeNumeros)
	{
		buscar5Numeros(numeros, numeroABuscar);
		indice = indice + 5;
		iteracion++;
	}
}

int indice = 0;

void buscar5Numeros(int *numeros, int numeroABuscar)
{
	indice = 5 * iteracion;
	int encontrado = -1;
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("Error al crear al hijo");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (indice > 5 * iteracion)
		{
			exit(0);
		}
		else if (buscar1Numero(numeros, numeroABuscar))
		{
			encontrado = 1;
			exit(1);
		}
	}
}

int buscar1Numero(int *numeros, int numeroABuscar)
{
	if (numeros[indice] == numeroABuscar)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
