#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

void verify_win(int table[3][3], int *pwin, int player, int *pplayer);
int selectPlayer(int *pp1, int *pp2);
void printTable(int [3][3]);
int ask_inputs(int *px, int *py, int player, int p1, int p2);
int get_answer(void);
int record_play_in_table(int table[3][3], int x, int y, int player, int p1, int p2);
void change_turn(int player, int *pplayer);
void verify_play(int x, int y, int table[3][3], int *pjugada_ok);

int main()
{
	int table[3][3];
	int *ptable[3][3];
	int player;
	int *pplayer;
	pplayer = &player;
	int p1;
	int p2;
	int *pp1;
	int *pp2;
	pp1 = &p1;
	pp2 = &p2;
	int x, y;
	int *px, *py;
	px = &x;
	py = &y;
	int win;
	int *pwin;
	pwin = &win;
	int contador;
	int jugada_ok;
	int *pjugada_ok;
	pjugada_ok = &jugada_ok;
	system("clear");
	jugada_ok = 1;
	contador = 9;
	int turno;
	turno = 1;
	/* initialize matrix */
	for (x = 0; x < 3; x++)
	{
		for (y = 0; y < 3; y ++)
		{
			table[x][y] = '.';
		}
	}
	x = 0;
	y = 0;
	win = 0;
	// select player
	player = selectPlayer(pp1, pp2);
	printf("Empieza jugador %d\n\n", player);

	while (!win && turno <= 9)
	{
		printTable(table);
		ask_inputs(px, py, player, p1, p2);
		verify_play(x, y, table, pjugada_ok);

		while(jugada_ok == 0)
		{
			system("clear");
			printTable(table);
			printf("Ingrese nuevas coordenadas\n");
			ask_inputs(px, py, player, p1, p2);
			verify_play(x, y, table, pjugada_ok);
		}
		record_play_in_table(table, x, y, player, p1, p2);
		system("clear");
		printTable(table);
		verify_win(table, pwin, player, pplayer);
		contador--;
		system("clear");
		turno++;
//printf("%d\n", player);
		//printTable(table);
	}
	if (!win && contador == 0)
	printf("Son un embole!\n\n");
	sleep(1);

//printf(" el valor de x es %d y el valor de y es %d \n", x, y);
	//printf("se ingreso la columna %d y la fila %d\n", *px, *py);
	//verify_play function
	//printf("main DATO %d GUARDADO EN MATRIZ\n", p1);
	//printf("main DATO %d GUARDADO EN MATRIZ\n", p2);

	return (0);
}
void verify_win (int table[3][3], int *pwin, int player, int *pplayer)
{
	int total = 0;
	int i, j;

	for (j = 0; j < 3; j++)
	{
		for (i = 0; i < 3; i++)
		{
			total += table[j][i];
			if (total == 264 || total == 237)
			{
				*pwin = 1;
				printf("Gano Jugador %d\n", player);
				sleep(3);
			}
		}
		total = 0;
	}
	total = 0;
	for (j = 0; j < 3; j++)
        {
                for (i = 0; i < 3; i++)
                {
                        total += table[i][j];
			if (total == 264 || total == 237)
			{
				*pwin = 1;
				printf("Gano Jugador %d\n", player);
				sleep(3);
			}
		}
                total = 0;
        }
	total = 0;
	for (i = 0; i < 3; i++)
	{
		total += table[i][i];
		if (total == 264 || total == 237)
		{
			*pwin = 1;
			printf("Gano Jugador %d\n", player);
			sleep(3);
		}
	}
	total = 0;

	for (i = 0, j = 2; i < 3; j--, i++)
	{
		total += table[i][j];
		if (total == 264 || total == 237)
                {
                        *pwin = 1;
                        printf("Gano Jugador %d\n", player);
			sleep(3);
		}
	}


	change_turn(player, pplayer);
}
void verify_play(int x, int y, int table[3][3], int *pjugada_ok)
{

	if (x <= 2 || x >= 0 || y >= 0 || y <= 2)
		if (table[x][y] != 'X' && table[x][y] != 'O')
	{
		*pjugada_ok = 1;
	}
	else
		*pjugada_ok = 0;

}


void change_turn(int player, int *pplayer)
{
	if (player == 1)
		*pplayer = 2;

	if (player == 2)
		*pplayer = 1;
}
int record_play_in_table(int table[3][3], int x, int y, int player, int p1, int p2)
{
	if (player == 1)
	{
		table[x][y] = p1;
		//printf("record DATO %d GUARDADO EN MATRIZ\n", p1);
		//printf("record DATO %d GUARDADO EN MATRIZ\n", p2);
	}
	else if(player == 2)
	{
		table[x][y] = p2;
		//printf("record DATO %d GUARDADO EN MATRIZ\n", p2);
		//printf("record DATO %d GUARDADO EN MATRIZ\n", p1);
	}
	return (1);
}
//genera player de forma random y asigna caracter a cada uno
int selectPlayer(int *pp1, int *pp2)
{
	srand(time(NULL));
	int player = rand() % 2;
	// printf( " se selecciono %d\n", player + 1);
	if (player == 0)
	{
		*pp1 = 88; // 88 = X
		*pp2 = 79; // 70 = O
		//printf("select player DATO %d GUARDADO EN MATRIZ\n", *pp1);
		//printf("select playerDATO %d GUARDADO EN MATRIZ\n", *pp2);
		return (1);
	}
	if (player == 1)
	{
		*pp1 = 88;
		*pp2 = 79;
		//printf("select playerDATO %d GUARDADO EN MATRIZ\n", *pp1);
		//printf("select playerDATO %d GUARDADO EN MATRIZ\n", *pp2);
		return (2);
	}
}
// imprime tablero
void printTable(int table[3][3])
{
	printf("   * 0 1 2\n   0 %c|%c|%c\n   1 %c|%c|%c\n   2 %c|%c|%c\n\n", table[0][0], table[0][1], table[0][2], table[1][0], table[1][1], table[1][2], table[2][0], table[2][1], table[2][2]);
}

int ask_inputs(int *px, int *py, int player, int p1, int p2)
{
	int c;
	(player == 1) ? (c = p1) : (c = p2);
	printf("Juega jugador %d '%c'\n\n", player, c);
	printf("Ingrese numero de fila:\n");
	*px = get_answer();
	printf("Ingrese numero de columna:\n");
	*py = get_answer();
	//printf("se ingreso la columna %d y la fila %d\n", px, py);
}

int get_answer(void)
{
	int c;
	int answer = 0;
	while ((c = getchar()) != EOF && c != '\n')
	{
		answer = c - '0';
	}
	return answer;
}
