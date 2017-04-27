#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main()
{	
	FILE *fdat;
	fdat = fopen("datos 1a.csv", "w");
	fprintf(fdat, "L	p_c\n");

	int i;
	int L;
	int n_precision = 100;
	int n_iteraciones_a = 100;
	int j;
	int cant_datos = 10;

	for (L=4; L<256; L=L*2){ 
		
			for(j=0; j < cant_datos; j++){
			int red[L*L];
			float p_c;
			p_c = calcular_p_c_a(red, L, n_precision, n_iteraciones_a);

			printf("Probabilidad critica para L=%i (corrida %i) con el metodo a) es %f", L, j, p_c);
			printf("\n");
			fprintf(fdat, "%i,%3.4g \n",L, p_c);
		}
	}
	/*
	int n_iteraciones_b = 1000;
	//float p;
	float F;
	F = calcular_p_c_b(red, L, p_c, n_iteraciones_b);
	printf("La probabilidad de aparicion del cluster para p=%.2f es %.2f\n", p_c, F);
	*/

	fflush(fdat);
	fclose(fdat);

	return 0;
}

// por alguna razon esto cuelga en un momento..
