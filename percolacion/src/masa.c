#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "funciones_percolacion.c"

int main(){
	int L = 4;
	float p_c = 0.6; // aca poner la que corresponda
	srand(time(NULL));
	int i;
	int n_iteraciones = 100; 
	float array[n_iteraciones];
	int m;

	FILE *fdat;
	fdat = fopen("datos masa.csv", "w");
	fprintf(fdat, "L    M\n");
	

	for (L; L<256; L=L*2){ // itero para cada tamaño

		int red[L*L];
		//int tag[L*L];
		float m_prom = 0;

		for (i=0; i<n_iteraciones ; i++){

			 //inicializo red
			//print_red(n, red);
			//hago HK en la red
			//print_red(n, red);
			//tags(L, red, tag); //obtengo tamaños de los clusters
			//printf("Empieza el loop\n");
			bool juanito = true;
			while (juanito){

				llenar(red, L, p_c);
				hoshen(red, L); 

				if(percola(L, red)){ //calcula la Masa
					m = masa(L, red);
					array[i] = (float)m;	
					//if (i % 10 == 0){
					//	printf("La Masa del cluster percolante para L=%i es %i \n", L, m );
					//}
					juanito = false;
				}
				
				

			}
			//printf("termina el loop\n");
			
		}		

	m_prom = promedio(n_iteraciones, array);			
	printf("la masa promedio para L = %i es %f \n", L, m_prom);
	fprintf(fdat, "%i,%3.3g \n",L, m_prom);

	}	

fflush(fdat);
fclose(fdat);

return 0;
}
