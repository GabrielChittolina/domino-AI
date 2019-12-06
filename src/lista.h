#ifndef LISTA_H
#define LISTA_H


#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PIECE_MAX 7
#define INF 1123

typedef struct _pecaDomino{
	int numberRight;
	int numberLeft;
	struct _pecaDomino *right;
	struct _pecaDomino *left;
}TppecaDomino;

TppecaDomino * new_list();

void print_deck(TppecaDomino * deck);

TppecaDomino * turn_piece(TppecaDomino * peca);

int deck_size(TppecaDomino * list_a);

TppecaDomino * add_left(TppecaDomino * list_a, int numberRight, int numberLeft);

TppecaDomino * add_right(TppecaDomino * list_a, int numberRight, int numberLeft);

TppecaDomino * new_deck(); 

int left_table_number(TppecaDomino * deck_table);

int right_table_number(TppecaDomino * deck_table);

int where_play(TppecaDomino * piece, TppecaDomino * table);

int _where_play(TppecaDomino * table, TppecaDomino * player, int numberRight, int numberLeft);

int number_is_in(int * freq_rank, int number);

int * frequency_rank(TppecaDomino * list_a);

TppecaDomino * delete(TppecaDomino * list_a, int numberRight, int numberLeft);

TppecaDomino * catch_piece(TppecaDomino * list_a, TppecaDomino ** deck_back);

TppecaDomino * push_table(TppecaDomino * list_a, TppecaDomino ** table, int right_value, int left_value);

TppecaDomino * sum(TppecaDomino * list_a, TppecaDomino * list_b);

#endif
