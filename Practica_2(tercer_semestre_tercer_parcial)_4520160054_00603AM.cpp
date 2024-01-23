#include<stdio.h>   
#include<stdlib.h>
#include <windows.h>
#include <iostream> //librerias
/*Andrés Humberto Martínez Escobedo
  6/6/2021
  4520160054
  Listas enlazadas con estructura FIFO
  00603AM
  Seminario de Solucion de Problemas de ED 1 */  
struct nodo   
{  
    int dato;   
    struct nodo *e;  //e hace referencia a enlace
}; //declaracion de lista enlazada 
struct nodo *f;  //f es una variable que utilizo para hacer referencia al frente de la cola
struct nodo *r;   //r es una variable que utilizo para hacer referencia el reverso o final de la cola
void agregar();//declaracion de funciones a utilizar  
void eliminar();  
void mostrar();//declaracion de funciones a utilizar  
int main () //inicio  
{  
    int op;//variable para opcion   
    while(op != 4)//mientras que opcion no sea 4   
    {   
 	    printf("\n---------------------------------------------------------------------\n");  
        printf("\nMenu\n");  
        printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");  
        printf("\n[1]Agregar.\n[2]Eliminar.\n[3]Consultar/Mostrar lista.\n[4]Salir\n");
		printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");    
        printf("\nIngrese la opcion a ejecutar: ");  //menu
        scanf("%d",& op);  //se obtiene la variable
        printf("\n---------------------------------------------------------------------\n");
        switch(op) //inicio de switch en base a la opcion 
        {  
            case 1:  
            agregar(); //funcion para agregar 
            break;  
            case 2:  
            eliminar();  //funcion para eliminar en base a la estructura FIFO
            break;  
            case 3:  
            mostrar();  //funcion para mostrar los valores
            break;  
            case 4:  
            exit(0);  //se termina el programa
            break;  
            default:   
            printf("\nOpcion invalida\n");  //en caso de no seleccionar ninguna opcion del menu
        }//fin del switch  
    }//fin del while  
}//fin de main  
void agregar()//funcion para agregar elementos  
{  
    struct nodo *ptr;  //utilizo la variable ptr para revisar el espacio de la memoria 
    int i;//variable para el elemento a ingresar   
      
    ptr = (struct nodo *) malloc (sizeof(struct nodo));  
    if(ptr == NULL)  
    {  
        printf("\nNo hay mas espacio.\n");  //si no se puede crear un nuevo espacio en la memoria 
        return;  
    } 
    else  //si la creacion del espacio fue exitosa se sigue con la asignacion del valor para ese espacio
    {   //si no esta llena la memoria
        printf("\nIngrese el valor: \n");  
        if(scanf("%i", &i) != 1){
        	Beep(523,500);
        	printf("ERROR.\nNo puedes ingresar letras ni caracteres especiales.\n");//verifico que el dato ingresado sea entero (int)
        	exit(0);
		}
		else{
		  
        ptr -> dato = i;  
        if(f == NULL)  
        {  
            f = ptr;  
            r = ptr;   
            f -> e = NULL;  
            r -> e = NULL;  
        }  
        else   
        {  
            r -> e = ptr;  
            r = ptr;  
            r->e = NULL;  
        }
		}    
    }  
}     
void eliminar ()  //funcion para eliminar elementos de la estructura FIFO
{  
    struct nodo *ptr;  
    if(f == NULL)  
    {  
        printf("\nNo hay elementos.\n");  //se utiliza f para revisar si la cola esta vacia
        return;  
    }  
    else   
    {  
        ptr = f;  
        f = f -> e;  
        free(ptr);
		printf("\nEliminado\n");  
    }  
}  
void mostrar()  //funcion para mostrar elementos
{  
    struct nodo *ptr;  
    ptr = f;      
    if(f == NULL)  
    {  
        printf("\nNo hay elementos.\n");  //por si la cola esta vacia
    }  
    else  
    {   printf("\nImprimiendo valores .....\n");  
        while(ptr != NULL)   
        {  
            printf("\n%d\n",ptr -> dato);  
            ptr = ptr -> e;  
        }  
    }  
} 
