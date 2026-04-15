# Guía de Imports en C

Este documento explica para qué sirven las librerías que hemos utilizado en el proyecto de Sistemas Operativos, con ejemplos prácticos de uso.

## 1. `<stdio.h>` (Standard Input/Output)

Es la librería fundamental para entrada y salida de datos por consola.

* **Funciones clave:** `printf`, `scanf`, `puts`, `perror`, `fgets`.

* **Ejemplo:**

    ```c
    int numero;
    printf("Introduce un número: ");
    scanf("%d", &numero);
    printf("Has introducido: %d\n", numero);
    ```

## 2. `<stdlib.h>` (Standard Library)

Proporciona funciones para gestión de memoria dinámica, control de procesos y conversiones.

* **Funciones clave:** `exit`, `malloc`, `free`, `rand`, `srand`.
* **Ejemplo:**

    ```c
    // Terminar un proceso hijo con éxito
    exit(EXIT_SUCCESS); 
    ```

## 3. `<unistd.h>` (POSIX Operating System API)

Es la librería estándar para interactuar con el sistema operativo (Unix/Linux). Fundamental para la gestión de procesos.

* **Funciones clave:** `fork`, `pipe`, `read`, `write`, `close`, `getpid`.
* **Ejemplo (Crear proceso):**

    ```c
    pid_t pid = fork();
    if (pid == 0) {
        // Código del hijo
    }
    ```

## 4. `<sys/wait.h>` y `<wait.h>`

Se utiliza para que un proceso padre espere a que sus procesos hijos terminen.

* **Funciones clave:** `wait`, `waitpid`.
* **Ejemplo:**

    ```c
    wait(NULL); // Espera a cualquier hijo
    ```

## 5. `<sys/types.h>`

Define tipos de datos del sistema como `pid_t` (usado para IDs de procesos).

## 6. `<string.h>`

Manipulación de cadenas de caracteres (strings).

* **Funciones clave:** `strlen`, `strcpy`, `strcmp`.
* **Ejemplo:**

    ```c
    int longitud = strlen("Hola"); // Retorna 4
    ```

## 7. `<ctype.h>`

Funciones para clasificación y conversión de caracteres individuales.

* **Funciones clave:** `tolower`, `toupper`, `isdigit`, `isalpha`.
* **Ejemplo:**

    ```c
    char minuscula = tolower('A'); // Convierte a 'a'
    ```

## 8. `<stdbool.h>`

Permite usar el tipo de dato `bool` (`true` y `false`) en C.

## 9. `<time.h>`

Gestión de tiempo y fechas. Útil para inicializar generadores de números aleatorios.

* **Funciones clave:** `time`.
* **Ejemplo:**

    ```c
    srand(time(NULL)); // Semilla aleatoria basada en el tiempo actual
    ```

## 10. `<sys/mman.h>` (Memory Management)

Gestión de memoria compartida y mapeo de archivos.

* **Funciones clave:** `mmap`, `munmap`.
* **Ejemplo (Memoria compartida entre procesos):**

    ```c
    int *shared = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, 
                       MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    ```
