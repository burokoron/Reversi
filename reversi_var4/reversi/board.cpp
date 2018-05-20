#include <stdio.h>
#include <stdint.h>

#include "board.h"

uint64_t board_key[2][64]={
	0x288952392e80456c, 0x1161f85b24b8f054,
	0x59a21c01b8c164f1, 0x5f7d93624b43595,
	0xa507464b7954d7d, 0x1119be3313e351f6,
	0x71daa2936dce7405, 0x630c56bff30c3f67,
	0x4e1eaf3823351e0, 0x2f7d819e100fd85d,
	0x2b042f9d5036257, 0x31a3c0385ced6109,
	0x22e8ad043d51e261, 0x4dd09626c9750d9c,
	0x7961f644b6540803, 0x8ad34aec2df63c3,
	0x2a6a08399bcf3745, 0x19c2491ca2ec0e4a,
	0x12dfb82cd42102f8, 0x7a793242dafd04cc,
	0x4aab267bba09619c, 0x37617150f13c0497,
	0x59c8668cd9746f33, 0x71d5b54b6b81e8d2,
	0x3f37a916c160bbab, 0x282a5f65748503b,
	0x41664fac35a214ad, 0x51948a1171ac0afb,
	0x7e37045d2e20212, 0x3d03d5ca752312bb,
	0xafbefebf6fe9127, 0x33a9d59b191c73d,
	0x1b0f6edf4d24550a, 0x68ea836b945d5994,
	0x2d91cd4b22afecab, 0x18a79bc6e6cc319c,
	0x5b6a720ebed3e728, 0x1801ca3e47d0faab,
	0x11fdc9640335e3e, 0x5103cefac1ff6cdb,
	0x34e2a8acc659847, 0x437fee9ddab1bb13,
	0x1dbc18bd51371f4b, 0x1e3d3b552ba5e983,
	0x7f3adc311059f92, 0x60c4180f12187c8f,
	0x666010f3291481f7, 0x349c8fc3782e8dd3,
	0x723b322ce121f080, 0x5ce15765ea8e1ba5,
	0x2b53f3053ce4823c, 0x2f407ab64fa2a1ca,
	0x18212d65fe46c2d1, 0x4d256db38bc8294e,
	0x749d0109f432a836, 0x37f5b2339c8a7626,
	0x1c4dcaaf2efe2596, 0xdbaef3f7886b73,
	0x30711013b8ae1228, 0x67da0d560ea7b128,
	0x444e6767496b5b7a, 0x38c1770ae9d18d68,
	0x223d86676cb55f56, 0x49a448a5edef1272,
	0x59893a3a103b5b59, 0x65eaf2fda8bca0ee,
	0x1b656612dcab9d21, 0x4b1f6e30b1defcb6,
	0x70183b7a9196ddff, 0xbd2b8032fac2793,
	0x4a0ba83f79e41a51, 0x78f6a7269582329f,
	0x70587b193130ad3, 0x17ba7e5765ed2ca9,
	0xa2913f0587183f2, 0x30a09aa3ca34b459,
	0x7b1e3adfa492e20b, 0x21bb9c4724585b74,
	0x3a0c07510a9e4707, 0x1761b7f1f73d2510,
	0x235f6a260d35a3ec, 0x75b3e518411e66b6,
	0x2763e25b328a3384, 0x5d874b5af6d994e2,
	0x6877d628251785b0, 0x14f7bdb9e36a3c1d,
	0x4802e4bbe2d18b13, 0x37327ada6befe199,
	0x53ac354a75bf401b, 0x7bf5f0042b2e4057,
	0x4a778285be3bfd01, 0x18e69c6ccaa1ccde,
	0x7642b57580e8d184, 0x5107346c1e43e6f4,
	0x546c4976a9daa8d3, 0x6f9a305f4b7d422f,
	0x1a8c409c443ce2cc, 0x1922ec5e9f4f0b39,
	0x11b505a1567ea81, 0x43f72c603030601b,
	0x47d3c4331edd03f5, 0x2fb65f038ec66387,
	0x430676bf0ec060ed, 0x47844acbc4cc62b1,
	0x31b74773aadff51d, 0x59838d9087808cb9,
	0x3fd8438c4991a427, 0x28cc099a86b6be74,
	0x5189340c1336f7e, 0x33d16e94e3a66fc3,
	0x72c5fe4bf5ea8a5b, 0xa489d027a9f4774,
	0x141460ce8ba727a3, 0xc9a643ae3c17ca7,
	0x599b159b6a1d0dd6, 0x27b2fb26cdda84a5,
	0x38b713445b2484eb, 0x5a6dffd419d4b0ff,
	0x71a61e51b4418b4c, 0x5bf4494579407336,
	0x3763c214794afce0, 0x2d3087b10f778136,
	0x69d01cd50e67da77, 0x2563d56fa897f1ea,
	0x11df7d8786f02169, 0x25ea5f3d3665a404,
	0x7c689c92b2942b8b, 0xc135fdde4ddbff6
}; // 盤面のハッシュ値
uint64_t turn_key=0x5dcb464576269bdb; // 手番のハッシュ値

