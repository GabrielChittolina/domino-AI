#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*
 *你是好马
 *我们是人。
 */

int main(void){

	TppecaDomino * deck_player; //pecas do usuario
	TppecaDomino * deck_pc; //pecas do computador
	TppecaDomino * deck_table; //pecas que estao na mesa
	TppecaDomino * deck_back; //pecas do monte

	deck_player = new_list();
	deck_pc = new_list();
	deck_table = new_list();
	deck_back = new_deck();


	return 0;
}
