#include <stdio.h>
#include <stdlib.h>

typedef struct _pecaDomino{
	int numberRight;
	int numberLeft;
	struct _pecaDomino *right;
	struct _pecaDomino *left;
}TppecaDomino;

TppecaDomino * new_list(){
	return NULL;
}

TppecaDomino * add_left(TppecaDomino * list_a, int numberRight, int numberLeft){
	TppecaDomino * new_piece = (TppecaDomino*)malloc(sizeof(TppecaDomino));
	new_piece->numberRight = numberRight;
	new_piece->numberLeft =  numberLeft;

	if(list_a == NULL){
		new_piece->right = NULL;
		new_piece->left = NULL;
		return new_piece;
	}

	new_piece->right = list_a;
	list_a->left = new_piece;
	new_piece->left = NULL;

	return new_piece;
}

TppecaDomino * add_right(TppecaDomino * list_a, int numberRight, int numberLeft){
	TppecaDomino * new_piece = (TppecaDomino*)malloc(sizeof(TppecaDomino));
	TppecaDomino * r;
	new_piece->numberRight = numberRight;
	new_piece->numberLeft = numberLeft;

	if(list_a == NULL){
		new_piece->right = NULL;
		new_piece->left = NULL;
		return new_piece;
	}

	for(r = list_a; r->right != NULL; r = r->right);

	r->right = new_piece;
	new_piece->left = r;
	new_piece->right = NULL;

	return list_a;
}

TppecaDomino * new_deck(){ //retorna uma lista com todas as peças do jogo
	int i, j;
	TppecaDomino * deck = new_list();

	for(i = 0; i <= 6; i++){
		for(j = 0; j <= i; j++){
			deck = add_left(deck, i, j);
		}
	}

	return deck;
}
