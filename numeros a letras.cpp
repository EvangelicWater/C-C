/* Este programa pide un numero entero del 1 al 10 y lo muestra escrito con letras*/
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
void gotoxy(int x,int y){  //columna, rengl
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
main()
{
	int num;
	setlocale(LC_CTYPE, "Spanish");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),3);

    gotoxy(50,10);
	printf( "Ingrese un numero entero del 1 al 10: ");
	 scanf( "%d", &num );
    system("cls");
     switch ( num )
    {   
        case  1 : gotoxy(50,10);
                  printf( "Usted introdujo el Uno" );
                  break;
        case  2 : gotoxy(50,10);
                  printf( "Usted introdujo el Dos" );
                  break;
        case  3 : gotoxy(50,10);
                  printf( "Usted introdujo el Tres" );
                  break;
        case  4 : gotoxy(50,10);
                  printf( "Usted introdujo el Cuatro" );
                  break;
        case  5 : gotoxy(50,10);
                  printf( "Usted introdujo el Cinco" );
                  break;
        case  6 : gotoxy(50,10);
                  printf( "Usted introdujo el Seis" );
                  break;
        case  7 : gotoxy(50,10);
                  printf( "Usted introdujo el Siete" );
                  break;
        case  8 : gotoxy(50,10);
                  printf( "Usted introdujo el Ocho" );
                  break;
        case  9 : gotoxy(50,10);
                  printf( "Usted introdujo el Nueve" );
                  break;
        case 10 : gotoxy(50,10);
                  printf( "Usted introdujo el Diez" );
                  break;
    
        default : gotoxy(50,10);
                  printf( "ERROR: El número debe ser mayor a uno y menor a 10." );
    }

    getch(); /* Pausa */

    return 0;
    
}
