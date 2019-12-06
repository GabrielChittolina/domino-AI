#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "domino.h"

int main(void){
	int i;
	int numberLeft, numberRight;
	int you_won;

	TppecaDomino * p;

	TppecaDomino * deck_player = new_list();
	TppecaDomino * deck_pc = new_list();
	TppecaDomino * deck_table = new_list();
	TppecaDomino * deck_back = new_deck();

	
	for(i = 0; i < 7; i++){
		deck_player = catch_piece(deck_player, &deck_back);
		deck_pc = catch_piece(deck_pc, &deck_back);
	}

	while(1){ //loop principal do jogo

		while(1){//loop para o player jogar
			system("clear");
			printf("Para jogar uma peça insira os seus dois números, para pescar insira -1 -1 e para pular a vez -2 -2.\n");
			printf("\nMesa\n");
			print_deck(deck_table);
			printf("Seu deck\n");
			print_deck(deck_player);
			printf("O computador tem %d peças\n", deck_size(deck_pc));
			printf("Sua jogada: ");
			scanf("%d %d", &numberLeft, &numberRight);

			if(numberLeft == -1 || numberRight == -1){//pescar
				if(deck_back == NULL) break;//se o player tenta pescar com o monte vazio

				deck_player = catch_piece(deck_player, &deck_back);
				continue;
			}

			else if(numberLeft == -2 || numberRight == -2){//pular a vez
				break;
			}

			
			//jogar uma peça na mesa

			if(!_where_play(deck_table, deck_player, numberRight, numberLeft)){//se o jogador escolheu uma peça invalida
				printf("Escolha uma peça válida ou pule sua vez!\n");
				continue;
			}

			deck_player = push_table(deck_player, &deck_table, numberRight, numberLeft);
			break;
		}

		if(deck_player == NULL) break;//se o jogador já ganhou


		//vez do computador jogar
		deck_pc = ai_move(deck_pc, deck_player, &deck_table, &deck_back);


		if(deck_back != NULL) continue; //se será possível pescar no próximo turno

		for(p = deck_player; p != NULL; p = p->right){//se o jogador poderá jogar no próximo turno
			if(where_play(p, deck_table)) continue;
		}

		for(p = deck_pc; p != NULL; p = p->right){//se o computador poderá jogar no próximo turno
			if(where_play(p, deck_table)) continue;
		}

		break; //se ninguém tem como jogar no próximo turno
	}

	if(deck_player == NULL) you_won = 1;
	else if (deck_pc == NULL) you_won = 0;
	else if (deck_size(deck_player) < deck_size(deck_pc)) you_won = 1;
	else if (deck_size(deck_player) > deck_size(deck_pc)) you_won = 0;
	else you_won = -1;

	if(you_won == 1) printf("Você ganhou!\n");
	else if(you_won == 0) printf("Você perdeu.\n");
	else printf("Empate!\n");

	return 0;
}

