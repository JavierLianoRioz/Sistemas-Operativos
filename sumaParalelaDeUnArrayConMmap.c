#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

#define N 10

void sumarPrimeraMitad(int *, int *);
void sumarSegundaMitad(int *, int *);

int main() {
  int *sumas = mmap(NULL, 2 * sizeof(int), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  int datos[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  pid_t pid = fork();

  if (pid < 0) {
    perror("Error al crear al hijo");
  } else if (pid == 0) {
    for (int i = 0; i < 70000; i++) {
      sumas[0] += 1;
    }
    exit(EXIT_SUCCESS);
  } else if (pid > 0) {
    for (int i = 0; i < 70000; i++) {
      sumas[0] -= 1;
    }
  }
  wait(NULL);
  printf("%d", sumas[0]);

  return EXIT_SUCCESS;
}

void sumarPrimeraMitad(int *sumas, int *datos) {
  for (int i = 0; i < N / 2; i++) {
    sumas[0] += datos[i];
  }
}
void sumarSegundaMitad(int *sumas, int *datos) {
  for (int i = N / 2; i < N; i++) {
    sumas[1] += datos[i];
  }
}
