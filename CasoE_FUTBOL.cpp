/* 
	Seminario de Solucion de Problemas de Estructura de Datos II
		++ Tema: Archivos Binarios
		++ Actividad: Caso de Estudio
	
	Equipo:
		++ MIREYA LIZETTE CISNEROS SANDOVAL,DIEGO RODOLFO VARGAS VEGA, ANDRES HUMBERTO MARTINEZ ESCOBEDO.

*/

	//Librerias del archivo
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>

	//Uso de espacio estandar
using namespace std;

	//Estructura equipo con todos los datos requeridos para cada equipo
struct equipo{
	char nombreEquipo[100], nombreGoleador[100];
	int victorias, derrotas, empates, goles, golesContra, golesGoleador;
};

	//Estructura nodo para cada equipo, se utiliza un nodo ya que desde el inicio no se conoce cuantos equipos tiene la liga
struct nodo{
	struct nodo *siguiente;
	equipo dato;
};

	//Variables globales que requieren para todo el programa 
const string fileName = "archivo.dat"; //Aqui se determina y extension del archivo con el que se trabaja
const int size = sizeof(equipo); //Determina el tamano de la estructura, necesario para escribirlo en el archivo binario
typedef struct nodo *listaEnlazada; //Declara un tipo defenido por el usuario de la clase nodo, para facilitar sus llamadas en el codigo


	//Protodeclaraciones de funciones para manipular el archivo binario
void escribir(listaEnlazada); //Funcion que se encagar de escribir la lista de equipos en el archivo
void leer(listaEnlazada &); //Funcio que se encarga de recuperar los datos del fichero binario
	
	//Proteclaraciones de funciones para administrar la lista enlazada
int obtenerTam(listaEnlazada); //Funcion que obtiene el numero de elementos o equipos registrados
void insertar(listaEnlazada &, equipo); //Fncion que inserta un nuevo nodo/equipo en la lista
void mostrar(listaEnlazada); //Funcion que muestra todos los equipos registrados
int eliminar(listaEnlazada &, char[]); //Funcion que se encarga de eliminar un equipo de la lista
int modificar(listaEnlazada &, char[]); //Funcion para modificar un equipo de la lista
equipo obtenerCampeon(listaEnlazada); //Funcion que devuelve el campeon actual de la lista
int esVacia(listaEnlazada); //Valida si la esta vacia o no

	//Proteclaraciones de funciones miscelaneas
void imprimir(equipo); //Se encarga de imprimir los datos del equipo que se le envia por paramtro
char menu(); //Se encarga de imprimir el menu en pantalla y retornar la seleccion del usuario

	//Funcion principal
