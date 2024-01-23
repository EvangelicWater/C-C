
/* 
	Practica: 02 - Ordenamientos
	Fecha del Programa: 09/27/2021
	Fecha de Elaboracion: 09/28/2021
	Nombres de los autores:MIREYA LIZETTE CISNEROS SANDOVAL,DIEGO RODOLFO VARGAS VEGA, ANDRES HUMBERTO MARTINEZ ESCOBEDO.
    FECHA DE ENTREGA: 4/10/2021.
*/


//Librerias requeridas para el programa
#include <iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

//Uso del espacio de nombres estnadar
using namespace std;

//Protodeclaraciones ed las funciones del programa
char menu(); //Protodeclaracion que muestra el menu del programa
void copiarArray(int [], int *); //Protodeclaracion que copea el arraya aleatorio para mantenerlo durante toda la ejecucion del programa
void llenarArray(int *); //Protodeclaracion que llena el array de manera aleatoria
void mostrarArray(int *, string); //Protodeclaracion Muestra el arraya que se envia por parametro
void intercambiar(int *, int *); //Protodeclaracion que intercambia de posiciones los elementos enviado mediante punteros
int* ordenamientoBurbuja(int []); //Protodeclaracion ordena el array enviado por parametro por el metodo burbuja
int* ordenamientoSeleccion(int []); //Protodeclaracion ordena el array enviado por parametro por el metodo seleccion
int* ordenamientoInsercion(int []); //Protodeclaracion ordena el array enviado por parametro por el metodo insercion
int* ordenamientoShell(int []); //Protodeclaracion ordena el array enviado por parametro por el metodo shell
int* ordenamientoRapido(int [], int, int); //Protodeclaracion ordena el array enviado por parametro por el metodo rapido
int particion(int [], int, int); //Protodeclaracion que obtiene el pivote para el ordenamiento rapido

//Funcion principal
main(){
	srand(time(NULL)); //Establece la base para la obtencion de numeros aleatorios
	int arrayAleatorio[15], array[15]; //Vectores que se usan para almacenar los datos generados aleatoriamente y ordenados
	char opc; //Variable para la opcion del menu
	bool bandera = false; //Variable bandera para validar que ya se haya llenado el vector
	
	do{ //Ciclo do ... while para repetir el menu hasta que el usuario lo decida
		opc = menu(); //Se manda llamar la funcion menu y se retorna la opcion elegida por el usuario
		
		system("cls"); //Limpia la pantalla
		
		switch(opc){ //Sentencia switch para la seleccion del usuario
			case '1': //LLenar array
				cout<<"* * * LLENAR VECTOR * * *"<<endl<<endl;
				llenarArray(arrayAleatorio); //Llena el array mediante punteros
				copiarArray(arrayAleatorio, array); //Copea de un vector a otro mediante punteros
				cout<<"Array llenado correctamente . . ."<<endl;
				bandera = true; //Pone la bandera en true para validar que ya se lleno el vector
				break;
				
			case '2': //Mostrar Array
			
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				cout<<"* * * MOSTRAR VECTOR ORIGINAL * * *"<<endl<<endl;
				mostrarArray(arrayAleatorio, "Array Original"); //Manda llamar la funcion mostrarArray
				break;
				
			case '3': //BubbleSort
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				mostrarArray(ordenamientoBurbuja(array), "Array Ordenado"); //Muestra el array ordenado mediente el metodo burbuja
				mostrarArray(arrayAleatorio, "Array Original"); //Muestra el array original
				copiarArray(arrayAleatorio, array); //Copea el array original y la variable auxiliar por si se desea utilizar otro metodo de ordenamiento
				break;
				
			case '4': //SelectionSort
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				mostrarArray(ordenamientoSeleccion(array), "Array Ordenado"); //Muestra el array ordenado mediente el metodo de seleccion
				mostrarArray(arrayAleatorio, "Array Original"); //Muestra el array original
				copiarArray(arrayAleatorio, array); //Copea el array original y la variable auxiliar por si se desea utilizar otro metodo de ordenamiento
				break;
				
			case '5': // InsertSort
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				mostrarArray(ordenamientoInsercion(array), "Array Ordenado"); //Muestra el array ordenado mediente el metodo de insercion
				mostrarArray(arrayAleatorio, "Array Original"); //Muestra el array original
				copiarArray(arrayAleatorio, array); //Copea el array original y la variable auxiliar por si se desea utilizar otro metodo de ordenamiento
				break;
				
			case '6': //ShellSort
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				mostrarArray(ordenamientoShell(array), "Array Ordenado"); //Muestra el array ordenado mediente el metodo shell
				mostrarArray(arrayAleatorio, "Array Original");  //Muestra el array original
				copiarArray(arrayAleatorio, array); //Copea el array original y la variable auxiliar por si se desea utilizar otro metodo de ordenamiento
				break;
				
			case '7': //QuickSort
			if(!bandera){ //Valida que el vector tenga datos
				cout<<"ERROR. . . El Vector se encuentra vacio..."<<endl;
				break;}
				
				mostrarArray(ordenamientoRapido(array, 0 ,14), "Array Ordenado"); //Muestra el array ordenado mediente el metodo de ordenamiento rapido
				mostrarArray(arrayAleatorio, "Array Original"); //Muestra el array original
				copiarArray(arrayAleatorio, array); //Copea el array original y la variable auxiliar por si se desea utilizar otro metodo de ordenamiento
				break;
				
			case '8': //Exit
				cout<<"Terminando el programa . . ."<<endl;
				break;
				
			default: //Incorrect Option
				cout<<"Opcion incorrecta . . ."<<endl;
		}
		
		getch();} //Espera hasta que se presione cualquier tecla
		
	while(opc != '8'); } //Termina el ciclo y el programa al seleccionar la opcion 8
	
