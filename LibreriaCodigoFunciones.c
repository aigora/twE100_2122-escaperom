#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "LibreriaCodigoFunciones.h"
#include <locale.h>

void menu (int *opcion)
{
        setlocale(LC_CTYPE,"spanish");
	
	system("cls");  //Borrar la pantalla 
	
	printf("Bienvenido a EscapeROM\n");

	printf("Selecciona una opción:\n");

	printf(" 1\tNueva Partida\n");
	printf(" 2\tCargar Partida\n");
	printf(" 3\tIntrucciones\n");
	printf(" 4\tSalir\n");

	fflush(stdin);

	scanf("%i", &*opcion);
}

void instrucciones (int *informacion)
{
	setlocale(LC_CTYPE,"spanish");
	
	printf("INSTRUCCIONES DEL ESCAPEROM:\n\n");
        printf("A lo largo del juego, se le irá mostrando una historia donde usted es el protagonista.\n");
        printf("Dicha historia esta dividida en 3 partes, en las cuales hay diferentes sucesos, donde usted podrá tomar sus propias decisiones.\n");
        printf("Para elegir dichos sucesos, solo será necesario presionar la tecla del número según el suceso que quiera que ocurra a continuación.\n");
        printf("Como aclaración del juego, dispones de un tiempo ilimitado para realizar toda la historia.\n");

        system("PAUSE");

}

int  comprobar_fichero_partidas (partida datos[], int *numero_partidas)
{
	setlocale(LC_CTYPE,"spanish");
	
	FILE *pleer ;
	int i=0;

	pleer = fopen("nombredelficheroejemplo.txt", "r");   //para abrir el fichero

	if(pleer == NULL)      //comprobacion de que existe el fichero
	{
		printf("No se ha podido encontrar el fichero.\n");
		printf("Comprueba que el nombre del fichero está escrito correctamente.\n");
     	        return 0;
        }

        while(fscanf(pleer, "%s", &datos[i].nombre_partida) != EOF)    //comprueba o cuenta cuantas partidas hay en el fichero guardadas y se guarda en un vector contador
        {
                i++;
        }
        *numero_partidas = i;

        fclose(pleer);
        return 1;
}

void nueva_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{ 
	setlocale(LC_CTYPE,"spanish");
	
	FILE *pescribir; 
	int i, aux = 0;

        do          //se comprueba que el nombre de la partida es el correcto y no existe otro igual
        {
		printf("Nombre de la partida:\n");

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
			printf("El nombre de la partida ya existe, inserte otro nombre:\n");
			system("PAUSE");
		}
		else
       		{
			printf("Nombre de la partida guardado correctamente.\n");
			strcpy(datos[*numero_partidas].nombre_partida, nombre_jugador);
		}
    	}
    	while(aux == 1);

    	pescribir = fopen("NOMBRES_PARTIDA.txt", "w");

    	for(i = 0; i <= *numero_partidas; i++)          //se añaden en el fichero los datos introducidos
    	{
       		fprintf(pescribir, "%s\n", datos[i].nombre_partida);
    	}

   	fclose(pescribir);
   	system("PAUSE");

}

void cargar_partida (partida datos[], char nombre_jugador[], int *numero_partidas)
{
	setlocale(LC_CTYPE,"spanish");
	
	int i, aux = 0;

    	printf("Cargar partida.\n");

    	do              //introduce el nombre de la partida y
    	{
       		printf("Nombre de la partida:\n");
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
                	printf("Nombre de la partida incorrecto.\n");
            		printf("Vuelve a introducirlo:\n");
        	}
        	else
        	{
            		printf("Partida cargada correctamente.\n");
        	}

        	system("PAUSE");

    	}
    	while(aux == 0);            //mientras aux valga 0 se hace el bucle y cuando cambia deja de preguntar


}


