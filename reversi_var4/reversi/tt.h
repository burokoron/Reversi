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

// 置換表の確保(必ず2のべき乗個)
void Init_tt(TTENTRY *ttentry, int entry_count);

// 置換表の削除
void Delete_tt(TTENTRY *ttentry);

// 置換表に保存
void Save_tt(TTENTRY *ttentry, int move_pos, uint64_t key, float alpha, float beta, int depth);

#endif