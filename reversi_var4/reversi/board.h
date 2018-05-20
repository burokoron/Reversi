#ifndef BOARD_H
#define BOARD_H

//手番
enum TURN{
	BLACK = 0, //先手
	WHITE = 1 //後手
};

// 盤面
typedef struct BOARD{
	uint64_t black, white; //石の配置
	int turn; //手番
	int move_num, empty_num; //手数, 空きマスの数
	uint64_t key; //ハッシュ値
}BOARD;

// 盤面の初期化
void Init_board(BOARD *board);

//　ベンチマークの盤面の初期化
void Init_ffo(BOARD *board, char *position, int turn);

// 合法手生成
uint64_t Move_picker(const BOARD *board);

// 石の反転パターン
uint64_t GetReverse(BOARD *board, uint64_t move_pos);

// 1手進める(hash有り)
void Do_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1手進める(hash無し)
void Do_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1手戻す(hash有り)
void UnDo_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1手戻す(hash無し)
void UnDo_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

//石を数える
int Count_stone(uint64_t bits);

#endif