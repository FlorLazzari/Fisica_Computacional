// ############################################################################
// para compilarlo haces :
// 1) gcc <nombre del .c> -o <nombre del ejecutable (este nombre lo elegis vos)>
// 2) ./<nombre del ejecutable>
// ############################################################################

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

// Genera un numero random de 0 a max
// [row0, row1, row2, row3, ...]
int random_number(float probability, int max) {
  return rand() % max;
}

// Imprime una matrix del formato
void print_matrix(int *matrix, int rows, int columns) {
  for (int column = 0; column < columns; column++) {
    for (int row = 0; row < rows; row++) {
      printf("%d,", matrix[row + (column * rows)]);
    }
    printf("\n");
  }
}

// Llena la matriz que se pasa por parametro (y guarda en memoria) con numeros
// aleatorios de 0 a max
int *fill_matrix(int rows, int columns, float probability, int max) {
  int *matrix = malloc(rows * columns * sizeof(int));

  for (int column = 0; column < columns; column++) {
    for (int row = 0; row < rows; row++) {
      matrix[row + (column * rows)] = random_number(probability, max);
    }
  }
  return matrix;
}

int main() {
  // http://stackoverflow.com/questions/822323/how-to-generate-a-random-number-in-c
  srand((unsigned int)time(NULL));

  // En realidad no es una matriz pero es un array con el formato
  // [row0, row1, row2, row3, ...]
  int *matrix = fill_matrix(10, 10, 1, 100);
  print_matrix(matrix, 10, 10);

  free(matrix);

  return 0;
}
