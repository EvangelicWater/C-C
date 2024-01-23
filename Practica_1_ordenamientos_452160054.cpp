#include <iostream> 
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h> //librerias



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
 
 using namespace std;
 int numeros[30];
 int number[30];
 int temp;
 int N=30,i,j;
 int a[30];
 int data[30];
 int data_s[30];
  int arr[30];
 //...............................................................//
 void pensarnumeros(void)//funcion perteneciente a el metodo de intercambio
{
int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
numeros[i]=rand()/327;
printf(" %d ",numeros[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
}
//...............................................................//
void ordenarnumeros(void)//funcion perteneciente a el metodo de intercambio
{
//Ordeno los numeros de menor a mayor
int j,k,t,conta=0;
for(j=1;j<N;j++)
 for(k=0;k<N-1;k++)
 {
  if(numeros[k+1]<numeros[k])
  {
  t=numeros[k];
  numeros[k]=numeros[k+1];
  numeros[k+1]=t;
  }
 }
 printf("\nOrdenados:\n");
for(i=0;i<N;i++){
conta++;
printf(" %d ",numeros[i]);
if(conta % 15 == 0)printf("\n");
}
}
//...............................................................//
 void generar(void)//para el metodo de insercion o tambien llamado metodo de Baraja
 {
 	 int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
number[i]=rand()/327;
printf(" %d ",number[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
 }
 //...............................................................//
  void insercion(void)//funcion claramente para el metodo de insercion
 {
 	int conta=0;
   for(i=1;i<N;i++){
      temp=number[i];
      j=i-1;
      while((temp<number[j])&&(j>=0)){
         number[j+1]=number[j];
         j=j-1;
      }
      number[j+1]=temp;
   }

   printf("\nOrdenados: \n");
   for(i=0;i<N;i++){
      conta++;
      printf(" %d",number[i]);
      if(conta % 15 == 0)printf("\n");
      }
 }
 //...............................................................//
 	void intercambiar( int * const aPtr, int * const bPtr)//para ordenamiento de seleccion
	{
 
		int aux = *aPtr;//uso de un auxiliar para el intercambio de los valores
		*aPtr = *bPtr;
		*bPtr = aux;
	}
	//...............................................................//
		void ordenarArreglo(int * const arreglo, const int tamanio)//para ordenamiento de seleccion
	{
		int minimo; //almacena el subíndice del valor minimo
		for(int i = 0; i < N; i++ )//recorre todo el arreglo desde la posición inicial hasta el final
		{
			minimo = i; //se asume que el subíndice del valor mínimo es el primer valor
			for( int j = i + 1; j < N; j++)//recorre el arreglo desde una posición siguiente al inicio
			{
				if( arreglo[j] < arreglo[minimo])
				minimo = j; //el minimo subíndice es j
 
			intercambiar( &arreglo[i] , &arreglo[minimo] ); //intercambio de valores del arreglo
 
			}
		}
 
 
 
	}
	//...............................................................//
		void imprimirArreglo( const int * const a, const int N)//para ordenamiento de seleccion
	{
		int conta=0;
		printf("\nOrdenados:\n");
		for(int i = 0; i < N; i++ ){
		    conta++;
		    printf(" %d ",a[i]);
		    if(conta % 15 == 0)printf("\n");
			
			
			}
	}
	//...............................................................//
	 void pensar_seleccion(void)//para ordenamiento de seleccion
	 {
int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
a[i]=rand()/327;
printf(" %d ",a[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
}
//...................................................................//	
 void pensarnumeros_shell(void)//funcion perteneciente a el metodo Shell
{
int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
data[i]=rand()/327;
printf(" %d ",data[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
}
//...................................................................//	
void shellSort(int array[], int n) {
  // Ordenamiento de valores conforme Shell Sort
  for (int interval = n / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < n; i += 1) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}	
//...................................................................//	
void printArray_shell(int array[], int size) {//para el metodo Shell
	int conta=0;
	printf("\nOredenados:\n");
  for (int i = 0; i < size; ++i) {
  	conta++;
    printf("%d  ", array[i]);
    if(conta % 15 == 0)printf("\n");
  }
  
} 
//...................................................................//
void swap(int *a, int *b) {// para el metodo Quick Sort
  int t = *a;
  *a = *b;
  *b = t;
}
//...................................................................//
void pensarnumeros_Q(void)//funcion perteneciente a el metodo Quick Sort
{
int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
data_s[i]=rand()/327;
printf(" %d ",data_s[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
}
//...................................................................//
int partition_Q(int array[], int low, int high) {//funcion de particion perteneciente al metodo Quick Sort
  
  
  int pivot = array[high];
  
  
  int i = (low - 1);

 
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
        
     
      i++;
      
     
      swap(&array[i], &array[j]);
    }
  }

  
  swap(&array[i + 1], &array[high]);
  
 
  return (i + 1);
}
//...................................................................//
void quickSort(int array[], int low, int high) {//ordenamiento Quick Sort
  if (low < high) {
    
    // find the pivot element such that
    // elements smaller than pivot are on left of pivot
    // elements greater than pivot are on right of pivot
    int pi = partition_Q(array, low, high);
    
    // recursive call on the left of pivot
    quickSort(array, low, pi - 1);
    
    // recursive call on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
//...................................................................//
void printArray_Q(int array[], int size) {//funcion para imprimir los elementos ordenados de Quick Sort
	int conta=0;
  for (int i = 0; i < size; ++i) {
  	conta++;
    printf("%d  ", array[i]);
    if(conta % 15 == 0)printf("\n");
  }
  
}
//...................................................................//
void swap_O_B(int* x, int* y)//funcion de intercambio perteneciente a el metodo de Burbuja mejorada
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
//...................................................................//
void pensarnumeros_O_B(void)//funcion perteneciente a el metodo de Burbuja mejorada
{
int conta=0;
//funcion que inicializa las secuencias de los numeros aleatorios
srand((unsigned)time(NULL));
//imprimo un cambio de linea por pantalla
printf("\nCreados:\n");
//Los imprimo 
for(i=0;i<N;i++){
conta++;
arr[i]=rand()/327;
printf(" %d ",arr[i]);
//Cuando al hacer la division entre 15 me da de resto 0 pongo un cambio de linea
if(conta % 15 == 0)printf("\n");
}
}
//...................................................................//	
void bubble_O_sort(int arr[], int n)//a diferencia de el metodo de burbuja normal este usa una variable bool para revisar cuando se intercambian los numeros en la previa iteracion
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap_O_B(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
}
//...................................................................//	
void mostrar_O_B(int arr[],int n)//funcion para imprimir los valores ordenados mediante el metodo de Burbuja mejorada
{
	int conta=0;
	for (int i = 0; i < n; i++){
	    conta++;
        printf("A%d ", arr[i]);
        if(conta % 15 == 0)printf("\n");
    }
	
}
 //...................................................................//	
 
int main(void)//inicializa main
{
	int opc;
    int key = 0;//se define que key vale 0
    printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Metodo de intercambio\n");
    printf("\n[F2] Metodo de Burbuja Mejorada\n");
    printf("\n[F3] Metodo Baraja\n");
    printf("\n[F4] Metodo de Seleccion\n");
    printf("\n[F5] Metodo Shell\n");
    printf("\n[F6] Metodo Quick Sort\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");//menu
    
   
    while(key != ESC)//mientras que la tecla ingresada sea diferente a ESC se ejecutara lo siguiente
    {
        key = getch();//se obtiene el valor ingresado de key
        if(key == 0)
            key = -getch();
        switch(key)//inicio de switch con el valor de key
        {
        case F1: { //inicio del primer case
			printf("\nMetodo de intercambio.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	    pensarnumeros();
	    ordenarnumeros();//funciones
	    
    printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso

	    
	    
		}
            break;//fin de primer case
        case F2://inicio de segundo case F2
        	{
        		printf("\nMetodo de Burbuja Mejorada.\n");//aviso
        		system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	    int n = sizeof(arr) / sizeof(arr[0]);
	     pensarnumeros_O_B();
	     bubble_O_sort(arr, n);
	      printf("\nOrdenados: \n");
    mostrar_O_B(arr,n);//funciones
	    
	     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
	    
			}
          
            break;//fin del segundo case
        case F3://inicio del tercer case
          {
          	printf("\nMetodo de Baraja.\n");//impresion
          	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	     generar();  

    insercion();//funciones
	    
	    
     printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");
    
            } break;//fin de case
        case F4://inicio de case
            {
			
            	printf("\nMetodo de Seleccion.\n");//aviso
            	system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	     pensar_seleccion();
	     ordenarArreglo( a, N );
	     imprimirArreglo(a, N);//funciones
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
}

			
    
        break;//fin de case
        
		case F5://inicio de case
		{
			printf("\nMetodo Shell.\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
	    system("cls");//se limpia la pantalla
	    
	    int size = sizeof(data) / sizeof(data[0]);
	    pensarnumeros_shell();
	    shellSort(data, size);
	    printArray_shell(data, size);//funciones
	   
      printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
		   } break;//fin de case
		   
		case F6://inicio de case
		{
			printf("\nMetodo Quick Sort\n");
			system("pause");//se pausa el programa hasta que se ingrese otra tecla
			system("cls");//se limpia la pantalla
			
			pensarnumeros_Q();
			int n = sizeof(data_s) / sizeof(data_s[0]);
			quickSort(data_s, 0, n - 1);
			printf("\nOrdenados:\n");
			printArray_Q(data_s, n);//funciones
			
			 printf("\nFIN. Ingrese otra opcion del menu para continuar o ingrese ESC para salir.\n");//aviso
			} break;//fin de case   
			
        default://default por si no se ingresa ninguna opcion del menu
            printf("\nERROR. No se selecciono ninguna opcion del menu.  \n");//aviso
         
            	 printf("\nMenu\n");
    printf("++++++++++++++++++++++++++++");
    printf("\n[F1] Metodo de intercambio\n");
    printf("\n[F2] Metodo de Burbuja Mejorada\n");
    printf("\n[F3] Metodo Baraja\n");
    printf("\n[F4] Metodo de Seleccion\n");
    printf("\n[F5] Metodo Shell\n");
    printf("\n[F6] Metodo Quick Sort\n");
    printf("\nESC. Salir\n");
     printf("++++++++++++++++++++++++++++");
    printf("\nSeleccione una opcion: ");
			
			
            break;//fin de default
 
        }//fin de switch
    }//fin de while
    return 0;
}//fin de main





