/*
 * funcion que invierta un array
 *
 * - NO VAMOS A UTILIZAR INDICES
 * - NO VAMOS A UTILIZAR UN ARRAY AUXILIAR
 */

#include <stdio.h>

void invertirArray(int *inicio, int tamaño);

int main(void) {
  int myNumbers[4] = {25, 50, 75, 100};

  int tamañoDelArray = (sizeof(myNumbers) / sizeof(myNumbers[0]));

  printf("%i", tamañoDelArray);
  puts("\n");

  imprimirArray(myNumbers);
  for (int i = 0; i < tamañoDelArray; i++) {
    printf("%d", *(myNumbers + i));
    puts("\n");
  }

  invertirArray(myNumbers, tamañoDelArray);

  for (int i = 0; i < tamañoDelArray; i++) {
    printf("%d", *(myNumbers + i));
    puts("\n");
  }
}

void invertirArray(int *inicio, int tamaño) {
  int *fin = inicio + (tamaño - 1);
  int aux1;
  int aux2;

  while (inicio < fin) {
    aux1 = *inicio;
    aux2 = *fin;
    *inicio = aux2;
    *fin = aux1;

    inicio++;
    fin--;
  }
}
