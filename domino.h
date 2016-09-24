#ifndef DOMINO_H
#define DOMINO_H

TppecaDomino * ai_move(TppecaDomino * deck_pc, TppecaDomino * deck_player, TppecaDomino ** _deck_table, TppecaDomino ** _deck_back);

int can_play(TppecaDomino * deck_a, TppecaDomino * deck_table, TppecaDomino * deck_back);

#endif
