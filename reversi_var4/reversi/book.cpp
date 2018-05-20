#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "book.h"

// íËê’ÇÃíTçı
float Book_search(BOARD *board, int margin){
	FILE *fp;
	int entry_count=1048576, entry_num, move_list[64]={0}, book_num, mid, empty;
	char file_name[] = "book/empty_00.bin";
	float value[] = { -9999, 0 }, var = -9999;
	uint64_t legal_pos, reverse_pos, move_pos;
	uint64_t *book_key;
	float *book_value;

	empty = board->empty_num - 1;
	file_name[11] = '0' + empty / 10;
	file_name[12] = '0' + empty % 10;

	if(fopen_s(&fp, file_name, "rb")!=0){
		//printf("Can't open '%s'\n", file_name);
		return -9999;
	}
	
	fread(&book_num, sizeof(int), 1, fp);

	book_key = (uint64_t*)calloc(book_num, sizeof(uint64_t));
	book_value = (float*)calloc(book_num, sizeof(float));

	for (int i = 0;i < book_num;i++) {
		fread(&book_key[i], sizeof(uint64_t), 1, fp);
		fread(&book_value[i], sizeof(float), 1, fp);
	}

	legal_pos=Move_picker(board);
	Killer_move(move_list, legal_pos);

	int move_list_num=0;
	while(move_list[move_list_num]!=0){
		move_pos=(uint64_t)1<<(move_list[move_list_num++]-1);
		reverse_pos=GetReverse(board, move_pos);
		Do_move_hash(board, move_pos, reverse_pos);

		entry_num=board->key&(entry_count-1);
		
		mid = My_bsearch(book_key, book_value, board->key, 0, book_num - 1);
		if (mid != -1) {
			var = book_value[mid] + (float)((rand() % (101 * margin) - (51 * margin)) / 100.0);
			if (board->turn == BLACK) var *= -1;
		}

		UnDo_move_hash(board, move_pos, reverse_pos);
		
		if(var>value[0]){
			value[0] = var;
			value[1] = book_value[mid];
			move_pos_pv[0]=move_pos;
		}
	}

	BOARD con_board;
	uint64_t storn=1;
	
	con_board.black=board->black;
	con_board.white=board->white;
	con_board.key=board->key;
	board->black=0;
	board->white=0;
	board->key=0x622b24abed22bd34;

	if(board->turn==WHITE) board->key^=turn_key;
	for(int i=0;i<64;i++){
		if((con_board.black&storn)!=0){
			board->black|=(uint64_t)1<<(8-i/8+(7-i%8)*8-1);
			board->key ^= board_key[0][8-i/8+(7-i%8)*8-1];
		}
		if((con_board.white&storn)!=0){
			board->white|=(uint64_t)1<<(8-i/8+(7-i%8)*8-1);
			board->key ^= board_key[1][8-i/8+(7-i%8)*8-1];
		}
		storn<<=1;
	}

	legal_pos=Move_picker(board);
	Killer_move(move_list, legal_pos);

	move_list_num=0;
	while(move_list[move_list_num]!=0){
		move_pos=(uint64_t)1<<(move_list[move_list_num++]-1);
		reverse_pos=GetReverse(board, move_pos);
		Do_move_hash(board, move_pos, reverse_pos);

		entry_num=board->key&(entry_count-1);
		
		mid = My_bsearch(book_key, book_value, board->key, 0, book_num - 1);
		if (mid != -1) {
			var = book_value[mid] + (float)((rand() % (101 * margin) - (51 * margin)) / 100.0);
			if (board->turn == BLACK) var *= -1;
		}

		UnDo_move_hash(board, move_pos, reverse_pos);

		if (var>value[0]) {
			value[0] = var;
			value[1] = book_value[mid];
			storn=1;
			for(int i=0;i<64;i++){
				if((move_pos&storn)!=0){
					move_pos=(uint64_t)1<<(8-i/8+(7-i%8)*8-1);
					break;
				}
				storn<<=1;
			}
			move_pos_pv[0]=move_pos;
		}
	}

	board->black=con_board.black;
	board->white=con_board.white;
	board->key=con_board.key;

	con_board.black=board->black;
	con_board.white=board->white;
	con_board.key=board->key;
	board->black=0;
	board->white=0;
	board->key=0x622b24abed22bd34;

	storn=1;

	if(board->turn==WHITE) board->key^=turn_key;
	for(int i=0;i<64;i++){
		if((con_board.black&storn)!=0){
			board->black|=(uint64_t)1<<(i/8+(i%8)*8);
			board->key ^= board_key[0][i/8+(i%8)*8];
		}
		if((con_board.white&storn)!=0){
			board->white|=(uint64_t)1<<(i/8+(i%8)*8);
			board->key ^= board_key[1][i/8+(i%8)*8];
		}
		storn<<=1;
	}

	legal_pos=Move_picker(board);
	Killer_move(move_list, legal_pos);

	move_list_num=0;
	while(move_list[move_list_num]!=0){
		move_pos=(uint64_t)1<<(move_list[move_list_num++]-1);
		reverse_pos=GetReverse(board, move_pos);
		Do_move_hash(board, move_pos, reverse_pos);

		entry_num=board->key&(entry_count-1);
		
		mid = My_bsearch(book_key, book_value, board->key, 0, book_num - 1);
		if (mid != -1) {
			var = book_value[mid] + (float)((rand() % (101 * margin) - (51 * margin)) / 100.0);
			if (board->turn == BLACK) var *= -1;
		}

		UnDo_move_hash(board, move_pos, reverse_pos);

		if (var>value[0]) {
			value[0] = var;
			value[1] = book_value[mid];
			storn=1;
			for(int i=0;i<64;i++){
				if((move_pos&storn)!=0){
					move_pos=(uint64_t)1<<(i/8+(i%8)*8);
					break;
				}
				storn<<=1;
			}
			move_pos_pv[0]=move_pos;
		}
	}

	board->black=con_board.black;
	board->white=con_board.white;
	board->key=con_board.key;

	con_board.black=board->black;
	con_board.white=board->white;
	con_board.key=board->key;
	board->black=0;
	board->white=0;
	board->key=0x622b24abed22bd34;

	storn=1;

	if(board->turn==WHITE) board->key^=turn_key;
	for(int i=0;i<64;i++){
		if((con_board.black&storn)!=0){
			board->black|=(uint64_t)1<<((7-i/8)*8+8-i%8-1);
			board->key ^= board_key[0][(7-i/8)*8+8-i%8-1];
		}
		if((con_board.white&storn)!=0){
			board->white|=(uint64_t)1<<((7-i/8)*8+8-i%8-1);
			board->key ^= board_key[1][(7-i/8)*8+8-i%8-1];
		}
		storn<<=1;
	}

	legal_pos=Move_picker(board);
	Killer_move(move_list, legal_pos);

	move_list_num=0;
	while(move_list[move_list_num]!=0){
		move_pos=(uint64_t)1<<(move_list[move_list_num++]-1);
		reverse_pos=GetReverse(board, move_pos);
		Do_move_hash(board, move_pos, reverse_pos);

		entry_num=board->key&(entry_count-1);
		
		mid = My_bsearch(book_key, book_value, board->key, 0, book_num - 1);
		if (mid != -1) {
			var = book_value[mid] + (float)((rand() % (101 * margin) - (51 * margin)) / 100.0);
			if (board->turn == BLACK) var *= -1;
		}

		UnDo_move_hash(board, move_pos, reverse_pos);

		if (var>value[0]) {
			value[0] = var;
			value[1] = book_value[mid];
			storn=1;
			for(int i=0;i<64;i++){
				if((move_pos&storn)!=0){
					move_pos=(uint64_t)1<<((7-i/8)*8+8-i%8-1);
					break;
				}
				storn<<=1;
			}
			move_pos_pv[0]=move_pos;
		}
	}

	board->black=con_board.black;
	board->white=con_board.white;
	board->key=con_board.key;

	fclose(fp);

	free(book_key);
	free(book_value);
	if (value[0] == -9999) return value[0];
	else return value[1];
}

// ìÒï™íTçı
int My_bsearch(uint64_t *book_key, float *book_value, uint64_t key, int left, int right) {
	int mid;

	while (left <= right) {
		mid = left + (right - left) / 2;
		if (book_key[mid] < key) left = mid + 1;
		else if (key < book_key[mid]) right = mid - 1;
		else return mid;
	}
	return -1;
}

