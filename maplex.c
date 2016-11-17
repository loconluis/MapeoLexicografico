/*Universidad de San Carlos De Guatemala
Facultad de Ingenieria
Luis Alfredo Locon Peña
2011-14279 */

#include <stdio.h>

  int bandera=0;
  int dim =0;
  int tam, pos=0;
  int i,j, aux;
  int ingreso=0;
  int total=0;
  int suma =0;

  int mapping( int listav[], int listapos[]){
    if(bandera < dim-1){
        if(ingreso < 1){

            int littlex = listapos[dim-1];
            int littley = listav[dim-2];
            int parcial = littlex * littley;
            suma = parcial + listapos[dim-2];
            total = suma;
            ingreso= 1;
            aux =  dim-2;

            bandera++;
            mapping(listav, listapos);
        }
        else {
            int parcial2 = suma * listav[aux-1];
            total = parcial2 + listapos[aux-1];
            aux=aux-1;
            bandera++;
            mapping(listav, listapos);
        }
    }
    else {
        return total;
    }

  }

  int main(){
    /*Incluimos el numero de dimensiones que tendra nuestro arreglo*/
    printf("¿Cuantas dimesiones tendra el arreglo? [En un intervalo de 1....n] \n");
    scanf("%d", &dim);
    int listavectores[dim];

    int listaposicion[dim];
    /*Iniciamos un ciclo en el cual pedimos los tamaños de los vectores*/
    for(i=0 ;i<dim;i++){
      printf("Ingrese el tamaño del vector %d\n", i+1);
      scanf("%d", &tam);
      listavectores[i]=tam;
    }

    for(j=0;j<dim;j++){
      printf("Ingrese la posicion del vector %d\n", j+1);
      scanf("%d", &pos);
      listaposicion[j]=pos;
    }

    int addres = mapping(listavectores, listaposicion);
    printf("La direccion del dato es:  %d\n", addres );

    return 0;
  }
