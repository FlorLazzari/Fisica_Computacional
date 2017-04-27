#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){
	int L;
	float p;
	srand(time(NULL));
	int n_promediado = 100;
	int i;
	float P[n_promediado];
	float P_prom;

	FILE *fdat;
	fdat = fopen("datos fuerza.csv", "w");
	fprintf(fdat, "L	p	P(p)\n");

	for (L=4; L<256; L = L*2){ // itero para cada tamaño

		printf("\n ~~~~~~~~ L = %i ~~~~~~~~\n", L);
		int red[L*L];

		for (p = 0.1; p<1; p = p + 0.01){ //calculo la fuerza para cada probabilidad
			
			for (i = 0; i < n_promediado; i++){

				llenar(red, L, p); //inicializo red
				hoshen(red, L); //hago HK en la red
				P[i] = 0;

				if (percola(L, red)){ //calcula la P_oo
					P[i] = fuerza(L, red);
				}
			}
			P_prom = promedio(n_promediado, P);
			
			printf("La fuerza del cluster percolante para L=%i, p = %.2f es %.3f \n", L, p, P_prom);
			fprintf(fdat, "%i,%.2g,%.3g\n", L, p, P_prom);
		}
	}


	return 0;
}
