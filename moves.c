#include "sokoban.h"

void player_move(char **board, int *p_rpy, int *p_rpx, int *p_rby, int *p_rbx, char move){

	if (move == 'z' && *p_rpy > 0) {
      board[*p_rpy][*p_rpx] = ' ';
      *p_rpy -= 1;
      if ((*p_rpy == *p_rby) && (*p_rpx == *p_rbx)) { //si les coordonnées du player et de la boîte sont les mêmes
        *p_rby -= 1;
        board[*p_rby][*p_rbx] = 'X';
      }
      board[*p_rpy][*p_rpx] = 'o';
    }
    else if (move == 's' && *p_rpy < 7) {
      board[*p_rpy][*p_rpx] = ' ';
      *p_rpy += 1;
      if ((*p_rpy == *p_rby) && (*p_rpx == *p_rbx)) {
        *p_rby += 1;
        board[*p_rby][*p_rbx] = 'X';
      }
      board[*p_rpy][*p_rpx] = 'o';
    }
    else if (move == 'd' && *p_rpx < 7) {
      board[*p_rpy][*p_rpx] = ' ';
      *p_rpx += 1;
      if ((*p_rpy == *p_rby) && (*p_rpx == *p_rbx)) {
        *p_rbx += 1;
        board[*p_rby][*p_rbx] = 'X';
      }
      board[*p_rpy][*p_rpx] = 'o';
    }
    else if (move == 'q' && *p_rpx > 0) {
      board[*p_rpy][*p_rpx] = ' ';
      *p_rpx -= 1;
      if((*p_rpy == *p_rby) && (*p_rpx == *p_rbx)) {
        *p_rbx -= 1;
        board[*p_rby][*p_rbx] = 'X';
	  }
      board[*p_rpy][*p_rpx] = 'o';
    }
}




