#include <iostream> 
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
#include <conio.h> //librerias
#include <bits/stdc++.h>
using namespace std; //uso de cin y cout

using namespace std;
template <class T>// iniciamos creando la plantilla T que se usara para las materias
class Materia{//creamos la clase Materia
	private://tipos de datos privados
		string nombreMateria;//String el que llevara el nombre de la materia
		int clave;// int para la clave de cada materia
		T calificacion;// dato generico que es la calificacion de cada materia
		
		public:// metodos publicos
			Materia(string nombreMateria, int clave, T calificacion){//inicializamos el metodo constructor de la clase materia
				this->nombreMateria = nombreMateria;//el nombre de la materia va a ser igual al nombre de la materia que se envie
				this->clave = clave;// la clave va a ser igual a la clave que se envie
				this->calificacion = calificacion;//la calificacion va a ser igual a la calificacion que se envie
				
				
			}
		void mostrarDatos(){// utilizamos este metodo para imprimir todos los datos de cada materia
			
			cout<<"\nMateria:\n "<<nombreMateria<<endl;
			cout<<"\nClave de la Materia: "<<clave<<endl;
			cout<<"\nCalificacion: "<<calificacion<<endl;
			cout<<"\n----------------\n"<<endl;//impresiones de pantalla
		}
		
		void modificarCalificacion(T calificacion){//utilizamos este metodo para modificar una calificacion especifica de una materia
			this->calificacion = calificacion;//la calificacion va a ser igual a la calificacion que se envie 
		}
		T obtenerCalificacion(){// en este tipo de dato generico obtenemos la calificacion 
			return calificacion;// se envia la calificacion
		}	
};//finaliza la clase Materia

struct paciente //struct que contiene nuestras variables a utilizar
{
	char nombre[80];
	char sexo;
	int condicion;
	string calle;
	string numero;
	char colonia[30];
	int codigo_p;
	char ciudad[30];
	string telefono;
};
int main(){
	We're no strangers to love
You know the rules and so do I (do I)
A full commitment's what I'm thinking of
You wouldn't get this from any other guy
I just wanna tell you how I'm feeling
Gotta make you understand
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
We've known each other for so long
Your heart's been aching, but you're too shy to say it (say it)
Inside, we both know what's been going on (going on)
We know the game and we're gonna play it
And if you ask me how I'm feeling
Don't tell me you're too blind to see
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
We've known each other for so long
Your heart's been aching, but you're too shy to say it (to say it)
Inside, we both know what's been going on (going on)
We know the game and we're gonna play it
I just wanna tell you how I'm feeling
Gotta make you understand
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
Never gonna give you up
Never gonna let you down
Never gonna run around and desert you
Never gonna make you cry
Never gonna say goodbye
Never gonna tell a lie and hurt you
}
