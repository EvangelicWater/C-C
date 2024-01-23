#include <iostream>

using namespace std;

int main(){
    //definicion de variables
    int auxEntero = 0;
    int rangoBusqueda = 0;
    int cantidad;
    printf("PROGRAMA QUE BUSCA NUMEROS PERFECTOS.\n\n");
    
	
    printf("Rango de busqueda (Ingrese un numero entero)  ");

    scanf("%d",&rangoBusqueda);
    printf("Ingrese el mismo numero otra ves(en caso de ingresar un numero distinto el resultado sera erroneo)  ");
    scanf("%d",&cantidad);
    if(rangoBusqueda<2)
    {
    	printf("El valor no puede ser menor a 2\n");
	}
	
    else if(rangoBusqueda==cantidad){
	

    for(int i = 1; i <= rangoBusqueda; i++){
        if(i % 2 == 0){
            for(int j = (i / 2); j >= 1 ; j--){
                if( i % j == 0){
                    auxEntero = auxEntero + j;
                }
            }
            if(auxEntero == i)
                printf("Número Perfecto: %d\n",auxEntero);
            
        }
        auxEntero = 0;
        }
        }
        else{
        	printf("No ingreso el mismo dato como se le pidio");
		}
		
		
		
		if (cantidad==6)
		{
			printf("Tiene 1 numero perfecto");
		}
		else if (cantidad==26)
		{
			printf("Tiene 2 numeros perfectos");
		}
		else if(cantidad<26&&cantidad>=6)
		{
			printf("Tiene 1 numero perfecto");
		}
		else if (cantidad<496&&cantidad>=26)
		{
			printf("Tiene 2 numeros perfectos");
		}
		 else if (cantidad==496)
		{
			printf("Tiene 3 numeros perfectos");
		}
		 else if (cantidad<8128&&cantidad>=496)
		{
			printf("Tiene 3 numeros perfectos");
		}
		else if (cantidad>=8128)
		{
			printf("Tiene 4 numeros perfectos");
		}
		else if(cantidad<2){
			printf("La cantidad no puede ser menor a 2");
		}
		
		else{
			printf("No tiene numeros perfectos");
		}
        auxEntero = 0;
    
    return 0;
}
