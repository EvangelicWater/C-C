#include <iostream>
using namespace std;
int main()
{
	int dia,mes,anio,dia_anio=0;
	printf("Ingrese el dia  ");
	scanf("%d",&dia);
	printf("Ingrese el mes  ");
	scanf("%d",&mes);
	printf("Ingrese el anio  ");
	scanf("%d",&anio);
	
	if(mes>=1&&mes<=12)
	{
		switch(mes)
		{
			case 1: //31 dias
			if(dia>=1&&dia<=31)
			{
				dia_anio=dia;
			}
			else{
				printf("dia no valido");
			}
			break;
			
			case 2://28 dias
			if(dia>=1&&mes<=28)
			{
				dia_anio= dia + 31;
				
			}
			else 
			{
				printf("dia no valido");
			}
			case 3://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 31;
				
			}
			
			break;
			case 4://30 dias
			if(dia>=1&&mes<=30)
			{
				dia_anio= dia + 90;
				
			}
			
			break;
			case 5://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 120;
				
			}
			
			break;
			case 6://30 dias
			if(dia>=1&&mes<=30)
			{
				dia_anio= dia + 151;
				
			}
		
			break;
			case 7://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 181;
				
			}
			
			break;
			case 8://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 212;
				
			}
			
			break;
			case 9://30 dias
			if(dia>=1&&mes<=30)
			{
				dia_anio= dia + 243;
				
			}
			
			break;
			case 10://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 274;
				
			}
		
			break;
			case 11://30 dias
			if(dia>=1&&mes<=30)
			{
				dia_anio= dia + 304;
				
			}
		
			break;
			case 12://31 dias
			if(dia>=1&&mes<=31)
			{
				dia_anio= dia + 334;
				
			}
		
			break;
			
			
		default:printf("Fecha no valida");
			
		}
		
	
	
	printf("El dia del anio es %d",dia_anio);

	}
	else{
		printf(" ERROR Fecha invalida Ingresada");
	}
	return 0;
}
