#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{
	int L = 5;
	int red[L*L];

	int n_trials_b = 100;
	int rango_p = 100;
	float p = 0;
	float F[rango_p];
	int i;

	for (i = 0; i < rango_p; i++){
		p = (float)i/rango_p;
		F[i] = calcular_p_c_b(red, L, p, n_trials_b);
		printf("La probabilidad de aparicion del cluster para p=%.2f es %.4f\n", p, F[i]);
	}
	
	
	return 0;
}

// por alguna razon esto cuelga en un momento..
