#include <stdio.h>
#include <string.h>

int main() {
  char nombreAComparar[] = "Midas";
  char nombre[15];
  char apellido[15];

  int longitud;

  puts("Ingrese su nombre: ");
  scanf("%s", nombre);
  puts("Ingrese su apellido: ");
  scanf("%s", apellido);

  char espacio[] = " ";

  longitud = strlen(nombre);
  longitud += strlen(apellido);

  printf("Encantado %s %s, tu nombre tiene %d letras", nombre, apellido,
         longitud);

  return 0;
}
