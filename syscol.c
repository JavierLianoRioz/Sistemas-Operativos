#include <stdio.h>
#include <string.h>

int pedirTamañoArray();
void pedirValoresArray(char *);
void imprimirArray(char *);
int pedirEditarUnValorArray(char *);
void editarValorArray(char *, int);
char pedirValor();

int main(void) {
  int tamañoArray = pedirTamañoArray() + 1;
  char array[tamañoArray];
  pedirValoresArray(array);
  imprimirArray(array);
  while (1) {
    int posicion = pedirEditarUnValorArray(array);
    editarValorArray(array, posicion);
    imprimirArray(array);
  }

  return 0;
}

int pedirTamañoArray() {
  int tamaño;
  puts("Introduce el número de elementos del array");
  scanf("%i", &tamaño);
  return tamaño;
}

void pedirValoresArray(char *array) {
  puts("Introduce los valores del array \n");
  for (int index = 0; index < strlen(array); index++) {
    *(array + index) = pedirValor();
  }
}

void imprimirArray(char *array) {
  puts("\n");
  for (int index = 0; index < strlen(array); index++) {
    if (array[index] != '\n') {
      printf("%c ", array[index]);
    }
  }
  puts("\n");
}

int pedirEditarUnValorArray(char *array) {
  puts("Introduce la posicion a editar en el Array \n");
  int posicion;
  int esValido;
  do {
    scanf("%i", &posicion);

    if (posicion > strlen(array) || posicion < 0) {
      esValido = 0;
      puts("Error, fuera del rango \n");
    } else {
      esValido = 1;
    }

  } while (!esValido);

  return posicion - 1;
}

void editarValorArray(char *array, int posicion) {
  puts("¿Qué valor quieres poner?");
  char valor = pedirValor();
  if (valor != '\n') {
    *(array + posicion) = valor;
  }
}

char pedirValor() {
  char valor;
  scanf("%c", &valor);
  return valor;
}
