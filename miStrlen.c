// strlen utilizando aritmetica de punteros

#include <stdio.h>

int miStrlen(char *);

int main(int argc, char *argv[]) {
  char cadena[150];
  puts("Introduce una cadena");
  fgets(cadena, sizeof(cadena), stdin);
  printf("%d\n", miStrlen(cadena));
  return 0;
}

int miStrlen(char *mensaje) {
  int contador = 0;

  while (*mensaje != '\0') {
    contador++;
    mensaje++;
  }

  return contador - 1;
}
