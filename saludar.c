// un programa que nos pida introducir el nombre.
// - el tope va a ser 50 caracteres.
// Después te pedirá introducir tu edad. Y leemos la edad de usuario
// - Máximo de 3 caracteres.
// Una vez almacenado, saluda y di cuantos años tiene.
// - [x] Utilizar solo llamadas al sistema.
#include <string.h>
#include <unistd.h>

char saltoDeLinea[] = "\n";

void imprimir(char *string) { write(1, &string, sizeof(string)); }

int main() {
  char preguntaNombre[] = "¿Cuál es tu nombre?";
  write(1, &preguntaNombre, sizeof(preguntaNombre));
  write(1, &saltoDeLinea, sizeof(char));
  char nombre[50];
  read(0, &nombre, sizeof(nombre));
  // write(1, &nombre, strlen(nombre));

  char preguntaAños[] = "¿Cuantos años tienes?";
  write(1, &preguntaAños, sizeof(preguntaAños));
  write(1, &saltoDeLinea, sizeof(char));
  char edad[3];
  read(0, &edad, sizeof(edad));

  char mensaje1[] = "Hola, ";
  write(1, &mensaje1, sizeof(mensaje1));

  write(1, &nombre, strlen(nombre));

  char mensaje2[] = "tienes ";
  write(1, &mensaje2, sizeof(mensaje2));

  write(1, &edad, strlen(edad));

  char mensaje3[] = "años.\n";
  write(1, &mensaje3, sizeof(mensaje3));

  return 0;
}
