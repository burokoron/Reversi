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

// 手の入力
uint64_t Input(const BOARD *board, uint64_t legal_pos);

// 盤面の出力
void Output_board(const BOARD *board);

// 勝敗
int Result(const BOARD *board);

// コンピュータの思考
uint64_t Com_think(BOARD *board, int level);

// 学習用の思考
//uint64_t Learn_think(BOARD *board, int depth);

// コンピュータの打ち手の出力
void Output_com_move(const BOARD *board, uint64_t move_pos);

// 人間vs人間
void Man_vs_man(void);

// 人間vsコンピュータ
void Man_vs_com(int level);

// コンピュータvsコンピュータ
int Com_vs_com(int com_1_level, int com_2_level);

// ベンチマーク
void ffo();

#endif