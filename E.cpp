#include <stdio.h>
#include <iostream>
#include <ctype.h>

using namespace std;

struct estudiante
{
	char nombre[80];
	char sexo;
	int condicion;
	char calle[30];
	int numero;
	char colonia[30];
	int codigo_p;
	char ciudad[30];
	int telefono;
};
int main(){
	struct estudiante est[100];
	int n,nest,ap=0,re=0,nef=0,nem=0,tr=0,ct=0,sg=0;
	float pap,prep,pf,pm,pt,pc,ps;
	printf("\nIntruduzca el numero de pacientes: ");
	scanf("%d",&nest);
	for(n=1;n<=nest;n++)
	{
		printf("\n--------------------------------------\n");
		printf("\nNombre  y Apellidos del paciente: ");
		fflush(stdin);
		gets(est[n].nombre);
		do{
			printf("\nSexo (f/m): ");
			fflush(stdin);
			est[n].sexo=(toupper(getchar()));
		}while(est[n].sexo !='F' && est[n].sexo!='M');
		if(est[n].sexo=='F')
		nef++;
		if(est[n].sexo=='M')
		nem++;
		
		printf("Condicion(1/5)\n(5 representa el mayor grado de gravedad)\n: ");
		scanf("%d",&est[n].condicion);
		
		if(est[n].condicion==1)
		re++;
		if(est[n].condicion==2)
		sg++;
		if(est[n].condicion==3)
		tr++;
		if(est[n].condicion==4)
		ct++;
		if(est[n].condicion==5)
		ap++;
		
		printf("\nCalle: ");
		fflush(stdin);
		gets(est[n].calle);
		printf("\nNumero: ");
		scanf("%d",&est[n].numero);
		printf("\nColonia: ");
			fflush(stdin);
		gets(est[n].colonia);
		printf("\nCodigo Postal: ");
		scanf("%d",&est[n].codigo_p);
		printf("\nCiudad: ");
			fflush(stdin);
		gets(est[n].ciudad);
		printf("\nTelefono (formato de 8 digitos): ");
		scanf("%d",&est[n].telefono);
	}
	pap=(ap*100)/nest;
	prep=(re*100)/nest;
	pf=(nef*100)/nest;
	pm=(nem*100)/nest;
	pt=(sg*100)/nest;
	pc=(tr*100)/nest;
	ps=(ct*100)/nest;
	int i;
	for(i=1;i<=nest;i++){
		fflush(stdin);
		if(est[i].condicion==5)
		{

		printf("\nImprimiendo telefonos de los pacientes en estado CRITICO\n");
		printf("\n%c",est[i].telefono);}
	}
	printf("\nHay %d pacientes en estado 5 CRITICO y representan el %.2f%% \n",ap,pap);
	printf("\nHay %d pacientes en estado 4 GRAVE y representan el %.2f%% \n",ct,ps);
	printf("\nHay %d pacientes en estado 3 RESERVADO y representan el %.2f%% \n",tr,pc);
	printf("\nHay %d pacientes en estado 2 SEMI CONTROLADO y representan el %.2f%% \n",sg,pt);
	printf("\nHay %d pacientes en estado 1 CONTROLADO y representan el %.2f%% \n\n",re,prep);
	printf("\nHay %d pacientes de sexo FEMENINO y representan el %.2f%%\n",nef,pf);
	printf("\nHay %d pacientes de sexo MASCULINO y representan el %.2f%% \n\n",nem,pm);
	return(0);
}
