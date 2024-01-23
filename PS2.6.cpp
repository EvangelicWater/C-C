#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
 void gotoxy(int x,int y){  //columna, renglón
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 main()
 {
 
 float n1,n2,n3;
 SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),14);    
    	gotoxy(23,9);
		printf("\tIngrese un numero real y positivo: ");
		scanf("%f",&n1);
		gotoxy(23,9);
		printf("\tIngrese otro numero real y positivo: ");
		scanf("%f",&n2);
		gotoxy(23,9);
		printf("\tIngrese un último numero real y positivo: ");
		scanf("%f",&n3);
		system("pause");
	    system("cls");
if(n1>n2&&n1>n3&&n1>0&&n2>0&&n3>0)
{
	printf("El primer numero ingresado es el mayor.");
	} 
else if(n2>n1&&n2>n3&&n1>0&&n2>0&&n3>0)
{
	printf("El segundo numero ingresado es el mayor.");
   } 
else if(n3>n1&&n3>n2&&n1>0&&n2>0&&n3>0)
{
	printf("El tercer numero ingresado es el mayor. ");
  }
else if(n1==n2&&n1==n3&&n2==n1&&n2==n3&n3==n2&&n3==n1&&n1>0&&n2>0&&n3>0)
{
	printf("Los números ingresados son iguales.");
  }
 else if(n1==n3&&n1>n2&&n3>n2&&n1>0&&n2>0&&n3>0)
 {
 	printf("El primer y tercer numero son iguales y son los mayores. ");
   }
 else if(n1==n2&&n1>n3&&n2>n3&&n1>0&&n2>0&&n3>0)
 {
 	printf("El primer y segundo numero son iguales y son los mayores.");
   }
 else if(n2==n3&&n2>n1&&n3>n1&&n1>0&&n2>0&&n3>0)
 {
 
 printf("El segundo numero y el tercero numero  son iguales y son los mayores.");
 } 
else if(n1<0&&n2>=0&&n3>=0)
{
	printf("El primero numero es negativo y por lo tanto es incorrecta la secuencia.");
	} 
else if(n2<0&&n1>=0&&n3>=0)
{
	printf("El segundo numero es negativo y por lo tanto es incorrecta la secuencia.");
}
else if(n3<0&&n2>=0&&n1>=0)
{
	printf("El tercer numero es negativo y por lo tanto es incorrecta la secuencia");
}
else if(n1<0&&n2<0&&n3>0)
{
	printf("El primer y segundo numero son negativos por lo tanto es incorrecta la secuencia.");
}
else if(n2<0&&n3<0&&n1>0)
{

printf("El segundo y tercer numero son negativos por lo tanto es incorrecta la secuencia.");
}
else if(n1<0&&n3<0&&n2>0)
{
	printf("El primer y tercer numero son negativos por lo tanto es incorrecta la secuencia");
  }
else if(n1<0&&n2<0&&n3<0)
{
	printf("Todos los números son incorrectos y por lo tanto es incorrecta la secuencia");
  }  
else
{
	printf("Los números ingresados no son validos.");
}
}
