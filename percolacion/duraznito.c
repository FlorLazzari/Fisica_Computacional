#include <stdio.h>
#include <time.h>

#define n 10
#define p 0.5

void init_red(int N, int a[]);
void print_red(int N, int a[]);
int clase(int N, int a[]);

int main()
{
	int red[n*n];
	// no hace falta devolver el puntero ya que la funcion no lo cambia
	init_red(n, red);
	print_red(n, red);
	// idem
	clase(n,red);
	print_red(n, red);

	return 0;
}


void init_red(int N, int a[]){
	int i;
	float r;

	srand(time(NULL));
	for (i=0; i<N*N; i++){
		r = rand()%100;
		r = r/100;

		if (r<=p){
			a[i] = 1;
				}
		else{
			 a[i] = 0;
			  }
		}
  // ojo! este return devuelve el puntero de el puntero de a ( a[] == *a )
	// saque el return
}

void print_red(int N, int a[]){
	int i;

	printf("\n");

	for (i = 0 ; i < N*N ; i++){
		if ((i)%N == 0){
			printf("\n %3i", a[i]);
		}
		else{
			printf("%3i",a[i]);
			}
		}
	printf("\n");
	printf("\n");
}

// hasta aca es lo mismo que el archivo percolacion.c
////////////////////////////////////////////////////////////////////////////////


int clase(int N, int a[])
{
	int clase[N*N/2]; // la maxima cantidad de clases se da para el caso "tablero de ajedrez"
	int i, j, s1, s2;
	int clase_nueva = 2;

	for (i=0; i<N*N/2; i++){ // inicializa vector de clases

		clase[i] = 0;

	}

	// Recorre la red y etiqueta clusters

	for (i=0; i<N; i++){ // recorre filas

		for (j=0; j<N; j++){ // recorre columnas

			if (a[i*N+j]==1){ // si el elemento seleccionado esta ocupado

				if (i==0 && j==0){ //primer elemento de la red

					a[i*N+j] = clase_nueva;
					clase[clase_nueva] = clase_nueva;
					clase_nueva++;
				}

				else if (i==0){// primera fila, solo vecinos a la izquierda

					if (a[i*N+j-1]==0){
						a[i*N+j] = clase_nueva;
						clase[clase_nueva] = clase_nueva;
						clase_nueva++;
					}

					else if (a[i*N+j-1]!=1){
						s1 = a[i*N+j-1];
						while (clase[s1]<0){
							s1 = -clase[s1];
						}
						// clase[s1] = s1 (ya esta de mas?)
						a[i*N+j] = s1;
					}
				}

				else if (j==0){ //primera columna

					if (a[(i-1)*N+j]==0){
						a[i*N+j] = clase_nueva;
						clase[clase_nueva] = clase_nueva;
						clase_nueva++;
					}

					else if (a[i*N+j-N]!=1){
						s1 = a[i*N+j-N];
						while (clase[s1]<0){
							s1 = -clase[s1];
						}
						clase[s1] = s1; //(ya esta de mas?)
						a[i*N+j] = s1;
					}
				}

				else { //bulk de la red

					if (a[i*N+j-1]==0 && a[i*N+j-N]==0){ // caso trivial, vecinos nulos
						a[i*N+j] = clase_nueva;
						clase[clase_nueva] = clase_nueva;
						clase_nueva++;
					}

					else if (a[i*N+j-1]!=1 && a[i*N+j-N]==0){ // caso simple, vecino a la izquierda
						s1 = a[i*N+j-1];
						while (clase[s1]<0){
							s1 = -clase[s1];
						}
						a[i*N+j] = s1;
					}

					else if (a[i*N+j-1]==0 && a[i*N+j-N]!=1){ //caso simple, vecino arriba
						s1 = a[i*N+j-N];
						while (clase[s1]<0){
							s1 = -clase[s1];
						}
						a[i*N+j] = s1;
					}

					else if (a[i*N+j-1]!=1 && a[i*N+j-N]!=1 && a[i*N+j-1]==a[i*N+j-N]){
						s1 = a[i*N+j-1];
						while(clase[s1]<0){
							s1 = -clase[s1];
						}
						a[i*N+j] = s1;
					}

					else if (a[i*N+j-1]!=1 && a[i*N+j-N]!=1 && a[i*N+j-1]!=a[i*N+j-N]){ //caso complicado, conficto de etiquetas
						s1 = a[i*N+j-1];
						s2 = a[i+N+j-N];
						while (clase[s1]<0){
							s1 = -clase[s1];
						}
						while (clase[s2]<0){
							s2 = -clase[s2];
						}

						if (s1<s2){
							a[i*N+j] = s1;
							clase[s2] = -s1;
						}

						else if (s2<s1){
							a[i*N+j] = s2;
							clase[s1] = -s2;
						}

					}

				}


			}

		}
	}

	// re-etiquetado corrige etiquetas falsas
	for (i=0; i<N*N/2; i++){
		s1 = a[i];
		while (clase[s1]<0){
			s1 = -clase[s1];
		}
		a[i] = s1;
	}

	return *a;
}