//Funcion que copea de un array a otro
void copiarArray(int array[15], int *arrayCpy){
	
	for(int i=0; i<15; i++){ //Ciclo que recorre todo el array
		arrayCpy[i] = array[i];} //Copea del original a Cpy
	}

//Funcion que llena el array de manera aleatoria
void llenarArray(int *array){
	for(int i=0; i<15; i++){//Ciclo que recorre todo el array
		array[i] = 1+rand()%(101-1);} //Genera un numero aleatorio y lo guarda el array
}

//Funcion que muestra el array enviado por parametro
void mostrarArray(int *array, string texto){
	cout<<texto<<": [";
	for(int i=0; i<15; i++){ //Ciclo que recorre todo el array
		cout<<array[i]; //Imprime la posicion i del array
		
		if(i<14) //Imprimie una coma (,) mientra no llegue al final del array
			cout<<", ";}
	cout<<"]"<<endl;
}

//Funcion que intercamvia valores entre los punteros j y k
void intercambiar(int *j, int *k){
	int temp = *j; //Asigna j a una variable temporal
	*j = *k; //Asigna k a j
	*k = temp; //asigna la variable temporal a k
}

//Funcion que ordena el array enviado por paramtro mediante el metodo burbuja
int* ordenamientoBurbuja(int array[]){
	int *arrayAux = array; //Puntero que recibe el array enviado por parametro
	int iteraciones = 0; //Variable que almacenara la cantidad de movimientos realizados para ordenar el array
	
	cout<<"* * * * * [ORDENAMIENTO BURBUJA] * * * * * "<<endl<<endl;
	
	for(int i=1; i<15; i++){ //Ciclo que recorre todo el array
        for(int j=0 ; j<15 - i; j++){ //Ciclo que recorre todo el array
            if(arrayAux[j] > arrayAux[j+1]){ //Si la posicion actual es mayor a j+1
            	
            	cout<<"[Se intercambia "<<arrayAux[j]<<" con "<<arrayAux[j+1]<<"] ";
            	mostrarArray(arrayAux, "Arary"); //Muestra el array actual
				
				intercambiar(&arrayAux[j], &arrayAux[j]+1);//Intercambia los valores enviados por parametros
				iteraciones++; } //Incrementa en 1 el numero de movimientos
        }
	}
	
	cout<<endl<<"Cantidad de movimientos: "<<iteraciones<<endl;

return arrayAux;}

//Funcion que ordena el array enviado por paramtro mediante el metodo seleccion
int* ordenamientoSeleccion(int array[]){
	int *arrayAux = array; //Asigna a un puntero el array que recibe por parametro para ordenarlo
	int iteraciones = 0; //Conteo de movimientos realizados para ordenarlo
	int menor; //Variable que almacena la posicion menor
	
	cout<<"* * * * * [ORDENAMIENTO POR SELECCION] * * * * * "<<endl<<endl;
	
	for (int i=0; i<15-1; i++){ //Ciclo que recorre todo el array
              menor=i; //asigna i como menor
              
              for(int j=i+1; j<15; j++) //ciclo que recorre todo el array
                    if(array[menor] > array[j]) //valida si la posicion actual sigue siendo la menor
                       menor=j; //Si no es asi la reasigna
                       
              intercambiar(&arrayAux[menor], &arrayAux[i]); //intercambia la posicion de i con la posicion menor
              
			  cout<<"[Se intercambia "<<arrayAux[menor]<<" con "<<arrayAux[i]<<"] ";
			  mostrarArray(arrayAux, "Array"); //Muestra el array actual
              iteraciones++; } //incrementa el coteoo de movimientos
	
	cout<<endl<<"Cantidad de movimientos: "<<iteraciones<<endl;
	
return arrayAux;}

