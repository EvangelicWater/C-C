#include<iostream>
#include<string>
#include<regex>
#include<locale.h>
#include<windows.h>

using namespace std;

bool vplaca(const string&);

int main(){
	
	setlocale(LC_ALL,"Spanish");
	string placa;
	while(true){
		cout<<"Ingrese la placa a validar"<<endl;
		getline(cin,placa);
		if(vplaca(placa)){
			cout<<"La placa es válida"<<endl;
		}
		else
		{
			cout<<"La placa no es valida"<<endl;
		}
		system("pause");
		system("cls");
	}
	
}//FIN MAIN

bool vplaca(const string& placa)//obtiene la direccion de memoria de el string placa, funcion por referencia
{
	regex valplaca{"([A-Z]{3}((-\\d\\d){2}))"};
	return regex_match(placa,valplaca);
	
}
