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

static int *numero;
static int *heLeidoValorPorTeclado;
static int *resultado;

int calcularFactorial(int numero);

int main() {
  numero = mmap(NULL, sizeof(*numero), PROT_READ | PROT_WRITE,
                MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  heLeidoValorPorTeclado =
      mmap(NULL, sizeof(*heLeidoValorPorTeclado), PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  resultado = mmap(NULL, sizeof(*resultado), PROT_READ | PROT_WRITE,
                   MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  *heLeidoValorPorTeclado = -1;
  pid_t subproceso = fork();

  if (subproceso < 0) {
    perror("Error al crear el hijo");
  } else if (subproceso == 0) {
    puts("inserta un valor:");
    scanf("%d", numero);
    *heLeidoValorPorTeclado = 1;
    wait(NULL);

  } else if (subproceso > 0) {
    while (*heLeidoValorPorTeclado) {
      sleep(2);
    }
    *resultado = calcularFactorial(*numero);
    exit(EXIT_SUCCESS);
  }

  munmap(numero, sizeof(*numero));
  munmap(heLeidoValorPorTeclado, sizeof(*heLeidoValorPorTeclado));
  munmap(resultado, sizeof(*resultado));

  exit(EXIT_SUCCESS);
}

int calcularFactorial(int numero) { return 23; }
