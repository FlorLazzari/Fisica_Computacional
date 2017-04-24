#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"


int main(){

	float p;

	for (p=0.1; p<1; p = p + 0.1){ // calcula el m2 para cada p

		int L = 6; //cambiar entre 6 y 128
		int red[L*L];
		int tag[L*L];
		int n_s[L*L];
		srand(time(NULL));


		// inicializa los arrays de la red, las etiquetas y los tamaños
		llenar(red, L, p);
		hoshen(red, L);
		tags(L, red, tag);
		ns(L, red, tag, n_s);

		int i;
		int m2 = 0;

		for (i=1; i<L*L; i++){ //ejecuta la suma del segundo momento de n_s

			m2 = m2 + n_s[i]*i*i;
		}

		printf("El segundo momento para L=%i, p=%.2f es %i \n", L, p, m2);
	}
}
