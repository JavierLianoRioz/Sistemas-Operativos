#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int numeroRandom = 0;
  pid_t pid1;
  pid1 = fork();

  if (pid1 < 0) {
    perror("Error en el fork");
    exit(EXIT_FAILURE);
  }

  if (pid1 == 0) {
    if (numeroRandom % 2 == 0) {
      exit(0);
    } else {
      exit(1);
    }
  }

  if (pid1 > 0) {
    int status;
    wait(&status);
    if (WIFEXITED(status)) {
      int resultado_hijo = WEXITSTATUS(status);
      if (resultado_hijo == 0) {
        puts("El hijo ha acabdo, la variable es PAR");
      } else {
        puts("El hijo ha acabdo, la variable es IMPAR");
      }
    } else {
      puts("El hijo ha terminado de una manera anormal");
    }
  }

  return EXIT_SUCCESS;
}
