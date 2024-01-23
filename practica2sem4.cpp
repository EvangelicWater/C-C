/* programa realizado por Diego Rodolfo Vargas Vega, Andrés Humberto Martínez Escobedo y Mireya Lizette Cisneros Sandoval
fecha de elaboración 23/08/21*/ 

#include <iostream> //librerías para funciones básicas y usar caracteres en español
#include <clocale>
#include <cstring>
using namespace std;

// clase
class Cliente {	
//atributos
private:
    char cuenta[6];
    int validacion;
    char nombre[30];
    char apellido[30];
    float saldo;
    string tel;
    int len;
    char tipocuenta;
    char domicilio[30];
//métodos
public:
    void pedirdatos() //función que pide los datos
    {
        cout << "\n Introduce un número de cuenta (6 dígitos): ";
        cin >> cuenta;
        len = strlen(cuenta);
 	while(!validar(cuenta,6))
    {
        cout << "\n dato no válido, sólo puede ser un número de 6 dígitos" << endl;
        cout <<"\n Introduce un número de cuenta (6 dígitos): ";
        cin >> cuenta;
        len = strlen(cuenta);
    }
		fflush(stdin);
        	do{
		  
		cout << "\n Introduce el primer nombre del títular: ";
		fflush(stdin);
		cin.getline( nombre, 30,'\n' );
		validacion=validarNombre(nombre);
		}while(validacion==0); 
		
		do{
		  
        cout << " Introduce el primer apellido del títular: ";  
		fflush(stdin);
		cin.getline( apellido, 30,'\n' );
		validacion=validarNombre(apellido);
		}while(validacion==0);
     
		cout << "\n Introduce el domicilio del títular: ";
		cin.getline( domicilio, 30);
		fflush(stdin);
        cout << "\n Introduce el tipo de cuenta del títular (1 = corriente | 2 = débito): ";
        while(!(cin >> tipocuenta)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << "\n Introduce el tipo de cuenta del títular (1 = corriente | 2 = débito): ";
		}
		cout << "\n Introduce el teléfono: ";
        cin >> tel;
		fflush(stdin);
        cout << "\n Introduce el saldo: ";
        while(!(cin >> saldo)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << "\n Introduce el saldo: ";
		}
		fflush(stdin);
		
    }
    void imprimir() //función que imprime los datos 
    {
        cout << " Número de cuenta: " << cuenta << endl;
        cout << " Nombre títular: " << nombre << " " << apellido << endl;
        cout << " Domicilio del títular: " << domicilio << endl;
        if (tipocuenta == '1')
        {
        	cout << " El tipo de cuenta es corriente \n";
		}
		else if (tipocuenta == '2')
        {
        	cout << " El tipo de cuenta es débito \n";
		} else{
			cout << "información no disponible en este momento \n";
		}
        cout << " teléfono: " << tel << endl;
        cout << " Saldo: " << saldo << endl;
    }
    void deposito() //función que nos permite depositar a una cuenta
    {
        long amt;
        cout << "\n Introduzca una cantidad a depositar:  ";
        cin >> amt;
        saldo = saldo + amt;
        cout << "\n El saldo ha sido depositado, para consultar el nuevo balance seleccione consultar ";
    }
    void retiro() //función que nos permite retirar de una cuenta efectivo
    {
        long amt;
        cout << "\n Introduzca la cantidad a retirar: ";
        cin >> amt;
        if (amt <= saldo)
        {
            saldo = saldo - amt;
            cout << "\n El saldo ha sido retirado, para consultar el nuevo balance seleccione consultar ";
		}else
            cout << "\n No cuentas con suficiente saldo " << endl;
    }
    
    int validarNombre(char nombre[])
	{
    int i;
    for(i=0 ; i<strlen(nombre); i++)
    {
        if(!(nombre[i]>=65 && nombre[i]<=90 || nombre[i]>=97 && nombre[i]<=122))
        {
            cout << " tipo de dato no permitido, intenta nuevamente\n";
            return 0;
        }
    }
    return 1;
	}
	bool validar(char cuenta[], int len)
{
    for (int i = 0; i < len; i++)
    {
	if (!isdigit (cuenta[i]))
        return false;
    }
    return true;
}
};

// programa principal
int main()
{
  
    setlocale(LC_CTYPE,"spanish");
	Cliente C;
    int found = 0, a, ch, i;
    int validacion;
 
       C.pedirdatos();
 

    do {
        // opciones del menú
        cout << "\n\n[1] Consultar \n[2] Depositar \n[3] Retirar\n[4] Salir\n" << endl;

        // opciones a escoger por el usuario
        cout<< "Respuesta: ";
        while(!(cin >> ch)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout<<"Respuesta: ";
		}

        switch (ch) {
        case 1: // muestra datos del cliente
          
               C.imprimir();
      
            break;
        case 2:  // deposito en cuenta 
            
                    C.deposito();
                    break;
             
        case 3: // operación retiro de cuenta

                    C.retiro();
                    break;
        
        case 4: // salida del programa
            cout << "\n Saliendo..." << endl;
            break;
        default:
            cout << " respuesta no válida " << endl;
        }
    } while (ch != 4);
    return 0;
}
