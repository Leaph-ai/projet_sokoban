#include "sokoban.h"

char ** init_board(){
  char ** board;
  int i;
  int j;

  i = 0;
  board = malloc(8 * sizeof(*board)); // le tableau aura 8 lignes

  while(i < 8){
    board[i] = malloc(8 * sizeof(char)); // chaque ligne aura 8 colonnes
	j = 0;

	while(j < 8){
	  board[i][j] = ' '; // je remplis avec des espaces pourque ça s'affiche "vide" sur le terminal
	  j++;
	}

    i++;
	}

	return board;
}

void display_board(char **board, int p_rpy, int p_rpx, int p_rby, int p_rbx, int p_rgy, int p_rgx){
	int i;
	i = 0;
	system("clear");
	printf("Joueur: %d, %d\n", p_rpy, p_rpx);
	printf("Boite: %d, %d\n", p_rby, p_rbx);
	printf("Emplacement: %d, %d\n", p_rgy, p_rgx);

	printf("##########\n");
	while(i < 8)
	{
		printf("#%c%c%c%c%c%c%c%c#\n", board[i][0], board[i][1], board[i][2], board[i][3], 
		                              board[i][4], board[i][5], board[i][6], board[i][7]);

		i++;
	}
	printf("##########\n");

}

 void place_random_start(char **board, int *p_rbx, int *p_rby, int *p_rgx, int *p_rgy, int *p_rpx, int *p_rpy){
    int rbx, rby;    
    int rgx, rgy;
    int rpx, rpy;

    char box_pos = 'X';
    char goal_pos = '.';
    char player_pos = 'o';
    
    do{
    rbx = (rand() % 5) + 1;
    rby = (rand() % 5) + 1;
    rgx = rand() % 8;
    rgy = rand() % 8;
    rpx = rand() % 8;
    rpy = rand() % 8;
  	} while((rbx == rgx && rby == rgy) || (rbx == rpx && rby == rpy) || (rgx == rpx && rgy == rpy));

  	*p_rbx = rbx;
  	*p_rby = rby;
    *p_rgx = rgx;
    *p_rgy = rgy;
    *p_rpx = rpx;
    *p_rpy = rpy;

	board[rby][rbx] = box_pos;
	board[rgy][rgx] = goal_pos;
    board[rpy][rpx] = player_pos;

  }



