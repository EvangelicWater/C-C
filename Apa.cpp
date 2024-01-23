#include<iostream>
#include<string>
#include<regex>
#include<locale.h>
#include<windows.h>

using namespace std;
//[:space:] para espacios
// se usa //para parentesis
// el caracter : no es metasimbolo por lo que no necesita //
int main(){
	
	regex erapa{"[A-Z][a-z]+,[[:space:]][A-Z]\\.[A-Z]\\.[[:space:]][A-Z][a-z]+\\.[[:space:]]\\(\\d{4}\\)\\.[[:space:]][A-Z][a-z]+:[A-Z][a-z]+\\."};
	
	string referencia;
	
	while(true){
		system("cls");
		cout<<"Referencia a validar:"<<endl;
		getline(cin,referencia);
		
		if(regex_match(referencia,erapa))
		{
			cout<<"Referencia correcta"<<endl;
		}
		else{
			cout<<"Error en la referencia"<<endl;
			
		}
		system("pause");
		system("cls");
	}
}