//Funcion que ordena el array enviado por paramtro mediante el metodo insercion
int* ordenamientoInsercion(int array[]){
	int *arrayAux = array; //Asigna el array recibido a un puntero para ordenarlo
	int iteraciones = 0; //Conteo de moviemintos realizados para ordenarlo
	int j; //Variable j para almacenar la posicion en la que se inserta el valor
	int temp; //variable temporal que almacena el dato a mover
	
	cout<<"* * * * * [ORDENAMIENTO POR INSERCION] * * * * * "<<endl<<endl;
	
	for (int i=1; i<15; i++){ //Ciclo que recorre todo el array
        temp = array[i]; //asigna a la variable temporal lo que hay en la posicion i
        j = i - 1; //asigna a j la nueva posicion
        
        while ( (array[j] > temp) && (j >= 0)){ //ciclo que recorre el array mientras sea menor a la varalb etemporal y sea myor a 
            array[j+1] = array[j]; //Asigna a j siguiente el valor de j actual
        	j--; //reduce j en 1
          	array[j+1] = temp; //asigna a j siguiente lo que contiene la variable temporal
          	
          	iteraciones++; //incrementa el conteo de movimientos
          	
          	if(array[j] != 0){ //Valida que la posicion de j no sea 0
          		cout<<"[Se intercambia "<<arrayAux[j+1]<<" con "<<arrayAux[j]<<"] ";
          		mostrarArray(arrayAux, "Array");} //muestra el array actual
          	else
          		iteraciones--;} //Si el valor de la posicion es 0, decrementa el conteo en 1
	}

cout<<endl<<"Cantidad de movimientos: "<<iteraciones<<endl;

return arrayAux;}

//Funcion que ordena el array enviado por paramtro mediante el metodo shell
int* ordenamientoShell(int array[]){
	int *arrayAux = array;
	int iteraciones = 0;
	int incremento, i, temp;
	bool bandera;
       
    incremento = 15;
       
    cout<<"* * * * * [ORDENAMIENTO SHELL] * * * * * "<<endl<<endl;
       
    while(incremento > 0){
        incremento = incremento / 2;
        bandera = true;
           
        while(bandera){
            bandera = false;
            i = 0;
               
            while((i + incremento) <= 15-1){
                if(arrayAux[i] > arrayAux[i+incremento]){
                	intercambiar(&arrayAux[i], &arrayAux[i + incremento]);
                    bandera = true;
					
					iteraciones++;
					cout<<"[Se intercambia "<<arrayAux[i]<<" con "<<arrayAux[i+incremento]<<"] ";
          			mostrarArray(arrayAux, "Array");}
                           
                i = i +1; 
           }
       }
   }
   
   cout<<endl<<"Cantidad de movimientos: "<<iteraciones<<endl;
	
return arrayAux;}

//Funcion que ordena el array enviado por paramtro mediante el metodo rapido
int* ordenamientoRapido(int array[], int menor, int mayor){
	int *arrayAux = array; //Asigna el array recibido a un puntero para ordenarlo
	
	if(menor < mayor){ //Si el valor inicial y menor al final
		int pivote = particion(arrayAux, menor, mayor); //Asigna a la variable pivote el resutltado de la funcion particion
		
		//Este ordaenamiento es recursivo por lo que hace dos llamadas a si mismo con diferentes parametros para ordenar el array
		ordenamientoRapido(arrayAux, menor, pivote-1);
		ordenamientoRapido(arrayAux, pivote+1, mayor);}
		
	return arrayAux;}

//Funcion que obtiene el pivote nuevo del ordenamiento
int particion(int array[], int menor, int mayor){
 int pivote = array[mayor]; //Asigna a la variable pivote el valor de termino del array
 int i = (menor - 1); //Asigna a i el valor inicial menos 1
 
 for(int j=menor; j<=mayor-1; j++){ //Recorre desde el menor hasta el mayor
 	if(array[j] <= pivote){ //Si el array actual en j es menor o igual al pivote
 		i++; //incremneta i en 1
 		
		 if(array[i] != array[j]){ //Si el array en la posicion i es diferente del array en la posicion j
		 	intercambiar(&array[i], &array[j]); //intercambia sus posiciones
		
			cout<<"[Se intercambia "<<array[i]<<" con "<<array[j]<<"] ";
        	mostrarArray(array, "Array");} //Nuestra el array actual
		}
 }
 
 	if(array[i+1] != array[mayor]){ //Si la posicion i mas 1 es direfente del la posicion mayor
 		intercambiar(&array[i+1], &array[mayor]); //intercambia sus posiciones
 	
	 	cout<<"[Se intercambia "<<array[i+1]<<" con "<<array[mayor]<<"] ";
    	mostrarArray(array, "Array");} //Imprimie el array actual
 	
 	return (i+1); //retorna i mas 1
}

//Funcion que muestra el menu del proframa
char menu(){
	char opc; //Variable temporal que retornara la seleccion del usuario
	system("cls"); //Limpia la pantalla
	
		//Impresion de las opciones elejibles
	cout<<" * * * * * MENU PRINCIPAL * * * * * "<<endl<<endl;
	cout<<"1.- LLenar vector aleatoriamente"<<endl;
	cout<<"2.- Mostrar vector"<<endl;
	cout<<"3.- Ordenamiento Burbuja"<<endl;
	cout<<"4.- Ordenamiento por Selecccion"<<endl;
	cout<<"5.- Ordenamiento por Insercion"<<endl;
	cout<<"6.- Ordenamiento Shell"<<endl;
	cout<<"7.- Ordenamiento Rapido"<<endl;
	cout<<"8.- Salir"<<endl<<endl;
	
	cout<<"Elije una opcion: [ ]\b\b";
	cin>>opc; //Captura la opcion del usuario
	
	//Retorna la opcion del usuario
	return opc;}
