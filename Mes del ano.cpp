/*Este es un programa que muestra el mes del año conforme los datos ingresados.*/

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
int main()
{
    int mes;
    
    setlocale(LC_CTYPE, "Spanish");
    SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),3);

    gotoxy(50,15);
    printf( "Introduzca mes del año: ");
    scanf( "%d", &mes );
    system("cls");

    switch ( mes )
    {   
        case  1 : gotoxy(60,15);
                  printf( "Enero" );
                  break;
        case  2 : gotoxy(60,15);
                  printf( "Febrero" );
                  break;
        case  3 : gotoxy(60,15);
                  printf( "Marzo" );
                  break;
        case  4 : gotoxy(60,15);
                  printf( "Abril" );
                  break;
        case  5 : gotoxy(60,15);
                  printf( "Mayo" );
                  break;
        case  6 : gotoxy(60,15);
                  printf( "Junio" );
                  break;
        case  7 : gotoxy(60,15);
                  printf( "Julio" );
                  break;
        case  8 : gotoxy(60,15);
                  printf( "Agosto" );
                  break;
        case  9 : gotoxy(60,15);
                  printf( "Septiembre" );
                  break;
        case 10 : gotoxy(60,15);
                  printf( "Octubre" );
                  break;
        case 11 : gotoxy(60,15);
                  printf( "Noviembre" );
                  break;
        case 12 : gotoxy(60,15);
                  printf( "Diciembre" );
                  break;
        default : gotoxy(50,15);
                  printf( "ERROR: Mes incorrecto." );
    }

    getch(); /* Pausa */

    return 0;
    }
