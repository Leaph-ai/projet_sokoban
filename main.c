#include "sokoban.h"

int main()
{

  int p_rbx, p_rby, p_rgx, p_rgy, p_rpx, p_rpy;
  char **board;
  char move;
  board = init_board();
  srand(time(NULL));

  place_random_start(board, &p_rbx, &p_rby, &p_rgx, &p_rgy, &p_rpx, &p_rpy);


  display_board(board, p_rpy, p_rpx, p_rby, p_rbx, p_rgy, p_rgx);

  while (1){
    printf("Choisissez un mouvement : Haut(z) Bas(s) Droite(d) Gauche(q) :\n");
    scanf(" %c", &move);

   //verif si le joueur perd
    if (p_rpy == 0 && move == 'z') {
      printf("Perdu ! Vous avez touché la bordure du haut :c\n");
      break;
    }

    else if (p_rpy == 7 && move == 's') {
      printf("Perdu ! Vous avez touché la bordure du bas :c\n");
      break;
    }

    else if (p_rpx == 7 && move == 'd') {
      printf("Perdu ! Vous avez touché la bordure de droite :c\n");
      break;
    }

    else if (p_rpx == 0 && move == 'q') {
      printf("Perdu ! Vous avez touché la bordure de gauche :c\n");
      break;
    }

    //verif si la boîte touche le bord
    if (p_rby == 0 && move == 'z' && p_rpy == p_rby + 1 && p_rpx == p_rbx) {
      printf("Perdu ! La boîte à touché la bordure du haut :c\n");
      break;
    }

    else if (p_rby == 7 && move == 's' && p_rpy == p_rby - 1 && p_rpx == p_rbx) {
      printf("Perdu ! La boîte à touché la bordure du bas :c\n");
      break;
    }

    else if (p_rbx == 7 && move == 'd' && p_rpx == p_rbx - 1 && p_rpy == p_rby) {
      printf("Perdu ! La boîte à touché la bordure de droite :c\n");
      break;
    }

    else if (p_rbx == 0 && move == 'q' && p_rpx == p_rbx + 1 && p_rpy == p_rby) {
      printf("Perdu ! La boîte à touché la bordure de gauche :c\n");
      break;
    }

    player_move(board, &p_rpy, &p_rpx, &p_rby, &p_rbx, move);

    //verif si le joueur gagne
    if((p_rgy == p_rby) && (p_rgx == p_rbx)){
      display_board(board, p_rpy, p_rpx, p_rby, p_rbx, p_rgy, p_rgx);
      printf("Bravo ! Vous avez gagné !\n");
      break;
    }

    display_board(board, p_rpy, p_rpx, p_rby, p_rbx, p_rgy, p_rgx);
  }

  free(board);
  return 0;
}
