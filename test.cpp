/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    02/09/22
    Práctica de Análisis Léxico 02
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
    
        Validacion=true;
        char Opcion;
        string Caracters[100];	//Variable de opcion para el selector multiple del menu
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
        printf("Teclea ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        printf("Esc ");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        printf("Para Dejar");
        gotoxy(43,9);
        printf("de introducir Caracteres: ");

        Contador=0;
        do{
            gotoxy(43,11+Contador);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
            cout<<"» ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Salmon
            cin>>Caracters[Contador];

            if (!Caracters[Contador].compare("Esc")||!Caracters[Contador].compare("esc"))    //Si Opcion Captura Esc, Se sale de el do-while.
            {
                Validacion=false;
            }
            Contador++;
        }while(Validacion);

        system("cls");	//funcion para borrado de pantalla
        fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        gotoxy(43,5);
        printf("A N Á L I S I S  L É X I C O");	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        gotoxy(44,7);
        printf("Resultados de el Análisis \n");

        for (int i = 0; i < Contador-1; i++)
        {
            if (sizeof(Caracters)<=1)   //Solo es un Caracter.
            {
                
            }else       //Es Más de un Caracter.
            {

            }
            
        }
        
        

        for (int i = 0; i < Contador; i++)  //Este for ira recorriendo los caracters para validarlos de uno en uno.
        {
            fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
            if((Caracters[i]=='s')||(Caracters[i]=='S'))
			{
				if((Caracters[i+1]=='i')||(Caracters[i+1]=='I')){
				
				for (int t=i;t<i+2;t++)
				cout<<Caracters[t];
				cout<<": Es una palabra reservada"<<endl;
				i=i+1;
				}
				}
            
            if (Caracters[i].compare("a")||Caracters[i].compare("b")||Caracters[i].compare("c")||Caracters[i].compare("d")||
            Caracters[i].compare("e")||Caracters[i].compare("f")||Caracters[i].compare("g")||Caracters[i].compare("h")||
            Caracters[i].compare("i")||Caracters[i].compare("j")||Caracters[i].compare("k")||Caracters[i].compare("l")||
            Caracters[i].compare("m")||Caracters[i].compare("n")||Caracters[i].compare("o")||Caracters[i].compare("p")||
            Caracters[i].compare("q")||Caracters[i].compare("r")||Caracters[i].compare("s")||Caracters[i].compare("t")||
            Caracters[i].compare("u")||Caracters[i].compare("v")||Caracters[i].compare("w")||Caracters[i].compare("x")||
            Caracters[i].compare("y")||Caracters[i].compare("z"))  //Verifica si el Caracter es una letra. (de a-z o A-Z)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                
                cout<<Caracters[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                printf("Letra ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("y esta ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                printf("RECONOCIDA \n");

            }
        }
    
}
