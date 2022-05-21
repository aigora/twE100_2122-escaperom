
#include <stdio.h>
#include "LibreriaCodigoFunciones.h"


void menu (int *opcion)
{
  system("cls");  //Borrar la pantalla  para poder mirar cuando se quiera las instruciones.

	printf("Bienvenido a EscapeROM\n");

	printf("Selecciona la opcion:\n");

	printf("Nueva partida   1\n");
	printf("Cargar partida  2\n");
	printf("Intrucciones    3\n");
	printf("Salir           4\n");

	fflush(stdin);

	scanf("%i", &*opcion);
}

void instrucciones (int *informacion)
{
	printf("INSTRUCCIONES DEL ESCAPEROM:\n");
        printf("A lo largo del juego, se le ira mostrando una historia donde usted es el protagonista.\n");
        printf("Dicha historia esta dividida en 3 partes, en las cuales hay diferentes sucesos, donde usted podra tomar sus propias decisiones.");
        printf("Para elegir dichos sucesos, solo sera necesario presionar la tecla del numero segun el suceso que quiera que ocurra a continuacion.\n");
        printf("Como aclaracion del juego, dispones de un tiempo ilimitado para realizar toda la historia.");

        system("PAUSE");

}

void nueva_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{

}

void cargar_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{

}

int  comprobar_fichero_partidas (partida datos[], int *numero_partidas)
{

}
