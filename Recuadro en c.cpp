#include <string.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
void gotoxy (short x, short y);
 
main()
{
   char v;
   int 
	for(x=0; x<=112; x++)
	{
		gotoxy (x,0);
		putchar ('*');
		gotoxy (x,30);
		putchar ('*');
	}
 
	for(int y=1; y<=30; y++)
	{
		gotoxy (0,y);
		putchar ('*');
		gotoxy (112,y);
		putchar ('*');
	}
	//Okami
}
 
void gotoxy (short x, short y){
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle (STD_OUTPUT_HANDLE), pos);
}
void t(int n)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}
