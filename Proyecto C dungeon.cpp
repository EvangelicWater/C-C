#include "score4.h"
#include <iostream>   
#include <locale.h> 
#include <windows.h>
#include <stdio.h>
// Programa elaborado por Andres Humberto Martinez Escobedo//
 void gotoxy(int x,int y){  //columna, rengl?
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }
void fun(int);  
int main()
{
	int in,i,e,op1,op2,op3,op4;
	char n[500];
	//Inicia presentacion del juego
	setlocale(LC_ALL,"spanish");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);    
    	gotoxy(22,8);
	printf("Bienvenido ingrese su nombre: ");
	scanf("%s",&n);
	system("pause");
	    system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);    
    	gotoxy(22,8);    
	printf("\nBienvenido a C dungeon %s\n",n);
	system("pause");
	system("cls");
	SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE),12);    
    	gotoxy(22,8);
	printf("\nEn este juego debes elegir la opción que consideres más  adecuada en cada situación para proseguir\n");
	system("pause");
	    system("cls");
	printf("En cada situación se te solicitara el ingresar la acción que deseas realizar\n y solamente debes ingresar el inciso numérico de la acción que deseas realizar.\n");
    system("pause");
    system("cls");
	void fun(int in);
	in=15;
	
	while(in<=0)
	{
	printf("\nEn cada situación se te solicitara el ingresar la acción que deseas realizar\n y solamente debes ingresar el inciso numérico de la acción que deseas realizar.\n");
	
	}
	
	int c=0;
	for(c=1;c<=10;c++)
	{
		printf("CARGANDO");
		printf("\n%d\n",c);
		Sleep(50);
		system("pause");
		system("cls");
	}
	
	//Finaliza presentacion
	//inicia el juego
	printf("Al abrir los ojos lo primero que notas es la inmensa oscuridad en la que te encuentras,\nsin saber porque te encuentras en esta situación tienes algo claro\n");
	printf("tienes que salir de aquí.\n");
	printf("queriendo encontrar una salida a la inmensa oscuridad encuentras una pared que recorriendo con tu mano usas de base para encontrar una salida.\n");
	system("pause");
	system("cls");
	printf("Después de recorrer la inmensa oscuridad por fin encuentras una salida emitiendo un brillo azul\nal cruzar la salida te encuentras con una habitación repleta de cristales azules\nmientras observas la habitacion descubres algo en el centro.");
	printf("\nen el centro de la habitacion se encuentra un slime!\nesa pequeña criatura gelatinosa no parece peligrosa en ablsoluto\nal observar la criatura descubres que en frente de ella se encuentra una espada tirada.\n");
	system("pause");
	system("cls");
	printf("Que haces?");
	printf("\n1)Agarrar la espada para matar a la docil criatura.");
	printf("\n2)Rapidamente agarrar la espada y buscar una salida.");
	printf("\nSeleccione la accion que desea realizar: ");
	scanf("%d",&op1);
	if(op1==2){
		printf("\nRapidamente agarras la espada sin subestimar a la criatura y buscas una salida\ninmediatamente encuentras una salida esta vez emitiendo un brillo de una luz roja.\n");
		system("pause");
		system("cls");
		printf("Al cruzar la luz roja te encuentras con una habitacion llena de huesos posiblemente humanos en cada esquina\nAsustado por el aspecto de la habitacion rapidamente buscas una salida\nAl intentar buscar una salida notas la presencia de un perro pero de apareciancia gigante con piel oscura y grandes dientes\nsin embargo detras de la criatura notas una puerta de madera.\n");
		printf("Que haces?");
		printf("\n1)Utilizar tu espada para matar rapidamente a la bestia.");
		printf("\n2)Buscar algun tipo de distraccion.");
		printf("\n3)Intentar acariciar a la bestia.");
		printf("\n4)Demostrar tu superioridad a la bestia.");
		printf("\nSeSeccione la accion que desea realizar: ");
		scanf("%d",&op2);
		system("pause");
		system("cls");
		switch(op2){
			case 1:
				if(op2==1)
				{
					printf("Sin duda alguna utilizas tu espada para eliminar a la feroz bestia\npero inmediatamente la bestia se da cuenta de tu presencia\nla bestia esquiva tu espada para despues lanzarse en contra de tu desprotejido cuello.\n");
					system("pause");
					system("cls");
					printf("BAD ENDING\n se te olvido un pequeño detalle que es el que no tienes experiencia con la espada...");
					int puntaje= sumar(100,0,0,0);
					printf("\nPuntaje final: %d",puntaje);
				}
				break;
			case 2:
			    if(op2==2)
				{
					printf("Temeroso de la feroz bestia buscas algun tipo de distraccion\nal buscar la habitacion lo unico que encuentras son los huesos de los anteriores enemigos de la bestia\naunque inmediatamente te das cuenta que los mismos huesos servirian para la distraccion\nseguidamente agarras un hueso para lanzarlo a la esquina mas lejana de la habitacion\n al escuchar eso la bestia corre en direccion del sonido\ngracias a eso lograr atravezar la puerta.\n");
					system("pause");
					system("cls");
					printf("Al atravezar la puerta de madera te encuentras en una habitacion con aspecto de cabaña de madera\nal buscar a tu alrededor encuentras varias cosas como si se tratara de una casa normal\npero aun asi no ves a nadie cerca\ndespues de buscar por la habitacion con aspecto hogareño encuentras una cama\nel aspecto de la cama es bastante elegante tanto asi que se podria decir que es de lujo\npero aun asi sientes algo de inseguridad.\n");
					printf("\nQue haces?");
					printf("\n1)Rendirte al cansancio y descanzar en la elegante cama.");
					printf("\n2)Enfocarte y seguir buscando la salida.");
					printf("\nSelecciona la accion que desea realizar: ");
					scanf("%d",&op3);
					system("pause");
					system("cls");
					if(op3==1)
					{
						printf("Rendido ante el cansancio te recuestas en la comoda cama\ninmediatamente caes en un profundo sueño.\n");
						system("pause");
						system("cls");
						printf("BAD ENDING\nnunca volviste a despertar.");
						int puntaje= sumar(100,200,0,0);
						printf("\nPuntaje final: %d",puntaje);
					}
					else if(op3==2)
					{
						printf("Venciendo el cansancio sigues adelante\ndespues de buscar por horas encuentras una puerte de hierro frio\narmandote de valor abres la puerta para seguir adelante\n");
						system("pause");
						system("cls");
						printf("Despues de cruzar la puerta metalica te encuentras con un escena sorpendente\nesta no es una habitacion es una calle de alguna ciudad gris y oscura\napesar de ser una ciudad notas que no ves a ninguna persona en la calle\nal seguir adelante notas una pequeña figura\nal acercarte a la figura notas que en realidad es un pequeño niño de al parecer unos 8 años\nrapidamente intentas hablar con el niño\n-te encuentras bien?-\nle dices al niño en un tono amigable\n-porfavor necesito algo de comida-\nel niño responde.\n");
						printf("\nQue haces?");
						printf("\n1)Intentar conseguir algo de comer para el pequeño niño.");
						printf("\n2)No confiar en el niño y seguir adelante.");
						printf("\nSeleccione la accion que desea realizar: ");
						scanf("%d",&op4);
						system("pause");
						system("cls");
						if (op4==1){
							printf("Queriendo ayudar al pobre niño dices\n-espera aqui ire en busca de algo de comida-\ny partes en busca de algo de comer para el niño adentrandote en la neblina que envuelve la ciudad\nmientras caminas logras escuchar una pequeña voz diciendo:\n-oh amable humano que apesar de enfrontar fuerzas desconocidas no te pierdes a ti mismo y deseas ayudar a los demas\nrezare porque encuentres salvacion en este putrido lugar-\n");
							system("pause");
							system("cls");
							printf("Mientras recorrias la niebla descubres una luz calida proveniente de una puerta a tu derecha\nsin siquiera darte cuenta ya te estabas dirigiendo a la puerta para cruzarla\ndespues de cruzar la puerta te encontraste con una escena que pensaste nunca volver a ver\nera el exterior\n rodeado de arboles y aves caes en tus rodillas alegre por al fin haber salido de ese infernal lugar\nlentamente te recuestas sobre el pasto para escuchar el cantar de los pajaros y al fin poder tener algo de descanso.\n");
							system("pause");
							system("cls");
							printf("\nFelizidades lograste conseguir el final verdadero.\n");
							int puntaje= sumar(100,200,300,400);
							printf("\nPuntaje final: %d\n",puntaje);
							system("pause");
							system("cls");
							printf("Mientras descansabas en el cesped te invadio una duda\nsi adentro de ese infernal lugar en el que desperte existian diferentes lugares tan parecidos al exterior\ncomo estoy seguro que esto no es otra habitacion de ese infernal lugar?.\nEND");
						}
						else if(op4==2){
							printf("Desconfiando de la extraña atmosfera y el peculiar niño decides avanzar por un callejon oscuro.\n");
							system("pause");
							system("cls");
							printf("BAD ENDING\n aun ahora sigues recorriendo el oscuro callejon.");
							int puntaje= sumar(100,200,300,0);
							printf("\nPuntaje final: %d",puntaje);
						}
					   else{
					   	printf("ERROR AL INGRESAR LOS DATOS");
					   }
						
					}
					else{
						printf("Error al ingresar los datos");
					}
					
					}
				break;
			case 3:
			    if(op2==3)
				{
					printf("Queriendo acariciar a la bestia para apaciguarla te acercas lentamente para reposar tu mano en su cabeza\nSorprendido logras acariciar su cabeza\npero seguido de esto la bestia muerde tu mano arrancandola en un parpadeo.\n");
					system("pause");
					system("cls");
					printf("BAD ENDING\n no es buena idea intentar acariciar animales violentos y peligrosos.");
					int puntaje= sumar(100,0,0,0);
					printf("\nPuntaje final: %d",puntaje);
					}
				break;
			case 4:
			    if(op2==4)
				{
					printf("Seguro de tu superioridad te pones enfrente de la bestia\ninflando el pecho miras con desprecio a la bestia\nseguido de eso la bestia sin dudar se abalanza con intencion de matar.\n");
					system("pause");
					system("cls");
					printf("BAD ENDING\nmostrar tu superioridad ante una bestia feroz y peligrosa no resuelve nada.");
					int puntaje= sumar(100,0,0,0);
					printf("\nPuntaje final: %d",puntaje);
					}
				break;
			
					
		}
	}
	else if(op1==1){
		printf("\nRapidamente agarras la espada para inediatamente clavarla en el cuerpo gelatinoso de la criatura\npero descubres que la criatura no se inmuta,\nal notar esto intentar sacar la espada para arremeter la criatura una segunda vez\npero al intentar sacar la espada notas que esta atascada en el cuerpo gelatinoso de la criatura\nlleno de panico sigues intentando sacar la espada hasta notar que tus manos ahora estan dentro de la criatura\nsin poder liberarte eres absorvido por la docil criatura\n");
		system("pause");
		system("cls");
		printf("BAD ENDING\nSubestimaste a la criatura queriendote aprovechar de ella solo para ser consumido por el pequeño slime.");
		int puntaje= sumar(0,0,0,0);
		printf("\nPuntaje final: %d",puntaje);
	}
	else{
		printf("Error al ingresar los datos.");
	}
	do 
	{
		int extra;
		extra=0;
	}
	while(in!=3);
}
