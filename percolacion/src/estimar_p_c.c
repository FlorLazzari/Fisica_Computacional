#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{
	int n;
	n = 5;
	int red[n*n];
	float p_c;
	int n_precision;
	int n_promediar;
	n_promediar = 100;
	n_precision = 100;
  p_c = calcular_p_c_a(red, n, n_precision, n_promediar);

	printf("la probabilidad critica es %f\n", p_c);

	return 0;
}


// ojo! para compilar debo escribir:
// gcc src/estimar_p_c.c -lm -o bin/pirulo

// esto lo hago para solucionar el problema de calcular la potencia
