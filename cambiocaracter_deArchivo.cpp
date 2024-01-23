/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 08/10/21
*/
#include <iostream> //librerías necesarias para el funcionamiento del programa
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdlib>
#include <clocale>
#include <windows.h>

using namespace std; //para uso de cout y cin 

void ingreso(); //prototipos de nuestras funciones 
void mostrar();
void renombrar();
void cambiocaracter();
void newdisplay();

char filename[20]; //variables globales a utilizar 
char newname[20];
char cadena[50];
char cambiar;
char sustituir ='@';
char c;
int i;


int main() //programa principal 
{
    
    int op;   // opcion del menu
	setlocale (LC_CTYPE, "spanish"); //para usar caracteres en español 
    do //inicia el ciclo
    { //menú
        cout<<"\n\n";
        cout<<"\n\n\t\t\t\t\tMenú\n";
        cout<<"\n\n\t\t\t\t[1] Crear archivo \n\t\t\t\t[2] Mostrar contenido \n\t\t\t\t[3] Renombrar archivo \n\t\t\t\t[4] Cambio de caracter \n\t\t\t\t[5] Mostrar contenido modificado \n\t\t\t\t[6] Salir\n\n"; //imprime el menú
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
                ingreso(); //ingreso de datos
                break;
 
            case 2:
                mostrar(); //muestra de datos
                break;
 
            case 3:
                renombrar(); //renombra el archivo
                break;
 
            case 4:
               cambiocaracter(); //cambia  el caracter escogido por una arroba
                break;
 
            case 5:
               newdisplay(); // muestra el contenido modificado
                break;
 
            case 6:
                cout<<"\n Saliendo... "; //finaliza el programa
                return 0;
                break;
 
        }
 
    } while(op != 6);//fin de ciclo
 
 
    return 0; //fin de programa

}

void ingreso()  //función que ingresa datos
{
	FILE *pf;
	char op;
	puts(" Ingrese el nombre del archivo: \n");
	fflush(stdin);
	gets(filename);
	strcat(filename,".txt"); 
	pf=fopen(filename, "w");
		if(pf==NULL)
		{
		puts("\n Error al abrir el archivo \n");
		system("pause");
		exit(1);
		}
		puts("\n se ha creado el archivo correctamente \n");
		system("pause");
		system("cls");
	do
	{
		system("cls");
		cout << "\n Escribe texto en el archivo: \n";
		gets(cadena);
		strcat(cadena,"\n");
		fputs(cadena, pf);
		cout<< "\n";
		cout<< "\n ¿Ingresarás más texto en el archivo? [ S / N ]\n";
		op=getch();
		op=toupper(op);
	}while(op!='N');
	fclose(pf);
	
}
 
void mostrar() // esta función muestra el contenido del archivo
{
	char c;
	FILE *pf = fopen(filename, "r");
	cout<< "\n el contenido de tu archivo es: \n";
	if (pf) 
	{
    while ((c = getc(pf)) != EOF)
        putchar(c);
    fclose(pf);
	}
	system ("pause");
	system ("cls");

}

void renombrar()// esta función cambia el nombre del archivo
{
	char confirm;
	int result;
	cout << "\n Introduce el nuevo nombre del archivo: \n";
        fflush(stdin);
		gets(newname);
        strcat(newname,".txt"); 
        if(rename(filename,newname)==0)
    {
			cout<<"\n el nombre ha sido cambiado correctamente \n";
	}
	 else
    cout<<" \n error, no se ha podido realizar el cambio \n";
	
}

void cambiocaracter()// realiza un cambio del caracter escogido por arroba 
{
	char c;
	FILE *pf = fopen(newname, "r");
	cout<< "\n el contenido de tu archivo es: \n";
	if (pf) 
	{
    while ((c = getc(pf)) != EOF)
        putchar(c);
    fclose(pf);
	}
	system ("pause");
	system ("cls");
	printf("\nCaracter para cambiar: "); //obtener caracter a buscar para remplazar
	fflush(stdin);
	cin >> cambiar;
	while (getchar ()!='\n');
	for (i=0;cadena[i]!='\0';i++)
	{ //recorremos la cadena
    if (cadena[i]==cambiar){ //compara
        cadena[i]=sustituir; //cambia el valor si lo encuentra
    }
	
}


	cout << "\n se ha realizado el cambio satisfactoriamente seleccione la opción 5 para ver el cambio \n\n";
	system ("pause");
	system ("cls");
}

void newdisplay() //muestra los cambios realizados del nombre del archivo y de la cadena
{
	char c;
	FILE *pf = fopen(newname, "r");
	cout<< "\n el nuevo nombre del archivo es: \n" << newname << "\n";
	cout<< "\n el contenido de tu archivo es: \n" << cadena << "\n";
	system ("pause");
	system ("cls");
}
