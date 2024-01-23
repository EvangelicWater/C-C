#include <windows.h>
#include <iostream>   
#include <locale.h> 
#include <stdio.h>
#include <conio.h>
int main(){
	char cad[200];
	int i;
	gets(cad);
	for (i=0;i<200;i++){
		printf("%s",cad[i]);
	}
}

