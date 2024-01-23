/*Andrés Humberto Martínez Escobedo
  16/6/2021
  4520160054
  Seminario de Solucion de Problemas de Estructura de Datos I
  tercer parcial
  00603AM */
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream>
using namespace std;


struct nodo

{
int dato;
struct nodo *ant, *sig; /*ant=ptr_ant 
                        sig=ptr_sig*/

};//struct con lista enlazada doble
//como es lista enlazada doble pude hacer el programa con la opcion de modificar el frente y final de la cola a gusto propio pero no lo hice porque eso le quita el sentido de ser una estructura FIFO

struct nodo *cabeza = NULL, *cola = NULL;

struct nodo * agregar_nodo(int dato)

{

/*creacion de un nodo nuevo*/

struct nodo *newnodo = (struct nodo *)malloc(sizeof (struct nodo));//newnodo= nodo nuevo

newnodo->dato = dato;
newnodo->sig = newnodo->ant = NULL;
return (newnodo);

}

/* creacion del cuerpo para el manejo de la cabeza y cola de la estructura */

void crear_cuerpo() /*se crea la cabeza y la cola*/ {

cabeza = agregar_nodo(0);
cola = agregar_nodo(0);
cabeza->sig = cola;
cola->ant = cabeza;
}

/* Se añade el dato al frente de la cola */

void agregar(int dato)
{
struct nodo *newnodo, *temp;
newnodo = agregar_nodo(dato);
temp = cabeza->sig;
cabeza->sig = newnodo;
newnodo->ant = cabeza;

newnodo->sig = temp;
temp->ant = newnodo;
}

/* se elimina el dato al final de la cola */

void eliminar()

{
struct nodo *temp;
if (cola->ant == cabeza)

{
printf("La lista esta vacia\n");
}
else
{

temp = cola->ant;
cola->ant = temp->ant;
temp->ant->sig = cola;
free(temp);
printf("\nEliminado\n");
}

return;
}

/* se muestran todos los datos de la cola */

void consultar()
{
struct nodo *temp;

if (cabeza->sig == cola)
{
printf("La cola esta vacia\n");
return;
}

temp = cabeza->sig;
while (temp != cola)
{

printf("%-3d", temp->dato);
temp = temp->sig;
}
printf("\n");
}


int main()
{
int data, ch;

crear_cuerpo();
while (1)

{
printf("\n---------------------------------------------------------------------\n");  
printf("\nMenu\n");
printf("\nEstructura FIFO\n");
printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");  	
printf("1. Agregar\n2. Consultar\n3. Eliminar\n4. Salir");
printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); 
printf("\nIngrese una opcion del menu: ");
scanf("%d", &ch);
printf("\n---------------------------------------------------------------------\n");
switch (ch) /*inicio de switch*/
{

case 1:
printf("Ingrese el dato: ");
if(scanf("%i", &data) != 1){
        	cout << '\a';
        	printf("\nERROR.\nNo puedes ingresar letras ni caracteres especiales.\n");//verifico que el dato ingresado sea entero (int)
        	exit(0);
		}
else{
	agregar(data);
}		
break;

case 2:

consultar();
break;

case 3:
eliminar();
break;

case 4:
Beep(523,500);
printf("Saliendo...");
exit(0);
break;

default:
printf(" Opcion Invalida\n");
break;
} /*fin de switch*/
}
return 0;
}
