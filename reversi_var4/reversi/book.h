#ifndef BOOK_H
#define BOOK_H

#include "board.h"
#include "tt.h"
#include "search.h"

extern uint64_t move_pos_pv[100];
extern uint64_t board_key[2][64];
extern uint64_t turn_key;

// ��Ղ̒T��
float Book_search(BOARD *board, int margin);

// �񕪒T��
int My_bsearch(uint64_t *book_key, float *book_value, uint64_t key, int left, int right);

#endif