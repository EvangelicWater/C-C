/*
    Kevin Navarro
    Andres Martinez
    Diego Vargas
    29/09/22
    Practica de Analisis Lexico 04
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <clocale>
#include <regex>

using namespace std;


bool validarLetra(const string& ); 
bool validarNumero(const string& ); 
bool validarOperadorMatematico(const string& ); 
bool validarEspecial(const string& ); 
bool validarOperadorRelacional(const string& ); 
bool validarPalabraReservada(const string& ); 
bool validarMayuscula(const string& ); 
bool validarTipoVariable(const string& ); 





int main()
{
	setlocale(LC_CTYPE, "Spanish");
    string input;
    vector< string > contenedor;
    bool mayus = false, digito = false, dot = false; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        cout << "\n\n\t\t\t\tA N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
       
        cout << "\n\n\t\t\t     Teclea un Caracter a para Analizar\n\n"; 
        
        cout << "\n\t\t      Teclea ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); //Rojo
        cout << "Esc ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
        cout << "Para Dejar";
       
        cout << " de introducir Caracteres: \n\n";
    while ( cin >> input ) {
        if ( input == "ESC" || input == "Esc" || input == "esc" ) {
            break;
        }
		else{
			contenedor.push_back( input );
		}
    }
	
	//comparamos la cadena del final al principio del vector
    sort( contenedor.begin() , contenedor.end() );  
	system("cls");
   // cout << "\n Introdujiste:\n";
    //recorremenos el vector
    for ( int i = 0; i < contenedor.size(); ++i ) {
		
		 if (validarLetra(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es letra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            } 
            else if (validarNumero(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un digito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarOperadorMatematico(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador matematico ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarEspecial(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarOperadorRelacional(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarPalabraReservada(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarTipoVariable(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una variable ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarMayuscula(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una MAYUSCULA ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y esta ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << "NO RECONOCIDO \n";
            }else{
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "caracter/palabra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //rojo
                cout << " NO RECONOCIDO \n";
            }	
    }
	
    return 0;
}

bool validarLetra(const string& contenedor){
    
    regex vall("([a-z])");
    return regex_match(contenedor,vall);   

}

bool validarNumero(const string& contenedor){

    regex numero{"([0-9])"};
    return regex_match(contenedor,numero);

}

bool validarOperadorMatematico(const string& contenedor){

    regex operadorMatematico{"([+-*/])"};
     return regex_match(contenedor,operadorMatematico);
}

bool validarEspecial(const string& contenedor){

    
    regex especial{"([.,;()_!])"};
    return regex_match(contenedor,especial);
}

bool validarOperadorRelacional(const string& contenedor){

    regex operadorRelacional{"([<>=])"};
    return regex_match(contenedor,operadorRelacional);
}

bool validarPalabraReservada(const string& contenedor){

    regex palabraReservada{"(si|no|repite|ir|mientras|para|hacer|esto|resultado|termina|inicio|principal|todo|con)"};
    return regex_match(contenedor, palabraReservada);
} 

bool validarMayuscula(const string& contenedor){

    regex mayuscula{"([A-Z])"};
    return regex_match(contenedor, mayuscula);

}

bool validarTipoVariable(const string& contenedor){

    regex tipoVariable{"([A-Z][0-9]([a-z0-9]){1,8}\\.)"};
    return regex_match(contenedor,tipoVariable);



}
