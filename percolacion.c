#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define P     16             // 1/2^P, P=16
#define Z     27000          // iteraciones
#define N     30             // lado de la red simulada


void  llenar(int *red,int n,float prob);
int   hoshen(int *red,int n);
int   actualizar(int *red,int *clase,int s,int frag);
void  etiqueta_falsa(int *red,int *clase,int s1,int s2);
void  corregir_etiqueta(int *red,int *clase,int n);
int   percola(int *red,int n);

int main(int argc,char *argv[])
{
  int    i,j,*red;
  float  prob,denominador;

  n=N;
  z=Z;

  if (argc==3) 
     {
       sscanf(argv[1],"%d",&n);
       sscanf(argv[2],"%d",&z);
     }
    
  red=(int *)malloc(n*n*sizeof(int));



  for(i=0;i<z;i++)
    {
      prob=0.5;
      denominador=2.0;
 
      srand(time(NULL));

      for(j=0;j<P;j++)
        {
          llenar(red,n,prob);
      
          hoshen(red,n);
        
          denominador=2.0*denominador;

          if (percola(red,n)) 
             prob+=(-1.0/denominador); 
          else prob+=(1.0/denominador);
        }
    }

  free(red);

  return 0;
}



int hoshen(int *red,int n)
{
  /*
    Esta funcion implementa en algoritmo de Hoshen-Kopelman.
    Recibe el puntero que apunta a la red y asigna etiquetas 
    a cada fragmento de red. 
  */

  int i,j,k,s1,s2,frag;
  int *clase;

  frag=0;
  
  clase=(int *)malloc(n*n*sizeof(int));

  for(k=0;k<n*n;k++) *(clase+k)=frag;
  
  // primer elemento de la red

  s1=0;
  frag=2;
  if (*red) frag=actualizar(red,clase,s1,frag);
  
  // primera fila de la red

  for(i=1;i<n;i++) 
    {
      if (*(red+i)) 
         {
           s1=*(red+i-1);  
           frag=actualizar(red+i,clase,s1,frag);
         }
    }
  

  // el resto de las filas 

  for(i=n;i<n*n;i=i+n)
    {

      // primer elemento de cada fila

      if (*(red+i)) 
         {
           s1=*(red+i-n); 
           frag=actualizar(red+i,clase,s1,frag);
         }

      for(j=1;j<n;j++)
	if (*(red+i+j))
	  {
	    s1=*(red+i+j-1); 
            s2=*(red+i+j-n);

	    if (s1*s2>0)
	      {
		etiqueta_falsa(red+i+j,clase,s1,s2);
	      }
	    else 
	      { if (s1!=0) frag=actualizar(red+i+j,clase,s1,frag);
	        else       frag=actualizar(red+i+j,clase,s2,frag);
	      }
	  }
    }


  corregir_etiqueta(red,clase,n);

  free(clase):

  return 0;
}



