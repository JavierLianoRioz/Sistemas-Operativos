#include <stdio.h>

int invertirNumero(int);
int contarDigitos(int);
int primosEntre(int, int);

int main(void) {
  printf("Introduce dos números enteros: ");
  int numero1, numero2;
  scanf("%i", &numero1);
  scanf("%i", &numero2);
  puts("\n");
  numero1 < numero2 ? primosEntre(numero1, numero2)
                    : primosEntre(numero2, numero1);
  return 0;
}

int suma = 0, resto;

int invertirNumero(int numero) {
  if (numero > 0) {
    resto = numero % 10;
    suma = suma * 10 + resto;
    invertirNumero(numero / 10);
  }
  return suma;
}

// 0 | 0
// -- | --
// 234 | 432
// 1234 | 4321
//
// f(n-1)*10 + cabeza

int contarDigitos(int numero) {
  if (numero == 0) {
    return 0;
  } else {
    return (1 + contarDigitos(numero / 10));
  }
};

int primosEntre(int minimo, int maximo) {
  int i, j, flag_var;
  for (i = minimo + 1; i < maximo; i++) {
    flag_var = 0;
    for (j = 2; j <= i / 2; j++) {
      if (i % j == 0) {
        flag_var = 1;
        break;
      }
    }
    if (flag_var == 0) {
      printf("%d\n", i);
    }
  }
}
