#include "lista.h"
#include <stdio.h>

#define PIECE_MAX 7

//deck_player
//deck_pc
//deck_table
//deck_back

TppecaDomino * ai_move(TppecaDomino * deck_pc, TppecaDomino * deck_player, TppecaDomino ** deck_table, TppecaDomino ** deck_back){
	//printf("DECK_TABLE is\n");
	//print_deck(*deck_table);
	//int was_null;
	//if(*deck_table == NULL) was_null = 1;
	//else was_null = 0;

	TppecaDomino * p; 

	int i;
	int bool1, bool2;

	TppecaDomino * unknown = sum(deck_player, *deck_back);


	int * freq_order = frequency_rank(unknown);
	free(unknown);
	unknown = NULL;

	/*
	for(i = 0; i <= 6; i++)printf("%d ", freq_order[i]);
	printf("\n");
	if(was_null)printf("WAS NULL\n");
	else printf("was not null\n");
	printf("DECK_TABLE is\n");
	print_deck(*deck_table);
	*/

	for(i = 0; i < PIECE_MAX; i++){
		//printf("DECK_TABLE is\n");
		//print_deck(*deck_table);

		for(p = deck_pc; p != NULL; p = p->right){


			bool1 = (int)p->numberRight == freq_order[i] && 
				(*deck_table == NULL || p->numberLeft == left_table_number(*deck_table) || p->numberLeft == right_table_number(*deck_table));
			bool2 = (int)p->numberLeft == freq_order[i] && 
				(*deck_table == NULL || p->numberRight == left_table_number(*deck_table) || p->numberRight == right_table_number(*deck_table));

			if(bool1 || bool2){
				deck_pc = push_table(deck_pc, deck_table, p->numberRight, p->numberLeft);
				return deck_pc;
			}
		}
		//printf("i2 = %d\n", i);

		if(i == PIECE_MAX - 1 && *deck_back != NULL){
			//printf("heeeeeeeeeeeeeeeeeere\n");
			deck_pc = catch_piece(deck_pc, deck_back);//pesca uma peça

			unknown = sum(deck_player, *deck_back);
			freq_order = frequency_rank(unknown);
			free(unknown);
			unknown = NULL;
			//atualiza o freq_order
			//printf("hmmmmmmmmmmm i = %d\n", i);

			i = -1;//para reiniciar o loop
		}
		//printf("i3 = %d\n", i);
	}

	return deck_pc;
}

int can_play(TppecaDomino * deck_a, TppecaDomino * deck_table, TppecaDomino * deck_back){
	TppecaDomino * p;

	//if(deck_back != NULL) return 1;

	for(p = deck_a; p != NULL; p = p->right){
		if(where_play(p, deck_table)) return 1;
	}

	return 0;
}
/*
int main(void){
	int i;

	TppecaDomino * deck_player = new_list();
	TppecaDomino * deck_pc = new_list();
	TppecaDomino * deck_table = new_list();
	TppecaDomino * deck_back = new_deck();

	
	for(i = 0; i < 7; i++){
		deck_player = catch_piece(deck_player, &deck_back);
		deck_pc = catch_piece(deck_pc, &deck_back);
	}

	printf("deck_player");
	print_deck(deck_player);
	printf("deck_pc");
	print_deck(deck_pc);
	printf("deck_table");
	print_deck(deck_table);
	printf("deck_back");
	print_deck(deck_back);

	while(scanf("%d",&i),1){
		if(i == 2) break;
		deck_player = catch_piece(deck_player, &deck_back);
		printf("deck_player");
		print_deck(deck_player);
		printf("deck_pc");
		print_deck(deck_pc);
		printf("deck_table");
		print_deck(deck_table);
		printf("deck_back");
		print_deck(deck_back);
	}

	deck_pc = ai_move(deck_pc, deck_player, &deck_table, &deck_back);
	printf("deck_player");
	print_deck(deck_player);
	printf("deck_pc");
	print_deck(deck_pc);
	printf("deck_table");
	print_deck(deck_table);
	printf("deck_back");
	print_deck(deck_back);

	return 0;
}
*/
