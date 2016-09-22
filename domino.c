#include "lista.h"
#include <string.h>
#include <stdio.h>

#define PIECE_MAX 7

//deck_player
//deck_pc
//deck_table
//deck_back

TppecaDomino * ai_move(TppecaDomino * deck_player, TppecaDomino * deck_pc, TppecaDomino ** _deck_table, TppecaDomino ** _deck_back){

	TppecaDomino * p; 

	TppecaDomino * deck_table = *_deck_table;
	TppecaDomino * deck_back = *_deck_back;

	int i;

	TppecaDomino * unknown = sum(deck_player, deck_back);


	int * freq_order = frequency_rank(unknown);
	free(unknown);
	unknown = NULL;

	for(i = 0; i < PIECE_MAX; i++){

		for(p = deck_pc; p != NULL; p = p->right){
			if(  (p->numberRight == freq_order[i] && 
						(p->numberLeft == left_table_number(deck_table) || p->numberLeft == right_table_number(deck_table))) 
					|| (p->numberLeft == freq_order[i] && 
						(p->numberRight == left_table_number(deck_table) || p->numberRight == right_table_number(deck_table)))){
				deck_pc = push_table(deck_pc, &deck_table, p->numberRight, p->numberLeft);
				return deck_pc;
			}
		}

		if(i == PIECE_MAX - 1 && deck_back != NULL){
			deck_pc = catch_piece(deck_pc, &deck_back);//pesca uma peça

			unknown = sum(deck_player, deck_back);
			freq_order = frequency_rank(unknown);
			free(unknown);
			unknown = NULL;
			//atualiza o freq_order

			i = -1;//para reiniciar o loop
		}
	}

	return deck_pc;
}

