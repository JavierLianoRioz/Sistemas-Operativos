// dos procesos.
// al menos una variable compartida.
// el padre una vez que ya ha creado al hijo lee un numero.
// cuando el padre lee un numero, el hijo va a calcular su factorial.
// Y el padre una vez que el hijo ha terminado de calcular el factorial, saca el
// valor del factorial por pantalla.

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Variables en memoria compartida
static int *numero;
static int *resultado;
static int *listo_para_calcular;

// Función para calcular el factorial (como pide el enunciado)
long factorial(int n) {
  if (n < 0)
    return 0;
  long res = 1;
  for (int i = 1; i <= n; i++) {
    res *= i;
  }
  return res;
}

int main() {
  // Reservar memoria compartida para que ambos procesos la vean
  numero = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  resultado = mmap(NULL, sizeof(long), PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  listo_para_calcular = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                             MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  *listo_para_calcular = 0; // Flag de control

  pid_t pid = fork();

  if (pid < 0) {
    perror("Error en fork");
    return 1;
  }

  if (pid == 0) {
    // --- PROCESO HIJO ---
    // Espera a que el padre lea el valor
    while (*listo_para_calcular == 0) {
      usleep(100);
    }

    printf("[Hijo] Calculando el factorial de %d...\n", *numero);
    *resultado = factorial(*numero);

    exit(EXIT_SUCCESS);
  } else {
    // --- PROCESO PADRE ---
    printf("[Padre] Introduce un número: ");
    scanf("%d", numero);

    // Avisa al hijo que ya puede leer el número
    *listo_para_calcular = 1;

    // El padre debe esperar a que el hijo termine su ejecución
    wait(NULL);

    printf("[Padre] El hijo ha terminado. El factorial es: %d\n", *resultado);

    // Liberar memoria
    munmap(numero, sizeof(int));
    munmap(resultado, sizeof(long));
    munmap(listo_para_calcular, sizeof(int));
  }

  return 0;
}
