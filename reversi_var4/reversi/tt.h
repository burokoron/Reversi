#ifndef TT_H
#define TT_H

#include "board.h"

typedef struct TTENTRY{
	uint64_t key;
	int move_pos;
	float lower, upper;
	int depth;
}TTENTRY;

typedef struct CLUSTER{
	TTENTRY *ttentry;
}CLUSTER;

#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))

// �u���\�̊m��(�K��2�ׂ̂����)
void Init_tt(TTENTRY *ttentry, int entry_count);

// �u���\�̍폜
void Delete_tt(TTENTRY *ttentry);

// �u���\�ɕۑ�
void Save_tt(TTENTRY *ttentry, int move_pos, uint64_t key, float alpha, float beta, int depth);

#endif