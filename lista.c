#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

TppecaDomino * catch(TppecaDomino * list_a, TppecaDomino *deck_back){
	TppecaDomino *back = deck_back;
	int size = deck_size(deck_back);
	int position;

	srand( (unsigned)time(NULL));
	position = rand() % (size +1);

	if(deck_back == NULL){
		return list_a;
	}

	if(deck_back->left == NULL && deck_back->right == NULL){
		add_left(list_a, deck_back->numberRight, deck_back->numberLeft);
		delete(deck_back, deck_back->numberRight, deck_back->numberLeft);
		return list_a;
	}


	for(i=0; i < position; i++){
		back = back->right;
	}

	add_left(list_a, back->numberRight, back->numberLeft);
	delete(deck_back, back->numberRight, back->numberLeft);
	return list_a;
}

TppecaDomino * delete(TppecaDomino * list_a, int numberRight, int numberLeft){
	TppecaDomino * piece = list_a;
	
	while(piece != NULL && piece->numberRight != numberRight && piece->numberLeft != numberLeft){
		piece = piece->right;
	}

	if(piece == NULL) return list_a;

	if(piece->right == NULL && piece->left == NULL){
		free(piece);
		return NULL;
	}

	if(piece->left == NULL){
		list_a = list_a->right;
		list_a->left = NULL;
		free(piece);
		return list_a;
	}

	if(piece->right == NULL){
		list_a->left->right = NULL;
		free(piece);
		return list_a;
	}

	piece->left->right = piece->right;
	piece->right->left = piece->left;
	free(piece);
	return list_a;
}
