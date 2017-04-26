#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{
	int L = 5;
	int red[L*L];
	float p_c;
	int n_precision = 100;
	int n_iteraciones_a = 100;
	p_c = calcular_p_c_a(red, L, n_precision, n_iteraciones_a);

	printf("Probabilidad critica con el metodo a) es %f", p_c);
	printf("\n");

	int n_iteraciones_b = 1000;
	//float p;
	float F;
	F = calcular_p_c_b(red, L, p_c, n_iteraciones_b);
	printf("La probabilidad de aparicion del cluster para p=%.2f es %.2f\n", p_c, F);
	return 0;
}

// por alguna razon esto cuelga en un momento..
