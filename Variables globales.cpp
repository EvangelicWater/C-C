//Imprimir el abecedario en mayusculas
#include <stdio.h>
char letra; //Alcance globar: utilizar en todo el programa y todas las funciones
main()
{
	for(char letra='A';letra<='Z';letra++)
	{
		printf("%c ", letra);
	}
}
