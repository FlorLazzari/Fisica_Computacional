#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

//#define n 10
// p ya no es mas una constante, necesito variarla


// lo que tenemos:
// void init_red(int N, int red[], float p); la cambie por llenar
void print_red(int N, int red[]); // la voy a dejar
// void clases(int N, int red[]); la cambie por hoshen  (que diferencia hay entre void y int con un return 0?)
// int generar_clase_nueva(int red[], int hoshen[], int elemento_actual, int clase_nueva); la cambie por actualizar
bool percola(int N, int red[]);
void tags(int N, int red[], int tag[]);
void ns(int N, int red[],int tag[], int tamanos[]);
void print_ns(int N, int red[]);
float calcular_p_c_b(int red[], int n, int num_iteraciones, int n_precision);
float calcular_p_c_a(int red[], int n, int n_precision, int n_promediar);
float fuerza(int N, int red[], int tag[]);
int masa(int N, int red[], int tag[]);

// lo que voy cambiando:
void  llenar(int *red,int N,float prob);
int   hoshen(int *red,int N);
int   actualizar(int *red,int *hoshen,int elemento_actual,int clase_nueva);

// lo que nos deberia quedar:
//void  llenar(int *red,int n,float prob);
//int   hoshen(int *red,int n);
//int   actualizar(int *red,int *clase,int s,int frag);
//void  etiqueta_falsa(int *red,int *clase,int s1,int s2);
//void  corregir_etiqueta(int *red,int *clase,int n);
//int   percola(int *red,int n);




void llenar(int *red, int N, float prob){
	int i;
	float r;


	for (i=0; i<N*N; i++){
		r = rand()%100;
		r = r/100;

		if (r<=prob){
			red[i] = 1;
				}
		else{
			 red[i] = 0;
			  }
		}
  // ojo! este return devuelve el puntero del puntero de a ( red[] == *a )
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

int clase_de_posicion(int hoshen[], int posicion) {
	while (hoshen[posicion]<0){
		posicion = -hoshen[posicion];
	}

	return posicion;
}

int actualizar(int red[], int hoshen[], int elemento_actual, int clase_nueva) {
	red[elemento_actual] = clase_nueva;
	hoshen[clase_nueva] = clase_nueva;
	return ++clase_nueva;
}


int hoshen(int *red, int N)
{
	int hoshen[N*N/2]; // la maxima cantidad de clases se da para el caso "tablero de ajedrez"
	int i, j;
	int clase_nueva = 2;
	for (i=0; i<N*N/2; i++){ // inicializa vector de clasess
		hoshen[i] = 0;
	}

	// Recorre la red y etiqueta clusters
	for (i=0; i<N; i++){ // recorre filas
		for (j=0; j<N; j++){ // recorre columnas
			int elemento_actual = i*N+j;
			int elemento_de_arriba = elemento_actual-N;
			int elemento_de_la_izquierda = elemento_actual-1;

			if (red[elemento_actual]==1){ // si el elemento seleccionado esta ocupado
				if (i==0 && j==0){ //primer elemento de la red
					clase_nueva = actualizar(red, hoshen, elemento_actual, clase_nueva);
				}

				else if (j==0){// primera columna, solo vecinos arriba
					if (red[elemento_de_arriba]==0){
						clase_nueva = actualizar(red, hoshen, elemento_actual, clase_nueva);
					}
					else if (red[elemento_de_arriba]!=0){
						red[elemento_actual] = clase_de_posicion(hoshen, red[elemento_de_arriba]);
					}
				}

				else if (i==0){ //primera fila
					if (red[elemento_de_la_izquierda]==0){
						clase_nueva = actualizar(red, hoshen, elemento_actual, clase_nueva);
					}

					else if (red[elemento_de_la_izquierda]!=0){
						red[elemento_actual] = clase_de_posicion(hoshen, red[elemento_de_la_izquierda]);
					}
				}

				else { //bulk de la red
					if (red[elemento_de_arriba]==0 && red[elemento_de_la_izquierda]==0){ // caso trivial, vecinos nulos
						clase_nueva = actualizar(red, hoshen, elemento_actual, clase_nueva);
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]==0){ // caso simple, vecino a la izquierda
						red[elemento_actual] = clase_de_posicion(hoshen, red[elemento_de_arriba]);
					}

					else if (red[elemento_de_arriba]==0 && red[elemento_de_la_izquierda]!=0){ //caso simple, vecino arriba
						red[elemento_actual] = clase_de_posicion(hoshen, red[elemento_de_la_izquierda]);
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]!=0 && red[elemento_de_arriba]==red[elemento_de_la_izquierda]){
						red[elemento_actual] = clase_de_posicion(hoshen, red[elemento_de_arriba]);
					}

					else if (red[elemento_de_arriba]!=0 && red[elemento_de_la_izquierda]!=0 && red[elemento_de_arriba]!=red[elemento_de_la_izquierda]){ //caso complicado, conficto de etiquetas
						int clase_de_arriba = clase_de_posicion(hoshen, red[elemento_de_arriba]);
						// Aca estaba haciendo mal la cuenta del elemento de la izquierda
						int clase_de_izquierda = clase_de_posicion(hoshen, red[elemento_de_la_izquierda]);

						if (clase_de_arriba<clase_de_izquierda){
							red[elemento_actual] = clase_de_arriba;
							hoshen[clase_de_izquierda] = -clase_de_arriba;
						}

						else if (clase_de_izquierda<clase_de_arriba){
							red[elemento_actual] = clase_de_izquierda;
							hoshen[clase_de_arriba] = -clase_de_izquierda;
						}

						else{
							red[elemento_actual] = clase_de_izquierda;
						}
					}
				}
			}
		}
	}

	//re-etiquetado corrige etiquetas falsas
	for (i = 0 ; i < N*N ; i++) {
		red[i] = clase_de_posicion(hoshen, red[i]);
	}
