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

// �L���[���[�u
void Killer_move(int *move_list, uint64_t legal_pos);

// ���[�u�I�[�_�����O(����)
void Mid_move_ordering(int *move_list, int move_pos);

// ���[�u�I�[�_�����O(�ǂݐ؂�)
void End_move_ordering(BOARD *board, int *move_list, int move_pos);

// ���萔�̏��������Ƀ\�[�g
void my_qsort(int *move_list, int *num, int left, int right);

// �����_���v���C���[
uint64_t Random_search(BOARD *board);

// PVS
double pvs(BOARD *board, CLUSTER *ttentry, double alpha, double beta, int deep, int depth);

// �P��alpha-beta(�}������)
double Mid_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth);

// �P��alpha-beta(�}���Ȃ�)
double End_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth);

// ���S�ǂݐ؂�
double End_search(BOARD *board, CLUSTER *ttentry, double alpha, double beta, int deep, int depth);

#endif