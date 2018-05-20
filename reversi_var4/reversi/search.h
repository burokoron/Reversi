#ifndef SEARCH_H
#define SEARCH_H

#include "board.h"
#include "tt.h"
#include "evaluation.h"

#define change_turn(a) ((a)==(BLACK)?(WHITE):(BLACK))

#define MY_INFINITY 10000.0

typedef struct MOVES_PV{
	int move[100];
}MOVES_PV;

// キラームーブ
void Killer_move(int *move_list, uint64_t legal_pos);

// ムーブオーダリング(中盤)
void Mid_move_ordering(int *move_list, int move_pos);

// ムーブオーダリング(読み切り)
void End_move_ordering(BOARD *board, int *move_list, int move_pos);

// 着手数の小さい順にソート
void my_qsort(int *move_list, int *num, int left, int right);

// ランダムプレイヤー
uint64_t Random_search(BOARD *board);

// PVS
double pvs(BOARD *board, CLUSTER *ttentry, double alpha, double beta, int deep, int depth);

// 単純alpha-beta(枝刈あり)
double Mid_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth);

// 単純alpha-beta(枝刈なし)
double End_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth);

// 完全読み切り
double End_search(BOARD *board, CLUSTER *ttentry, double alpha, double beta, int deep, int depth);

#endif