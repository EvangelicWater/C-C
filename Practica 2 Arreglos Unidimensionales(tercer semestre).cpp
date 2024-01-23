#include <stdlib.h>
#include <time.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
// Programa elaborado por Andres Humberto Martinez Escobedo elaborado el 3/3/2021//
void noRepetir(int * valores, int tamVector);//se declara la funicion "noRpetir"
int main()//inicializacion de main
{
int opcion;//declaracion de la variable opcion
do{//inicio de do-while

   printf("\n---------------------------------\n");//se imprimen "guiones" para la estetica del menu 
   printf("\nBienvenido\n");//se imprime el mensaje bienvenido
   printf("\nMenu de opciones:\n");//Se imprime "menu de opciones"
   printf("\nVector Aleaetorio.....1");//se imprime la primera opcion perteneciente a "vector aleatorio"
   printf("\nPar/Impar.....2");//se imprime la segunda opcion perteneciente a "par/impar"
   printf("\nNumeros Repetidos.....3");//se imprime la tercera opcion perteneciente a "numeros repetidos" 
   printf("\nSalir.....4\n");//se imprime la opcion "salir"
   printf("\n---------------------------------\n");//se imprimen "guiones" para la estetica del menu
   printf("\nIntroduzca la opcion que desea ejecutar: \n");//se solicita la opcion a realizar
   scanf("%d",&opcion);//se obtiene la opcion ingresada
   switch(opcion){//inicio del switch
   
   case 1:{//inicio del case 1
   	printf("\nVector Aleatorio\n");//impresion de la opcion elegida "vector aleatorio"
   	int numAleatorio[19];//declaracion de vector "numAleatorio" que contiene 19 espacios(20 debido a que se inicializa en 0)
   	int lista1[19];//declaracion de vector "lista 1" que contiene 19 espacios(20 debido a que se inicializa en 0)
   	int lista2[19];//declaracion de vector "lista 2" que contiene 19 espacios(20 debido a que se inicializa en 0)
	int lista3[19];//declaracion de vector "lista 3" que contiene 19 espacios(20 debido a que se inicializa en 0)
   	int i;//declaracion del contador "i"
   	
   	srand(time(NULL));//se coloca e indica al programa que tome la "semilla" para generar valores aleatorios (no tengo ni idea porque esta colocando todas las l como mayusculas y no minusculas)  
   	for(i=0;i<=19;i++){//inicio del primer for
   		numAleatorio[i]= rand()%149;//numAleatorio obtiene valores aleatorios de la funcion rand que genera numeros aleatorios desde 0 a 149
	   }//finaliza for
	  
	   
	for (i=0;i<=19;i++){//inicio del segundo for
		
		printf("\nAleatorio numero %d vale: %d\n",i,numAleatorio[i]);//se imprime la lista con los valores aleatorios obtenidos
		
	}//finaliza segundo for
	 for(i=0;i<=19;i++){//inicia tercer for para las condiciones 
	   	
	   
	   if(numAleatorio[i]>=0&&numAleatorio[i]<=50)//se declara que si el numero aleatorio obtenido es mayor o igual a 0 y el numero aleatorio obtenido es menor a 50 se realize la siguiente accion
	   	{
	   		lista1[i]=numAleatorio[i];//lista1 obtiene los valores de el vector original con los valores aleatorios
	   		printf("\n El numero aleatorio  del 0 al 50  perteneciente a la lista 1 es: %d \n",lista1[i]);//se imprime la lista1 
		   }//finaliza if
	   	}//finaliza tercer for
	   	for(i=0;i<=19;i++){//se inicia el cuarto for 
	   	
	   
	   if(numAleatorio[i]>=51&&numAleatorio[i]<=100)//si numAleatorio es mayor o igual a 51 y el numero aleatorio es menor o igual a 100 se realiza la siguiente opcion (comento que no estoy ingresando las l en mayuscula por gusto)
	   	{
	   		lista2[i]=numAleatorio[i];//lista2 obtiene los valores del vector "numAleatorio"
	   		printf("\n El numero aleatorio  del 51 al 100  perteneciente a la lista 2 es: %d \n",lista2[i]);//se imprimen los resultados de la lista2
		   }
	   	}//finaliza cuarto for
	   	
	   	for(i=0;i<=19;i++){//inicio de quinto for
	   	
	   
	   if(numAleatorio[i]>=101)//si numAleatorio es mayor o igual a 101 se realiza la siguiente accion
	   	{
	   		lista3[i]=numAleatorio[i];//lista3 obtiene el valor de numAleatorio
	   		printf("\n El numero aleatorio  mayor a 101  perteneciente a la lista 3 es: %d \n",lista3[i]);//se imprime la lista3
		   }
	   	}//finaliza el quinto y ultimo for para el primer case
	   	
   }
   break;//finalizacion del primer case
   case 2:{//inicio del primer case
   	printf("\nPar/Impar\n");//se imprime cual es la opcion que se eligio
   	int num[10], par[10], impar[10], i, j=0, c=0;//declaracion de los tres vectores que contienen 19 espacios(20 en realidad porque se inicializa en 0) y se declaran los 3 contadores a utilizar 
   	int opcion=0;//declaracion de la variable opcion con valor de 0
   	
   	do{//se indica que haga la siguiente accion 
   		for(i=0;i<=9;i++){//inicio de for con contador "i"
   		printf("\nIngrese el valor: ");//se solicita el primer valor
   		scanf("%d",&num[i]);}//se obtiene el primer valor
   		printf("\nIngrese 1 para volver a ingresar los datos  o ingrese 0 para proceder: ");//intente añadir una condicion de vector[i]!=0 pero no logre que se ejecutara de ninguna manera asi que tuve que optar por usar una variable para la condicion del while 
   		scanf("%d",&opcion);//se obtiene el valor de opcion
	   }while(opcion==1);//se realiza la accion anterior solo si opcion es igual a 1


 
for(i=0;i<10;i++)//inicio del segundo for
{
if(num[i]%2==0)//si "num" dividido entre 2 es igual a 0 se realiza la siguiente opcion
{par[j]=num[i];j++;}//par obtiene el valor proveniente del vector num y se incrementa el contador j
else//si no se cumple el primer if se realiza la siguiente opcion
{impar[c]=num[i];c++;}//impar obtiene el valor de num y se incrementa el contador c
}
 for(i=0;i<j;i++){//inicio del tercer for que indica que se ejecutara mientras que i tiene un valor de 0, i es menor a j y se realizara un incremento de j
 
printf("\nPares: %d\n",par[i]);}//se imprimen los pares y finaliza el tercer for

for(i=0;i<c;i++)//inicio del cuarto for que indica que se ejecutara mientras i tiene un valor de 0, i es menor a c y se realizara un incremento de c
printf("\nImpares: %d\n",impar[i]);//se imprimen los impares


	
   }//finalizacion del ultimo for
   break;//finalizacion del segundo case
   case 3:{//inicio del tercer case
   	printf("\nNumeros repetidos\n");//se imprime que la opcion ingresada pertenece a "Numeros repetidos"
   	 int const TamVector = 10;//se declara que la constante "TamVector" tiene un valor de 10
  int valores[TamVector] = {'\0'};//se declara un vector con los espacios pertenecientes a el valor de TamVector

  int opc = 0;//se declara que la variable opc tiene un valor de 0
  do {//se realizara la siguiente accion
    noRepetir(valores,TamVector);//llamado a la funcion noRepetir
    printf("\nDesea volver a ingresar otro dato? (1=Si | 0=NO): )");//se pregunta si deasea volver a ingresar otro dato
    scanf("%d",&opc);//se obtiene el valor ingresado de opc
  } while (opc == 1);//se realizara la accion anterior mientras que "opc" tenga un valor de 1
  for(int i=0;i<10;i++){//inicio de el primer for
  	printf("\nValores ingresados: %d ",valores[i]);//se imprimen los valores ingresados pertenecientes a el vector "valores"
  }

  
	
   }
   break;}//finalizacion del ultimo case y finalizacion del swtich
   
   	}while(opcion!=4);//finalizacion del primer do-while con la condicion de que opcion ingresada sea diferente a 4 
   	return 0;//se regresa valor 0(finalizacion)
}//finaliza main
void noRepetir(int * valores, int tamVector)//declaracion de la funcion noRepetir que lo que hace es una unica letra y buscarla en el vector "variable" y despues lo devuelve a main
{
  int valor;//declaracion de la variable "valor"
  printf("\nIngrese el valor: ");//se solicita un valor
  scanf("%d",&valor);//se obtiene el valor ingresado

  int i;//declaracion de el contador "i"
  bool unica = true;//declaracion de la variable tipo bool"unica" que es igual a "true"  lo que ocasiona que se le asigne un 1
  for( i=0; i<tamVector && valores[i] != '\0' && unica; i++ )//inicio de segundo for que indica que se ejecutara mientras  i es igual a 0, i sea menor a "tamVector" y que el vector "valores" sea diferente a 0 y unica y debido a lo anterior i tendra un incremento 
    unica = (valores[i] != valor);//declara es igual a el vector "valores" mientras que sea diferente a valor 

  if( unica )//se reakiza la siguiente valor con base a "unica"
  {
    if( i < tamVector )//se realiza la siguiente accion si el contador "i" es menor al tamaño del vector
      valores[i] = valor;//se declara que la variable "valores" es igual a la variable "valor"
  }
  else//se realiza la siguiente accion si no se cumplen los if anteriores
  {
    printf("\nEste valor ya ha sido ingresado\n");//se imprime que el valor obtenido ya a sido ingresado 
  }
  
}//finalizacion de la funcion noRepetir

