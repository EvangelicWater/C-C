/*
programa realizado por:
 
 - Diego Rodolfo Vargas Vega
 - Andrés Humberto Martínez Escobedo
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 10/10/21
*/
#include <iostream> //librerías necesarias para el funcionamiento del programa
#include <cstring>
#include <cstdlib>
#include <clocale>

using namespace std; //para uso de cout y cin 

void archivo(); //prototipos de nuestras funciones 
void consulta();
void alta();

char filename[20]; //variables globales a utilizar 
struct contacto
{
char nombre[50];
char calle[30];
char numero[10];
char colonia[30];
char codigo_p[6];
char telefono[11];
};

int main() //programa principal 
{
    
    int op;   // opcion del menu
	setlocale (LC_CTYPE, "spanish"); //para usar caracteres en español 
    do //inicia el ciclo
    { //menú
        cout<<"\n\n";
        cout<<"\n\n\t\t\t\t\tAgenda";
        cout<<"\n\n\t\t\t\t[1] Crear archivo \n\t\t\t\t[2] Alta contacto \n\t\t\t\t[3] Consulta contacto \n\t\t\t\t[4] Salir\n\n"; //imprime el menú
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
                archivo(); //ingreso de datos
                break;
 
            case 2:
                alta();//muestra de datos
                break;
 
            case 3:
                consulta(); //muestra contacto
                break;
 
            case 4:
                cout<<"\n Saliendo... "; //finaliza el programa
                return 0;
                break;
 
        }
 
    } while(op != 4);//fin de ciclo
 
 
    return 0; //fin de programa

}

void archivo()  //función que ingresa datos
{
	FILE *pf;
	char op;
	puts(" Ingrese el nombre del archivo: ");
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
	fclose(pf);
	
}
 
void consulta() // esta función muestra el contenido del archivo
{
	char contenido[500];
	FILE *pf = fopen(filename, "r");
	if(pf==NULL)
	{
		cout<< "\n Error al abrir el archivo.";
		system("pause");
		exit(0);
	}
	cout<< "\n la lista de contactos es: \n\n";
    fgets (contenido,500, pf);
    while(!feof(pf))
	{
    cout << contenido;
    fgets(contenido,500,pf);
	}
	system ("pause");
	system ("cls");
	fclose(pf);
}

void alta() // se da de alta un registro
{
	struct contacto c[100]; //llamado/ alias del struct
	int n, nest, lnom=0, lca=0, lnum=0, lcol=0, lcp=0, ltel=0;
	char nom[50], ca[50],num[50],col[50],cp[50],tel[50],l[3];
	FILE *pf;
	pf=fopen(filename, "w");
		if(pf==NULL)
		{
		puts("\n Error al abrir el archivo \n");
		system("pause");
		exit(1);
		}
		system("cls");
		cout << "\n  Nombre  y apellidos: ";
		fflush(stdin);
		gets(c[n].nombre);
		lnom=strlen(c[n].nombre);
		itoa(lnom,l,10);
		strcat(nom,l);
		strcat(nom," Nombre: ");
		strcat(nom,c[n].nombre);
		strcat(nom,"\t\t ");
		fputs(nom,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		cout << "\n Domicilio:\n";
		cout << "\n\tCalle: ";
		fflush(stdin);
		gets(c[n].calle);
		lca=strlen(c[n].calle);
		itoa(lca,l,10);
		strcat(ca,l);
		strcat(ca," Calle: ");
		strcat(ca,c[n].calle);
		strcat(ca,"\t\t\t ");
		fputs(ca,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		cout << "\n\tNúmero: ";
		gets(c[n].numero);
		lnum=strlen(c[n].numero);
		itoa(lnum,l,10);
		strcat(num,l);
		strcat(num," Número: ");
		strcat(num,c[n].numero);
		strcat(num,"\t\t\t\t ");
		fputs(num,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		cout << "\n\tColonia: ";
		fflush(stdin);
		gets(c[n].colonia);
		lcol=strlen(c[n].colonia);
		itoa(lcol,l,10);
		strcat(col,l);
		strcat(col," Colonia: ");
		strcat(col,c[n].colonia);
		strcat(col,"\t\t\t ");
		fputs(col,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		cout << "\n\tCódigo Postal: ";
		gets(c[n].codigo_p);
		lcp=strlen(c[n].codigo_p);
		itoa(lcp,l,10);
		strcat(cp,l);
		strcat(cp," Código postal: ");
		strcat(cp,c[n].codigo_p);
		strcat(cp,"\t\t ");
		fputs(cp,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		cout << "\n\tTeléfono (formato de 10 digitos): ";
		gets(c[n].telefono);
		ltel=strlen(c[n].telefono);
		itoa(ltel,l,10);
		strcat(tel,l);
		strcat(tel," Teléfono: ");
		strcat(tel,c[n].telefono);
		strcat(tel,"\t\t ");
		fputs(tel,pf);
		fputs(" ",pf);
		fputs("\n",pf);
		fclose(pf);
		system("cls");

}
	



