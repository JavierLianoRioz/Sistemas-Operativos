#include <stdio.h>

int contarDigitos(int);

int main(void) {
  printf("Introduce un número entero: ");
  int numero;
  scanf("%i", &numero);
  int longitud = contarDigitos(numero);
  printf("longitud: %i \n", longitud);
  return 0;
}

int contarDigitos(int numero) {
  if (numero == 0) {
    return 0;
  } else {
    return (1 + contarDigitos(numero / 10));
  }
};
