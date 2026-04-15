# Templates y Funciones Útiles

Bloques de código listos para copiar, pegar y modularizar proyectos de C enfocados a Sistemas Operativos.

## 1. Estructura de Control de Procesos (Fork)

Template básico para separar la lógica de padre e hijo.

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void logica_hijo() {
    printf("Soy el hijo (PID: %d)\n", getpid());
    exit(EXIT_SUCCESS);
}

void logica_padre() {
    printf("Soy el padre, esperando al hijo...\n");
    wait(NULL);
    printf("El hijo ha terminado.\n");
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Error al crear el proceso");
        return EXIT_FAILURE;
    } else if (pid == 0) {
        logica_hijo();
    } else {
        logica_padre();
    }
    return EXIT_SUCCESS;
}
```

## 2. Comunicación mediante Pipes (Tuberías)

Para enviar datos de un proceso a otro.

```c
// Definir tubería
int pipe_fd[2]; 
pipe(pipe_fd);

// En el Emisor:
close(pipe_fd[0]); // Cerrar lectura
write(pipe_fd[1], &dato, sizeof(dato));
close(pipe_fd[1]);

// En el Receptor:
close(pipe_fd[1]); // Cerrar escritura
read(pipe_fd[0], &dato, sizeof(dato));
close(pipe_fd[0]);
```

## 3. Memoria Compartida (mmap)

Útil para que padre e hijos compartan variables (como acumuladores o arrays).

```c
#include <sys/mman.h>

// Crear espacio compartido para N enteros
int *memoria = mmap(NULL, N * sizeof(int), PROT_READ | PROT_WRITE,
                    MAP_SHARED | MAP_ANONYMOUS, -1, 0);

// Al terminar, liberar:
munmap(memoria, N * sizeof(int));
```

## 4. Utilidades de Validación de Procesos

Funciones para hacer el código más legible.

```c
int is_padre(pid_t pid) {
    return pid > 0;
}

int is_hijo(pid_t pid) {
    return pid == 0;
}

void check_fork_error(pid_t pid) {
    if (pid < 0) {
        perror("Error en fork");
        exit(EXIT_FAILURE);
    }
}
```

## 5. Algoritmos Comunes Reutilizables

### Verificar si un número es primo

```c
#include <stdbool.h>

bool es_primo(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}
```

### Generar número aleatorio en un rango

```c
#include <time.h>

int aleatorio(int min, int max) {
    static bool init = false;
    if (!init) {
        srand(time(NULL));
        init = true;
    }
    return (rand() % (max - min + 1)) + min;
}
```

### Limpiar buffer de entrada (Strings)

```c
void limpiar_salto_linea(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') {
        str[len-1] = '\0';
    }
}
```