//盤面の初期化
void Init_board(BOARD *board){
	board->key=0x622b24abed22bd34;
	board->black = ((uint64_t)1<<28) + ((uint64_t)1<<35);
	board->key ^= board_key[0][28]^board_key[0][35];
    board->white = ((uint64_t)1<<27) + ((uint64_t)1<<36);
	board->key ^= board_key[1][27]^board_key[1][36];
    board->turn = BLACK;
	board->move_num = 0;
	board->empty_num = 60;
}

//　ベンチマークの盤面の初期化
void Init_ffo(BOARD *board, char *position, int turn){
	board->turn=turn;
	board->empty_num=64;
	board->move_num = 1;
	board->key=0x622b24abed22bd34;
	board->black=(uint64_t)0;
	board->white=(uint64_t)0;

	for(int i=0;i<64;i++){
		if(position[i]=='O'){
			board->white|=((uint64_t)1<<(63-i));
			board->key ^= board_key[WHITE][63-i];
			board->empty_num--;
		}
		else if(position[i]=='X'){
			board->black|=((uint64_t)1<<(63-i));
			board->key ^= board_key[BLACK][63-i];
			board->empty_num--;
		}
	}
	if (board->turn == WHITE) board->key ^= turn_key;
}

//合法手生成
uint64_t Move_picker(const BOARD *board){
    uint64_t me, enemy, masked_enemy, t, valid = 0, blank;
 
    // 現在手番の方をme、相手をenemyにする
	if(board->turn == BLACK){
        me = board->black;
        enemy = board->white;
    }else{
        me = board->white;
        enemy = board->black;
    }
 
    // 空マスのビットボードを（黒または白）のビットNOTで得る
    blank = ~(board->black | board->white);
 
    // 右方向
    masked_enemy = enemy & 0x7e7e7e7e7e7e7e7e; //端列を除く敵石
    t = masked_enemy & (me << 1); //自石の左隣にある敵石を調べる
    for(int i = 0; i < 5; i++){
        t |= masked_enemy & (t << 1);
    }
    valid = blank & (t << 1);
 
    // 左方向
    masked_enemy = enemy & 0x7e7e7e7e7e7e7e7e;
    t = masked_enemy & (me >> 1);
    for(int i = 0; i < 5; i++){
        t |= masked_enemy & (t >> 1);
    }
    valid |= blank & (t >> 1);
 
    // 上方向
    masked_enemy = enemy & 0x00ffffffffffff00;
    t = masked_enemy & (me << 8);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t << 8);
    }
    valid |= blank & (t << 8);
 
    // 下方向
    masked_enemy = enemy & 0x00ffffffffffff00;
    t = masked_enemy & (me >> 8);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t >> 8);
    }
    valid |= blank & (t >> 8);
 
    // 右上方向
    masked_enemy = enemy & 0x007e7e7e7e7e7e00;
    t = masked_enemy & (me << 7);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t << 7);
    }
    valid |= blank & (t << 7);
 
    // 左上方向
    masked_enemy = enemy & 0x007e7e7e7e7e7e00;
    t = masked_enemy & (me << 9);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t << 9);
    }
    valid |= blank & (t << 9);
 
    // 右下方向
    masked_enemy = enemy & 0x007e7e7e7e7e7e00;
    t = masked_enemy & (me >> 9);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t >> 9);
    }
    valid |= blank & (t >> 9);
 
    // 左下方向
    masked_enemy = enemy & 0x007e7e7e7e7e7e00;
    t = masked_enemy & (me >> 7);
    for (int i = 0; i < 5; i++){
        t |= masked_enemy & (t >> 7);
    }
    valid |= blank & (t >> 7);
 
    return valid;
}

