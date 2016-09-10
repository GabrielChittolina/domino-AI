#include "lista.c"
#include <string.h>

#define PIECE_MAX 7

//deck_player
//deck_pc
//deck_table
//deck_back

TppecaDomino * next_move(TppecaDomino * deck_player, TppecaDomino * deck_pc,
		TppecaDomino * deck_table, TppecaDomino * deck_back){
	/*
	 * Função em que a IA decide a próxima
	 * jogada a ser realizada com base nas
	 * peças que estão no seu "deck_pc",
	 * nas peças que estão na mesa, e nas
	 * peças que ela não tem acesso
	 * (deck_player e deck_back).
	 */

	int * frequency = (int*)malloc(PIECE_MAX*sizeof(int));
	//vetor em que a posição (n-1) representa a
	//frequência do número n nas peças que podem
	//estar no deck_player
	//(quando um número aparece duas vezes na mesma
	//peça ele só é contado uma vez)
	memset(frequência, 0, PIECE_MAX);

	TppecaDomino * unknown = sum(deck_player, deck_back);
	//conjunto de peças que tem alguma chance de
	//estar no deck_player

}
