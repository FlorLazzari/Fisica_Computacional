int main()
{
	int red[n*n];
	int tag[n*n];
	int tamanos[n*n];
	srand(time(NULL));
	calcular_p_c(15, red);
	// no hace falta devolver el puntero ya que la funcion no lo cambia
	llenar(red, n, 0.5);
	print_red(n, red);
	// idem
	hoshen(red, n);
	print_red(n, red);

	printf("%s\n", percola(n, red) ? "percola" : "no percola");

	printf("\n");
	tags(n, red, tag);
	//ns(n, red, tag, tamanos);
	if (percola(n, red)){
		printf("La fuerza del cluster percolante es %.3f \n", fuerza(n, red, tag) );
	}

	print_ns(n, red);



	return 0;
}








	// estimo p_c como el valor de p para el cual la red percola al menos la mitad de veces

void calcular_p_c(int num_iteraciones, int red[]){
	float i;
	int j;
	float percolo[num_iteraciones];
	float p;
	for (j = 0; j< num_iteraciones; j++){
		for (i = 0; i<100; i++){
			p = i/100;
			llenar(red, n, p);
			hoshen(red, n);
			if (percola(n, red)){
			percolo[j] = p;
			break;
			}
		}
	printf("percolo para el valor de proba = %f", percolo[j]);
	printf("\n");
	}
//return p_c
}