int juego(char nombre_jugador[])
{
    setlocale(LC_CTYPE,"spanish");
	
    srand (time(NULL));

    //variables para el juego en general
    int decision;
    int nota1 = 0, llaves = 0, palanca = 0, linterna = 0, nota2 = 0;
    int control = 0, control2 = 0, control3 = 0;
    int mueres = 0, vives = 0;

    //variables código secreto
    int a = 0, b = 0, c = 0, d = 0;
    int numero1, numero2, numero3, numero4, pata;
    int codigofinal = 99999, codigosecreto;

    //variables prueba final
    int error = 0;
    char rp;

    //para el código de las pruebas que se realizan en el juego
    pata= rand () % (4-1+1)  + 1;
    numero1= rand() % (9-1+1)  + 1;
    numero2= rand() % 10;
    numero3= rand() % 10;
    numero4= rand() % 10;
    codigofinal= (numero1*1000) + (numero2*100) + (numero3*10) + numero4;


    //printf(" codigo %i, pata %i.\n", codigofinal, pata);		//trucos


	
    printf("\n");

    printf("Te despiertas un poco desorientado.\n");
    printf("Observas que, gracias a la luz muy tenue de una bombilla situada en el centro, hay una mesa con una nota, una llave y una estatuilla de la torre eiffel.\n");
    printf("Además, fijandote en las paredes de tu alrededor, te das cuenta de que estás dentro de un contenedor de carga, encerrado.\n");
	
    do
    { 
        printf("\n¿Qué haces?\n");

        printf(" 1\tLeer nota.\n 2\tCoger llave.\n 3\tInspeccionar estatuilla.\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)
        {
            printf("Bienvenido %s, veo que estás en una situación un poco peliaguda, pareces el Rey Arturo sin sus caballeros de la mesa redonda, todo te engaña.\n", nombre_jugador);



            do
            {
                printf("\n");

                printf("Te da por inspeccionar la mesa.\n");

                printf("¿Qué haces?\n");
		    
		printf("Revisar parte superior.      1\n");
		printf("Revisar parte inferior.      2\n");
		printf("Revisar patas de la mesa.    3\n");
		printf("Volver atrás.                4\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("Encuentras un mensaje escrito a rayajos que dice: \"EL 11 DE MAYO FUE MI NACIMIENTO, ESCRIBIRÉ ALGO MÁS SI NO HAYO LA MUERTE\", te estremeces y buscas desesperadamente algo con lo que poder abrirte paso, no acabas encontrando nada y empiezas a temblar.\n");

                }
                else if(decision == 2)
                {
                    printf("Enhorabuena has encontrado un chicle, ahora tienes la mano pegajosa.\n");

                }
                else if(decision == 3)
                {

                    do
                    {
                        printf("\n¿Qué pata miras?\n");
                       
			printf(" Pata\t1\n Pata\t2\n Pata\t3\n Pata\t4\n");
                        
			fflush(stdin);
                       
			scanf("%i", &decision);

                        if(decision == pata)
                        {
                            printf("Se activa un interruptor.\n");
                            nota1 = 1;
                            decision = 4;
                        }
                        else
                        {
                            printf("No hay nada.\n");
                        }
                    }
                    while(nota1 != 1);

                }
                else if(decision == 4)
                {
                    printf("Vuelves atrás.\n");
                }

                else
                {
                    printf("Opción incorrecta.\n");
                }

            }
            while(decision != 4);

        }

        else if(decision == 2)
        {
            printf("Coges la llave.\n");
            llaves = 1;

            do
            {
                printf("\n¿Dónde buscas?\n");

                printf(" Buscar en la mesa.        1\n");
		printf(" Buscar en las paredes.    2\n");
		printf(" Volver atras.             3\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("No encuentras nada.\n");
                }
                else if(decision == 2)
                {
                    printf("Bonita mancha.\n");
                }
                else if(decision == 3)
                {
                    printf("Vuelves atras.\n");
                }
                else
                {
                    printf("Tecla incorrecta.\n");
                }

            }
            while(decision != 3);

        }

        else if(decision == 3)
        {
            printf("Es una estatua... ¿te esperabas algo más?\n");
        }
        else
        {
            printf("Tecla incorrecta.\n");
        }
        system("PAUSE");
    }
    while((decision != 1) && (nota1 != 1));

//segunda parte
	
    printf("\n");

    printf("La puerta del contenedor se empieza a abrir...\"¿Estoy salvado?\", piensas.\n");
    printf("Te diriges a toda prisa hacia el exterior temiendo que se vaya a cerrar como si tuviera un temporizador.\n");
    printf("Al salir te encuentras en la proa de un barco, miras al mar, te encuentras rodeado de tiburones \"Como no\", y viendo que las desgracias no terminan, vuelcas tu vista de vuelta al barco.\n");
	
    do
    {

        printf("\n¿Qué haces?\n");

        printf(" Mirar hacia el puente de mando del capitán.   1\n");
	printf(" Ir a babor.                                   2\n");
	printf(" Ir a estribor.                                3\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)  //Mando capitán
        {
            printf("Está vacío... Estás solo...\n");

        }
        else if(decision == 2)  //Costado izquierdo (babor)
        {
            printf("Te encuentras una compuerta.\n");

            do
            {
                printf("\n");

                printf("¿Qué haces?\n");

                printf(" Intentar abrirla.               1\n");
		printf(" Seguir andando.                 2\n");
		printf(" Volver por donde has venido.    3\n");

                fflush(stdin);

                scanf("%i", &decision);

                if (decision == 1)
                {
                    printf("No puedes abrirla.\n");

                }
                else if (decision == 2)  //Seguir andando
                {
                    printf("Sigues andando.\n");

                    printf("No encuentras nada interesante por el camino y acabas llegando a la popa del barco. En la popa del barco, lo único que te encuentras son unas cajas y el compartimento de un bote salvavidas.\n");

                    do //mirar cajas, bote o volver atrás.
                    {
                        printf("\n¿Qué haces?\n");

                        printf(" Mirar cajas\t 1\n Mirar compartimento del bote salvavidas\t 2\n Volver atras\t 3\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if (decision == 1)
                        {
                            printf("Son cajas cerradas herméticamente, las cuales no puedes abrir.\n");
                        }
                        else if (decision == 2)
                        {
                            printf("Al mirar en el compartimento de los botes, no encuentras ninguno, pero si que encuentras una palanca, ¿qué conveniente no?\n \"Coges la palanca.\"\n");
                            palanca = 1;
                        }
                        else if (decision == 3)
                        {
                            printf("Vuelves hacia atrás.\n");
                        }
                        else
                        {
                            printf("Tecla incorrecta.\n");
                        }

                    }
                    while(decision != 3);

                }
                else if (decision == 3)
                {
                    printf("Vuelves a proa.\n");
                }
                else
                {
                    printf("Tecla incorrecta.\n");
                }

            }
            while(decision != 3);

        }
        else if(decision == 3)   //Costado derecho (estribor)
        {
            printf("Te encuentras una compuerta oxidada.\n");

            do
            {
                printf("\n");

                printf("¿Qué haces?\n");

                printf(" Intentar abrirla\t 1\n Seguir andando\t 2\n Volver por donde has venido\t 3\n");

                fflush(stdin);

                scanf("%i", &decision);

                if ((decision == 1) && (palanca == 0))
                {
                    printf("No puedes abrirla. \"¿Se podrá abrir con algo?\", piensas.\n");
                }
                else if((decision == 1) && (palanca == 1)) 
                {
                    printf("Has conseguido abrirla con la palanca.\n");
                    break;

                }

                else if (decision == 2)
                {
                    printf("Sigues andando.\n");

                    printf("No encuentras nada interesante por el camino y acabas llegando a la popa del barco. En la popa del barco lo único que te encuentras son unas cajas y el compartimento de un bote salvavidas.\n");

                    do //mirar cajas, bote o volver atrás.
                    {
                        printf("\n¿Qué haces?\n");

                        printf(" Mirar cajas\t 1\n Mirar compartimento del bote salvavidas\t 2\n Volver atras\t 3\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if (decision == 1)
                        {
                            printf("Son cajas cerradas herméticamente, las cuales no puedes abrir. \n");
                        }
                        else if (decision == 2)
                        {
                            printf("Al mirar en el compartimento de los botes, no encuentras ninguno, pero si que encuentras una palanca, ¿qué conveniente no?\n \"Coges la palanca.\"\n");
                            palanca = 1;
                        }
                        else if (decision == 3)
                        {
                            printf("Vuelves hacia atras.\n");
                        }
                        else
                        {
                            printf("Tecla incorrecta.\n");
                        }

                    }
                    while(decision != 3);

                }
                else if (decision == 3)
                {
                    printf("Vuelves a proa.\n");
                }
                else
                {
                    printf("Tecla incorrecta.\n");
                }

            }
            while(decision != 3);

        }
        else
        {
            printf("Tecla incorrecta.\n");
        }

        if((decision == 1) && (palanca == 1))
        {
            control = 1;
        }
        system("PAUSE");

    }
    while ((decision != 4) && (control != 1));
	
//tercera parte

    printf("Entras al barco.\n");

    printf("Finalmente abriéndote paso tras abrir la compuerta oxidada, la cual se cierra según vas pasando. Al avanzar te encuentras una trifurcación:\n");
    
    printf("A la izquierda, ves un pasillo iluminado.\n");

    printf("A la derecha, ves otro, pero observas que hay unas escaleras que te dirigen hacia arriba.\n");

    printf("Y si continuas, unas escaleras que se notan que van hacia abajo, pero estas se van sumiendo en la oscuridad.\n");
	
    do
    {
        printf("\n¿Qué haces?\n");

        printf(" Ir hacia la izquierda\t 1\n Ir hacia abajo\t 2\n Pasillo de la derecha\t 3\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)
        {
            printf("Avanzas hasta llegar a una especie de bodega, la cual, tiene en su interior unas cajas.\n");

            printf("Decides abrir las cajas y te encuentras con comida en mal estado, deduciendo así que este barco ha estado inactivo mucho tiempo.\n");

            printf("Además, te encuentras una nota. AL leerla, te das cuenta de que en vez de un mensaje, hay escrito un código y decides guardatelo.\n");

            //numero 1
            printf("1er Dígito: ");

            do
            {
                if(numero1==0)
                {
                    printf("(23+100)*0=X\n");
                }
                else if (numero1==1)
                {
                    printf("19-15-3=X\n");
                }
                else if (numero1==2)
                {
                    printf("12-(2*5)=X\n");
                }
                else if (numero1==3)
                {
                    printf("12-(3*3)=X\n");
                }
                else if (numero1==4)
                {
                    printf("1*3+1=X\n");
                }
                else if (numero1==5)
                {
                    printf("15/3 + 0=X\n");
                }
                else if (numero1==6)
                {
                    printf("2*2+2=X\n");
                }
                else if (numero1==7)
                {
                    printf("12/4 +4=X\n");
                }
                else if (numero1==8)
                {
                printf("2+2+2+2=X\n");
                }
                else if (numero1==9)
                {
                    printf("2+2+3+2=X\n");
                }
                else
                {
                    printf("Algo ha ido mal.");
                }
            }
            while (a != 0);

            //numero 2
            printf("2do Dígito: ");

            do
            {
                if(numero2==0)
                {
                    printf("(23+100)*0=X\n");
                }
                else if (numero2==1)
                {
                    printf("19-15-3=X\n");
                }
                else if (numero2==2)
                {
                    printf("12-(2*5)=X\n");
                }
                else if (numero2==3)
                {
                    printf("12-(3*3)=X\n");
                }
                else if (numero2==4)
                {
                    printf("1*3+1=X\n");
                }
                else if (numero2==5)
                {
                    printf("15/3 + 0=X\n");
                }
                else if (numero2==6)
                {
                    printf("2*2+2=X\n");
                }
                else if (numero2==7)
                {
                    printf("12/4 +4=X\n");
                }
                else if (numero2==8)
                {
                    printf("2+2+2+2=X\n");
                }
                else if (numero2==9)
                {
                    printf("2+2+3+2=X\n");
                }
                else
                {
                    printf("Algo ha ido mal.");
                }
                }
                while (b != 0);

            //numero 3
            printf("3er Dígito: ");
            do
            {
                if(numero3==0)
                {
                    printf("(23+100)*0=X\n");
                }
                else if (numero3==1)
                {
                    printf("19-15-3=X\n");
                }
                else if (numero3==2)
                {
                    printf("12-(2*5)=X\n");
                }
                else if (numero3==3)
                {
                    printf("12-(3*3)=X\n");
                }
                else if (numero3==4)
                {
                    printf("1*3+1=X\n");
                }
                else if (numero3==5)
                {
                    printf("15/3 + 0=X\n");
                }
                else if (numero3==6)
                {
                    printf("2*2+2=X\n");
                }
                else if (numero3==7)
                {
                    printf("12/4 +4=X\n");
                }
                else if (numero3==8)
                {
                    printf("2+2+2+2=X\n");
                }
                else if (numero3==9)
                {
                    printf("2+2+3+2=X\n");
                }
                else
                {
                    printf("Algo ha ido mal.");
                }
            }
            while (c != 0);

            //numero4
            printf("4to Dígito: ");

            do
            {
                if(numero4==0)
                {
                    printf("(23+100)*0=X\n");
                }
                else if (numero4==1)
                {
                    printf("19-15-3=X\n");
                }
                else if (numero4==2)
                {
                    printf("12-(2*5)=X\n");
                }
                else if (numero4==3)
                {
                    printf("12-(3*3)=X\n");
                }
                else if (numero4==4)
                {
                    printf("1*3+1=X\n");
                }
                else if (numero4==5)
                {
                    printf("15/3 + 0=X\n");
                }
                else if (numero4==6)
                {
                    printf("2*2+2=X\n");
                }
                else if (numero4==7)
                {
                    printf("12/4 +4=X\n");
                }
                else if (numero4==8)
                {
                    printf("2+2+2+2=X\n");
                }
                else if (numero4==9)
                {
                    printf("2+2+3+2=X\n");
                }
                else
                {
                    printf("Algo ha ido mal.");
                }
            }
            while (d != 0);

            nota2 = 1;
        }
	else if((decision == 2) && (linterna == 1) && (nota2 == 1))
        {
            printf("Iluminas las escaleras con la linterna y consigues llegar a una puerta. En la puerta hay un panel de lectura de código.\n");

            do
            {
                printf("\n¿Quieres introducir el código?\n");

                printf(" si\t 1\n no\t 2\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("Introduce el codigo:\n");

                    do
                    {
                        fflush(stdin);

                        scanf("%i", &codigosecreto);

                        if(codigofinal == codigosecreto)
                        {
                            printf("Prueba final:\nNo debe contestar mal más 3 de las siguientes preguntas para poder escapar, o sino morirás.\n\n");

                            //pregunta 1
                            printf("¿Cuál es el edificio más alto del mundo actualmente?:\n");
                            printf("a - Empire State (EEUU)\n");
                            printf("b - Burj Khalifa (Arabia Saudi)\n");
                            printf("c - Torre Iberdrola (España)\n");

                            scanf(" %c", &rp);

                            if(rp == 'b')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                                printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                                error++;
                            }

                            //pregunta 2
                            fflush(stdin);
                            printf("¿Qué comida es tradicional de España?:\n");
                            printf("a - Paella\n");
                            printf("b - Sushi\n");
                            printf("c - Hamburguesa\n");

                            scanf(" %c", &rp);

                            if(rp == 'a')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                                printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                                error++;
                            }

                            //pregunta 3
                            fflush(stdin);
                            printf("¿Qué pesa más?:\n");
                            printf("a - un kilo de acero\n");
                            printf("b - un kilo de plumas\n");
                            printf("c - pesan lo mismo\n");

                            scanf(" %c", &rp);

                            if(rp == 'c')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                                printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                                error++;
                            }

                            //pregunta 4
                            fflush(stdin);
                            printf("¿Cual es el oceano mas grande del mundo?:\n");
                            printf("a - Oceano Atlantico\n");
                            printf("b - Oceano Pacifico\n");
                            printf("c - Oceano Indico\n");

                            scanf(" %c", &rp);

                            if(rp == 'b')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                                printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                                error++;
                            }

                            //pregunta 5
                            fflush(stdin);
                            printf("Si 60 es el 100%, ¿cuanto es el 90%?:\n");
                            printf("a - 50\n");
                            printf("b - 48\n");
                            printf("c - 54\n");

                            scanf(" %c", &rp);

                            if(rp == 'c')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                                printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                                error++;
                            }

                            //pregunta 6
                            fflush(stdin);
                            printf("¿Cual es la ciudad mas grande del mundo?:\n");
                            printf("a - Tokio (Japon)\n");
                            printf("b - Nueva York (EEUU)\n");
                            printf("c - Madrid (España)\n");

                            scanf(" %c", &rp);

                            if(rp == 'a')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                               printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                               error++;
                            }

                            //pregunta 7
                            fflush(stdin);
                            printf("¿Quien es el autor de la frase: \"pienso, luego existo\"?:\n");
                            printf("a - Platon\n");
                            printf("b - Descartes\n");
                            printf("c - Galileo\n");

                            scanf(" %c", &rp);

                            if(rp == 'b')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                               printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                               error++;
                            }

                            //pregunta 8
                            fflush(stdin);
                            printf("¿Cuantos decimales tiene el numero pi?:\n");
                            printf("a - infinitos\n");
                            printf("b - mil\n");
                            printf("c - veinte\n");

                            scanf(" %c", &rp);

                            if(rp == 'a')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                               printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                               error++;
                            }

                            //pregunta 9
                            fflush(stdin);
                            printf("¿cuanto tiempo tarda la la luz del sol en llegar a la tierra?:\n");
                            printf("a - 10 horas\n");
                            printf("b - 1 dia\n");
                            printf("c - 8 minutos\n");

                            scanf(" %c", &rp);

                            if(rp == 'c')
                            {
                                printf("Respuesta correcta!\n\nSiguiente pregunta:\n");
                            }
                            else
                            {
                               printf("Respuesta incorrecta!\n\nSiguiente pregunta:\n");
                               error++;
                            }

                            //pregunta 10
                            fflush(stdin);
                            printf("¿Cual es la capital de Australia?:\n");
                            printf("a - Canberra\n");
                            printf("b - Sydney\n");
                            printf("c - Perth\n");

                            scanf(" %c", &rp);

                            if(rp =='a')
                            {
                                printf("Respuesta correcta!\n\n");
                            }
                            else
                            {
                               printf("Respuesta incorrecta!\n\n");
                               error++;
                            }

                            //Errores y decision final
                            printf("Has tenido un total de %i errores\n", error);

                            if(error >= 3)
                            {
                                printf("Deberías mirarte unos cuantos vídeos sobre cultura general, ¡MÁQUINA!\n");
                                control3 = 1;
                                decision = 1;
                            }
                            else
                            {
                                printf("Enhorabuena! No te quejes, que no ha sido para tanto, ¡CRACK!\n");
                                control2 = 1;
                                decision = 1;
                            }
                        }
                        else
                        {
                            printf("Código incorrecto.");
                        }

                    }
                    while(codigosecreto != codigofinal);

                }
                else if(decision == 2)
                {
                    printf("Tanto sufrimiento te esta afectando.\n");

                    printf("Intentas recordar el código.\n");

                    //numero 1
                    printf("1er Dígito: ");

                    do
                    {
                        if(numero1==0)
                        {
                            printf("(23+100)*0=X\n");
                        }
                        else if (numero1==1)
                        {
                            printf("19-15-3=X\n");
                        }
                        else if (numero1==2)
                        {
                            printf("12-(2*5)=X\n");
                        }
                        else if (numero1==3)
                        {
                            printf("12-(3*3)=X\n");
                        }
                        else if (numero1==4)
                        {
                            printf("1*3+1=X\n");
                        }
                        else if (numero1==5)
                        {
                            printf("15/3 + 0=X\n");
                        }
                        else if (numero1==6)
                        {
                            printf("2*2+2=X\n");
                        }
                        else if (numero1==7)
                        {
                            printf("12/4 +4=X\n");
                        }
                        else if (numero1==8)
                        {
                        printf("2+2+2+2=X\n");
                        }
                        else if (numero1==9)
                        {
                            printf("2+2+3+2=X\n");
                        }
                        else
                        {
                            printf("Algo ha ido mal.");
                        }
                    }
                    while (a != 0);

                    //numero 2
                    printf("2do Dígito: ");

                    do
                    {
                        if(numero2==0)
                        {
                            printf("(23+100)*0=X\n");
                        }
                        else if (numero2==1)
                        {
                            printf("19-15-3=X\n");
                        }
                        else if (numero2==2)
                        {
                            printf("12-(2*5)=X\n");
                        }
                        else if (numero2==3)
                        {
                            printf("12-(3*3)=X\n");
                        }
                        else if (numero2==4)
                        {
                            printf("1*3+1=X\n");
                        }
                        else if (numero2==5)
                        {
                            printf("15/3 + 0=X\n");
                        }
                        else if (numero2==6)
                        {
                            printf("2*2+2=X\n");
                        }
                        else if (numero2==7)
                        {
                            printf("12/4 +4=X\n");
                        }
                        else if (numero2==8)
                        {
                            printf("2+2+2+2=X\n");
                        }
                        else if (numero2==9)
                        {
                            printf("2+2+3+2=X\n");
                        }
                        else
                        {
                            printf("Algo ha ido mal.");
                        }
                        }
                        while (b != 0);

                    //numero 3
                    printf("3er Dígito: ");
                    do
                    {
                        if(numero3==0)
                        {
                            printf("(23+100)*0=X\n");
                        }
                        else if (numero3==1)
                        {
                            printf("19-15-3=X\n");
                        }
                        else if (numero3==2)
                        {
                            printf("12-(2*5)=X\n");
                        }
                        else if (numero3==3)
                        {
                            printf("12-(3*3)=X\n");
                        }
                        else if (numero3==4)
                        {
                            printf("1*3+1=X\n");
                        }
                        else if (numero3==5)
                        {
                            printf("15/3 + 0=X\n");
                        }
                        else if (numero3==6)
                        {
                            printf("2*2+2=X\n");
                        }
                        else if (numero3==7)
                        {
                            printf("12/4 +4=X\n");
                        }
                        else if (numero3==8)
                        {
                            printf("2+2+2+2=X\n");
                        }
                        else if (numero3==9)
                        {
                            printf("2+2+3+2=X\n");
                        }
                        else
                        {
                            printf("Algo ha ido mal.");
                        }
                    }
                    while (c != 0);

                    //numero4
                    printf("4to Dígito: ");

                    do
                    {
                        if(numero4==0)
                        {
                            printf("(23+100)*0=X\n");
                        }
                        else if (numero4==1)
                        {
                            printf("19-15-3=X\n");
                        }
                        else if (numero4==2)
                        {
                            printf("12-(2*5)=X\n");
                        }
                        else if (numero4==3)
                        {
                            printf("12-(3*3)=X\n");
                        }
                        else if (numero4==4)
                        {
                            printf("1*3+1=X\n");
                        }
                        else if (numero4==5)
                        {
                            printf("15/3 + 0=X\n");
                        }
                        else if (numero4==6)
                        {
                            printf("2*2+2=X\n");
                        }
                        else if (numero4==7)
                        {
                            printf("12/4 +4=X\n");
                        }
                        else if (numero4==8)
                        {
                            printf("2+2+2+2=X\n");
                        }
                        else if (numero4==9)
                        {
                            printf("2+2+3+2=X\n");
                        }
                        else
                        {
                            printf("Algo ha ido mal.");
                        }
                    }
                    while (d != 0);
                }
                else
                {
                  printf("Tecla incorrecta\n");
                }

            }
            while(decision != 1);
            decision = 2;
        }
        else if((decision == 2) && (linterna == 0) )
        {
            printf("No ves nada, ni siquiera tus esperanzas de salir de ahí, te tropiezas con las escaleras y te caes, mueres\n");

        }
        else if((decision == 2) && (linterna == 1) && (nota2 == 0))
        {
            printf("Te adentras en la oscuridad con la linterna. Notas que algo te observa pero no le prestas atención,\n");
	    printf("hasta que escuchas un ruido por detrás tuyo, cuando te das la vuelta te quedas congelado al ver una\n"); 
	    printf("silueta para nada semejante a lo que puede llegar a ser una persona... No creo que sea necesario decir\n");
	    printf("como terminas, pero jaja nada bien.\n");

        }
	else if(decision == 3)
        {
            printf("Al subir las escaleras, te encuentras en el puente de mando, te fijas bien y encuentras un compartimento y ... ¡UN ESQUELETO!\n");

            do
            {
                printf("\n¿Qué haces?\n");

                printf(" Acercarme al esqueleto\t 1\n Abrir compartimento\t 2\n Volver atras\t 3\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("Te acercas lentamente y ves que lo único que queda de él, es su ropa y su forma esquelética.\n");

                    do
                    {
                        printf("\n¿Qué haces?\n");

                        printf(" Investigar esqueleto\t 1\n Dejar el esqueleto y regresar\t 2\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if(decision == 1)
                        {
                            printf("Al fijarte ves que el esqueleto es el capitán del barco, por su gorra. Al revisar sus bolsillos lentamente tratando de conservar la poca cordura que te queda, encuentras una nota y una linterna recargable.\n");

                            do
                            {
                                printf("\n¿Qué haces?\n");

                                printf(" Recoger linterna\t 1\n Leer nota\t 2\n Salir por donde has venido\t 3\n");

                                printf("\n");

                                fflush(stdin);

                                scanf("%i", &decision);

                                if(decision == 1)
                                {
                                    printf("Enhorabuena %s, tienes una linterna. Espero que sobrevivas, utlizala bien.\n", nombre_jugador);
                                    linterna = 1;
                                }
                                else if (decision == 2)
                                {
                                    printf("La nota dice:\n\"No aguanto más, no se que hago aquí, no puedo salir.\nHe tratado de abrir las cajas pero nada funciona, no creo que vaya a continuar, me rindo.\nSi lees esto dile a mi familia que el capitán Lorenzo navega hasta el final.\n");
                                }

                                else if (decision == 3)
                                {
                                    printf("Vuelves por donde has venido.");
                                }
                                else
                                {
                                    printf("Tecla incorrecta.\n");
                                }

                            }while(decision != 3);

                        }
                        else if (decision == 2)
                        {
                            printf("Vuelves hacia atras.\n");
                            break;

                        }
                        else
                        {
                            printf("Tecla incorrecta.\n");
                        }

                    }
                    while(decision != 2);

                }
                else if (decision == 2)
                {
                    printf("No encuentras nada interesante.\n");

                }
                else if (decision == 3)
                {
                    printf("Vuelves hacia atras.\n");
                    break;
                }
                else
                {
                    printf("Tecla incorrecta.\n");
                }

            }
            while(decision != 3);
        }
        else
        {
            printf("Tecla incorrecta.\n");
        }


        if((decision == 2) && (linterna == 0))
        {
            mueres = 1;
        }
        if((decision == 2) && (codigosecreto == codigofinal) && (control3 == 1))
        {
            mueres = 1;
        }
        if((decision == 2) && (linterna == 1) && (nota2 == 0))
        {
            mueres = 1;
        }
        if((decision == 2) && (codigosecreto == codigofinal) && (control2 == 1))
        {
            vives = 1;
        }



        system("PAUSE");
    }
    while((decision != 2) ||  ((decision != 2) && (mueres != 1)) ||  ((decision != 2) && (vives != 1)) );

    if(mueres == 1)
    {
        printf("\n¡Felicidades, has acabado el juego!\n");
        printf("...desde luego no de la mejor manera pero lo has conseguido.\n");
	printf("¡Te recomiendo que lo vuelvas a intentar!");
    }
    if(vives == 1)
    {
        printf("\n¡Felicidades, has acabado el juego con éxito!\n");
        printf("...ahora te toca ir a buscar al responsable que te haya metido en este sitio en plan película de venganza o algo\n");
    }

    system("PAUSE");


return 0;
}