main(){
	char opc; //Variable para guardar la opcion seleccionada por el usuario
	equipo temp; //Variable temporal que guarda los datos de cada equipo que se va registrando
	listaEnlazada listaEquipos = NULL; //Lista enlazada que almacena todos los equipo
	char nombreEquipo[100]; //Variable temporal para guardar el nombre del equipo
	
	leer(listaEquipos); //Al iniciar el programa recupera los datos del fichero binario, si es que este existe
	
	do{ //Ciclo para mostrar el menu hasta que se seleccione la opcion 6
		opc = menu(); //Imprime, recupera y almacena la opcion seleccionada por el usuario del menu
		system("cls"); //Limpia la pantalla
		
		switch(opc){ //Sentencia de seleccion para ir a la opcion seleccionada
			case '1': //Opcion nuevo equipo
				cout<<"* * * NUEVO EQUIPO * * *"<<endl<<endl;
				
					//Solicita y almacena los datos en la variable temporal
				cout<<"Nombre del equipo: "; cin.getline(temp.nombreEquipo, 100, '\n');
				cout<<"Victorias: "; cin>>temp.victorias;
				cout<<"Derrotas: "; cin>>temp.derrotas;
				cout<<"Empates: "; cin>>temp.empates;
				cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
				cout<<"Goles a favor: "; cin>>temp.goles;
				cout<<"Goles en contra: "; cin>>temp.golesContra;
				cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
				fflush(stdin);
				cout<<"Nombre goleador: "; cin.getline(temp.nombreGoleador, 100, '\n');
				cout<<"Goles del goleador: "; cin>>temp.golesGoleador;
				fflush(stdin);
				
					//Inserta y escribe en el fichero el nuevo equipo en la lista actual
				insertar(listaEquipos, temp);
				cout<<endl<<"Equipo registrado..."<<endl; //Imprime un mensaje 
				break;
				
			case '2':  //Opcion modficar equipo
				cout<<"* * * MODIFICAR DATOS DEL EQUIPO * * *"<<endl<<endl;
					
					if(esVacia(listaEquipos) == 0){ //Valida que haya elementos en la lista
						cout<<"No hay equipos para modificar..."<<endl;
						break;
					}
						
					//Solicita el nombre del equipo que se desea modificar
				cout<<"Que equipo deseas modificar?: "; cin.getline(nombreEquipo, 100, '\n');
				
					//Manda llamar y valida a la vez la modificacion del usuario
				if(modificar(listaEquipos, nombreEquipo) == 1){ //Si es correcto imprime un mensaje
					cout<<endl<<"Equipo modifcado correctamente"<<endl;
				} else { //Si no encuentra el registro
					cout<<endl<<"No se ha encontrado en equipo con ese nombre..."<<endl;
				}
				
				break;
				
			case '3':  //Opcion baja equipo
				cout<<"* * * DAR DE BAJA EQUIPO * * *"<<endl<<endl;
				
				if(esVacia(listaEquipos) == 0){
						cout<<"No existen equipos en la lista..."<<endl;
						break;
					}
					
					//Solicita el nombre del equipo que se desea eliminar
				cout<<"Que equipo quieres dar de baja?: "; cin.getline(nombreEquipo, 100, '\n');
				
					//Manda llamar la funcion y valida a la vez que la tarea se realice correctamente
				if(eliminar(listaEquipos, nombreEquipo) == 1){
						//Si es correcto imprime un mensaje
					cout<<endl<<"Equipo eliminado correctamente"<<endl;
				} else {
					cout<<endl<<"No se ha encontrado en equipo con ese nombre..."<<endl;
				}
				break;
				
			case '4':  //Opcion mostrar campeon 
				cout<<"* * * CAMPEON ACTUAL DE LA LIGA * * *"<<endl<<endl;
				
				if(esVacia(listaEquipos) == 0){ //Valida que haya elementos en la lista
						cout<<"No hay equipos registrados..."<<endl;
						break;
					}
					
					//Manda llamar dos funciones imprimir, para mostrar en pantalla el equipo devuelto por la funcion interna
				imprimir(obtenerCampeon(listaEquipos));
				break;
				
			case '5':  //Opcion "Extra" Mostrar
				cout<<"* * * EQUIPO REGISTRADOS * * *"<<endl<<endl;
					//Manda llamar la funcion mostrar lista de equipo
				mostrar(listaEquipos); 
				break;
			
			case '6': //Opcion salir
				cout<<"Finalizando el programa..."<<endl;
				break;
				
			default: //Opcion incorrecta
				cout<<"Opcion incorrecta..."<<endl;
		}
		
			//Muestra un mensaje
		cout<<"Presione cualquier tecla para continuar..."<<endl;
		getch(); //Espera que se presione una tecla para continuar la ejecucion del programa
	} while(opc != '6');
}

// * * * METODOS PARA LA ADMINISTRACION DE LA LISTA ENLAZADA * * * 
	
	//Definicion de la funcion, se encarga de devolver la cantidad de elementos que contiene
	//Recibe por parametros la lista de la que se desea conocer la cantidad de elementos
int obtenerTam(listaEnlazada lista){ 
	listaEnlazada aux = lista; //Iguala la lista a una variable auxiliar del mismo tipo
	int n = 0; //Inicializa un valor entero en 0 para el conteo
	
	while(aux != NULL){ //Ciclo que se repite mientras haya elementos
		n++; //Por cada iteracion incrementa el contador
		aux = aux->siguiente; //Por cada iteracion avanza en al lista
	}
	
	return n; //Retorna el coteo final
}

	//Definicion de la funcion, se encarga de insertar un nuevo elemento en la lista
	//Recibe por paramtros la lista en la que se inserta el nuevo elemento, y el nuevo elemento
void insertar(listaEnlazada &lista, equipo dato){
	listaEnlazada aux; //Variable que crea una llista auxiliar
	
	aux = new(struct nodo); //Crea un nuevo nodo para la lista auxiliar
	aux->dato = dato; //Inserta el equipo en el nodo recien creado
	aux->siguiente = lista; //Le asigna como elemento siguiente la lista actual
	lista = aux; //Asigna a la lista actual el nodo recien creado
	
	escribir(lista); //Escribe en el fichero binario la lista actual
}

	//Definicion de la funcion, se encarga de mostrar todos los elementos de la lista
	//Recibe por paramtros la lista que desea mostrar
