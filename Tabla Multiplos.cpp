#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
// Programa elaborado por Andres Humberto Martinez Escobedo//
 void gotoxy(int x,int y){  //columna, rengl?
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  

int main()
{
    char next;
    int x,mul;

    do
    {
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	    gotoxy(24,10);    
        printf( " Ingrese un numero entero:  " );
        scanf( "%d",&mul );
        SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),13);
	    gotoxy(24,10);    
        printf( "\n   La tabla de multiplicar del %d es:\n",mul );

         for ( x = 1 ; x <= 10 ; x++ )
            printf( "   %d * %d = %d", x,mul, x * mul );

        printf( "\n\n   %cDesea realizar otra tabla? ingrese /s/ para realizar otra tabla o ingrese /n/ para terminar: ", 168 );
        fflush( stdin );
        scanf( "%c", &next );

    } while ( next != 'n' );

    return 0;
}
