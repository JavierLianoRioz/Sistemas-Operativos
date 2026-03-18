#include <stdio.h>

int suma(int x, int y);
int isPrimo(int x);

int main() {
  int var1;
  puts("Introduce el valor de la primera variable:");
  scanf("%i", &var1);

  // puts("Introduce el valor de la segunda variable:");
  // int var2;
  // scanf("%i", &var2);

  // printf("la suma es %i \n", suma(var1, var2));
  if (isPrimo(var1)) {
    puts("Es primo :3");
  } else {
    puts("no es primo :C");
  }

  return 0;
}

int suma(int x, int y) { return x + y; }

int isPrimo(int x) {

  for (int i = 2; i < x; i++) {

    if (x % i == 0) {
      return 0;
    }
  }

  return 1;
}
