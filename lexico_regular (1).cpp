/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    22/09/22
    Práctica de Análisis Léxico 03
*/

#include <conio.h>
#include <stdio.h>
#include <locale.h>		//librerias
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <regex>

using namespace std;//al parecer lo necesitas o te da error con regex
regex lextra{"([a-z])"};
regex lexmero{"([0-9])"};
regex lexpecial{"([.,;()_!])"};
regex lexmetico{"([+|-|*|/])"};
regex lexcion{"([<|>|=|/])"};
regex lexservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
/*([A-Z])([\d])(([a-z|\d])+)([.]){3,10} intento expresion regular*/
regex lexicador{"(([A-Z])([0-9])(([a-z|\\d])?)(([a-z|\\d])?)(([a-z|\\d])?)(([a-z|\\d])?)(([a-z|\\d])?)(([a-z|\\d])?)(([a-z|\\d])?)[.])"};

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
    
        system("cls");	//funcion para borrado de pantalla
        int Contador=0;
        bool Bandera;    
        char Caracters[100][100];	//Variable de opcion para el selector multiple del menu
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
        printf("de introducir Caracteres:");
        do{
            printf("\n\t\t");
            Validacion=true;
            gets(Caracters[Contador]);
            if (!strcmp(Caracters[Contador],"Esc")||!strcmp(Caracters[Contador],"esc"))    //Si entra a if, es porque se tecleo Esc.
            {
                Validacion=false;
            }
            Contador++;
        }while(Contador<100&&Validacion);

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
            fflush(stdin);	//Se hace un vaciado de la memoria para que no contenga basura
            /*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
            if (regex_match(Caracters[i],lextra))  //Verifica si el Caracter es una letra. (de a-z o A-Z)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("\n\t\t\t\t\t %s Es una ",Caracters[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                printf("Letra ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("y esta ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                printf("RECONOCIDA");

            } else if (regex_match(Caracters[i],lexmero))    //Verifica si el Caracter es un número. (de 0-9)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                    printf("\n\t\t\t\t\t %s Es un ",Caracters[i]);
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11); //Azul Claro
                    printf("Número ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                    printf("y esta ");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                    printf("RECONOCIDO");  
                } else if (regex_match(Caracters[i],lexpecial)) //Verifica si el Caracter es un Caracter Especial. ( . , ; ( ) - _ ! )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("\n\t\t\t\t\t %s Es un ",Caracters[i]);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //Amarillo
                        printf("Caracter Especial ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("y esta ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                        printf("RECONOCIDO");
                    } else if (regex_match(Caracters[i],lexmetico))   
                        //Verifica si el Caracter es un Operador Aritmetico. ( =  + - * / )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("\n\t\t\t\t\t %s Es un ",Caracters[i]);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado
                        printf("Operador Aritmetico ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("y esta ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                        printf("RECONOCIDO");
                    } else if (regex_match(Caracters[i],lexcion))   
                        //Verifica si el Caracter es un Operador de Relacion. ( < > = )
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("\n\t\t\t\t\t %s Es un ",Caracters[i]);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                        printf("Operador Aritmetico ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("y esta ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                        printf("RECONOCIDO");
                    }else if (regex_match(Caracters[i],lexservada))    
                    //Verifica si el Es una Palabra Reservada.
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("\n\t\t\t\t\t %s Es una ",Caracters[i]);
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                        printf("Palabra Reservada ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                        printf("y esta ");
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                        printf("RECONOCIDO");
                    }
					else if (regex_match(Caracters[i],lexicador))
                    {
                      
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                    printf("\n\t\t\t\t\t %s Es una ",Caracters[i]);
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                                    printf("Variable ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                                    printf("y esta ");
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                                    printf("RECONOCIDA");
                              
                            
                    }

            else     //Si el caracter es invalido, entonces se ejecuta este bloque de instruccion.
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("\n\t\t\t\t\t %s Este Caracter ",Caracters[i]);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
                printf("NO ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                printf("esta ");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8); //Gris
                printf("RECONOCIDO");
            }
            /*//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
        }
    return 0;
}
