#include <stdio.h>
#include <string.h>
#include "LibreriaFunciones.h"
#define limite_partidas 100



int main()
{
    int opciones, info;

    char jugador[100];


    FILE *ppartidas;            //poner nombre adecuado para las partidas
    int NP = 0;             //contador numero de partidas
    partida nombre[limite_partidas];


    printf("WARNING: Para que el juego funcione correctamente se debe crear en tu equipo un fichero / documento de texto llamado NOMBRES_PARTIDAS vacio\n");

    system("PAUSE");            //pausa del programa hasta que el usuario pulsa una tecla para continuar



    do
    {
        menu(&opciones);

        switch(opciones)
        {
            case 1:
                if(comprobar_fichero_partidas(nombre, &NP) == 0)  //comprueba que exista el fichero con las partidas
                {
                    return 0;
                }
                else
                {
                    nueva_partida(nombre, jugador, &NP);   //crea una partida nueva
                }
                break;

            case 2:
                if(comprobar_fichero_partidas(nombre, &NP) == 0)    //comprueba que exista el fichero con las partidas
				{
					return 0;
				}
				else
				{
					cargar_partida(nombre, jugador, &NP);    //carga una partida creada
				}
                break;

            case 3:
                instrucciones(&info);           //instrucciones
                break;

            case 4:
                printf("juego terminado\n");            //salir del juego
                break;

            default:
                printf("Opcion incorrecta\n");
				break;
        }

        if(opciones == 1 || opciones == 2)          //llamada al juego
        {
            juego(jugador);
        }

    }
    while(opciones != 4);


return 0;
}
