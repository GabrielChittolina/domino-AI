#include "lista.h"
#include <stdio.h>

#define PIECE_MAX 7

//deck_player
//deck_pc
//deck_table
//deck_back

TppecaDomino * ai_move(TppecaDomino * deck_pc, TppecaDomino * deck_player, TppecaDomino ** deck_table, TppecaDomino ** deck_back){

	printf("in ai_move\n");

	TppecaDomino * p; 

	int i;
	int bool1, bool2;

	TppecaDomino * unknown = sum(deck_player, *deck_back);


	int * freq_order = frequency_rank(unknown);
	free(unknown);
	unknown = NULL;

	for(i = 0; i <= 6; i++)printf("%d ", freq_order[i]);
	printf("\n");

	for(i = 0; i < PIECE_MAX; i++){
		printf("checking for %d\n",freq_order[i]);

		for(p = deck_pc; p != NULL; p = p->right){

			bool1 = (int)p->numberRight == freq_order[i] && 
				(p->numberLeft == left_table_number(*deck_table) || p->numberLeft == right_table_number(*deck_table));
			bool2 = (int)p->numberLeft == freq_order[i] && 
				( p->numberRight == left_table_number(*deck_table) || p->numberRight == right_table_number(*deck_table));
			printf("checking for [%d|%d] %d %d\n", p->numberLeft, p->numberRight, bool1, bool2);

			if(bool1 || bool2){
				deck_pc = push_table(deck_pc, deck_table, p->numberRight, p->numberLeft);
				return deck_pc;
			}
		}

		if(i == PIECE_MAX - 1 && *deck_back != NULL){
			printf("PESCANDO\n");
			deck_pc = catch_piece(deck_pc, deck_back);//pesca uma peça
			printf("...PESCOU [%d|%d]\n", deck_pc->numberLeft, deck_pc->numberRight);

			unknown = sum(deck_player, *deck_back);
			freq_order = frequency_rank(unknown);
			free(unknown);
			unknown = NULL;
			//atualiza o freq_order

			i = -1;//para reiniciar o loop
		}
	}

	return deck_pc;
}
//deck_player
//deck_pc
//deck_table
//deck_back

/*
int main(void){

	TppecaDomino * deck_player = new_list();
	TppecaDomino * deck_pc = new_list();
	TppecaDomino * deck_table = new_list();
	TppecaDomino * deck_back = new_deck();

	for(int i = 0; i < 7; i++){
		deck_pc = catch_piece(deck_pc, &deck_back);
		deck_player = catch_piece(deck_player, &deck_back);
	}

	printf("deck_table:");
	print_deck(deck_table);
	printf("deck_pc:");
	print_deck(deck_pc);
	printf("deck_player:");
	print_deck(deck_player);

	deck_player = push_table(deck_player, &deck_table, 0, 4);

	printf("\n\n");

d	printf("deck_table:");
	print_deck(deck_table);
	printf("deck_pc:");
	print_deck(deck_pc);
	printf("deck_player:");
	print_deck(deck_player);

	return 0;
}
*/
