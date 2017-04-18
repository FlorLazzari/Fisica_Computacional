#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Imprime una matrix del formato
// [row0, row1, row2, row3, ...]

void imprimir(int *red, int n) {
  int i;
  int j;
  for (i = 0; i < n ; i++) {
    for (j = 0; j < n; j++) {
      printf("%d,", red[j + (i * n)]);
    }
    printf("\n");
  }
}

// Llena la matriz que se pasa por parametro (y guarda en memoria) con numeros
// que dependen de la proba

void llenar(int *red, int n, float prob) {
  int i;
  float a;
  for (i = 0; i < n * n; i++) {
    a = rand() % 100;
    if ( a > (prob * 100)) {
      red[i] = 1;
    }
    else {
      red[i] = 0;
    }
  }
}




int main() {
  // http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
  srand((unsigned int)time(NULL));

  int n = 5;
  float prob = 0.5;
  int *red = malloc(n * n * sizeof(int));
  llenar (red, n, prob);
  imprimir (red, n);

  free(red);

  return 0;
}




// ############################################################################
// para compilarlo haces :
// 1) gcc <nombre del .c> -o <nombre del ejecutable (este nombre lo elegis vos)>
// 2) ./<nombre del ejecutable>
// ############################################################################
