/*
programa realizado por:
 - Andrés Humberto Martínez Escobedo
 - Diego Rodolfo Vargas Vega
 - Mireya Lizette Cisneros Sandoval 
fecha de elaboración 07/09/21
*/

//librerías 
#include<iostream>
#include<conio.h>
#include<cstring>
#include <cstdlib>
#include <clocale>

using namespace std;

//6 equipos
char equipos[6][15];//equipos
int puntaje[6][6];  // pg pe pp gf puntaje
int i,j;

//funciones
void ingreso();
void ordena_tabla();
void presenta_matriz();

int main() //programa principal
{
	// llamado de funciones 
     ingreso(); //ingreso input
 
     ordena_tabla();//se ordena la tabla segun puntajes
     presenta_matriz();//se imprime la tabla
}

void ingreso() //función que ingresa info de equipos
{
  int jugados;
  int dif;
      for(i=0;i<6;i++) //recorre el arreglo
      {
      	        printf("\n-----------------------------------------------\n");
                printf("\n\n  Ingrese el nombre del equipo %d: ",i+1);
                scanf("%s", equipos[i]);
          do{
          	    printf ("\n  La cantidad de PARTIDOS jugados debe de ser 6\n");
                printf("\n  Ingrese partidos ganados:");
                        scanf("%d", &puntaje[i][0]);
                         printf("\n  Ingrese partidos empatados:");
                         scanf("%d", &puntaje[i][1]);
                         printf("\n  Ingrese partidos perdidos:");
                         scanf("%d", &puntaje[i][2]);
                        jugados=puntaje[i][0]+puntaje[i][1]+puntaje[i][2];  //debe sumar 10
            }while(jugados!=6);
                 printf("\n  Ingrese goles a favor: ");
                 scanf("%d", &puntaje[i][3]);
                  printf("\n Ingrese los goles en contra: ");
                 scanf("%d",&puntaje[i][4]);
                 puntaje[i][5]=(puntaje[i][0]*3)+puntaje[i][1];
                
                
                 system("cls");
      }
}

void presenta_matriz() //imprime tabla
{
	int dg1=0,dg2=0,dg3=0;
	printf("\n%s-%d vs %s-%d \n",equipos[0],puntaje[0][3],equipos[1],puntaje[1][3]);
	dg1=puntaje[0][3]-puntaje[1][3];
	printf("\nDiferencia de goles: %d\n",dg1);

	printf("\n%s-%d vs %s-%d\n",equipos[2],puntaje[2][3],equipos[3],puntaje[3][3]);
	dg2=puntaje[2][3]-puntaje[3][3];
	printf("\nDiferencia de goles:%d\n",dg2);
	
	printf("\n%s-%d vs %s-%d\n",equipos[4],puntaje[4][3],equipos[5],puntaje[5][3]);
	dg3=puntaje[4][3]-puntaje[5][3];
	printf("\nDiferencia de goles:%d\n",dg3);// se imprimen los equipos que jugaron y la diferencia de goles anotados
	
    printf ("\n\n");
    printf("PG = Partidos Ganados\tPE = Partidos Empatados\tPP = Partidos Perdidos\nGF = Goles a Favor\tGC = Goles en Contra\n");
     printf ("\n\n");
    printf("EQUIPOS\tPG\tPE\tPP\tGF\tGC\tPUNTAJE");
      for(i=0;i<6;i++)
      {
             printf("\n%s", equipos[i]);
             for(j=0;j<6;j++)
                 printf("\t%d",puntaje[i][j]);//se imprime la tabla
      }
  getch();
}

 

void ordena_tabla() //función que ordena la tabla acorde a la información ingresada 
{
  int aux,k;
  char auxi[15];
    for(k=1;k<=7;k++)
      for(i=0;i<7;i++)
      {
       if((puntaje[i][5]<puntaje[i+1][5])||(puntaje[i][5]==puntaje[i+1][5]) && (puntaje[i][3]<puntaje[i+1][3]))
          {
                 //intercambio de equipos
                strcpy(auxi,equipos[i]);
                strcpy(equipos[i],equipos[i+1]);
                strcpy(equipos[i+1],auxi);

                 for(j=0;j<7;j++)
                 {
                         aux=puntaje[i][j];
                         puntaje[i][j]=puntaje[i+1][j];
                         puntaje[i+1][j]=aux;
                 }
          }
      }
}

 

