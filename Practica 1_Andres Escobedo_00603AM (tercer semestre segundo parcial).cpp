#include<stdio.h>
#include<stdlib.h>
#include <conio.h>
#include <iostream>
#include <string>
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>//librerias
#define VALOR 0 //definimos que VALOR tiene un valor de 0 
#define ESC 27 //definimos que esc corresponde a 27 del codigo ascii
 
#define F1  -59
#define F2  -60
#define F3  -61
#define F4  -62
#define F5  -63
#define F6  -64
#define F7  -65
#define F8  -66
#define F9  -67
//se define cada tecla f con su respectivo valor del codigo ascii

/*Programa hecho por Andres Humberto Martinez Escobedo 
 4520160054
 00603AM
 20/4/2021
*/
typedef struct {//struct con todo lo que necesitamos
    int clave;
    char nombre[41];
    char calle[20];
    int numero;
    char colonia[20];
    char ciudad[20];
    char pais[50];
    int telefono;
    char email[50];
    char tiporev[20];
    int costo;
    char mes[10];
    int anio;
    int nreg;
}fichero;//creo que la idea era crear mas de un struct pero se me facilito mas el crear un solo struct con todo lo necesario 

int listfic=0;//variable para contar ficheros creados
int reg=0;//variable para el numero de registro
void continuar()//funcion continuar para crear una pausa debido a que sigo olvidando las diferentes maneras que hay para pausar el programa


{
    printf("Presione una tecla para continuar\n");
    getch();
}

