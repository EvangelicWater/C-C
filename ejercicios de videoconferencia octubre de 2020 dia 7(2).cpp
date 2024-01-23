#include <stdio.h>
#include <windows.h>
//imprimir los valores del 5 al 500 de 5 en 5

int x,y;
main()
{
	x=5;
	y=500;
	while(x<=500 && y>=5)
	{
		printf("%4d %4d",x,y);
		Sleep(300);
		x+=5;
		y-=5;
	}
}
