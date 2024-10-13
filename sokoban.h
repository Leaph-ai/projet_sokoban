#ifndef __SOKOBAN_H__
#define __SOKOBAN_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


	/*board.c*/
char ** init_board();
void display_board(char **board, int p_rpy, int p_rpx, int p_rby, int p_rbx, int p_rgy, int p_rgx);
void place_random_start(char **board,int *p_rbx,int *p_rby, int *p_rgx, int *p_rgy, int *p_rpx, int *p_rpy);
void player_move(char **board, int *p_rpy, int *p_rpx, int *p_rby, int *p_rbx, char move);


#endif