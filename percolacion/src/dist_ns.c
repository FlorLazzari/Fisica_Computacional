#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){

	int L;
	float p;
	int rango_p = 10;
	int i;

	for (L=4; L<256; L=L*2){ 

		int red[L*L];
		int tag[L*L];
		float n_s[L*L];
		printf("\n ~~~~~~~~ L = %i ~~~~~~~~\n", L);

		for (i = 0; i < rango_p; i++){

			p = (float)i/rango_p;
			printf("\n ~~~~~~~~ p = %f ~~~~~~~~\n", p);
			llenar(red, L, p);
			hoshen(red, L);
			tags(L, red, tag);
			ns(L, red, tag, n_s);
			print_ns(L, red);
		}
	}
}