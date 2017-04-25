#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{
	int n = 5;
	int red[n*n];
	float p_c;
	int n_precision = 10;
	int n_iteraciones_a = 10;
	p_c = calcular_p_c_a(red, n, n_precision, n_iteraciones_a);

	printf("Probabilidad critica con el metodo a) es %f", p_c);
	printf("\n");

//  	int n_iteraciones_b = 100;
//	int n_precision_b = 100;
//	calcular_p_c_b(red, n, n_iteraciones_b, n_precision_b);
	return 0;
}


// para compilar:
// gcc src/estimar_p_c.c -lm -o bin/pirulo

// esto lo hago para solucionar el problema de calcular la potencia


// por alguna razon esto cuelga en un momento..
