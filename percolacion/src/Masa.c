#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){
	int L;
	float p_c = 0.6; // aca poner la que corresponda
	srand(time(NULL));

	for (L=4; L<256; L = L*2){ // itero para cada tamaño

			int red[L*L];
			//int tag[L*L];

			llenar(red, L, p_c); //inicializo red
			//print_red(n, red);
			hoshen(red, L); //hago HK en la red
			//print_red(n, red);
			//tags(L, red, tag); //obtengo tamaños de los clusters

			if (percola(L, red)){ //calcula la Masa
				printf("La Masa del cluster percolante para L=%i es %i \n", L, masa(L, red));
			}


	}


	return 0;
}
