
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
