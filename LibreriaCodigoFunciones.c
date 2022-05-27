#include <time.h>
#include <stdlib.h>
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


	
    printf("\n");

    printf("Te despiertas, estás en un contenedor de carga con una luz de una bombilla muy tenue en el centro,dentro del contenedor de carga, el cual está cerrado. En el centro te encuentras una mesa con una nota, una llave y una estatuilla de la torre eiffel.\n");

    do
    { 
        printf("\nQue haces?\n");

        printf(" Leer nota\t 1\n Coger llave\t 2\n Inspeccionar estatuilla\t 3\n");

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

                printf(" revisar parte isuperior\t 1\n revisar parte inferior\t 2\n revisar patas de la mesa\t 3\n volver atras\t 4\n");

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
                        printf("\nque pata miras?\n");
                       
			printf("pata\t 1\n pata\t 2\n pata\t 3\n pata\t 4\n");
                        
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
            printf("coges la llave\n");
            llaves = 1;

            do
            {
                printf("\ndonde buscas?\n");

                printf(" buscar en la mesa\t 1\n buscar en las paredes\t 2\n volver atras\t 3\n");

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
    while((decision != 1) && (nota1 != 1));
//segunda parte



    do
    {

        printf("\n");

        printf("La puerta del contenedor se empieza a abrir... Te diriges a toda prisa hacia el exterior temiendo que se vaya a cerrar como si tuviera un temporizador. Al salir te encuentras en la proa de un barco, miras al mar, te encuentras rodeado de tiburones “Como no”, Vuelcas tu vista de vuelta al barco.\n");

        printf("Que haces?\n");

        printf(" Mirar hacia el puente de mando del capitán 1\n Ir al costado izquierdo 2\n Ir al costado derecho 3\n\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)  //Mando capitán
        {
            printf("Está vacío... Estás solo\n");

        }
        else if(decision == 2)  //Cost izq
        {
            printf("Te encuentras una compuerta\n");

            do
            {
                printf("\n");

                printf("¿Que haces?\n");

                printf(" Intentar abrirla 1\n Seguir andando 2\n Volver por donde has venido 3\n");

                fflush(stdin);

                scanf("%i", &decision);

                if (decision == 1)
                {
                    printf("No puedes abrirla\n");

                }
                else if (decision == 2)  //Seguir andando
                {
                    printf("sigues andando\n");

                    printf("No encuentras nada interesante por el camino y acabas llegando a la popa del barco. En la popa del barco lo único que te encuentras son unas cajas y el compartimento de un bote salvavidas.\n");

                    do //mirar cajas, bote o volver atrás.
                    {
                        printf("Que haces?\n");

                        printf(" Mirar cajas 1\n Mirar compartimento del bote salvavidas 2\n Volver atras 3\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if (decision == 1)
                        {
                            printf("Son cajas cerradas herméticamente las cuales no puedes abrir \n");
                        }
                        else if (decision == 2)
                        {
                            printf("Al mirar en el bote salvavidas, no encuentras ningún bote, pero si que encuentras una palanca ¿qué conveniente no? Coges la palanca.\n");
                            palanca = 1;
                        }
                        else if (decision == 3)
                        {
                            printf("Vuelves hacia atras\n");
                        }
                        else
                        {
                            printf("tecla incorrecta\n");
                        }

                    }
                    while(decision != 3);

                }
                else if (decision == 3)
                {
                    printf("Vuelves a proa\n");
                }
                else
                {
                    printf("tecla incorrecta\n");
                }

            }
            while(decision != 3);

        }
        else if(decision == 3)   //Cost Dere
        {
            printf("Te encuentras una compuerta oxidada\n");

            do
            {
                printf("\n");

                printf("¿Que haces?\n");

                printf(" Intentar abrirla 1\n Seguir andando 2\n Volver por donde has venido 3\n");

                fflush(stdin);

                scanf("%i", &decision);

                if ((decision == 1) && (palanca == 0))
                {
                    printf("No puedes abrirla. no tienes nada con que abrirla\n");
                }
                else if((decision == 1) && (palanca == 1)) //   DKIFJOESFSFHSJEFESLIFJKEJLSHCSHKCLKSDNCIJSDBCSJKCNLKCNAJHCIOAULJNC
                {
                    printf("Has conseguido abrirla con la palanca\n");
                    break;

                }

                else if (decision == 2)
                {
                    printf("sigues andando\n");

                    printf("No encuentras nada interesante por el camino y acabas llegando a la popa del barco. En la popa del barco lo único que te encuentras son unas cajas y el compartimento de un bote salvavidas.\n");

                    do //mirar cajas, bote o volver atrás.
                    {
                        printf("Que haces?\n");

                        printf(" Mirar cajas 1\n Mirar compartimento del bote salvavidas 2\n Volver atras 3\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if (decision == 1)
                        {
                            printf("Son cajas cerradas herméticamente las cuales no puedes abrir \n");
                        }
                        else if (decision == 2)
                        {
                            printf("Al mirar en el bote salvavidas, no encuentras ningún bote, pero si que encuentras una palanca ¿qué conveniente no? Coges la palanca.\n");
                            palanca = 1;
                        }
                        else if (decision == 3)
                        {
                            printf("Vuelves hacia atras\n");
                        }
                        else
                        {
                            printf("tecla incorrecta\n");
                        }

                    }
                    while(decision != 3);

                }
                else if (decision == 3)
                {
                    printf("Vuelves a proa\n");
                }
                else
                {
                    printf("Tecla incorrecta\n");
                }

            }
            while(decision != 3);

        }
        else
        {
            printf("tecla incorrecta\n");
        }

        if((decision == 1) && (palanca == 1))
        {
            control = 1;
        }
        system("PAUSE");

    }
    while ((decision != 4) && (control != 1));
//tercera parte


    do
    {
        printf("Entras al barco.\n");

        printf("Finalmente abriéndote paso tras abrir la compuerta oxidada la cual se cierra según vas pasando. Al avanzar te encuentras una trifurcación:\n");

        printf("A la izquierda es un pasillo iluminado\n");

        printf("A la derecha otro pasillo pero ves que hay unas escaleras que dirigen hacia arriba.\n");

        printf("Y si continuas unas escaleras que se notan que van hacia abajo pero estas se van sumiendo la oscuridad.\n");

        printf("Que haces?\n");

        printf(" Ir hacia la izquierda 1\n Ir hacia abajo 2\n Pasillo de la derecha 3\n");

        printf("\n");

        fflush(stdin);

        scanf("%i", &decision);

        if(decision == 1)
        {
            printf("Avanzas hasta llegar a una especie de bodega, y la cual en su interior hay unas cajas\n");

            printf("decides abrir las cajas y te encuentras con comida en mal estado, deduces que este barco ha estado inactivo mucho tiempo. También te encuentras una nota. la lees\n");

            printf("hay escrito un codigo, te lo guardas\n");

            //numero 1
            printf("1º Digito ");

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
                    printf("Algo ha ido mal");
                }
            }
            while (a != 0);

            //numero 2
            printf("2º Digito ");

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
                    printf("Algo ha ido mal");
                }
                }
                while (b != 0);

            //numero 3
            printf("3º Digito ");
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
                    printf("Algo ha ido mal");
                }
            }
            while (c != 0);

            //numero4
            printf("4º Digito ");

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
                    printf("Algo ha ido mal");
                }
            }
            while (d != 0);

            nota2 = 1;
        }
	else if((decision == 2) && (linterna == 1) && (nota2 == 1))
        {
            printf("iluminas las escaleras con la linterna y consigues llegar a una puerta. En la luerta hay un panel de lectura de codigo\n");

            do
            {
                printf("introducir el codigo?\n");

                printf("si 1\n no 2\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("introduces el codigo\n");

                    do
                    {
                        fflush(stdin);

                        scanf("%i", &codigosecreto);

                        if(codigofinal == codigosecreto)
                        {
                            printf("Prueba final:\nNo debe contestar mal mas 3 de las siguientes preguntas para sobrevivir.\n\n");

                            //pregunta 1
                            printf("¿Cual es el edificio mas alto del mundo actualmente?:\n");
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
                            printf("¿Que comida es tradicional de España?:\n");
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
                            printf("¿Que pesa mas?:\n");
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
                                printf("Que pena! Tanto esfuerzo para nada! otra vez sera.");
                                control3 = 1;
                                decision = 1;
                            }
                            else
                            {
                                printf("Enhorabuena! Pasaste tu ultima prueba, ya eres libre!");
                                control2 = 1;
                                decision = 1;
                            }
                        }
                        else
                        {
                            printf("codigo incorrecto");
                        }

                    }
                    while(codigosecreto != codigofinal);

                }
                else if(decision == 2)
                {
                    printf("tanto sufrimiento te esta afectando \n");

                    printf("intentas recordar el codigo\n");

                    //numero 1
                    printf("1º Digito ");

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
                            printf("Algo ha ido mal");
                        }
                    }
                    while (a != 0);

                    //numero 2
                    printf("2º Digito ");

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
                            printf("Algo ha ido mal");
                        }
                        }
                        while (b != 0);

                    //numero 3
                    printf("3º Digito ");
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
                            printf("Algo ha ido mal");
                        }
                    }
                    while (c != 0);

                    //numero4
                    printf("4º Digito ");

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
                            printf("Algo ha ido mal");
                        }
                    }
                    while (d != 0);
                }
                else
                {
                  printf("tecla incorrecta\n");
                }

            }
            while(decision != 1);
            decision = 2;
        }
        else if((decision == 2) && (linterna == 0) )
        {
            printf("no ves nada, ni siquiera tus esperanzas de salir de ahi, te tropiezas con las escaleras y te caes, mueres\n");

        }
        else if((decision == 2) && (linterna == 1) && (nota2 == 0))
        {
            printf("te mueres\n");

        }
	else if(decision == 3)
        {
            printf("Al subir las escaleras te encuentras en el puente de mando, te fijas bien y encuentras un compartimento y…. ¡UN ESQUELETO! Tirado te encuentras.\n");

            do
            {
                printf("¿Que haces?\n");

                printf("Acercarme al esqueleto 1\n Abrir compartimento 2\n Volver atras\n");

                printf("\n");

                fflush(stdin);

                scanf("%i", &decision);

                if(decision == 1)
                {
                    printf("Te acercas lentamente y ves que lo único que queda de él es su ropa y su forma esquelética.\n");

                    do
                    {
                        printf("¿Que haces?\n");

                        printf("Investigar esqueleto 1\n Dejar el esqueleto y regresar 2\n");

                        printf("\n");

                        fflush(stdin);

                        scanf("%i", &decision);

                        if(decision == 1)
                        {
                            printf("Al fijarte ves que el esqueleto es el capitán del barco por su gorra. Al revisar sus bolsillos lentamente tratando de conservar la poca cordura que te queda, encuentras una nota y una linterna recargable.\n");

                            do
                            {
                                printf("¿Que haces?\n");

                                printf("Recoger linterna 1\n Leer nota 2\n Salir por donde has venido 3\n");

                                printf("\n");

                                fflush(stdin);

                                scanf("%i", &decision);

                                if(decision == 1)
                                {
                                    printf("Enhorabuena %s tienes una linterna espero que sobrevivas\n", nombre_jugador);
                                    linterna = 1;
                                }
                                else if (decision == 2)
                                {
                                    printf("La nota dice: No aguanto más nose que hago aquí no puedo salir he golpeado y tratado de abrir las cajas a golpes pero nada funciona , no creo que vaya a continuar, me rindo, si lees esto dile a mi familia que el capitán Lorenzo navega hasta el final.\n");
                                }

                                else if (decision == 3)
                                {
                                    printf("Vuelves por donde has venido");
                                }
                                else
                                {
                                    printf("Tecla incorrecta\n");
                                }

                            }while(decision != 3);

                        }
                        else if (decision == 2)
                        {
                            printf("Vuelves hacia atras\n");
                            break;

                        }
                        else
                        {
                            printf("Tecla incorrecta\n");
                        }

                    }
                    while(decision != 2);

                }
                else if (decision == 2)
                {
                    printf("No encuentras nada interesante\n");

                }
                else if (decision == 3)
                {
                    printf("Vuelves hacia atras\n");
                    break;
                }
                else
                {
                    printf("Tecla incorrecta\n");
                }

            }
            while(decision != 3);
        }
        else
        {
            printf("tecla incorrecta\n");
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
        printf("Felicidades has acabado el juego con exito!\n");
        printf("...desde luego no de la mejor manera pero lo has conseguido\n");
    }
    if(vives == 1)
    {
        printf("Felicidades has acabado el juego con exito!\n");
        printf("ahora te toca ir a buscar al responsable te haya metido en ese sitio en plan pelicula de venganzas o algo\n");
    }

    system("PAUSE");


return 0;
}
