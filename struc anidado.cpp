#include <iostream>
using namespace std;

//Lo que antes era la estructura Cliente,
//Ahora se llama Persona.
struct Persona{
 char nombre[20], apellido[20];
 int edad, numeroIdentificacion;
 long telefono;
};

//Una estructura para representar la
//Fecha de nacimiento de una persona.
struct Fecha{
 int dia,mes,anio;
};

//Esta estructura representa el registro
//De una persona a una centro educativo.
//¡Dentro de ella están todos lo campos 
//Solicitados! 
struct Registro{
 Persona persona;
 Fecha fec;
};

int main(){
 Registro nuevoIngreso;
 cout << "Ingrese el nombre" << endl;
 cin.getline(nuevoIngreso.persona.nombre,20);
 
 cout << "Ingrese apellido" << endl;
 cin.getline(nuevoIngreso.persona.apellido,20);
 
 cout << "Ingrese edad" << endl;
 cin >> nuevoIngreso.persona.edad;
 
 cout << "Ingrese numero de identificacion" << endl;
 cin >> nuevoIngreso.persona.numeroIdentificacion;
 
 cout << "Ingrese telefono" << endl;
 cin >> nuevoIngreso.persona.telefono;
 
 cout << "Ingrese dia de nacimiento" << endl;
 cin >> nuevoIngreso.fec.dia;
 
 cout << "Ingrese mes de nacimiento" << endl;
 cin >> nuevoIngreso.fec.mes;
 
 cout << "Ingrese anio de nacimiento" << endl;
 cin >> nuevoIngreso.fec.anio;
 
 system("cls"); //Borra la pantalla.
 
 cout << "Nombre: " << nuevoIngreso.persona.nombre;
 cout << "\nApellido: " << nuevoIngreso.persona.apellido;
 cout << "\nEdad: " << nuevoIngreso.persona.edad;
 cout << "\nNumero de identificacion: " << nuevoIngreso.persona.numeroIdentificacion;
 cout << "\nTelefono: " << nuevoIngreso.persona.telefono;
 cout << "\nDia de nacimiento: " << nuevoIngreso.fec.dia;
 cout << "\nMes de nacimiento: " << nuevoIngreso.fec.mes;
 cout << "\nAnio de nacimiento: " << nuevoIngreso.fec.anio;
 cout << endl << endl << endl;
 return 0;
}
