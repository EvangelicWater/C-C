#include <cstring>
#include <iostream>
#include <fstream>
#include <stdio.h> 
void removerCaracteres(char *cadena, char *caracteres);
using namespace std;
int main()
{
  char cadena[20];
  char cadena2[20];//si el array es mas grande que la cadena almacenada, las dos palabras jamas van a ser iguales
  int ret=0;
  char caracteres[] = "A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,  ";//Mayusculas y espacios en blanco
   ifstream inData;
    inData.open("prueba.txt");
    for (int i=0;i<20;i++){
        inData >> cadena[i];//cadena obtiene el texto de test.txt
    
        
    }
  
  printf("Los caracteres que se quitan son: Mayusculas y espacios.\n\n");
  removerCaracteres(cadena, caracteres);
  //isalpha para verificar si es mayuscula
  //isblank para verificar si es espacio
  //? para eliminar
  
  
  printf("Despues de remover es: %s\n\n", cadena);
  strncpy (cadena2,cadena,sizeof(cadena2));
  printf("Cadena copiada: %s\n\n",cadena2);
  printf("Cadena invertida:%s\n\n",strrev(cadena2));
   ret = strcmp(cadena,cadena2);

 
    if (ret > 0) {
    	printf("No es Palindromo\n");
       
    } else if (ret < 0) {
        	printf("No es Palindromo \n");
    } else {
        	printf("Es Palindromo\n");
    }
    printf("Valor resutlado de strcmp:%d\n",ret);
  inData.close();
  system("pause");
  return 0;
}
void removerCaracteres(char *cadena, char *caracteres) {
  int indiceCadena = 0, indiceCadenaLimpia = 0;
  int deberiaAgregarCaracter = 1;
  // Recorrer cadena caracter por caracter
  while (cadena[indiceCadena]) {
    // Primero suponemos que la letra si debe permanecer
    deberiaAgregarCaracter = 1;
    int indiceCaracteres = 0;
    // Recorrer los caracteres prohibidos
    while (caracteres[indiceCaracteres]) {
      // Y si la letra actual es uno de los caracteres, ya no se agrega
      if (cadena[indiceCadena] == caracteres[indiceCaracteres]) {
        deberiaAgregarCaracter = 0;
      }
      indiceCaracteres++;
    }
    // Dependiendo de la variable de arriba, la letra se agrega a la "nueva
    // cadena"
    if (deberiaAgregarCaracter) {
      cadena[indiceCadenaLimpia] = cadena[indiceCadena];
      indiceCadenaLimpia++;
    }
    indiceCadena++;
  }
  // Al final se agrega el caracter NULL para terminar la cadena
  cadena[indiceCadenaLimpia] = 0;
}


