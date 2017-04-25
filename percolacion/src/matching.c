#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"
#include <unistd.h>



int main(){

	float p;
	int j;
 	int n_promediar=100;
	float m2promedio=0;
	float m2array[n_promediar];
	srand(time(NULL)); // no hace falta cambiar la semilla adentro del loop!!

	FILE *fdat;
	fdat = fopen("datos matching.tsv", "w");
	fprintf(fdat, "p	m2\n");

	for (p=0.3; p<0.8; p = p + 0.01){ // calcula el m2 para cada p
		int L = 6; //cambiar entre 6 y 128
		int red[L*L];
		int tag[L*L];
		float n_s[L*L];
		for (j=0; j < n_promediar; j++){
			// inicializa los arrays de la red, las etiquetas y los tamaños
			llenar(red, L, p);
			hoshen(red, L);
			tags(L, red, tag);
			ns(L, red, tag, n_s);

			int i;
			int m2 = 0;

				for (i=0; i<L*L; i++){ //ejecuta la suma del segundo momento de n_s
					m2 = m2 + n_s[i]*i*i;
				}
				m2 = m2 - (masa(L, red)*masa(L, red))/(L*L);
			m2array[j] = m2;
			// if(j%10==0){
			// 	printf("el prom para p=%f es %f \n", p, m2array[j]);
			// 	print_ns(L, red);
			// }
		}
		m2promedio = promedio(n_promediar, m2array);
		printf("El segundo momento para L=%i, p=%.2f es %.2f \n", L, p, m2promedio);
		fprintf(fdat, "%.3g	%.3g\n",p, m2promedio);
	}/*
int n =10;
float array[n] = {4, 4, 4, 4, 5, 5, 5, 5, 5,	5};
printf("promedio prueba = %f \n", promedio(n,array));
*/

fflush(fdat);
fclose(fdat);
}
