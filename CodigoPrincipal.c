#include <stdio.h>
#include <string.h>
#include "LibreriaCodigoFunciones.h"
#define limite_partidas 100



int main()
{
    int opciones, info;



/////falta crear los nombres que iran en el main y colocarlos en las llamadas a las funciones

    char jugador[100];



    FILE * pv;  //poner nombre adecuado para las partidas
    int NP = 0;   //contador numero de partidas
    partida nombre[limite_partidas];



    printf("WARNING: Para que el juego funcione correctamente se debe crear en tu equipo un fichero / documento de texto llamado NOMBRES_PARTIDAS vacio\n");

    system("PAUSE");



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
                    juego();
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
                instrucciones(&info);
                break;

            case 4:
                    printf("juego terminado\n");
                    break;

            default:
                printf("Opcion incorrecta\n");
				break;
        }
    }
    while(opciones != 4);






return 0;
}