return 0;
}


bool percola(int N, int red[]) {
	int *primera_fila = &red[0];
	int *ultima_fila = &red[N*(N - 1)];

	int indice_primera_fila, indice_ultima_fila;

	for (indice_primera_fila = 0; indice_primera_fila < N; indice_primera_fila++) {
		int elemento_primera_fila = primera_fila[indice_primera_fila];
		for (indice_ultima_fila = 0; indice_ultima_fila < N; indice_ultima_fila++) {
			int elemento_ultima_fila = ultima_fila[indice_ultima_fila];

			if (elemento_primera_fila == elemento_ultima_fila && elemento_ultima_fila != 0) {
				return true;
			}
		}
	}

	return false;
}

// genera un array contando cuantas veces aparece cada etiqueta (la entrada i es
// la cantidad de elementos con la etiqueta i)
void tags(int N, int *red, int *tag){

	int i;

	for (i=0; i<N*N; i++){
		tag[i] = 0;
	}

	for (i=0; i<N*N; i++){
		if(red[i]!=0){
		tag[red[i]]++;
		}
	}
}

// genera un array con la cantidad de clusters de un dado tamaño
// tamanos[i] es la cantidad de clusters de tamaño i
void ns(int N, int *red, int *tag, int *tamanos){

	int i;

	tags(N, red, tag); // genera el vector con el tamaño de cada etiqueta

	for (i=0; i<N*N; i++){
		tamanos[i] = 0;
	}

	for (i=0; i<N*N; i++){ // cuando la etiqueta i aparece n veces, se suma uno a tamanos[n]
		if (tag[i]!=0){
		tamanos[tag[i]]++;
		}
	}
}

void print_ns(int N, int red[]){

	int tag[N*N]; //genera el array de tamaños de etiquetas
	int tamanos[N*N]; // genera el array con el ns a partir de las etiquetas
	int i;

	tags(N, red, tag);
	ns(N, red, tag, tamanos);

	printf("\n");
	for (i=1; i<N*N; i++){
		if (tamanos[i]!=0){
		printf("La cantidad de clusters de tamaño %i es %i \n", i, tamanos[i]);
		}
	}
}

// Calcula la fuerza del cluster percolante P_oo, a partir de la red y del
// array con los tamaños de las etiquetas
float fuerza(int N, int red[], int tag[]){
	if (percola(N, red)){ // repite lo de la funcion percola
		float P;
		int *primera_fila = &red[0];
		int *ultima_fila = &red[N*(N - 1)];

		int indice_primera_fila, indice_ultima_fila;

		for (indice_primera_fila = 0; indice_primera_fila < N; indice_primera_fila++) {
			int elemento_primera_fila = primera_fila[indice_primera_fila];
			for (indice_ultima_fila = 0; indice_ultima_fila < N; indice_ultima_fila++) {
				int elemento_ultima_fila = ultima_fila[indice_ultima_fila];

				if (elemento_primera_fila == elemento_ultima_fila && elemento_ultima_fila != 0) {
					P = tag[elemento_ultima_fila]; //mira el tamaño de la etiqueta que percola
				}
			}
		}
		return P/(N*N);
	}

}

int masa(int N, int red[], int tag[]){
	if (percola(N, red)){ // repite lo de la funcion percola
		int M;
		int *primera_fila = &red[0];
		int *ultima_fila = &red[N*(N - 1)];

		int indice_primera_fila, indice_ultima_fila;

		for (indice_primera_fila = 0; indice_primera_fila < N; indice_primera_fila++) {
			int elemento_primera_fila = primera_fila[indice_primera_fila];
			for (indice_ultima_fila = 0; indice_ultima_fila < N; indice_ultima_fila++) {
				int elemento_ultima_fila = ultima_fila[indice_ultima_fila];

				if (elemento_primera_fila == elemento_ultima_fila && elemento_ultima_fila != 0) {
					M = tag[elemento_ultima_fila]; //mira el tamaño de la etiqueta que percola
				}
			}
		}
		return M;
	}

}





float calcular_p_c_a(int red[], int n, int n_precision, int n_promediar){
	float p_c;
	float p;
	p = 0.5;
	double i;
	float potencia;
	int j;
	float suma[j+1];
	suma[0] = 0;
	for (j=1; j < n_promediar; j++){
		srand(time(NULL));
		for (i=1; i < n_precision; i++){
			llenar(red, n, p);
			hoshen(red, n);
			potencia = pow(2, i);
			if (percola(n, red)){
				p = p - (1.0/ potencia);
			}
			else{
				p = p + (1.0/ potencia);
			}
		}
	suma[j] = p + suma[j-1];
	p_c = suma[j] / j;
	}
return p_c;
}






float calcular_p_c_b(int red[], int n, int num_iteraciones, int n_precision){
	float i;
	int j;
	float percolo[num_iteraciones];
	float p;
	for (j = 0; j < num_iteraciones; j++){
		for (i = 0; i<n_precision; i++){
			p = i/n_precision;
			llenar(red, n, p);
			hoshen(red, n);
			if (percola(n, red)){
			percolo[j] = p;
			break;
			}
		}
	}
return p;
}
