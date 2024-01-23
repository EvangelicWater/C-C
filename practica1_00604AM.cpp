/*
programa hecho por Diego Rodolfo Vargas Vega, Andrés Humberto Martínez Escobedo y Mireya Lizette Cisneros Sandoval

fecha de elaboración 18/08/2021
*/

#include <iostream> //librerías
#include <cstdlib>
#include <cstring>
#include <clocale> 	 //define el tamaño de las cadenas de caracteres, todas estas son variables globales para determinar el tamaño de los arreglos
#define V 10     // no. vendedores
#define PV 10   //  productos vendidos

using namespace std;
 
struct Producto {
   
    float  precio; //variable del precio
	int  cantidad; //cantidad
	char prod[50];  // nombre del producto
    
    
};
 
struct cantidadpro { //struct que organiza variables a usar en productos
    int numProd ;             // numero de productos por vendedor
    Producto vp[PV];      //varios productos cada uno en una posicion del  vector

};
 
struct Vendedor { //struct que organiza las variables a usar en los vendedores
    char nombre[50]   ; //variable del nombre
    char apellido[50] ; //variable del apellido
    char direccion[50]; //variable de la dirección
    int  cv; //variable de la clave
    cantidadpro P; //llaamdo a la struct 
};
 
struct Vendedor lista[V]; // llamado de los struct a usar alias
struct Vendedor aux; 


//prototipo de las funciones a usar 
void busqueda( int num); 
void eliminarvendedor( int x, int &num);
void imprimirvendedores(int num);
void imprimirproductos(int nv);
void prodVendedor(int x, int num);
void infov(int x, int num);
void registrovend(int n);
void registroprod(int nv, int np);
int validarNombre(char nombre[]); 
int validarNombreP(char nombre[]); 
int validarApellido(char nombre[]); 
 
int main() //programa principal 
{
    int num=0;  // variable numero 
    int op;   // opcion del menu
    int num_vendedor ; //variable cantidad de vendedores 
	setlocale (LC_CTYPE, "spanish"); //para usar caracteres en español 
 
    do //inicia el ciclo
    { //menú
        cout<<"\n\n";
        cout<<"\n\n\t\t\t\t[1] Registro Vendedor/productos \n\t\t\t\t[2] Mostrar registros\n\t\t\t\t[3] Buscar registro\n\t\t\t\t[4] Buscar registro por clave\n\t\t\t\t[5] Eliminar registro\n\t\t\t\t[6] Salir\n\n"; //imprime el menú
        cout<<"\n"; //imprime un espacio 
        cout<< "  Respuesta: ";
        while(!(cin >> op))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "  tipo de dato no permitido, intenta nuevamente\n";
		cout<<"  Respuesta: ";
		}
 
        switch(op) //inicio del switch que nos permite escoger una opción
        {
            case 1:
                cout<<"\n Numero de vendedores: ";
                 while(!(cin >> num)) 
				{
  				cin.clear();
  				cin.ignore(1000, '\n');
 	 			cout << "tipo de dato no permitido, intenta nuevamente\n";
				cout<<"\n Numero de vendedores: ";
				}
                registrovend(num);  cout<<endl;
                break;
 
            case 2:
                imprimirvendedores(num);
                break;
 
            case 3:
                cout<<"\n Ingrese numero de vendedor: ";
                 while(!(cin >> num_vendedor)) 
				{
  				cin.clear();
  				cin.ignore(1000, '\n');
 	 			cout << "tipo de dato no permitido, intenta nuevamente\n";
				cout<<"\n Ingrese numero de vendedor: ";
				}
                infov( num_vendedor-1, num);
                break;
 
            case 4:
                cout<<"\n Ingrese la clave: ";
                 while(!(cin >> aux.cv)) 
				{
  				cin.clear();
  				cin.ignore(1000, '\n');
 	 			cout << "tipo de dato no permitido, intenta nuevamente\n";
				cout<<"\n Ingrese la clave: ";
				}
                busqueda(num);
                break;
 
            case 5:
                cout<<"\n Ingrese no. de vendedor: ";
                while(!(cin >> num_vendedor)) 
				{
  				cin.clear();
  				cin.ignore(1000, '\n');
 	 			cout << "tipo de dato no permitido, intenta nuevamente\n";
				cout<<"\n Ingrese no. de vendedor: ";
				}
                eliminarvendedor( num_vendedor-1, num);
                cout<<"\n\n\t\tVendedor eliminado ..!"<<endl;
                break;
 
            case 6:
                cout<<"\n Saliendo... ";
                return 0;
                break;
 
        }
 
    } while(op != 6);//fin de ciclo
 
 
    return 0; //fin de programa

}

 
void registroprod(int nv, int np)  //funcion ára registrar los productos
{
    int validacion;
 
    for(int i=0; i<np; i++)
    {
        cout<<"\n\tProducto "<< i+1 <<endl;
        cin.ignore();
        do{
		
        cout<<"\t\tNombre   : " ;
        cin.getline( lista[nv].P.vp[i].prod, 50 );
         validacion=validarNombreP(lista[nv].P.vp[i].prod);
 		}while(validacion==0);
 		cout<<"\t\tCantidad : ";
        while(!(cin >> lista[nv].P.vp[i].cantidad)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout<<"\t\tCantidad : ";
		}
 
        
        cout<<"\t\tPrecio   : ";
        while(!(cin >> lista[nv].P.vp[i].precio)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
    	cout<<"\t\tPrecio   : ";
		}
       
 
    }
 
}
void registrovend(int n) //función para registro de vendedores 
{
    int np ;  //  numero de productos por cada vendedor
    int validacion;
    int validacion2;
    for(int i=0; i<n; i++)
    {
        cout<<"\nVENDEDOR "<< i+1 << "\n";
 
        cin.ignore();
		do{
		  
		cout << "   Nombres   : ";  
		cin.getline( lista[i].nombre, 50  );
		validacion=validarNombre(lista[i].nombre);
		}while(validacion==0); 
	
  		do{
		  
        cout << "   Apellidos : ";  
		cin.getline( lista[i].apellido, 50 );
		validacion2=validarApellido(lista[i].apellido);
		}while(validacion2==0);
        cout << "   Direccion : ";  
		cin.getline( lista[i].direccion, 50 );
        cout << "   Clave     : ";  
        while(!(cin >> lista[i].cv)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
    	cout << "   Clave     : ";
		}
		
        cout<<"\n   > Numero de productos: ";
        while(!(cin >> lista[i].P.numProd)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
    	cout<<"\n   > Numero de productos: ";
		}
 
        registroprod( i ,lista[i].P.numProd );
    }
}
 
