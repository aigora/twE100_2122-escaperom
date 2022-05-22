
typedef struct     //estructura para el nombre de la partida/jugador
{
	char nombre_partida[100];

}partida;



void menu (int *opcion);         //funcion del menu
void instrucciones (int *informacion);           //funcion de las instruciones
void nueva_partida (partida datos[], char nombre_jugador[], int *numero_partidas);            //funcion que crea una partida nueva
void cargar_partida (partida datos[], char nombre_jugador[], int *numero_partidas);           //funcion que carga partida seleccionada
int  comprobar_fichero_partidas (partida datos[], int *numero_partidas);             //funcion que comprueba si existe la partida seleccionada
