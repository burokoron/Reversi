#ifndef MAIN_H
#define MAIN_H

#include "board.h"
#include "search.h"
#include "tt.h"
#include "book.h"
#include "leraner.h"

extern int node;
extern int rand_margin;
extern int entry_count;
extern bool search_stop;
extern uint64_t move_pos_pv[100];
extern MOVES_PV moves_pv[100];

// ��̓���
uint64_t Input(const BOARD *board, uint64_t legal_pos);

// �Ֆʂ̏o��
void Output_board(const BOARD *board);

// ���s
int Result(const BOARD *board);

// �R���s���[�^�̎v�l
uint64_t Com_think(BOARD *board, int level);

// �w�K�p�̎v�l
//uint64_t Learn_think(BOARD *board, int depth);

// �R���s���[�^�̑ł���̏o��
void Output_com_move(const BOARD *board, uint64_t move_pos);

// �l��vs�l��
void Man_vs_man(void);

// �l��vs�R���s���[�^
void Man_vs_com(int level);

// �R���s���[�^vs�R���s���[�^
int Com_vs_com(int com_1_level, int com_2_level);

// �x���`�}�[�N
void ffo();

#endif