//石の反転パターン
uint64_t GetReverse(BOARD *board, uint64_t move_pos){
	int i;
    uint64_t me, enemy, mask, rev = 0, rev_cand;
     
    // 現在手番の方をme、相手をenemyにする
	if(board->turn == BLACK){
        me = board->black;
        enemy = board->white;
    }else{
        me = board->white;
        enemy = board->black;
    }
     
    // 右方向
    rev_cand = 0;
    mask = 0x7e7e7e7e7e7e7e7e;
    for( i = 1; ( (move_pos >> i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos >> i);
    }
    if( ( (move_pos >> i) & me) != 0 ) rev |= rev_cand;
     
    // 左方向
    rev_cand = 0;
    mask = 0x7e7e7e7e7e7e7e7e;
    for( i = 1; ( (move_pos << i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos << i);
    }
    if( ( (move_pos << i) & me) != 0 ) rev |= rev_cand;
     
    // 上方向
    rev_cand = 0;
    mask = 0x00ffffffffffff00;
    for( i = 1; ( (move_pos << 8 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos << 8 * i);
    }
    if( ( (move_pos << 8 * i) & me) != 0 ) rev |= rev_cand;
     
    // 下方向
    rev_cand = 0;
    mask = 0x00ffffffffffff00;
    for( i = 1; ( (move_pos >> 8 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos >> 8 * i);
    }
    if( ( (move_pos >> 8 * i) & me) != 0 ) rev |= rev_cand;
 
    // 右上方向
    rev_cand = 0;
    mask = 0x007e7e7e7e7e7e00;
    for( i = 1; ( (move_pos << 7 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos << 7 * i);
    }
    if( ( (move_pos << 7 * i) & me) != 0 ) rev |= rev_cand;
     
    // 左上方向
    rev_cand = 0;
    mask = 0x007e7e7e7e7e7e00;
    for( i = 1; ( (move_pos << 9 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos << 9 * i);
    }
    if( ( (move_pos << 9 * i) & me) != 0 ) rev |= rev_cand;
     
    // 右下方向
    rev_cand = 0;
    mask = 0x007e7e7e7e7e7e00;
    for( i = 1; ( (move_pos >> 9 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos >> 9 * i);
    }
    if( ( (move_pos >> 9 * i) & me) != 0 ) rev |= rev_cand;
     
    // 左下方向
    rev_cand = 0;
    mask = 0x007e7e7e7e7e7e00;
    for( i = 1; ( (move_pos >> 7 * i) & mask & enemy ) != 0; i++ ){
        rev_cand |= (move_pos >> 7 * i);
    }
    if( ( (move_pos >> 7 * i) & me) != 0 ) rev |= rev_cand;
     
    return rev;
}

// 1手進める(hash有り)
void Do_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos){
	uint64_t key_pos=1;

	for(int i=0;i<64;i++){
		if((move_pos&key_pos)!=0){
			board->key^=board_key[board->turn][i];
			break;
		}
		key_pos<<=1;
	}

	if(board->turn==BLACK){
		board->black ^= move_pos | reverse_pos;
		board->white ^= reverse_pos;
		board->turn = WHITE;
	}
	else{
		board->white ^= move_pos | reverse_pos;
		board->black ^= reverse_pos;
		board->turn = BLACK;
    }
    board->move_num++;
	board->empty_num--;
	key_pos=1;
	for(int i=0;i<64;i++){
		if((key_pos&reverse_pos)!=0){
			board->key^=board_key[0][i]^board_key[1][i];
		}
		key_pos<<=1;
	}
	board->key^=turn_key;
}

// 1手進める(hash無し)
void Do_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos) {
	if (board->turn == BLACK) {
		board->black ^= move_pos | reverse_pos;
		board->white ^= reverse_pos;
		board->turn = WHITE;
	}
	else {
		board->white ^= move_pos | reverse_pos;
		board->black ^= reverse_pos;
		board->turn = BLACK;
	}
	board->move_num++;
	board->empty_num--;
}

// 1手戻す(hash有り)
void UnDo_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos){
	uint64_t key_pos=1;

	if(board->turn==WHITE){
		board->black ^= move_pos | reverse_pos;
		board->white ^= reverse_pos;
		board->turn = BLACK;
	}
	else{
		board->white ^= move_pos | reverse_pos;
		board->black ^= reverse_pos;
		board->turn = WHITE;
    }
    board->move_num--;
	board->empty_num++;
	for(int i=0;i<64;i++){
		if((move_pos&key_pos)!=0){
			board->key^=board_key[board->turn][i];
			break;
		}
		key_pos<<=1;
	}
	key_pos=1;
	for(int i=0;i<64;i++){
		if((key_pos&reverse_pos)!=0){
			board->key^=board_key[0][i]^board_key[1][i];
		}
		key_pos<<=1;
	}
	board->key^=turn_key;
}

// 1手戻す(hash無し)
void UnDo_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos) {
	if (board->turn == WHITE) {
		board->black ^= move_pos | reverse_pos;
		board->white ^= reverse_pos;
		board->turn = BLACK;
	}
	else {
		board->white ^= move_pos | reverse_pos;
		board->black ^= reverse_pos;
		board->turn = WHITE;
	}
	board->move_num--;
	board->empty_num++;
}


//石を数える
int Count_stone(uint64_t bits){
    bits = bits - (bits >> 1 & 0x5555555555555555);                           // 2bitごと
    bits = (bits & 0x3333333333333333) + (bits >> 2 & 0x3333333333333333);    // 4bit
    bits = (bits & 0x0f0f0f0f0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f0f0f0f0f);    // 8bit
    bits = (bits & 0x00ff00ff00ff00ff) + (bits >> 8 & 0x00ff00ff00ff00ff);    //16bit
    bits = (bits & 0x0000ffff0000ffff) + (bits >> 16 & 0x0000ffff0000ffff);   //32bit
    return (bits + (bits >> 32)) & 0x000000000000007f;                        //64bit
}