void mostrar(listaEnlazada lista){
	listaEnlazada aux = lista; //Se instancia una variable auxiliar y se igual a la lista
	
	if(aux == NULL){ //Si la lista esta vacia 
			//Imprime un mensaje mencionandolo
		cout<<"No hay registros actualmente..."<<endl;
		return; //Termina la ejecucion del metodo en este momento
	}
	
		//Si la lista no esta vacia
	while(aux != NULL){ //Ciclo que se repite hasta el ultimo elemento de la lista
		imprimir(aux->dato); //Manda llamar la funcion imprimir para mostrar en pantalla el equipo actual
		aux = aux->siguiente; //Asigna a auxiliar el siguiente elemento de la lista
	}
}

	//Definicion de la funcion, se encarga de liminar el elemento que se envia por parametro
	//Recibe por paramtros los lista de la que se desea eliminar y el nombre del equipo a eliminar
int eliminar(listaEnlazada &lista, char nombre[]){
	//Declara dos variables auxiliares para la eliminacion del equipo
	listaEnlazada aux = lista; 
	listaEnlazada ant;
	int bandera = 0;
	 
	 	//Si la lista no esta vacia
	 while(aux != NULL){ //Se ejecuta un ciclo hasta el ultimo elemento
	 	if(strcmp(aux->dato.nombreEquipo, nombre) == 0){ //Si encuentra el elemento
	 		bandera = 1; //Si encontro el registro cambia el estado de la bandera
	 		
	 		if(aux == lista){ //Valida si es el inicio de la lista
	 			lista = lista->siguiente; //Elimina el elemnto
			 } else{ //En caso de no serlo continua con los elementos siguientes
			 	ant->siguiente = aux->siguiente;
			 	delete(aux); 
			 	escribir(lista); //Escribe la lista actual en el archivo binario
			 	return bandera; //Retorna un 1 simbolizando la correcta eliminacion
			 }
		 }
		 
		 //Continua hasta encontrar el elemento a eliminar
		ant = aux; 
		aux = aux->siguiente;
	 }
	 
	escribir(lista); //Escribe la lista actual en el archivo binario
	return bandera; //Retorna un 1 simbolizando la correcta eliminacion
}

	//Definicion de la funcion, se encarga de modificar el elemento enviado por parametro
	//Recibe como parametros la lista en la que se encuentra el elemento y el elemento que se desea modificar
int modificar(listaEnlazada &lista, char nombre[]){
	listaEnlazada aux = NULL; //Crea una lista auxiliar sin ningun dato
	int bandera = 0; // Variable temporal que representa si se realizo modificacion o no
	
		//Si la lista no esta vacia
	while(lista != NULL){ //Ciclo que se repite hasta el ultimo elemento de la lista
		equipo temp = lista->dato; //Declaracion de un quipo tempora y asigna al equipo actual
		
		if(strcmp(temp.nombreEquipo, nombre) == 0){	//Valida que el equipo actual es el que debe modifcarse
				//Si es asi solcita todos los datos
			cout<<"Victorias: "; cin>>temp.victorias;
			cout<<"Derrotas: "; cin>>temp.derrotas;
			cout<<"Empates: "; cin>>temp.empates;
			cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
			cout<<"Goles a favor: "; cin>>temp.goles;
			cout<<"Goles en contra: "; cin>>temp.golesContra;
			cout<<" * * * * * * * * * * * * * * * * * * * * * * * * * * "<<endl;
			fflush(stdin);
			cout<<"Nombre goleador: "; cin.getline(temp.nombreGoleador, 100, '\n');
			cout<<"Goles del goleador: "; cin>>temp.golesGoleador;
			fflush(stdin);
			bandera = 1;
		}
		
		insertar(aux, temp); //Insrta el equipo actual (Modificado o no) en la lista auxiliar
		lista = lista->siguiente; //Avanza al siguiente elemento de lista
	}
	
	lista = aux; //Asigna a la lista original la lista auxiliar
	escribir(lista); //Escribe en el ficher binario la lista actual
	return bandera;
}

	//Definicion de la funcion, se encarga de obtener el equipo campeon de lista enviada por parametro
	//Recibe por parametro a lista de la que se desea conocer el campeon
equipo obtenerCampeon(listaEnlazada lista){
	equipo campeon; //Declaracion del equipo campeon, variable temproal
	listaEnlazada aux = lista; //Asigna a una lista temporal la lista actual
	int puntos = 0; //Inicializa la variable puntos en 0
	
	for(int i=0; aux!=NULL; i++){ //Ciclo que se repite hasta el ultimo archivo de la lista
		int temp = (aux->dato.victorias * 3) + aux->dato.empates; //Asigna los puntos del equipo actual a una variable temporal
		
		if(temp > puntos){ //Si la variable temporal es mayor a los puntos
			campeon = aux->dato; //Asigna como campeon al equipo actual
			puntos = temp; //Asigna como puntos maximos los puntos del equipo
		}  //El procedimiento del if se repite hasta que termino con los elementos de la lista y solo hay 1 campeon
		
		aux = aux->siguiente; //Avanza al siguiente elemento de la lista
	}
	
	return campeon; //Retorna el campeon de lista
}

