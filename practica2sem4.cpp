/* programa realizado por Diego Rodolfo Vargas Vega, Andr�s Humberto Mart�nez Escobedo y Mireya Lizette Cisneros Sandoval
fecha de elaboraci�n 23/08/21*/ 

#include <iostream> //librer�as para funciones b�sicas y usar caracteres en espa�ol
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
//m�todos
public:
    void pedirdatos() //funci�n que pide los datos
    {
        cout << "\n Introduce un n�mero de cuenta (6 d�gitos): ";
        cin >> cuenta;
        len = strlen(cuenta);
 	while(!validar(cuenta,6))
    {
        cout << "\n dato no v�lido, s�lo puede ser un n�mero de 6 d�gitos" << endl;
        cout <<"\n Introduce un n�mero de cuenta (6 d�gitos): ";
        cin >> cuenta;
        len = strlen(cuenta);
    }
		fflush(stdin);
        	do{
		  
		cout << "\n Introduce el primer nombre del t�tular: ";
		fflush(stdin);
		cin.getline( nombre, 30,'\n' );
		validacion=validarNombre(nombre);
		}while(validacion==0); 
		
		do{
		  
        cout << " Introduce el primer apellido del t�tular: ";  
		fflush(stdin);
		cin.getline( apellido, 30,'\n' );
		validacion=validarNombre(apellido);
		}while(validacion==0);
     
		cout << "\n Introduce el domicilio del t�tular: ";
		cin.getline( domicilio, 30);
		fflush(stdin);
        cout << "\n Introduce el tipo de cuenta del t�tular (1 = corriente | 2 = d�bito): ";
        while(!(cin >> tipocuenta)) 
		{
  		cin.clear();
  		cin.ignore(1000, '\n');
 	 	cout << "tipo de dato no permitido, intenta nuevamente\n";
		cout << "\n Introduce el tipo de cuenta del t�tular (1 = corriente | 2 = d�bito): ";
		}
		cout << "\n Introduce el tel�fono: ";
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
    void imprimir() //funci�n que imprime los datos 
    {
        cout << " N�mero de cuenta: " << cuenta << endl;
        cout << " Nombre t�tular: " << nombre << " " << apellido << endl;
        cout << " Domicilio del t�tular: " << domicilio << endl;
        if (tipocuenta == '1')
        {
        	cout << " El tipo de cuenta es corriente \n";
		}
		else if (tipocuenta == '2')
        {
        	cout << " El tipo de cuenta es d�bito \n";
		} else{
			cout << "informaci�n no disponible en este momento \n";
		}
        cout << " tel�fono: " << tel << endl;
        cout << " Saldo: " << saldo << endl;
    }
    void deposito() //funci�n que nos permite depositar a una cuenta
    {
        long amt;
        cout << "\n Introduzca una cantidad a depositar:  ";
        cin >> amt;
        saldo = saldo + amt;
        cout << "\n El saldo ha sido depositado, para consultar el nuevo balance seleccione consultar ";
    }
    void retiro() //funci�n que nos permite retirar de una cuenta efectivo
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
        // opciones del men�
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
             
        case 3: // operaci�n retiro de cuenta

                    C.retiro();
                    break;
        
        case 4: // salida del programa
            cout << "\n Saliendo..." << endl;
            break;
        default:
            cout << " respuesta no v�lida " << endl;
        }
    } while (ch != 4);
    return 0;
}
