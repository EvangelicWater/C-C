#include<iostream>
#include<string>
#include<regex>
#include<locale.h>
#include<windows.h>

using namespace std;
regex erplaca{"[A-Z]{3}-\\d{2}-\\d{2}"};

int main()
{
	setlocale(LC_ALL,"Spanish");
	string placa;
	
	while(true)
	{
		cout<<endl<<"Ingrese la placa a validar:"<<endl;
		getline(cin,placa);
		if(regex_match(placa,erplaca))
		{
			cout<<"Placa válida"<<endl;
		}
		else
		{
			cout<<"La placa no corresponde"<<endl;
		}
		system("pause");
		system("cls");
	}
	//FIN DEL PROGRAMA
}
