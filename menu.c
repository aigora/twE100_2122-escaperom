#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, eleccion1;
    char eleccion2;

    do                              //opciones del menu principal
    {
        printf("\n");
        printf("1. Nueva partida\n" );
        printf("2. Continuar partida\n");
        printf("3. Salir\n" );
        printf("\n");

        do                                   //selecion de opciones
        {
            printf("Selecciona la opcion 1, 2 o 3: ");
            scanf("%d", &eleccion1);

        }
        while (eleccion1 < 1 || eleccion1 > 3);

        switch (eleccion1)
        {
            case 1:               //envia a funcion o donde sea para empezar el juego
                printf("");
                scanf("%d", &n);
                printf("");
            break;

            case 2:                //envia al ultimo punto de guardado
                printf("");
                scanf("%d", &n);
                printf("");
            break;

            case 3:                 //te vuelve a preguntar por si no estas seguro
                do                                   //selecion de opciones
                {
                    printf("Esta seguro que quieres salir? SI/NO ");
                    scanf("%c", &eleccion2);

                }
                while (eleccion1 == 'SI' || eleccion1 == 'NO');

                switch (eleccion2)
                {
                    case 'SI':              //termina y sale del juego

                    break;

                    case 'NO':              //vuelve al menu principal

                    break;

                }

                printf("");
            break;
         }

    }
    while (eleccion1 != 3);

return 0;
}
