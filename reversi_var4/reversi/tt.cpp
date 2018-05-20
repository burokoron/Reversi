#include <stdint.h>
#include <stdlib.h>

#include "tt.h"

int entry_count;

// �u���\�̊m��(�K��2�ׂ̂����)
void Init_tt(TTENTRY *ttentry, int entry_count){
	ttentry = (TTENTRY*)calloc(entry_count, sizeof(TTENTRY));
}

// �u���\�̍폜
void Delete_tt(TTENTRY *ttentry){
	free(ttentry);
}

// �u���\�ɕۑ�
void Save_tt(TTENTRY *ttentry, int move_pos, uint64_t key, float alpha, float beta, int depth){
	ttentry[key&(entry_count-1)].key=key;
	ttentry[key&(entry_count-1)].move_pos=move_pos;
	ttentry[key&(entry_count-1)].lower=alpha;
	ttentry[key&(entry_count-1)].upper=beta;
	ttentry[key&(entry_count-1)].depth=depth;
}