#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{
	int L;
	int n_trials_b = 100;
	int rango_p = 100;
	float p = 0;
	float F[rango_p];
	int i;

	FILE *fdat;
	fdat = fopen("datos 1b.csv", "w");
	fprintf(fdat, "L	p	F(p)\n");

	for (L=4; L<256; L=L*2){ 

		int red[L*L];

		for (i = 0; i < rango_p; i++){
			p = (float)i/rango_p;
			F[i] = calcular_p_c_b(red, L, p, n_trials_b);
			printf("La probabilidad de aparicion del cluster para L=%i p=%.2f es %.4f\n", L, p, F[i]);
			fprintf(fdat, "%i,%3.3g,%3.3g \n",L, p, F[i]);
		}

	}
	fflush(fdat);
	fclose(fdat);
	
	return 0;
}

