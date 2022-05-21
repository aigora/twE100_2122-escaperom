
typedef struct     //estructura para el nombre de la partida/jugador
{
	char nombre_partida[100];

}partida;



void menu (int *opcion);         //funcion del menu
void instrucciones (int *informacion);           //funcion de las instruciones
int  comprobar_fichero_partidas (partida datos[], int *numero_partidas);             //funcion que comprueba si existe la partida seleccionada
