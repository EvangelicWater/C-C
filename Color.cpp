#include<stdio.h>
#include<windows.h>
#include<locale.h>


main()
{
	setlocale(LC_CTYPE, "Spanish"); //establezco idioma espa�ol
    int edad;  
    //comentario
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),5);          
	printf("\t     �Hola Mundo! \n");
	printf("\t     �Sludos! \n");
	system("pause");
SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);
    system("cls");
	printf("\t�C�mo est�s?\n");
	printf("\tUna pregunta, �qu� edad tienes? ");
	scanf("%d",&edad); 
//	system(�COLOR 14�);
	printf("\tVaya asi que tienes %d a�os\n",edad);
	system("PAUSE"); 
} 

