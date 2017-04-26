#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){

	int L;
	float p;
	int rango_p = 10;
	int i;
	int s;
	int j;
	int n_prom = 10;
	srand(time(NULL));

	FILE *fdat;
	fdat = fopen("datos dist_ns.csv", "w");
	fprintf(fdat, "L	p	s	n(s)\n");


	for (L=4; L<256; L=L*2){

		float array_ns[n_prom];

		int L = 4;
		int red[L*L];
		float n_s[L*L];
		printf("\n ~~~~~~~~ L = %i ~~~~~~~~\n", L);

		for (i = 0; i < rango_p; i++){
			p = (float)i/rango_p;
			printf("\n ~~~~~~~~ p = %f ~~~~~~~~\n", p);

			for (s = 0; s<L*L; s++){

					for(j = 0; j < n_prom; j++){
						llenar(red, L, p);
						hoshen(red, L);

						array_ns[j] = ns_s(L, red, s);
						printf("El array_ns de j = %i es array_ns = %f \n", j, array_ns[j]);
					}

					n_s[s] = promedio(n_prom, array_ns);
					printf("El n_s promediado es %f para s = %i \n", n_s[s], s);
					fprintf(fdat, "%i,%3.3g,%i,%3.3g \n",L, p, s, n_s[s]);


			}
		}
	}
return 0;
}