//para este programa utilize archivos binarios porque despues de 4 programas fallidos opte por manejar archivos binarios lo que me facilito la creacion del programa 
//y claramene investigue previamente sobre el manejo de los archivos binarios y su manejo por lo que explico las funciones utilizadas a continuacion 
void crear()//funcion para crear ficheros
{
    
	FILE *arch;//definimos un puntero tipo "FILE"
    arch=fopen("fic.dat","ab");//se abre el archivo binario "fic.dat" que corresponde a los ficheros con el segundo parametro "ab"
    if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    fichero fic;//definimos que el struct fichero va a ser llamado mediante "fic"
    listfic++;//incrementa la lista de ficheros
    if(listfic<6){//si los ficheros creados son menos que 6 = 5 ficheros entonces se procede 
	reg++;//la variable reg con valor de 0 obtiene un incremento
	printf("\nNumero de Registro: %i\n",reg);//se imprime el valor del numero de registro ya con el incremento
	fic.nreg=reg;//se obtiene el valor incrementado y se guarda en una variable del struct
    printf("\nClave numerica: ");//se solicita la clave numerica para el fichero
    scanf("%i",&fic.clave);//se obtiene la clave y se guarda en el struct
    fflush(stdin);//se limpia el buffer
    printf("\nNombre del fichero:");//se solicita nombre del fichero
    gets(fic.nombre);//se obtiene el nombre del fichero
    printf("\n-Domicilio-\n");
    printf("\nCalle:");
    gets(fic.calle);
    printf("\nNumero:");
    scanf("%i",&fic.numero);
    fflush(stdin);
    printf("\nColonia:");
    gets(fic.colonia);
    printf("\n-Localidad-\n");
    printf("\nCiudad:");
    gets(fic.ciudad);
    printf("\nPais:");
    gets(fic.pais);
    printf("\nTelefono:");
    scanf("%i",&fic.telefono);
    fflush(stdin);
    printf("\nEmail:");
    gets(fic.email);
    printf("\nTipo de revista (especializada, informativa, divulgacion cientifica, entretenimiento, educativa, tematica, comics):\n");
    gets(fic.tiporev);
    printf("\nCosto de Suscripcion:");
    scanf("%i",&fic.costo);
    fflush(stdin);
    printf("\n-Fecha de suscripcion-\n");
    printf("\nMes:");
    gets(fic.mes);
     setlocale(LC_ALL, "spanish");//para maquinas linux
	    SetConsoleCP(1252);//para maquinas windows
	    SetConsoleOutputCP(1252);//para maquinas windows pero la diferencia es que se cambia STDOUT y no STDIN
		//utilice estas 3 lineas de codigo para que el usuario pueda agregar caracteres especiales como la ñ independientemente de sistema tengan 
    printf("\nAño:");
    scanf("%i",&fic.anio);//se obtuvieron todos los datos para el fichero
    fwrite(&fic, sizeof(fichero), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();}//llamado a la funcion continuar
    else{
    	printf("\nNumero maximo de ficheros alcanzado (5)\n");//si los ficheros ingresados  superan los 5 se muestra una aviso
    	fclose(arch);//cierra el archivo
	}
}

void listado()//funcion utilizada para mostrar todos los ficheros ingresados
{
	//Es necesario remarcar que si se cierra el programa sin eliminar o vaciar los ficheros estos se seguiran mostrando cuando se solicite
    FILE *arch;//definicion de puntero FILE para el manejo de arch
    arch=fopen("fic.dat","rb");//abirmos el archivo fic.dat con el segundo parametro rb
    if (arch==NULL)//si el archivo no se puede abrir termina el programa regresando un valor 1
        exit(1);
    fichero fic;//necesario para poder llamar al fichero como fic 
    fread(&fic, sizeof(fichero), 1, arch);//fread similar a fwrite lee los archivos pero en este caso despues de leerlos los pasa a la memoria principal
    while(!feof(arch))//feof sirve para hacer referencia al final del archivo por lo que el while se ejecuta hasta que finalice el archivo
    {
        printf("**\nNumero de registro: %i \nClave: %i \nNombre: %s \nCalle: %s \nNumero %i \nColonia: %s \nCiudad: %s \nPais:%s \nTelefono:%i \nEmail:%s \nTipo de Revista:%s  \nCosto: %i\n \nMes:%s \nAño:%i\n**",fic.nreg ,fic.clave, fic.nombre, fic.calle, fic.numero, fic.colonia, fic.ciudad, fic.pais, fic.telefono, fic.email, fic.tiporev ,fic.costo, fic.mes, fic.anio);
        fread(&fic, sizeof(fichero), 1, arch);//se imprimen los valores previamente ingresados al fichero para leer los archivos mediante fread
    }
    fclose(arch);//se cierra el archivo
    continuar();//llamado a la funcion continuar
}

void consulta()//funcion consulta utilizada para mostrar un fichero especifico 
{
    FILE *arch;//definicion de puntero FILE
    arch=fopen("fic.dat","rb");//abrimos el archivo fic.dat con el segundo parametro rb
    if (arch==NULL)//si el archivo no se puede abrir se termina la ejecuccion 
        exit(1);
    printf("\nIngrese la clave del fichero a consultar:");//se solicita la clave numera del fichero que desea consultar
    int clav;//se declara la variable clav
    scanf("%i", &clav);//se guarda la clave del fichero que desea consultar el usuario 
    fichero fic;//necesario para el manejo del fichero conforme fic
    int existe=0;//variable existe para verificar si existe la clave ingresada
    fread(&fic, sizeof(fichero), 1, arch);//fread para leer los archivos del fichero
    while(!feof(arch))//while que se ejecuta hasta el final del archivo
    {
        if (clav==fic.clave)//si la clave ingresada es igual a una clave guardada de cualquier fichero se procede
        {
           printf("\nNumero de registro: %i \nClave: %i \nNombre: %s \nCalle: %s \nNumero %i \nColonia: %s \nCiudad: %s \nPais:%s \nTelefono:%i \nEmail:%s \nTipo de Revista:%s  \nCosto: %i\n \nMes:%s \nAño:%i\n",fic.nreg ,fic.clave, fic.nombre, fic.calle, fic.numero, fic.colonia, fic.ciudad, fic.pais, fic.telefono, fic.email, fic.tiporev ,fic.costo, fic.mes, fic.anio);
           existe=1;//se imprimen los datos del fichero y el valor de existe cambia a 1
           fclose(arch);//se cierra el archivo
           break;//fin
        }
        fread(&fic, sizeof(fichero), 1, arch);//fread para leer los archivos del fichero
    }
    if (existe==0)//si no se encontro ninguna clave igual a la ingresada existe seguiria con un valor de 0 por lo que imprime lo siguiente
        printf("No existe ningun fichero con esa clave\n");//aviso
    fclose(arch);//cierra el archivo
    continuar();//llamado a funcion continuar
}

void modificacion()//funcion modificar 
{
    FILE *arch;//definicion de puntero FILE
    arch=fopen("fic.dat","r+b");//se abre fic.dat con segundo parametro r+b, r+b para leer y escribir en el archivo
    if (arch==NULL)//por si no se puede abrir
        exit(1);
    printf("\nIngrese la clave del fichero a modificar:\n");//se solicita la clave del fichero que se desea modificar
    int cl;
    scanf("%i", &cl);
    fichero fic;
    int existe=0;//proceso igual al anterior utilizado para comprobar la clave ingresada
    fread(&fic, sizeof(fichero), 1, arch);//fread para leer el archivo
    while(!feof(arch))//feof marca el final del archivo 
    {
        if (cl==fic.clave)//si se encuentra la clave
        {
           printf("\nClave:%i \n Nombre: %s\n Costo de Suscripcion:%0.2f\n", fic.clave, fic.nombre, fic.costo);//se imprime un breve resumen del fichero antes de modificarlo
           
           fic.nreg++;//incremento de la variable del numero de registro para poder otorgar una nueva clave
           printf("\nNuevo numero de registro: %i\n",&fic.nreg);
           printf("Ingrese nuevo nombre:");
           scanf("%s",&fic.nombre);
           printf("\nIngrese una nueva Clave numerica: ");
    scanf("%i",&fic.clave);
    fflush(stdin);
    printf("\n-Domicilio-\n");
    printf("\nIngrese una nueva Calle:");
    scanf("%s",&fic.calle);
    printf("\nNumero:");
    scanf("%i",&fic.numero);
    fflush(stdin);
    printf("\nIngrese nueva Colonia:");
    scanf("%s",&fic.colonia);
    printf("\n-Localidad-\n");
    printf("\nIngrese nueva Ciudad:");
    scanf("%s",&fic.ciudad);
    printf("\nIngrese nuevo Pais:");
    scanf("%s",&fic.pais);
    printf("\nIngrese nuevo Telefono:");
    scanf("%i",&fic.telefono);
    fflush(stdin);
    printf("\nIngrese nuevo Email:");
    scanf("%s",&fic.email);
    printf("\nIngrese nuevo Tipo de revista (especializada, informativa, divulgacion cientifica, entretenimiento, educativa, tematica, comics):\n");
    scanf("%s",&fic.tiporev);
    printf("\nIngrese nuevo Costo de Suscripcion:");
    scanf("%i",&fic.costo);
    fflush(stdin);
    printf("\n-Fecha de suscripcion-\n");
    printf("\nIngrese nuevo Mes:");
    scanf("%s",&fic.mes);
     setlocale(LC_ALL, "spanish");
	    SetConsoleCP(1252);
	    SetConsoleOutputCP(1252);
    printf("\nIngrese nuevo Año:");
    scanf("%i",&fic.anio);//se modifican los datos del fichero
           int pos=ftell(arch)-sizeof(fichero);//la funcion ftell obtiene el valor actual del indicador de posicion del fichero para un determinado archivo y pos se guarda la posicion actual obtenido con ftell menos el tamaño de los registros del fichero
           fseek(arch,pos,SEEK_SET);//fseek permite ubicarnos en cualquier posicion para actualizar datos, en este caso utilizamos la posicion guardada en pos para actualizar los datos previamente ingresados
           fwrite(&fic, sizeof(fichero), 1, arch);//utilizamos fwrite para guardar los nuevos datos ingresados en la posicion previamente especificada
           printf("\n Se modifico el  fichero seleccionado.\n");//aviso de que se modificaron los datos del fichero
           existe=1;//existe obtiene valor de 1
           
           
           break;
        }
        fread(&fic, sizeof(fichero), 1, arch);//fread para leer el fichero
    }
    if (existe==0)
        printf("\nNo existe ningun fichero con esa clave\n");//aviso por si no se encontro ninguna clave 
    fclose(arch);//cierra el archivo 
    continuar();//llamado a  la funcion continuar
}
void eliminar()
{
          FILE *arch;//definicion de puntero FILE
	
	fichero fic;
	char elimina;//bandera utilizada para este caso llamada eliminar
	int cl;
 

	arch = fopen("fic.dat", "r+b");	// Modo lectura y escritura. si el archivo no existe, es creado 
 
	if (arch == NULL) { // por si no se puede abrir el archivo
		elimina = 0;
 
	} else {
		
      printf("Codigo del archivo que desea borrar: ");
      scanf("%i",&cl);
		elimina = 0;
		fread(&fic, sizeof(fichero), 1, arch);
		while (!feof(arch)) {
			if (fic.clave == cl) {
				fseek(arch, ftell(arch) - sizeof(fic), SEEK_SET);
				fic.nreg= VALOR;//en este caso para la eliminacion no encontre ninguna otra forma mas que vaciar completamente el archivo dejandolo en blanco y se puede modificar para volverlo a llenar por completo
				fic.anio = VALOR;//VALOR previamente lo declaramos con valor 0
				memset(fic.calle,'\0',20);//utilizo memset para vaciar las cadenas de caracteres
				memset(fic.ciudad,'\0',20);
				fic.clave = VALOR;
				memset(fic.colonia,'\0',20);
				fic.costo = VALOR;
				memset(fic.email,'\0',50);
				memset(fic.mes,'\0',10); 
				memset(fic.nombre,'\0',41);
				fic.numero = VALOR;
				memset(fic.pais,'\0',50);
				fic.telefono = VALOR;
				memset(fic.tiporev,'\0',20);
				
				fwrite(&fic, sizeof(fichero), 1, arch);//se terminan de vaciar los archivos y modifica el archivo principal
				elimina = 1;
				break;
			}
			fread(&fic, sizeof(fichero), 1, arch);
		}
        printf("\nEl fichero se vacio con exito\n");
		
		fclose(arch);//cierra el archivo
	}
 
	if(elimina==0)
            printf("\nEl fichero no se pudo vaciar, verifique la clave ingresada\n");//por si no se puede vaciar ningun archivo
            fclose(arch);//cierra el archivo 
    continuar();//llamado a  la funcion continuar
        }
        
void del()//funcion para eliminar el archivo binario que aunque no fue solicitada me parecia algo practico 
{
	
	FILE *arch;//puntero FILE
    arch=fopen("fic.dat","rb");//se abre el archivo
    if (arch==NULL)
        exit(1);//si no abre el archivo
        fichero fic;
        fclose(arch);//para eliminar el archivo binario primero es necesario cerrarlo
        remove("fic.dat");//remove elimina el archivo binario 
        printf("\nArchivo binario eliminado con exito\n");//aviso
        continuar();//llamado a la funcion continuar
        
}

int main()
{
	setlocale(LC_ALL, "spanish");
    
    int key = 0;//se define que key vale 0
     
    while(key != ESC){//mientras que la tecla ingresada no sea esc
    	printf("**********************************");
    printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Alta de Registro.\n");
    printf("\n[F2] Mostrar Registros.\n");
    printf("\n[F3] Buscar Registros.\n");
    printf("\n[F4] Editar Registro.\n");
    printf("\n[F5] Vaciar registro.\n");
    printf("\n[F6] Eliminar archivo binario \n");
    printf("\n[ESC]. Salir\n");
    printf("\n!No es posible acceder a las demas partes del menu sin primero haber dado de alta por lo menos un registro!\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//impresion de menu y se solicita la opcion a ejecutar

   key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        
        switch (key) {
            case F1:crear();
                   break;
            case F2:listado();
                   break;
            case F3:consulta();
                   break;
            case F4:modificacion();
                   break;
            case F5:; eliminar();
                   break;
            case F6: del();//en cada case se llama a la funcion que se desea ejecutar
			break;      
        }
    }
    return 0;//finaliza programa
}//!No se olvide de borrar el archivo binario
//que tenga un buen dia.
