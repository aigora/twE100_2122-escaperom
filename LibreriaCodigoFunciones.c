
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

int  comprobar_fichero_partidas (partida datos[], int *numero_partidas)
{
	FILE * pv ;   //p hay que ponerle nombre correspondiente
	int i=0;

	pv = fopen("nombredelficheroejemplo.txt", "r");   //para abrir el fichero

	if(pv == NULL)      //comprobacion de que existe el fichero
	{
		printf("No se ha podido encontrar el fichero\n");
		printf("comprueba que el nombre del fichero esta escrito correctamente\n");
     	        return 0;
        }

        while(fscanf(pv, "%s", &datos[i].nombre_partida) != EOF)    //comprueba o cuenta cuantas partidas hay en el fichero guardadas y se guarda en un vector contador
        {
                i++;
        }
        *numero_partidas = i;

        fclose(pv);
        return 1;
}

void nueva_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{ //printf("sigue las instrucciones para crear la partida\n");

    FILE * pv; //poner nombre correspondiente
    int i, aux = 0;

    do          //se comprueba que el nombre de la partida es el correcto y no existe otro igual
    {
        printf("nombre de la partida\n");

        fflush(stdin);

        scanf("%s", nombre_jugador);

        for(i = 0; i < *numero_partidas; i++)
        {
			if(strcmp(nombre_jugador, datos[i].nombre_partida) == 0)
			{
				aux = 1;
				break;
			}
            else
            {
				aux = 0;
			}
		}

        if(aux == 1)
        {
			printf("el nombre de la partida ya existe, inserte otro nombre\n");
			system("PAUSE");
		}
		else
        {
			printf("nombre de la partida guardado correctamente\n");
			strcpy(datos[*numero_partidas].nombre_partida, nombre_jugador);
		}
    }
    while(aux == 1);

    pv = fopen("NOMBRES_PARTIDA.txt", "w");

    for(i = 0; i <= *numero_partidas; i++)          //se añaden en el fichero los datos introducidos
    {
        fprintf(pv, "%s\n", datos[i].nombre_partida);
    }

    fclose(pv);
    system("PAUSE");

}

void cargar_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{int i, aux = 0;

    printf("cargar partida\n");

    do              //introduce el nombre de la partida y
    {
        printf("nombre de la partida\n");
        fflush(stdin);
        scanf("%s",nombre_jugador);

        for(i = 0; i < *numero_partidas; i++)           //comprobamos que el nombre de la partida existe
        {
            if(strcmp(nombre_jugador, datos[i].nombre_partida) == 0)
            {
                aux = 1;
                break;
            }
            else
            {
                aux = 0;
            }
        }

        if(aux == 0)
        {
            printf("nombre de la partida incorrecto\n");
            printf("vuelve a introducirlo\n");
        }
        else
        {
            printf("partida cargada correctamente\n");
        }

        system("PAUSE");

    }
    while(aux == 0);            //mientras aux valga 0 se hace el bucle y cuando cambia deja de preguntar
}

}