//* * * METODOS PARA LA ADMINISTRACION DEL ARCHIVO BINARIO * * * 

	//Definicion de la funcion, se encarga de escribir en el archivo binario
	//Recibe por parametro la lista con los datos que se van a escribirr
void escribir(listaEnlazada lista){
	ofstream archivo; //Declaracion del tipo de archivo de salida
	archivo.open(fileName.c_str(), ios::out|ios::binary);   //Apertura del archivo como salida binaria
	int tam = obtenerTam(lista); //Obtiene el numero de equipos en la lista
	listaEnlazada aux = lista; //Asigna a una lista temporal auxiliar la lista actual
	
	if(aux == NULL){ //Si la lista esta vacia
		return; //Termina el metodo sin escribir nada
	}
	
	archivo.write((char*) &tam, sizeof(tam)); //Escribe en el fichero el numero de equipos
	
	while(aux != NULL){ //Si la lista no esta vacia
		equipo dato = aux->dato; //Asigna a una variable de equipo temporal el equipo actual
		archivo.write((char*) &dato, size);	//Escribe en el fichero binario el equipo actual
		aux = aux->siguiente; //Avanza al siguiente elemento
	}
	
	archivo.flush(); //Limpia el flujo de datos
	archivo.close(); //Cierra el archivo
}

	//Definicion de la funcion, se encarga de leer y llenar los datos que contiene el archivo binario
	//Recibe por paramtros la lista por refenencia en la que se guardaran los datos
void leer(listaEnlazada &lista){
	int tam, i=0; //Variables temporales con el numero de elementos y un iterador
	
	ifstream archivo; //Variable de archivo de tipo entrada
	archivo.open(fileName.c_str(), ios::in|ios::binary);  //Apertura del archivo como entrada binaria
	
	archivo.read((char*) &tam, sizeof(int)); //Lee del archivo el numero de elemntos registrados
	
	for(int i=0; i<tam; i++){ //Ciclo que se repite hasta el numero de equipos en el archivo
		equipo dato; //Equipo temporal
		archivo.read((char*) &dato, size);	 //Lee del archivo binario el equipo siguiente
		insertar(lista, dato); //Inserta en la lista los equipos conforme se van leyendo
	}
	
	archivo.close(); //Cierra el archivo
}

//METODOS EXTRA 

	//Definicion de la funcion, se encarga de imprimir los datos del equipo que senvia por parametro
	//Recibe por parametro el equipo
void imprimir(equipo dato){
	cout<<"Nombre del equipo: "<< dato.nombreEquipo<<endl;
	cout<<"Victorias: "<<dato.victorias<<" | Derrotas: "<<dato.derrotas<<" |  Empates: "<<dato.empates<<endl;
	cout<<"Goles a favor: "<<dato.goles<<" | Goles en contra: "<<dato.golesContra<<endl;
	cout<<"Goleador: "<<dato.nombreGoleador<<" | Goles: "<<dato.golesGoleador<<endl<<endl;;
}

	//Definicion de la funcion, se encarga de imprimri en pantalla el menu de opcion y retornar la opcion elegida por el usuario
char menu(){
	string opc; //Variable temporal
	
	system("cls"); //Limpia la pantalla
		
		//Imprime la opciones disponibles
	cout<<" * * * * * MENU PRINCIPAL * * * * *"<<endl<<endl;
	cout<<"1.- Alta equipo"<<endl;
	cout<<"2.- Modificar equipo"<<endl;
	cout<<"3.- Baja equipo"<<endl;
	cout<<"4.- Campeon actual"<<endl;
	cout<<"5.- Mostrar equipos"<<endl;
	cout<<"6.- Salir"<<endl<<endl;
	
		//Solicita una opcion al usuario
	cout<<"Elija una opcion: [ ]\b\b"; 
	getline(cin, opc); //Captura la opcion del usuario
	
	if(opc.size() > 1){ //Si ingreso mas de un caracter 
		opc = '0'; //Asigna en cero la opcion para que sea incorrecta
	}
	
		//Limpia el buffer
	fflush(stdin);
		
		//Retorna la opcion del usuaio
	return opc[0];	
}

	//Definicion de la funcion, retorna 1 si la lista no esta vacia y 0 si lo esta.
int esVacia(listaEnlazada lista){
	if(lista == NULL)
		return 0;
	
	return 1;
}
