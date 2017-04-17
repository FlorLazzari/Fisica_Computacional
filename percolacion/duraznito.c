#include <stdio.h>
#include <time.h>

#define n 10
#define p 0.5

void init_red(int N, int red[]);
void print_red(int N, int red[]);
void clases(int N, int red[]);

int main()
{
	int red[n*n];
	// no hace falta devolver el puntero ya que la funcion no lo cambia
	init_red(n, red);
	print_red(n, red);
	// idem
	clases(n,red);
	print_red(n, red);

	return 0;
}


void init_red(int N, int red[]){
	int i;
	float r;

	srand(time(NULL));
	for (i=0; i<N*N; i++){
		r = rand()%100;
		r = r/100;

		if (r<=p){
			red[i] = 1;
				}
		else{
			 red[i] = 0;
			  }
		}
  // ojo! este return devuelve el puntero de el puntero de a ( red[] == *a )
	// saque el return
}

void print_red(int N, int red[]){
	int i;

	printf("\n");

	for (i = 0 ; i < N*N ; i++){
		if ((i)%N == 0){
			printf("\n %3i", red[i]);
		}
		else{
			printf("%3i",red[i]);
			}
		}
	printf("\n");
	printf("\n");
}

int clase_de_posicion(int clases[], int posicion) {
	while (clases[posicion]<0){
		posicion = -clases[posicion];
	}

	return posicion;
}

// hasta aca es lo mismo que el archivo percolacion.c
////////////////////////////////////////////////////////////////////////////////


void clases(int N, int red[])
{
	int clases[N*N/2]; // la maxima cantidad de clasess se da para el caso "tablero de ajedrez"
	int i, j, s1, s2;
	int clases_nueva = 2;
	for (i=0; i<N*N/2; i++){ // inicializa vector de clasess
		clases[i] = 0;
	}

	// Recorre la red y etiqueta clusters
	for (i=0; i<N; i++){ // recorre filas
		for (j=0; j<N; j++){ // recorre columnas
			int elemento_actual = i*N+j;
			int elemento_de_la_izquierda = i*N+j-N;
			int elemento_de_arriba = i*N+j-1;

			if (red[i*N+j]==1){ // si el elemento seleccionado esta ocupado
				if (i==0 && j==0){ //primer elemento de la red
					red[i*N+j] = clases_nueva;
					clases[clases_nueva] = clases_nueva;
					clases_nueva++;
				}

				else if (i==0){// primera fila, solo vecinos a la izquierda
					if (red[elemento_de_arriba]==0){
						red[i*N+j] = clases_nueva;
						clases[clases_nueva] = clases_nueva;
						clases_nueva++;
					}

					else if (red[elemento_de_arriba]!=0){
						red[i*N+j] = clase_de_posicion(clases, red[elemento_de_arriba]);;
					}
				}

				else if (j==0){ //primera columna
					if (red[(i-1)*N+j]==0){
						red[i*N+j] = clases_nueva;
						clases[clases_nueva] = clases_nueva;
						clases_nueva++;
					}

					else if (red[elemento_de_la_izquierda]!=0){
						s1 = clase_de_posicion(clases, red[elemento_de_la_izquierda]);
						clases[s1] = s1; //(ya esta de mas?)
						red[i*N+j] = s1;
					}
				}

				else { //bulk de la red
					if (red[elemento_de_arriba]==0 && red[elemento_de_la_izquierda]==0){ // caso trivial, vecinos nulos
						red[i*N+j] = clases_nueva;
						clases[clases_nueva] = clases_nueva;
						clases_nueva++;
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]==0){ // caso simple, vecino a la izquierda
						red[i*N+j] = clase_de_posicion(clases, red[elemento_de_arriba]);
					}

					else if (red[elemento_de_arriba]==0 && red[elemento_de_la_izquierda]!=0){ //caso simple, vecino arriba
						red[i*N+j] = clase_de_posicion(clases, red[elemento_de_la_izquierda]);
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]!=0 && red[elemento_de_arriba]==red[elemento_de_la_izquierda]){
						red[i*N+j] = clase_de_posicion(clases, red[elemento_de_arriba]);
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]!=0 && red[elemento_de_arriba]!=red[elemento_de_la_izquierda]){ //caso complicado, conficto de etiquetas
						s1 = clase_de_posicion(clases, red[elemento_de_arriba]);
						s2 = clase_de_posicion(clases, red[i+N+j-N]);

						if (s1<s2){
							red[i*N+j] = s1;
							clases[s2] = -s1;
						}

						else if (s2<s1){
							red[i*N+j] = s2;
							clases[s1] = -s2;
						}
					}
				}
			}
		}
	}

	// re-etiquetado corrige etiquetas falsas
	for (i=0; i<N*N/2; i++){
		s1 = red[i];
		while (clases[s1]<0){
			s1 = -clases[s1];
		}
		red[i] = s1;
	}
}
