/* programa realizado por: 
 - Diego Rodolfo Vargas Vega 
 - Andr�s Humberto Mart�nez Escobedo 
 - Mireya Lizette Cisneros Sandoval
fecha de elaboraci�n 07/09/21*/ 

//librer�as necesarias para que el prgorama funcione el getch por ejemplo
//#include <conio.h> //para getch();
#include <iostream> // librer�a escencial para poder usar funciones  de escanear y printear en c++
#include <clocale>  //para poner caracteres en espa�ol
#include <conio.h>
using namespace std; //para dar acceso al espacio de nombres (namespace) std, donde se encuentra encerrada toda la librer�a est�ndar

//agregar arreglo para recorrer con el for 

struct vendedor {     //estructura con los datos que vamos a usar en el programa, cada tipo de dato es asi porque asi lo pide y cada uno ser� usado para guardar los datos que se piden
     char calle[50];
     char numdom [10];
     char col[50];      
     char cp[50];
     char ciudad[50];
     int numReg;
     int nov;
     char nombre[60];
     long sueldo;
     long venta;
     string banco;
     string cuenta;
     int pago;
}; //nuestro arreglo


int main () { //esta variable es la que nos pide los datos
	
	struct vendedor ve[100];
	long porcentaje = 0, nuevosueldo = 0, sueldofinal = 0;
	int n=0, ch = 0, cantidad = 0, num = 0;
	setlocale(LC_ALL, "spanish"); //para poner caracteres del espa�ol
	cout << "\n Introduzca la cantidad de registro de vendedores que desea realizar: "; // se piden los pacientes a registrar 
	while(!(cin >> cantidad))  //valida que no pongas letras
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << "\n Introduzca la cantidad de registro de vendedores que desea realizar: ";
		}
       fflush(stdin); 
	for(n=1;n<=cantidad;n++) //realiza el registro por la cantidad de veces que se le dijo
	{
			 num++;
			 cout << " registro:  00"<<num <<endl;
    		 ve[n].numReg=num; //con esto vamos contando en qu� registro vamos de los 5 posibles
    cout << " Introduce el n�mero de vendedor: "; //pide la clave de identificaci�n delv registro que debe ser proporcionada por el usuario
    while(!(cin >> ve[n].nov)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << " Introduce el n�mero de vendedor: ";
		}
       fflush(stdin); 
    cout << " Introduce el nombre del vendedor: "; //pide datos
    cin.getline( ve[n].nombre, 60 );
    
    cout << " Introduce el domicilio del vendedor:\n";    
    cout << "\tCalle: ";    
    cin.getline( ve[n].calle, 50 );
    
    cout << "\tN�mero del domicilio: ";    
    cin >> ve[n].numdom, 10; cin.ignore();
    
    cout << "\tColonia: ";
    cin.getline( ve[n].col, 50 );
    
    cout << "\tC�digo Postal: ";
    cin.getline( ve[n].cp, 50 );
      
    cout << "\tCiudad: ";
    cin.getline( ve[n].ciudad, 50 );
    
    cout << " Introduce la forma de pago ([1] cheques, [2] nomina, [3] ventanilla): ";
    fflush(stdin);
	while(!(cin >> ve[n].pago))  //valida que no pongas letras
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << " Introduce la forma de pago ([1] cheques, [2] nomina, [3] ventanilla): ";
		}
       fflush(stdin); 
    cout << " Introduce el nombre del banco: ";
    cin >> ve[n].banco; cin.ignore();
    
    cout << " Introduce el n�mero de cuenta: ";
    while(!(cin >> ve[n].cuenta))  //valida que no pongas letras
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << " Introduce el n�mero de cuenta: ";
		}
       fflush(stdin); 
    cout << " Introduce el sueldo mensual: ";
    while(!(cin >> ve[n].sueldo))  //valida que no pongas letras
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << " Introduce el sueldo mensual: ";
		}
       fflush(stdin); 
    cout << " Introduce las ventas anuales: ";
    while(!(cin >> ve[n].venta))  //valida que no pongas letras
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << " Introduce las ventas anuales: ";
		}
       fflush(stdin); 
    if (ve[n].venta >= 1500000)
    {
    	cout << "\n Se a detectado que las ventas anuales de este vendedor son iguales o mayores a $1,500,000,\n se a aplicado un incremento del 5% al sueldo mensual de este vendedor" << endl;
    	porcentaje = ve[n].sueldo*5/100;
    	sueldofinal=porcentaje+ve[n].sueldo;
    	cout << "\n su nuevo sueldo es: " << sueldofinal << endl;
	}
    getch();
    system("cls");
	}
		for(n=1;n<=cantidad;n++) //recorre el arreglo
	{
	if (ve[n].venta <= 300000) //valida que las ventas sean iguales o menos a $300,000
	{//imprime el registro
    cout << "\n\n Esta es la lista de vendedores que hicieron ventas anuales menores o iguales a $300,000 " << endl
		 << " N�m. de registro: " <<  ve[n].numReg << endl
         << " N�m. de vendedor: " << ve[n].nov << endl
         << " Nombre completo: "  << ve[n].nombre << endl
		 << " Ventas anuales: "   << ve[n].venta << endl;    
    cout << "\n\n";  
	cout << "\n--------------------------------------------\n";
	}
    getch();
    system("cls");
	}
	for(n=1;n<=cantidad;n++) //recorre el arreglo
	{
    if (ve[n].pago==1) //valida que la forma de pago sea cheques e imprime los registros
    {
    cout << "\n\n Esta es la lista de vendedores que su forma de pago es mediante cheques: " << endl;
    cout << "\n\nN�m. de registro: " <<  ve[n].numReg << endl
         << " N�m. de vendedor: " << ve[n].nov << endl
         << " Nombre completo: "  << ve[n].nombre << endl
         << " Banco: "  << ve[n].nombre << endl
		 << " N�m. cuenta: "   << ve[n].venta << "\n\n" << endl;  
	cout << "\n\n";  
	cout << "\n--------------------------------------------\n";  
    getch();
	system("cls");
	}
	
	}
	getch();
	return 0; //fin programa
}

