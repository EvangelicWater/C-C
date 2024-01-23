//librerias
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;
#define VALOR 0 //definimos que VALOR tiene un valor de 0 

 


/* 
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval
 10/11/2021 
*/
typedef struct {//struct con todo lo que necesitamos
    int matricula;
    char nombre[41];
    char ap[41];
    char am[45];
    char calle[20];
    int numero;
    int postal;
    char colonia[20];
    char ciudad[20];
    char pais[50];
    int telefono;
    char email[50];
    char carrera[50];
    int promedio;
    char semestre[10];
    
    int nreg;
}fichero;

int listfic=0;//variable para contar ficheros creados
int reg=0;//variable para el numero de registro
void continuar()


{
    printf("Presione una tecla para continuar\n");
    getch();
}


void crear()//funcion para crear ficheros
{
    
	FILE *arch;//definimos un puntero tipo "FILE"
    arch=fopen("fic.dat","ab");//se abre el archivo  "fic.dat" que corresponde a los ficheros con el segundo parametro "ab"
    if (arch==NULL)//si el archivo no se puede abrir el programa regresa de valor "1"
        exit(1);
    fichero fic;//definimos que el struct fichero va a ser llamado mediante "fic"
    listfic++;//incrementa la lista de ficheros
    if(listfic<99){//si los ficheros creados son menos que 99 ficheros entonces se procede 
	reg++;//la variable reg con valor de 0 obtiene un incremento
	printf("\nNumero de Registro: %i\n",reg);//se imprime el valor del numero de registro ya con el incremento
	fic.nreg=reg;//se obtiene el valor incrementado y se guarda en una variable del struct
    printf("\nMatricula: ");//se solicita la clave numerica para el fichero
    scanf("%i",&fic.matricula);//se obtiene la clave y se guarda en el struct
    fflush(stdin);//se limpia el buffer
    printf("\nNombre: ");
    gets(fic.nombre);
    printf("\nApellido Paterno:");
    gets(fic.ap);
    printf("\nApellido Materno:");
    gets(fic.am);
    printf("\n-Domicilio-\n");
    printf("\nCalle:");
    gets(fic.calle);
    printf("\nNumero:");
    scanf("%i",&fic.numero);
    printf("\nCodigo Postal:");
    fflush(stdin);
    scanf("%i",&fic.postal);
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
    printf("\nCarrera:\n");
    gets(fic.carrera);
    printf("\nPromedio:");
    scanf("%i",&fic.promedio);
    fflush(stdin);
    
    printf("\nSemestre:");
    gets(fic.semestre);
  
    fwrite(&fic, sizeof(fichero), 1, arch);//fwrite sirve para leer los datos de la memoria principal y los pasa el archivo, en este caso lee los datos ingresados del fichero y los pasa a el struct y el 1 representa las veces en las que se escribiran los datos
    fclose(arch);//fclose sirve para cerrar el archivo 
    continuar();}//llamado a la funcion continuar
    else{
    	printf("\nNumero maximo de ficheros alcanzado (99)\n");//si los ficheros ingresados  superan los 99 se muestra una aviso
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
        printf("**\nNumero de registro: %i \nMatricula: %i \nNombre: %s \nApellido Paterno: %s \nApellido Materno: %s   \nCalle: %s \nNumero: %i \nCP: %i \nColonia: %s \nCiudad: %s \nPais:%s \nTelefono:%i \nEmail:%s \nCarrera:%s  \nPromedio: %i\n \nSemestre:%s \n**",fic.nreg ,fic.matricula, fic.nombre,fic.ap,fic.am, fic.calle, fic.numero,fic.postal, fic.colonia, fic.ciudad, fic.pais, fic.telefono, fic.email, fic.carrera ,fic.promedio, fic.semestre);
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
    printf("\nIngrese la Matricula del fichero a consultar:");//se solicita la clave numera del fichero que desea consultar
    int clav;//se declara la variable clav
    scanf("%i", &clav);//se guarda la clave del fichero que desea consultar el usuario 
    fichero fic;//necesario para el manejo del fichero conforme fic
    int existe=0;//variable existe para verificar si existe la clave ingresada
    fread(&fic, sizeof(fichero), 1, arch);//fread para leer los archivos del fichero
    while(!feof(arch))//while que se ejecuta hasta el final del archivo
    {
        if (clav==fic.matricula)//si la clave ingresada es igual a una clave guardada de cualquier fichero se procede
        {
           printf("\nNumero de registro: %i \nMatricula: %i \nNombre: %s \nApellido Paterno: %s \nApellido Materno: %s   \nCalle: %s \nNumero: %i \nCP: %i \nColonia: %s \nCiudad: %s \nPais:%s \nTelefono:%i \nEmail:%s \nCarrera:%s  \nPromedio: %i\n \nSemestre:%s \n",fic.nreg ,fic.matricula, fic.nombre,fic.ap,fic.am, fic.calle, fic.numero,fic.postal, fic.colonia, fic.ciudad, fic.pais, fic.telefono, fic.email, fic.carrera ,fic.promedio, fic.semestre);
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
    printf("\nIngrese la matricula del fichero a modificar:\n");//se solicita la clave del fichero que se desea modificar
    int cl;
    scanf("%i", &cl);
    fichero fic;
    int existe=0;//proceso igual al anterior utilizado para comprobar la clave ingresada
    fread(&fic, sizeof(fichero), 1, arch);//fread para leer el archivo
    while(!feof(arch))//feof marca el final del archivo 
    {
        if (cl==fic.matricula)//si se encuentra la clave
        {
           printf("\nMatricula:%i \n Nombre: %s\n Promedio:%i\n", fic.matricula, fic.nombre, fic.promedio);//se imprime un breve resumen del fichero antes de modificarlo
           
           fic.nreg++;//incremento de la variable del numero de registro para poder otorgar una nueva clave
          
           printf("Ingrese nuevo nombre:");
           scanf("%s",&fic.nombre);
           printf("Ingrese nuevo apellido paterno:");
           scanf("%s",&fic.ap);
           printf("Ingrese nuevo apellido materno:");
           scanf("%s",&fic.am);
           printf("\nIngrese una nueva Matricula numerica: ");
    scanf("%i",&fic.matricula);
    fflush(stdin);
    printf("\n-Domicilio-\n");
    printf("\nIngrese una nueva Calle:");
    scanf("%s",&fic.calle);
    printf("\nNumero:");
    scanf("%i",&fic.numero);
    fflush(stdin);
     printf("\nCodigo Postal:");
    scanf("%i",&fic.postal);
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
    printf("\nIngrese la nueva carrera: \n");
    scanf("%s",&fic.carrera);
    printf("\nIngrese nuevo Promedio:");
    scanf("%i",&fic.promedio);
    fflush(stdin);
  
    printf("\nIngrese nuevo Semestre:");
    scanf("%s",&fic.semestre);

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
		
      printf("Matricula del archivo que desea borrar: ");
      scanf("%i",&cl);
		elimina = 0;
		fread(&fic, sizeof(fichero), 1, arch);
		while (!feof(arch)) {
			if (fic.matricula == cl) {
				fseek(arch, ftell(arch) - sizeof(fic), SEEK_SET);
				fic.nreg= VALOR;//en este caso para la eliminacion no encontre ninguna otra forma mas que vaciar completamente el archivo dejandolo en blanco y se puede modificar para volverlo a llenar por completo
				memset(fic.calle,'\0',20);//utilizo memset para vaciar las cadenas de caracteres
				memset(fic.ciudad,'\0',20);
				fic.matricula = VALOR;
				memset(fic.colonia,'\0',20);
				fic.promedio = VALOR;
				memset(fic.email,'\0',50);
				memset(fic.semestre,'\0',10); 
				memset(fic.nombre,'\0',41);
				memset(fic.ap,'\0',41);
				memset(fic.am,'\0',41);
				fic.numero = VALOR;
				fic.postal= VALOR;
				memset(fic.pais,'\0',50);
				fic.telefono = VALOR;
				memset(fic.carrera,'\0',20);
				
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
        printf("\nArchivo  eliminado con exito\n");//aviso
        continuar();//llamado a la funcion continuar
        
}

int main()
{
	setlocale(LC_ALL, "spanish");
    
   int key;
     
    do{
    	printf("**********************************");
    printf("\n\t   Menu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[1] Llenar Datos.\n");
    printf("\n[2] Mostrar Datos.\n");
    printf("\n[3] Buscar Alumno.\n");
    printf("\n[4] Modificar datos de Alumno.\n");
    printf("\n[5] Eliminar alumno.\n");
    printf("\n[6] Eliminar archivo binario \n");
    printf("\n[7]. Salir\n");
    printf("\n!No es posible acceder a las demas partes del menu sin primero haber dado de alta por lo menos un registro!\n");
     printf("++++++++++++++++++++++++++++");
    printf("\n Seleccione una opcion: ");//impresion de menu y se solicita la opcion a ejecutar
   while(!(cin >> key))  //para evitar que introduzcan mal un caracter
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "  tipo de dato no permitido, intenta nuevamente\n";
		printf("\n Seleccione una opcion: ");
		}
        
        switch (key) {
            case 1:crear();
                   break;
            case 2:listado();
                   break;
            case 3:consulta();
                   break;
            case 4:modificacion();
                   break;
            case 5:; eliminar();
                   break;
            case 6: del();//en cada case se llama a la funcion que se desea ejecutar
            break;
            case 7:
               		printf("\n Saliendo...");
                    exit(0);
			break;      
        }
    }while(key!=7);
    return 0;//finaliza programa
}//!No se olvide de borrar el archivo 