void infov(int b, int num) //función que imprime la info del vendedor 
{
    if(num>0)
    {
        cout<<endl<<endl;
        cout << "\t" << lista[b].nombre <<' '<< lista[b].apellido << endl;
        cout << "\tClave      :  "<< lista[b].cv       << endl;
        cout << "\tDirección:  "<< lista[b].direccion << endl;
    }
    else
        cout<<"\n\tEste registro está vacío";
 
}
 
void prodVendedor(int a, int num) // función  que imprime los productos de los vendedores 
{
    if(num>0)
    {
        cout<<endl<<endl;
        cout << "   Productos de " << lista[a].nombre <<' '<< lista[a].apellido << endl<<endl;
 
        for(int i=0; i<lista[a].P.numProd; i++)
        {
            cout<<"\n   Producto "<< i+1                      <<endl;
            cout<<"\tNombre  : " << lista[a].P.vp[i].prod  <<endl;
            cout<<"\tCantidad: " << lista[a].P.vp[i].cantidad <<endl;
        }
        cout<<endl;
    }
    else
        cout<<"\n\tEste registro está vacío";
 
}
 
void imprimirproductos(int nv) //lista productos 
{
    cout<<"   Productos: \n\n";
    for(int i=0; i<lista[nv].P.numProd; i++)
    {
        cout<<"\t- " << lista[nv].P.vp[i].prod <<endl ;
    }
}
 
void imprimirvendedores(int num)  //imprime info de los vendedores
{
    if( num>0)
    {
        cout<<"\n\nVendedores\n";
        for(int i=0; i<num; i++)
        {
            cout<<endl<<endl;
            cout<< i+1<<". "<< lista[i].nombre <<' '<< lista[i].apellido << endl;
            cout << "\tClave      :  "<< lista[i].cv       << endl;
            cout << "\tDireccion:  "<< lista[i].direccion << endl;
 
            imprimirproductos( i );
            cout<<endl;
 
        }
    }
    else
        cout<<"\n\tEste registro está vacío";
}
 
void eliminarvendedor( int z, int &num) //elimina un registro de un vendedor
{
    if(num>0)
    {
        for(int i=z; i<num-1; i++)
            lista[i] = lista[i+1];
 
        num--;
    }
    else
        cout<<"\n\tEste registro está vacío";
 
}
 
void busqueda( int num) //busca por clave la info del vendedor
{
    int bandera = 0;
 
    if(num>0)
    {
        for(int i=0; i<num; i++)
        {
            if(lista[i].cv==aux.cv)
            {
                cout<<"\n\n La dirección de "<<lista[i].nombre<<" "
                    <<lista[i].apellido<<" es : "
                    <<lista[i].direccion <<endl ;
                bandera = 1 ;
                break;
            }
        }
    }
    else
        cout<<"\n\tEste registro está vacío";
 
    if(bandera==0)
        cout<<"\n\n\tNo existe registro :"<<endl;
 
}
int validarNombre(char nombre[])
{
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122))
        {
            cout << " tipo de dato no permitido, intenta nuevamente\n";
            return 0;
        }
    }
    return 1;
}
//-----------------------------------------------------------------------------------------
int validarNombreP(char prod[])
{
    int i;
    for(i=0 ; i<strlen(prod); i++)
    {
        if(!(prod[i]>=65 && prod[i]<=90 || prod[i]>=97 && prod[i]<=122))
        {
            cout << " tipo de dato no permitido, intenta nuevamente\n";
            return 0;
        }
    }
    return 1;
}
//-----------------------------------------------------------------------------------------
int validarApellido(char apellido[])
{
    int i;
    for(i=0 ; i<strlen(apellido); i++)
    {
        if(!(apellido[i]>=65 && apellido[i]<=90 || apellido[i]>=97 && apellido[i]<=122))
        {
            cout << " tipo de dato no permitido, intenta nuevamente\n";
            return 0;
        }
    }
    return 1;
}
