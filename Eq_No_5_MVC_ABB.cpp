/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 8/11/21
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

/*---------  Estructura del arbol  -------*/
typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ABB;

int numNodos = 0; // nummero de nodos del arbol ABB
    
int hojas =0; //numero de hojas del arbol ABB


/* ---------- Estructura de la cola ---------*/
struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};
struct cola{
    struct nodoCola *delante;
    struct nodoCola *atras;
};

void inicializaCola(struct cola &q)//funcion para iniciar la cola del arbol ABB
{
    q.delante = NULL;
    q.atras = NULL;
}

void encola(struct cola &q, ABB n)//funcion para añadir a la cola el nodo creado 
{
     struct nodoCola *p;
     p = new(struct nodoCola);
     p->ptr = n;
     p->sgte = NULL;
     if(q.delante==NULL)
         q.delante = p;
     else
         (q.atras)->sgte = p;
     q.atras = p;
}

ABB desencola(struct cola &q)// funcion para eliminar de la cola el nodo eliminado 
{
    struct nodoCola *p;
    p = q.delante;
    ABB n = p->ptr;
    q.delante = (q.delante)->sgte;
    delete(p);
    return n;
}

ABB crearNodo(int x)//funcion para crear un nuevo nodo
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;
     numNodos++;
     return nuevoNodo;
}
void insertar(ABB &arbol, int x)//funcion para insertar al arbol ABB el nodo
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado..!"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

void preOrden(ABB arbol)//funcion para visualizar el arbol ABB en preorden
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

void enOrden(ABB arbol)////funcion para visualizar el arbol ABB en orden
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

void postOrden(ABB arbol)//funcion para visualizar el arbol ABB en postorden
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}

void verArbol(ABB arbol, int n)//funcion para visualizar el arbol ABB
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

    
     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

int busquedaRec(ABB arbol, int dato)//funcion para buscar en el arbol ABB
{
     int r=0;  

     if(arbol==NULL)
        return r;

     if(dato<arbol->nro)
         r = busquedaRec(arbol->izq, dato);

     else if(dato> arbol->nro)
         r = busquedaRec(arbol->der, dato);

     else
        r = 1;   

     return r;
}

ABB unirABB(ABB izq, ABB der)//funcion para unir las partes del arbol ABB utilizada en la funcion para eliminar el nodo
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}

void elimina(ABB &arbol, int x)//funcion para eliminar un nodo 
{
     if(arbol==NULL) return;

     if(x<arbol->nro)
         elimina(arbol->izq, x);
     else if(x>arbol->nro)
         elimina(arbol->der, x);

     else
     {
         ABB p = arbol;
         arbol = unirABB(arbol->izq, arbol->der);
         delete p;
     }
     
}

int alturaAB(ABB arbol)//funcion  para calcular la altura del Arbol ABB
{
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

void recorrerxNivel(ABB arbol)//funcion para recorrer por nivel el arbol ABB
{
     struct cola q;
     inicializaCola(q);
     cout << "\t";

     if(arbol!=NULL)
     {
         encola(q, arbol);

         while(q.delante!=NULL)
         {
             arbol = desencola(q);
             cout << arbol->nro << ' ';

             if(arbol->izq!=NULL)
                 encola(q, arbol->izq);
             if(arbol->der!=NULL)
                 encola(q, arbol->der);
         }
     }
}





int contarHojas(ABB arbol)//funcion para contar los nodos hoja del arbol ABB
{
        if (arbol==NULL)
        {
                return 0;
        }
        if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
        {
        	hojas++;
        	 
        	 
                return 1;
        }
        else
        {
                return contarHojas(arbol->izq) + contarHojas(arbol->der);
        }
}

int main()
{
    ABB arbol = NULL;
    int x;
    int op, op2;
    int c;
    //variables para el uso dentro del main
    
    do
    {
          
     system("cls");
     cout << "\n\t..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
     cout << "\t [1]  Insertar elemento                  \n";
     cout << "\t [2]  Mostrar arbol                      \n";
     cout << "\t [3]  Recorridos de profundiad           \n";
     cout << "\t [4]  Buscar elemento                    \n";
     cout << "\t [5]  Eliminar elemento                  \n";
     cout << "\t [6]  Recorrido por  Amplitud  \n";
     cout << "\t [7]  Altura del arbol                   \n";
     cout << "\t [8]  Contar nodos                       \n";
     cout << "\t [9]  Contar hojas                       \n";
     cout << "\t [10] SALIR                              \n";
     cout<<"\n  Respuesta: ";
      while(!(cin >> op))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
		cout<<"  Respuesta: ";
		}

          switch(op)
          {
               case 1:
               	do{
				   
                    cout << " Ingrese valor : ";
                     while(!(cin >> x))  //para evitar que introduzcan mal un caracter
	             	{
  		            cin.clear();
  		            cin.ignore(1000, '\n');
 	 	            cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
		            cout<<"  : ";
		             }
                    insertar( arbol, x);
                    cout<<"\nDesea ingresar mas nodos? [1] SI [2] NO: "; cin>>c;
                    }
                    while(c!=2);
                    break;

               case 2:
                    verArbol(arbol, 0);
                    break;

               case 3:
                    
                int op2;
				system("cls");  
				cout << endl;
				cout << "\t [1] En Orden     \n";
				cout << "\t [2] Pre Orden    \n";
				cout << "\t [3] Post Orden   \n";
				cout<<"\n  Respuesta: ";
				while(!(cin >> op2))  //para evitar que introduzcan mal un caracter
				{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
				cout<<"  Respuesta: ";
				}

                    if(arbol!=NULL)
                    {
                         switch(op2)
                         {
                             case 1:
                                 enOrden(arbol); break;
                             case 2:
                                 preOrden(arbol); break;
                             case 3:
                                 postOrden(arbol); break;
                         }
                    }
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;

               case 4:
                    int band;
                    

                    cout<<" Valor a buscar: "; cin>> x;

                    band = busquedaRec(arbol,x);

                    if(band==1)
                    
					
					
                       cout << "\n\tEncontrado...";
                    
                    else
                       cout << "\n\tNo encontrado...";
                    break;

               case 5:
                    cout<<" Valor a eliminar: "; cin>> x;
                    elimina(arbol, x);
                    cout << "\n\tEliminado..!";
                    numNodos--;
                    break;

               case 6:
                    cout<<"\n\n Mostrando recorrido por amplitud\n\n";
                    recorrerxNivel(arbol);
                    break;

               case 7:
                    int h;
                    h = alturaAB(arbol);
                    cout << " La altura es : "<< h << endl;
                    break;

            

               case 8:
                    verArbol(arbol, 0);
                    cout << "\n\n El numero de nodos es : ";
                    cout << numNodos;
                    break;
               
               case 9:
               	   verArbol(arbol,0);
               	   contarHojas(arbol);
               	   cout<<"\nNumero de hojas: "<<hojas<<endl;
               	   
               	    break;
            

               case 10:
               		cout<<"\n Saliendo...";
                    exit(0);
          }

          cout<<"\n\n\n";
          system("pause");  
    }while(op!=10);

}
