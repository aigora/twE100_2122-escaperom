
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
{
	int i, aux = 0;

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


int juego(char nombre_jugador[])
{
    srand (time(NULL));

    //varables para el juego en general
    int decision, decisionX;
    int nota1 = 0, llaves = 0, palanca = 0, linterna = 0, nota2 = 0;
    int control = 0, control2 = 0, control3 = 0;
    int mueres = 0, vives = 0;

    //variables codigo
    int a = 0, b = 0, c = 0, d = 0;
    int numero1, numero2, numero3, numero4, pata;
    int codigofinal = 99999, codigosecreto;

    //variables examen
    int error = 0;
    char rp;


    pata= rand () % (4-1+1)  + 1;
    numero1= rand() % (9-1+1)  + 1;
    numero2= rand() % 10;
    numero3= rand() % 10;
    numero4= rand() % 10;
    codigofinal= (numero1*1000) + (numero2*100) + (numero3*10) + numero4;


    printf(" codigo %i, pata %i.\n", codigofinal, pata);



    do
    {

        printf("\n");

        printf("Te despiertas, estás en un contenedor de carga con una luz de una bombilla muy tenue en el centro,dentro del contenedor de carga, el cual está cerrado. En el centro te encuentras una mesa con una nota, una llave y una estatuilla de la torre eiffel.\n");

        printf("Que haces?\n");

        printf(" Leer nota 1\n Coger llave 2\n Inspeccionar estatuilla 3\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)
        {
            printf("Bienvenido %s, veo que estás en una situación un poco peliaguda, pareces el rey Arturo sin sus caballeros de la mesa redonda, todo te engaña.\n", nombre_jugador);



            do
            {
                printf("\n");

                printf("te da por inspeccionar la mesa\n");

                printf("Que haces?\n");

                printf(" revisar parte isuperior 1\n revisar parte inferior 2\n revisar patas de la mesa 3\n volver atras 4\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("Encuentras un mensaje escrito a rayajos que dice: “El 11 de MAYO FUE MI NACIMIENTO, ESCRIBIRÉ ALGO MÁS SI NO HALLO LA MUERTE” ,te estremeces y buscas desesperadamente, no acabas encontrando nada y empiezas a temblar.\n");

                }
                else if(decision == 2)
                {
                    printf("Enhorabuena has encontrado un chicle ahora tienes la mano pegajosa.\n");

                }
                else if(decision == 3)
                {


                    do
                    {

                        printf("q pata miras\n");
                        printf("pata 1\n pata 2\n pata 3\n pata 4\n");
                        fflush(stdin);
                        scanf("%i", &decision);

                        if(decision == pata)
                        {
                            printf("se activa un interruptor\n");
                            nota1 = 1;
                            decision = 4;

                        }
                        else
                        {
                            printf("no hay nada\n");


                        }
                    }
                    while(nota1 != 1);

                }
                else if(decision == 4)
                {
                    printf("vuelves atras\n");
                }

                else
                {
                    printf("Opcion incorrecta\n");
                }

            }
            while(decision != 4);

        }

        else if(decision == 2)
        {
            printf("coges la llave y te pones a buscar\n");
            llaves = 1;

            do
            {
                printf("\n");

                printf(" buscar en la mesa 1\n buscar en las paredes 2\n volver atras 3\n\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("no encuentras nada\n");
                }
                else if(decision == 2)
                {
                    printf("no ves ningun agujero\n");
                }
                else if(decision == 3)
                {
                    printf("vuelves atras\n");
                    //break;
                }
                else
                {
                    printf("tecla incorrecta\n");
                }

            }
            while(decision != 3);

        }

        else if(decision == 3)
        {
            printf("es una estatua... te esperabas algo mas?\n");
        }
        else
        {
            printf("tecla incorrecta\n");
        }
        system("PAUSE");
    }
    while((decision != 1) && (nota1 != 1) );
	
	
	
}


