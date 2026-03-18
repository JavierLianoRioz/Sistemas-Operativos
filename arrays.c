#include <stdio.h>

int main(void) {
  int misNumeros[4] = {25, 50, 75, 100};
  int iterador;
  int *puntero = misNumeros;

  // printf("%p\n", misNumeros);
  // printf("%p\n", &misNumeros);
  // printf("%p\n", &misNumeros);
  // printf("%d\n", *misNumeros);

  for (iterador = 0; iterador < 4; iterador++) {
    printf("%d en %p\n", *puntero, puntero + 1);
    puntero = puntero + 1;
  }

  return 0;
}
