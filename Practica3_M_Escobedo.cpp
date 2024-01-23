/*
programa hecho por Diego Rodolfo Vargas Vega, Andrés Humberto Martínez Escobedo y Mireya Lizette Cisneros Sandoval

fecha de elaboración 18/08/2021
cuarto semestre primer parcial
*/
#include <iostream>//libreria
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

int main(){
	
	Materia<int> materia1("\nAlgoritmia",1,4);//incluimos la clase Materia para definir que el tipo de dato generico sera de tipo entero y creamos un objeto llamado materia1 con los atributos que son nombre,clave y calificacion
	Materia<float> materia2("\nSeminario de Solucion de Problemas de Algoritmia",2,9.99);//incluimos la clase Materia para definir que el tipo de dato generico sera de tipo flotante y creamos un objeto llamado materia2 con los atributos que son nombre,clave y calificacion
	Materia<char> materia3("\nProgramacion",3,'B');//incluimos la clase Materia para definir que el tipo de dato generico sera de tipo caracter y creamos un objeto llamado materia3 con los atributos que son nombre,clave y calificacion
	
		cout<<"\nDatos de la Materia 1:\n "<<endl;//impresion de pantalla
		materia1.mostrarDatos();//llamamos al metodo utilizado para mostrar los datos en este caso de la materia1
		cout<<"\nDatos de la Materia 2:\n "<<endl;//impresion de pantalla
		materia2.mostrarDatos();//llamamos al metodo utilizado para mostrar los datos en este caso de la materia2
		cout<<"\nDatos de la Materia 3:\n "<<endl;//impresion de pantalla
		materia3.mostrarDatos();//llamamos al metodo utilizado para mostar los datos en este caso de la materia3
		
		materia1.modificarCalificacion(8);//llamamos al metodo utilizado para modificar la calificacion de la materia1
		cout<<"\nLa nueva calificacion  de la Materia 1 es: "<<materia1.obtenerCalificacion()<<endl;//se obtiene el nuevo valor de la calificacion
		materia2.modificarCalificacion(99.99);//llamamos al metodo utilizado para modificar la calificacion de la materia2 
		cout<<"\nLa nueva calificacion de la Materia 2  es: "<<materia2.obtenerCalificacion()<<endl;//se obtiene el nuevo valor de la calificacion
		materia3.modificarCalificacion('A');//llamamos al metodo utilizado para modificar la calificacion de la materia3
		cout<<"\nLa nueva calificacion de la Materia 3 es: "<<materia3.obtenerCalificacion()<<endl;//se obtiene el nuevo valor de la calificacion
	return 0;//finaliza el programa 
}
