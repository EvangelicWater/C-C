/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    28/08/22
    Práctica de Análisis Léxico
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>		//librerias
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

#define Esc 27      //Definimos Esc
using namespace std;

void gotoxy(int x, int y) {  //columna, renglón Funcion Gotoxy
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

int main (){
	setlocale(LC_CTYPE, "Spanish");
    bool Validacion;	//Variable de tipo booleana para el do while 
    do
    {
        Validacion=true;
        char Opcion;
        char Caracters[100];	//Variable de opcion para el selector multiple del menu
        bool Bandera=false;
        int Contador=0;
        system("cls");	//funcion para borrado de pantalla
        fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        gotoxy(43,5);
        printf("A N Á L I S I S  L É X I C O");	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        gotoxy(40,7);
        printf("Teclea un Caracter a para Analizar"); 
        gotoxy(43,8);
        printf("Presiona ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        printf("[Esc] ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        printf("Para Dejar");
        gotoxy(43,9);
        printf("de introducir Caracteres: ");

        do{
            Opcion=getch();     //getch para obtener un Caracter.

            if (Opcion==Esc)    //Si Opcion Captura Esc, Se sale de el do-while.
            {
                Validacion=false;
            }else
            {
                if (Contador%5==0)      //Esto se hace para que cada 5 Caracters Capturados, se realize un salto de linea.
                {
                    printf("\n\t\t\t\t");
                }
                Caracters[Contador]=Opcion;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Salmon
                printf("\t%c",Caracters[Contador]);
                Contador++; 
            }   
        }while(Validacion);

        system("cls");	//funcion para borrado de pantalla
        fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        gotoxy(43,5);
        printf("A N Á L I S I S  L É X I C O");	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        gotoxy(44,7);
        printf("Resultados de el Análisis \n");

        for (int i = 0; i < Contador; i++)  //Este for ira recorriendo los caracters para validarlos de uno en uno.
        {
            fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
            //Validacion de palabras reservadas
            if((Caracters[i]=='s')||(Caracters[i]=='S'))
			{
				if((Caracters[i+1]=='i')||(Caracters[i+1]=='I')){
				
				for (int t=i;t<i+2;t++)
				cout<<Caracters[t];
				cout<<": Es una palabra reservada"<<endl;
				i=i+1;
				}
				}
            
           else if (Caracters[i] == 'a' || Caracters[i] == 'b' || Caracters[i] == 'c' || Caracters[i] == 'd' || Caracters[i] == 'e' || Caracters[i] == 'f' ||
			Caracters[i] == 'g' || Caracters[i] == 'h' || Caracters[i] == 'i' || Caracters[i] == 'j' || Caracters[i] == 'k' || Caracters[i] == 'l' ||
			Caracters[i] == 'm' || Caracters[i] == 'n' || Caracters[i] == 'o' || Caracters[i] == 'p' || Caracters[i] == 'p' || Caracters[i] == 'q' ||
			Caracters[i] == 'r' || Caracters[i] == 's' || Caracters[i] == 't' || Caracters[i] == 'u' || Caracters[i] == 'v' || Caracters[i] == 'w' ||
			Caracters[i] == 'x' || Caracters[i] == 'y' || Caracters[i] == 'z' )  //Verifica si el Caracter es una letra. (de a-z o A-Z)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("\n\t\t\t\t\t %c Es una ",Caracters[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                printf("Letra ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("y esta ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                printf("RECONOCIDA");

            } else if (isdigit(Caracters[i]))    //Verifica si el Caracter es un número. (de 0-9)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                    printf("\n\t\t\t\t\t %c Es un ",Caracters[i]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Azul Claro
                    printf("Número ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                    printf("y esta ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                    printf("RECONOCIDO");  
                } else
                    {
                        switch (Caracters[i])
                        {
                            case '.':       //Verifica si el Caracter es un Caracter Especial. ( . , ; ( ) - _ ! )
                            case ',':
                            case ';':
                            case '(':
                            case ')':
                            case '_':
                            case '!':
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("\n\t\t\t\t\t %c Es un ",Caracters[i]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Amarillo
                                printf("Caracter Especial ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("y esta ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                                printf("RECONOCIDO");
                                break;

                            case '+':       //Verifica si el Caracter es un Operador Aritmetico. ( =  + - * / )
                            case '-':
                            case '*':
                            case '/':
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("\n\t\t\t\t\t %c Es un ",Caracters[i]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado
                                printf("Operador Aritmetico ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("y esta ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                                printf("RECONOCIDO");
                                break;

                            case '<':       //Verifica si el Caracter es un Operador de Relacion. ( < > = )
                            case '>':
                            case '=':
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("\n\t\t\t\t\t %c Es un ",Caracters[i]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                                printf("Operador Aritmetico ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("y esta ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                                printf("RECONOCIDO");
                                break;

                            default:        //Si el caracter no paso ninguna validacion, entonces se ejecuta este bloque de instruccion.
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("\n\t\t\t\t\t %c Este Caracter ",Caracters[i]);
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
                                printf("NO ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                printf("esta ");
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //Gris
                                printf("RECONOCIDO");
                                break;
                        }
                    } 
        }

        Validacion=true;    //Se restablece la bandera a true.
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        printf("\n\n\t\t\t\t      Presione ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        printf("[Esc] ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        printf("Para Salir Ó ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Amarillo
        printf("Cualquier \n\t\t\t\t\t Tecla ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        printf("Para Repetir El Programa.");
        
        Opcion=getch();     //getch para obtener un Caracter.

        if (Opcion==Esc)    //Si Opcion Captura Esc, Se sale de el do-while.
        {
            Validacion=false;
        }
    }while(Validacion);
    return 0;
}
