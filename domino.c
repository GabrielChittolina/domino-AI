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

	int * frequency;
	//vetor em que a posição n representa a
	//frequência do número n dentre peças que podem
	//estar no deck_player
	//(quando um número aparece duas vezes na mesma
	//peça ele só é contado uma vez)
	memset(frequência, 0, PIECE_MAX);

	TppecaDomino * unknown = sum(deck_player, deck_back);
	//conjunto de peças que tem alguma chance de
	//estar no deck_player
	
	frequency = frequency_in(unknown);
	free(unknown);
	unknown = NULL;

	int * order_of_freq = order_freq(frequency);
}

int * order_freq(int * frequency){
	int * order_of_freq = (int*)malloc(PIECE_MAX * sizeof(int));
	memset(order_of_freq, -1, PIECE_MAX * sizeof(int));

}

int is_in(int * vetor, int n){
	//retorna 1 se um número está no vetor,
	//do contrário retorna 0
	int i;

	for(i = 0; i < PIECE_MAX; i++)
		if(vetor[i] == n) return 0;
	
	return 1;
}
