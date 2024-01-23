#include<iostream>
#include<string>
#include<regex>
#include<locale.h>
#include<windows.h>

using namespace std;
bool vNombre(const string&);
bool vEdad(const string&);
bool vCURP(const string&);
bool vRFC(const string&);
bool vDomicilio(const string&);

int main()
{
	setlocale(LC_ALL,"Spanish");
	
	string Nombre;
	string Edad;
	string CURP;
	string RFC;
	string Domicilio;
	while(true){
		cout<<"Inicio de Registro\n"<<endl;
		cout<<"(Se debe de ingresar el nombre y domicilio separados por espacios como se va a mostrar posteriormente)\n"<<endl;
		cout<<"Ingrese su nombre empezando por mayusculas:"<<endl;
		cout<<"Ejemplo:Andres Humberto\n"<<endl;
		getline(cin,Nombre);
		cout<<"\nIngrese su edad (solo numeros y sin ceros al principio ni caracteres especiales):"<<endl;
		getline(cin,Edad);
		cout<<"\nIngrese su CURP:"<<endl;
		getline(cin,CURP);
		cout<<"\nIngrese su RFC:"<<endl;
		getline(cin,RFC);
		cout<<"\nIngrese su domicilio segun el siguiente formato: Calle #digitos Colonia CP"<<endl;
		cout<<"Ejemplo:Calle #123 Colonia 00000"<<endl;
		getline(cin,Domicilio);
		cout<<"\nProcesando la informacion\n";
		system("pause");
		system("cls");
		if(vNombre(Nombre)){
			cout<<"Nombre validado correctamente\n"<<endl;
			if(vEdad(Edad)){
				cout<<"Edad validada correctamente\n"<<endl;
				if(vCURP(CURP)){
					cout<<"CURP validado correctamente\n"<<endl;
					if(vRFC(RFC)){
						cout<<"RFC validado correctamente\n"<<endl;
						if(vDomicilio(Domicilio)){
							cout<<"Domicilio validado correctamente\n"<<endl;
							cout<<"Se validaron correctamente todos los datos\n\nRegresando al incio\n"<<endl;
							system("pause");
							system("cls");
						}
						else{
							cout<<"\nERROR\nSe ingreso incorrectamente el Domicilio"<<endl;
							cout<<"\nRegresando al incio\n"<<endl;
						}
					}
					else{
						cout<<"\nEROR\nSe ingreso incorrectamente el RFC"<<endl;
						cout<<"\nRegresando al incio\n"<<endl;
					}
				}
				else{
					cout<<"\nError\nSe ingreso incorrectamente la CURP"<<endl;
					cout<<"\nRegresando al incio\n"<<endl;
				}
			}
			else{
				cout<<"\nError\nSe ingreso incorrectamente la edad"<<endl;
				cout<<"\nRegresando al incio\n"<<endl;
			}
		}
		else
		{
			cout<<"\nError\nSe ingreso incorrectamente el nombre"<<endl;
			cout<<"\nRegresando al incio\n"<<endl;
		}
		
		
		
	}
	
}

bool vNombre(const string&Nombre){
	regex erNombre{"(([A-Z][a-z]*\\s?)+)"};
	return regex_match(Nombre,erNombre);
}
bool vEdad(const string&Edad){
	regex erEdad{"[1-9]([0-9]?){1,2}"};
	return regex_match(Edad,erEdad);
}
bool vCURP(const string&CURP){
	regex erCURP{"([A-Z][AEIOU][A-Z][A-Z]([0-9]){6}[HM]([A-Z]){2}([BCDFGHJKLMNÑPQRSTVWXYZ]){3}[0-9A-Z][0-9])"};
	return regex_match(CURP,erCURP);
}
bool vRFC(const string&RFC){
	regex erRFC{"([A-Z][AEIOU][A-Z][A-Z]([0-9]){2}([0-9]){2}([0-9]){2}([A-Z0-9]){3})"};
	return regex_match(RFC,erRFC);
}
bool vDomicilio(const string&Domicilio){
	regex erDomicilio{"([A-Z][a-z]+\\s#[0-9]+\\s[A-Z][a-z]+\\s([0-9]){5})"};
	return regex_match(Domicilio,erDomicilio);
}
