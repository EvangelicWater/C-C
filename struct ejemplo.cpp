// Array con muchos struct y menu para manejarla
 
#include <iostream>
#include <string>
#include <ios>
#include <ostream>        
#include <locale.h> 
#include <windows.h>
using namespace std;
 
struct tipoDatos
{
    string nombreFich;        // Nombre del fichero
    long tamanyo;            // El tama�o en bytes
    int nu;
    int num;
    int numero;
};
 
int numeroFichas=0;  // N�mero de fichas que ya tenemos
int i;               // Para bucles
int opcion;          // La opcion del menu que elija el usuario
 
string textoTemporal; // Para pedir datos al usuario
int numeroTemporal;
 
int main()
{
    tipoDatos *fichas = new tipoDatos[5];
 
    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo fichero" << endl;
        cout << "2.- Mostrar los nombres de todos los ficheros" << endl;
        cout << "3.- Mostrar ficheros que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un fichero" << endl;
        cout << "5.- Salir" << endl;
 
        cin >> opcion;
 
        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(opcion)
        {
            case 1: // A�adir un dato nuevo
                if (numeroFichas < 5)   // Si queda hueco
                {
                    cout << "Introduce el nombre del fichero: ";
                    cin >> fichas[numeroFichas].nombreFich;
                    cout << "Introduce el tama�o en KB: ";
                    cin >> fichas[numeroFichas].tamanyo;
                    cin >> fichas[numeroFichas].nu;
                    cin >> fichas[numeroFichas].num;
                    cin >> fichas[numeroFichas].numero;
                    numeroFichas++;  // Y tenemos una ficha m�s
                }
                else   // Si no hay hueco para m�s fichas, avisamos
                    cout << "M�ximo de fichas alcanzado (5)!" << endl;
                break;
 
            case 2: // Mostrar todos
                for (i=0; i<numeroFichas; i++)
                    cout << "Nombre: " << fichas[i].nombreFich
                        << "; Tama�o: " << fichas[i].tamanyo
                        << "Kb" << endl;
                break;
 
            case 3: // Mostrar seg�n el tama�o
                cout << "�A partir de que tama�o quieres que te muestre? ";
                cin >> numeroTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].tamanyo >= numeroTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;
 
            case 4: // Ver todos los datos (pocos) de un fichero
                cout << "�De qu� fichero quieres ver todos los datos?";
                cin >> textoTemporal;
                for (i=0; i<numeroFichas; i++)
                    if (fichas[i].nombreFich == textoTemporal)
                        cout << "Nombre: " << fichas[i].nombreFich
                            << "; Tama�o: " << fichas[i].tamanyo
                            << " Kb" << endl;
                break;
 
            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;
 
            default: // Otra opcion: no v�lida
                cout << "Opci�n desconocida!" << endl;
                break;
        }
    } while (opcion != 5);  // Si la opcion es 5, terminamos
 
    return 0;
}
