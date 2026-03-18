#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int main(void) {
  int numero1, numero2, resultado;
  puts("Introduce el primer número:");
  scanf("%i", &numero1);
  puts("Introduce el segundo número:");
  scanf("%i", &numero2);

  pid_t pid1, pid2;

  pid1 = fork();

  if (pid1 == 0) {
    resultado = numero1 + numero2;
    printf("Resultado de la suma: %i\n", resultado);
    exit(0);
  } else if (pid2 < 0) {
    perror("Error al intentar crear el proceso");
  }

  pid2 = fork();

  if (pid2 == 0) {
    resultado = numero1 - numero2;
    printf("Resultado de la resta: %i\n", resultado);
    exit(0);
  } else if (pid2 < 0) {
    perror("Error al intentar crear el proceso");
  }

  return 0;
}
