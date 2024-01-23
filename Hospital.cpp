/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval  
 fecha de elaboración 06/09/21
*/

//librerías a usar 
#include <iostream>
#include <clocale>
#include <cstdlib>

using namespace std; //uso de cin y cout

struct paciente //struct que contiene nuestras variables a utilizar
{
	char nombre[80];
	char sexo;
	int condicion;
	string calle;
	string numero;
	char colonia[30];
	int codigo_p;
	char ciudad[30];
	string telefono;
};

//programa principal
int main()
{
	setlocale (LC_CTYPE,"spanish");
	struct paciente pa[100]; //llamado/ alias del struct
	int n,nest,ap=0,re=0,nef=0,nem=0,tr=0,ct=0,sg=0;
	float pap,prep,pf,pm,pt,pc,ps;
	
	
	cout << "\n  Introduzca la cantidad de pacientes: "; // se piden los pacientes a registrar 
	cin >> nest;
	for(n=1;n<=nest;n++)
	{
		cout << "\n--------------------------------------------\n";
		cout << "\n  Nombre  y apellidos del paciente: ";
		fflush(stdin);
		gets (pa[n].nombre);
		do{
			printf("\n  Sexo (f/m): "); //validamos el sexo de la persona 
			fflush(stdin);
			pa[n].sexo=(toupper(getchar()));
		}while(pa[n].sexo !='F' && pa[n].sexo!='M');
		if(pa[n].sexo=='f' || pa[n].sexo=='F' )
		nef++;
		if(pa[n].sexo=='m' || pa[n].sexo=='M')
		nem++;
		
		cout << " Condición( 1 / 5 )\n ( 5 representa el mayor grado de gravedad )\n: ";
		cin >> pa[n].condicion;
		//validamos el grado de la persona
		if(pa[n].condicion==1)
		re++;
		if(pa[n].condicion==2)
		sg++;
		if(pa[n].condicion==3)
		tr++;
		if(pa[n].condicion==4)
		ct++;
		if(pa[n].condicion==5)
		ap++;
		//pedimos datos 
		cout << "\n\tCalle: ";
		fflush(stdin);
		cin >> pa[n].calle;
		cout << "\n\tNúmero: ";
		cin>> pa[n].numero;
		cout << "\n\tColonia: ";
		fflush(stdin);
		gets(pa[n].colonia);
		cout << "\n\tCódigo Postal: ";
		cin >> pa[n].codigo_p;
		cout << "\n\tCiudad: ";
		fflush(stdin);
		gets(pa[n].ciudad);
		cout << "\n\tTeléfono (formato de 10 digitos): ";
		cin >>pa[n].telefono;
		system("cls");
		
	}
	pap=(ap*100)/nest; //sirven para sacar los porcentajes que se nos piden y que vamos a imprimir
	prep=(re*100)/nest;
	pf=(nef*100)/nest;
	pm=(nem*100)/nest;
	pt=(sg*100)/nest;
	pc=(tr*100)/nest;
	ps=(ct*100)/nest;
	
	cout << "\n--------------------------------------------\n";
	printf("\n Hay %d pacientes en estado 5 CRITICO y representan el %.2f%% \n",ap,pap);
		int i=0;
	for(i=1;i<=nest;i++) // recorre el arreglo y si hay coincidencia nos imprime el nombre y número del paciente grado 5
	{
		
		if(pa[i].condicion==5)
		{
		cout << "\n  Imprimiendo nombres y telefonos de los pacientes en estado CRITICO\n";
       
       	cout << "\n\t Nombre: " << pa[i].nombre << endl;
		cout << "\n\t Teléfono: " << pa[i].telefono;
        
		cout << "\n\n";  
		cout << "\n--------------------------------------------\n";
		}
	} //imprime la info con porcentajes de los pacientes
	printf("\n Hay %d pacientes en estado 5 CRITICO y representan el %.2f%% \n",ap,pap);
	printf("\n Hay %d pacientes en estado 4 GRAVE y representan el %.2f%% \n",ct,ps);
	printf("\n Hay %d pacientes en estado 3 RESERVADO y representan el %.2f%% \n",tr,pc);
	printf("\n Hay %d pacientes en estado 2 SEMI CONTROLADO y representan el %.2f%% \n",sg,pt);
	printf("\n Hay %d pacientes en estado 1 CONTROLADO y representan el %.2f%% \n\n",re,prep);
	cout << "\n--------------------------------------------\n";
	printf("\n Hay %d pacientes de sexo FEMENINO y representan el %.2f%%\n",nef,pf);
	printf("\n Hay %d pacientes de sexo MASCULINO y representan el %.2f%% \n\n",nem,pm);
	cout << "\n--------------------------------------------\n";
	return(0);
}
