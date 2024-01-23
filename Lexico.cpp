/*Equipo 6
Andrés Humberto Martínez Escobedo

*/
#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <iostream>
#define ESC 27
using namespace std;

int main()
{
	char cadena[20];
	int k, j,tam=0, agru=0,salida=0;
	while (salida!=1){
		cout<<"Ingrese la cadena a analizar\nPara dejar de recibir caracteres presione ESC\n"<<endl;
		 
		for(j=0;j<20;j++){
			cadena[j]=getch();
			cout<<cadena[j]<<endl;
			if (cadena[j]==ESC)
			{
				k=j;
				j=20;
			}
		}
		while (tam<k)
		{
			/*validacion de las letras*/
			if((cadena[tam]=='a')||(cadena[tam]=='b')||(cadena[tam]=='c')||(cadena[tam]=='d')||(cadena[tam]=='e')||(cadena[tam]=='f')||(cadena[tam]=='g')||(cadena[tam]=='h')||(cadena[tam]=='i')||(cadena[tam]=='j')||(cadena[tam]=='k')||(cadena[tam]=='l')||(cadena[tam]=='m')||(cadena[tam]=='n')||(cadena[tam]=='ñ')||(cadena[tam]=='o')||(cadena[tam]=='p')||(cadena[tam]=='q')||(cadena[tam]=='r')||(cadena[tam]=='s')||(cadena[tam]=='t')||(cadena[tam]=='u')||(cadena[tam]=='v')||(cadena[tam]=='w')||(cadena[tam]=='x')||(cadena[tam]=='y')||(cadena[tam]=='z'))
            cout<<cadena[tam]<<": Es una letra"<<endl;
            if((cadena[tam]=='A')||(cadena[tam]=='B')||(cadena[tam]=='C')||(cadena[tam]=='D')||(cadena[tam]=='E')||(cadena[tam]=='F')||(cadena[tam]=='G')||(cadena[tam]=='H')||(cadena[tam]=='I')||(cadena[tam]=='J')||(cadena[tam]=='K')||(cadena[tam]=='L')||(cadena[tam]=='M')||(cadena[tam]=='N')||(cadena[tam]=='Ñ')||(cadena[tam]=='O')||(cadena[tam]=='P')||(cadena[tam]=='Q')||(cadena[tam]=='R')||(cadena[tam]=='S')||(cadena[tam]=='T')||(cadena[tam]=='U')||(cadena[tam]=='V')||(cadena[tam]=='W')||(cadena[tam]=='X')||(cadena[tam]=='Y')||(cadena[tam]=='Z'))
            cout<<cadena[tam]<<": Es una letra"<<endl;
			/*validacion de los signos de agrupacion*/
			if((cadena[tam]=='(')||(cadena[tam]=='{')||(cadena[tam]=='['))
			{
				cout<<cadena[tam]<<": Se abre signo de agrupacion"<<endl;
				agru=agru+1;
			}
			if((cadena[tam]==')')||(cadena[tam]=='}')||(cadena[tam]==']'))
			{
				cout<<cadena[tam]<<": Se cierra signo de agrupacion"<<endl;
				agru=agru-1;
			}
			//
			if((cadena[tam]=='s')||(cadena[tam]=='S'))
			{
				if((cadena[tam+1]=='i')||(cadena[tam]=='I')){
				
				for (int t=tam;t<tam+2;t++)
				cout<<cadena[t];
				cout<<": Es una palabra reservada"<<endl;
				tam=tam+1;
				}
			}
			/*validacion de los operadores matematicos*/
			if((cadena[tam]=='+')||(cadena[tam]=='-')||(cadena[tam]=='*')|| (cadena[tam]=='/'))
			cout<<cadena[tam]<<": Es un operador matematico"<<endl;
			/*validacion de los operadores relacionales*/
			if(cadena[tam]=='<')
			{
				if(cadena[tam+1]=='=')
				cout<<cadena[tam]<<cadena[tam+1]<<": Operador Relacional menor o igual a que"<<endl;
				else
				cout<<cadena[tam]<<": Operador Relacional menor que"<<endl;
			}
			if(cadena[tam]=='>')
			{
				if(cadena[tam+1]=='=')
				cout<<cadena[tam]<<cadena[tam+1]<<": Operador Relacional mayor o igual a que"<<endl;
				else
				cout<<cadena[tam]<<": Operador Relacional mayor que"<<endl;
			}
			if(cadena[tam]=='!')
			{
				if(cadena[tam+1]=='=')
				{
					cout<<cadena[tam]<<cadena[tam+1]<<": Operador Relacional diferente que"<<endl;
					tam=tam+1;
				}
			}
			if(cadena[tam]=='=')
			cout<<cadena[tam]<<": Operador Relacional igual que"<<endl;
			/*validacion de los operadores logicos*/
			if(cadena[tam]=='&')
			cout<<cadena[tam]<<": Operador logico and"<<endl;
			if(cadena[tam]=='|')
			cout<<cadena[tam]<<": Operador logico or"<<endl;
			if(cadena[tam]=='~')
			cout<<cadena[tam]<<": Operador logico negacion"<<endl;
			/*validacion de los numeros*/
			if((cadena[tam]=='0')||(cadena[tam]=='1')||(cadena[tam]=='2')||(cadena[tam]=='3')||(cadena[tam]=='4')||(cadena[tam]=='5')||(cadena[tam]=='5')||(cadena[tam]=='6')||(cadena[tam]=='7')||(cadena[tam]=='8')||(cadena[tam]=='9'))
			cout<<cadena[tam]<<": Es un numero"<<endl;
			/*validacion de los signos de puntuacion*/
			if(cadena[tam]==':')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]==';')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]=='"')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]=='.')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]==',')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]=='_')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			if(cadena[tam]=='!')
			cout<<cadena[tam]<<": Es un signo especial"<<endl;
			/*Termina la aplicacion*/
			if(cadena[tam]=='@')
			{
				cout<<cadena[tam]<<": Termina la ejecucion del programa"<<endl;
				salida=1;
			}
			tam=tam+1;
		}
		tam=0;
		for(j=0;j<k+1;j++)
		cadena[j];
		if(agru!=0)
		cout<<"Falta cerrar un signo de agrupacion"<<endl;
		agru=0;
		cout<<"Para finalizar el programa ingrese @"<<endl;
	}
	system ("Pause");
 } 

