/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 10/10/21
*/

//librerías
#include<iostream>
#include <clocale> 
#include <windows.h>
#include <ctime>


using namespace std; //para uso de cin y cout

// estructura con las variables que vamos a usar 
static struct {
    char nom[50];
    char ap[50];
    int cod;
    char libro[50]; 
}libreria;

int i,j,N; //variables globales
int temp;
int lib[10];

//prototipo de funciones




int busqueda() //función hace la busqueda de manera secuencial
{
	
    int i,dato;
    char band='f';
    i=0;//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
  
    cout << "Ingrese el tomo a buscar:";
	//aqui seria algo como "Buscar existencias del libro "variable"                                                 //
	//Ingrese el tomo por buscar en existencias
     while(!(cin >> dato))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "\n tipo de dato no permitido, intenta nuevamente \n\n";
		cout << " Ingrese el tomo a buscar:";
		}
		
    while((band=='f')&&(i<10)){
    	if(lib[i]==dato){
    		band='v';
		}                                                                                                                                                           // 
		i++;
	}
	if(band=='f'){
		cout << " No hay existencias disponibles";//Hay existencias del capitulo deseado                                                                     /
	
	}else if(band=='v'){
		cout << " Hay existencias disponibles";//sin existencias del capitulo deseado                                                            /
		
	}////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

int validarNombre(char nombre[])
{
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122))
        {
            cout << " favor de solo ingresar letras \n";
            return 0;
        }
    }
    return 1;
}

void generar(void)//para el metodo de insercion o tambien llamado metodo de Baraja
 {
 	 int conta=0;
 	 int x;
 	 int validacion;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
	cout << "\n";
	do
	{ 
	cout << " Nombre del empleado que desea solicitar nuevo lote: ";
	cin >> libreria.nom;
	validacion=validarNombre(libreria.nom);
	}while(validacion==0);
	fflush(stdin);
	do
	{ 
	cout << " Apellido: ";
	cin >> libreria.ap;
	validacion=validarNombre(libreria.ap);
	}while(validacion==0);
	
	fflush(stdin);
	cout << " Código de empleado: ";
	 while(!(cin >> libreria.cod))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << " favor de ingresar solo el número \n";
		cout << " Código de empleado: ";
		}
	
	fflush(stdin);
	cout << " Nombre del libro: ";
	cin >> libreria.libro;
	
 	fflush(stdin);
	cout << " Cantidad que desea solicitar (máximo 10): ";
	while(!(cin >> N))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << " favor de ingresar solo números \n";
		cout << " Cantidad que desea solicitar (máximo 10): ";
		}
	system("pause");
	system("cls");

cout << " " << libreria.nom << " ha solicitado los siguientes tomos del libro: " << libreria.libro << " \n";
//Los imprimo 
for(i=0;i<10;i++)
{
conta++;
lib[i]=rand()/327;
cout << " " << lib[i];
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)cout << "\n";
}
	cout << "\n";
	system ("pause");
    system ("cls");
}

 //...............................................................//
  void insercion(void)//funcion claramente para el metodo de insercion
 {
 	int conta=0;
   for(i=1;i<10;i++){
      temp=lib[i];
      j=i-1;
      while((temp<lib[j])&&(j>=0)){
         lib[j+1]=lib[j];
         j=j-1;
      }
      lib[j+1]=temp;
   }

   cout << "\n tomos existentes: \n";
   for(i=0;i<10;i++){
      conta++;
      cout << " " << lib[i];
      if(conta % 15 == 0)cout << "\n";
      }
      cout << "\n";
      system ("pause");
      system ("cls");
 }

int main ()
{
	int op;   // opcion del menu
	setlocale (LC_CTYPE, "spanish"); //para usar caracteres en español 
    do //inicia el ciclo
    { //menú
        cout << "\n\n";
        cout << "\n\t\t\t\t   ¡Bienvenido!\n";
        
        cout << "\n\t\t\t    Librerías  MUNDO SUBMARINO ";
        cout << "\n\n\t\t\t\t      Menú";
        cout << "\n\n\t\t\t[1] Solicitar nuevo lote de libros \n\t\t\t[2] consulta tomos por libro \n\t\t\t[3] Consultar disponibilidad  \n\t\t\t[4] Salir \n\n"; //imprime el menú
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        // en el menu puede ser algo como 1[solcitar Nuevo lote de libros] 2[Ordenar libros por orden cronologico] 3[Buscar existencias de un capitulo especifico]//
        ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
			generar();  ////registra el ingreso del lote de libros
            break;
 
            case 2:
			insercion(); // busca un libro en específico por ID 
            break;
 
            case 3:	
			busqueda();
            break;
 
            case 4:
            cout<<"\n Saliendo... "; //finaliza el programa
            return 0;
            break;
 
        }
 
    } while(op != 4);//fin de ciclo
 
	return 0;
} 



