#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){
	int L;
	float p;
	srand(time(NULL));

	for (L=4; L<256; L = L*2){ // itero para cada tamaño

		printf("\n ~~~~~~~~ L = %i ~~~~~~~~\n", L);

		for (p = 0.1; p<1; p = p + 0.05){ //calculo la fuerza para cada probabilidad
			int red[L*L];
			int tag[L*L];

			llenar(red, L, p); //inicializo red
			//print_red(n, red);
			hoshen(red, L); //hago HK en la red
			//print_red(n, red);
			tags(L, red, tag); //obtengo tamaños de los clusters

			if (percola(L, red)){ //calcula la P_oo
				printf("La fuerza del cluster percolante para L=%i, p = %.2f es %.3f \n", L, p, fuerza(L, red, tag));
			}

		}
	}


	return 0;
}
