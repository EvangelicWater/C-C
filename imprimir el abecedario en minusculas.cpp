//imprimir el abecedario en minusculas
#include <stdio.h>
#include <windows.h>
char letra;
main()
{
	letra=122; 
	do
	{
		printf("%c   ",letra);
		Sleep(200);
		letra--;
		
	}while(letra>=97);
}
