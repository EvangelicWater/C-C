#include <stdio.h>
#include <iostream>   
#include <locale.h> 
#include <windows.h>
 using namespace std;
 
 
 int main()

 {
 	float num[9];
 	int i;
 		for(i=0;i<=9;i++)
 		{
 			cout<<"Ingrese el valor : \n",i+1;
 			cin>>num[i];
		 }
		 for(i=9;i>=0;i--){
		 	cout<<"\n"<<num[i]<<" "<<"\n";
		 }
 }
