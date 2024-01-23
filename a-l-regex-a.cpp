/*
    Diego Vargas
    Kevin Navarro
    Andres Martinez
    29/09/22
    Pr�ctica de An�lisis L�xico 04
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
#include <locale>
#include <regex>
#include <cstring>

using namespace std;

//prototipo
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
	
    FILE *fptr;
  
    char filename[100];

    setlocale(LC_CTYPE, "Spanish");
    string input;
    vector< string > contenedor;
    int c, i;
    int respuesta;
    bool mayus = false, digito = false, dot = false; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13); //Morado 	Se definen colores 
        
        

        cout << "\n\n\t\t\t\tA N A L I S I S  L E X I C O\n";	//Nombre del programa ("nombre de la practica")
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco


        cout << "\n\n\t\t\t\t\t MENU: \n\n";
        cout << "\n\n\t\t\t\t    1. leer archivo \n";
        cout << "\n\n\t\t\t\t    2. ingresar desde consola \n";
        cout << "\n\n\t\t\t\t    3. salir \n\n";
        cin >> respuesta;      

        switch (respuesta){

            case 1:

            cout << "\n\n\t\t\t     Ingresa el nombre del archivo: \n\n";
            gets(filename);

            fptr = fopen(filename, 0);
             if (fptr == NULL)
            {
            cout << "Cannot open file \n";
            exit(0);
            }
  
            // Read contents from file
            c = fgetc(fptr);
            while (c != EOF)
            {
            
            cout << c;

            validarLetra(contenedor[i]); 
            validarNumero(contenedor[i]); 
            validarOperadorMatematico(contenedor[i]); 
            validarEspecial(contenedor[i]); 
            validarOperadorRelacional(contenedor[i]); 
            validarPalabraReservada(contenedor[i]); 
            validarMayuscula(contenedor[i]); 
            validarTipoVariable(contenedor[i]); 

            c = fgetc(fptr);
            }
  
            fclose(fptr);

                break;

            case 2:

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
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            } 
            else if (validarNumero(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un digito ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarOperadorMatematico(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador matemático ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarEspecial(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter especial ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarOperadorRelacional(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un operador relacional ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDO \n";
            }else if (validarPalabraReservada(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una palabra reservada ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarTipoVariable(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es una variable ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10); //Verde
                cout << "RECONOCIDA \n";
            }else if (validarMayuscula(contenedor[i])){
                
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << " " << contenedor[i];
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9); //Azul
                cout << " es un caracter/palabra ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //Blanco
                cout << "y est� ";
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

                break;

            case 3:

                return 0;

                break;

            default:

                cout << " respuesta  no valida ";

                break;
       
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

    regex tipoVariable{"([A-Z][0-9]([a-z0-9]){1,10}\\.)"};
    return regex_match(contenedor,tipoVariable);



}
