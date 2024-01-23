
/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 26/10/21
*/

//librerías
#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo{
     int nro;
     struct nodo *izq, *der;
};

typedef struct nodo *ABB;


ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          postOrden(arbol->izq);
          postOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< " " << arbol->nro << " " <<endl;

     verArbol(arbol->izq, n+1);
}

int main()
{
    ABB arbol = NULL;   // creado Arbol

    int n;  
    int x; 
    int i=0;
    
    int op;
    setlocale (LC_CTYPE, "spanish"); //para usar caracteres en español 
    do{
	
    cout << "\n\t\t      [ ARBOL BINARIO DE BUSQUEDA ]  \n\n";
    cout << "\n\n\t\t\t\t  Menú";
    cout << "\n\n\t\t\t[1] Inserción al árbol \n\t\t\t[2] Consultar el árbol \n\t\t\t[3] Recorridos  \n\t\t\t[4] Salir \n\n"; //imprime el menú
    cout<<"\n"; //imprime un espacio 
    cout<< "  Respuesta: ";
        while(!(cin >> op))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
		cout<<"  Respuesta: ";
		}
        switch(op) //inicio del switch que nos permite escoger una opción
        {
            case 1:
            cout<<"\n";
		   

        do
       {
        cout << " Numero del nodo " << ": ";
        while(!(cin >> x))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
		cout<<"  : ";
		}
        insertar( arbol, x);
        cout<<"\n";
        cout<<"Deseas Ingresar mas nodos? 1[SI] 2[NO]: ";
        cin >>n;
      
       }while(n != 2);
		    cout<<"\n";
            break;
 
            case 2:
            cout<<"\n";
			cout << "\n Mostrando Arbol Binario \n\n";
            verArbol( arbol, 0);
			cout<<"\n";
            break;
 
            case 3:	
            cout<<"\n";
			cout << "\n Recorridos del Arbol";

            cout << "\n\n In orden   :  ";   enOrden(arbol);
            cout << "\n\n Pre Orden  :  ";   preOrden(arbol);
            cout << "\n\n Post Orden :  ";   postOrden(arbol);

            cout << endl << endl;
			cout<<"\n";
            break;
 
            case 4:
            cout<<"\n Saliendo... "; //finaliza el programa
            return 0;
            break;
 
        }
 


   
    }while(op != 4);
    return 0;
}
