// 3 Procesos:
// 1. Papa
// 2. Lee
// 3. Escribe
// Una vez que los dos procesos estan creados, el proceso LEE lee un numero por
// teclado. El proceso ESCRIBE accede a la variable compartida (mmap) y muestra
// el número por pantalla. El proceso ESCRIBE dice "escribe una tecla para
// terminar" Y en ese momento ambos procesos mueren y con ello el padre.

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

int isPadre(pid_t pid) { return pid > 0; }

int isHijo(pid_t pid) { return pid == 0; }

void errorAlCrearHijo(pid_t pid) {
  if (pid < 0) {
    perror("Error en el fork");
    exit(EXIT_FAILURE);
  }
}

int leerPorPantalla() {
  int numero;
  scanf("%d", &numero);
  return numero;
}

void escribirPorPantalla(int numero) { printf("Numero escrito: %d\n", numero); }

int main(void) {
  int *numero = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
                     MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  int *haEscritoPrimeraRespuesta =
      mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  int *haEscritoSegundoRespuesta =
      mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE,
           MAP_SHARED | MAP_ANONYMOUS, -1, 0);

  *haEscritoPrimeraRespuesta = 1;
  *haEscritoSegundoRespuesta = 1;
  pid_t lee = fork();
  errorAlCrearHijo(lee);

  if (isPadre(lee)) {
    pid_t escribe = fork();
    errorAlCrearHijo(escribe);

    if (isHijo(escribe)) {
      puts("Introduce un numero a leer");
      while (*haEscritoPrimeraRespuesta) {
        sleep(2);
      }
      escribirPorPantalla(*numero);
      puts("Introduce un numero para terminar");
      while (*haEscritoSegundoRespuesta) {
        sleep(2);
      }
      exit(EXIT_SUCCESS);
    }

    wait(NULL);
    wait(NULL);
  }

  if (isHijo(lee)) {
    *numero = leerPorPantalla();
    *haEscritoPrimeraRespuesta = 0;
    puts("Has escrito la primer respuesta");
    *numero = leerPorPantalla();
    *haEscritoSegundoRespuesta = 0;
    exit(EXIT_SUCCESS);
  }

  return EXIT_SUCCESS;
}
