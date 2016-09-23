#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "domino.h"

//这很好！！！

int main(void){
	int i;
	int numberLeft, numberRight;
	int end_game = 0;

	TppecaDomino * deck_player; //pecas do usuario
	TppecaDomino * deck_pc; //pecas do computador
	TppecaDomino * deck_table; //pecas que estao na mesa
	TppecaDomino * deck_back; //pecas do monte

	deck_player = new_list();
	deck_pc = new_list();
	deck_table = new_list();
	deck_back = new_deck();

	for(i = 0; i < 7; i++){
		deck_player = catch_piece(deck_player, &deck_back);
		deck_pc = catch_piece(deck_pc, &deck_back);
	}

	while(1){ //loop principal do jogo

		printf("Table:\n");
		print_deck(deck_table);
		printf("Player's deck:\n");
		print_deck(deck_player);
		printf("PC deck:\n");
		print_deck(deck_pc);

		printf("Piece to play is: ");

		while(1){
			scanf("%d %d", &numberLeft, &numberRight);

			if(numberLeft < 0 || numberRight < 0){
				deck_player = catch_piece(deck_player, &deck_back);
				printf("Table:\n");
				print_deck(deck_table);
				printf("Player's deck:\n");
				print_deck(deck_player);
				printf("PC deck:\n");
				print_deck(deck_pc);

				continue;
			}

			if(_where_play(deck_table, deck_player, numberRight, numberLeft)){
				deck_player = push_table(deck_player, &deck_table, numberRight, numberLeft);
				break;
			}

			if(deck_player == NULL){
				end_game = 1;
				break;
			}

			printf("Choose another piece! Or fish one.\n");
		}
		if(end_game) break;


		deck_pc = ai_move(deck_pc, deck_player, &deck_table, &deck_back);
		if(deck_pc == NULL) break;
	}

	if(deck_player == NULL) printf("Você ganhou!!!\n");
	else if(deck_pc == NULL) printf("Você perdeu!!!\n");
	else if(deck_size(deck_player) == deck_size(deck_pc)) printf("Emapte!\n");
	else if(deck_size(deck_player) < deck_size(deck_pc)) printf("Você ganhou!\n");
	else printf("Você perdeu!\n");

	return 0;
}
