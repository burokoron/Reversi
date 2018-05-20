#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "search.h"

int node;
int rand_margin;
bool search_stop;
uint64_t move_pos_pv[100];
MOVES_PV moves_pv[100];
extern int entry_count;

// キラームーブ
void Killer_move(int *move_list, uint64_t legal_pos){
	int move_list_num=0;

	if((0x1&legal_pos)!=0) move_list[move_list_num++]=1;
	if((0x80&legal_pos)!=0) move_list[move_list_num++]=8;
	if((0x100000000000000&legal_pos)!=0) move_list[move_list_num++]=57;
	if((0x8000000000000000&legal_pos)!=0) move_list[move_list_num++]=64;
	if((0x4&legal_pos)!=0) move_list[move_list_num++]=3;
	if((0x20&legal_pos)!=0) move_list[move_list_num++]=6;
	if((0x10000&legal_pos)!=0) move_list[move_list_num++]=17;
	if((0x40000&legal_pos)!=0) move_list[move_list_num++]=19;
	if((0x200000&legal_pos)!=0) move_list[move_list_num++]=22;
	if((0x800000&legal_pos)!=0) move_list[move_list_num++]=24;
	if((0x10000000000&legal_pos)!=0) move_list[move_list_num++]=41;
	if((0x40000000000&legal_pos)!=0) move_list[move_list_num++]=43;
	if((0x200000000000&legal_pos)!=0) move_list[move_list_num++]=46;
	if((0x800000000000&legal_pos)!=0) move_list[move_list_num++]=48;
	if((0x400000000000000&legal_pos)!=0) move_list[move_list_num++]=59;
	if((0x2000000000000000&legal_pos)!=0) move_list[move_list_num++]=62;
	if((0x8&legal_pos)!=0) move_list[move_list_num++]=4;
	if((0x10&legal_pos)!=0) move_list[move_list_num++]=5;
	if((0x80000&legal_pos)!=0) move_list[move_list_num++]=20;
	if((0x100000&legal_pos)!=0) move_list[move_list_num++]=21;
	if((0x1000000&legal_pos)!=0) move_list[move_list_num++]=25;
	if((0x4000000&legal_pos)!=0) move_list[move_list_num++]=27;
	if((0x20000000&legal_pos)!=0) move_list[move_list_num++]=30;
	if((0x80000000&legal_pos)!=0) move_list[move_list_num++]=32;
	if((0x100000000&legal_pos)!=0) move_list[move_list_num++]=33;
	if((0x400000000&legal_pos)!=0) move_list[move_list_num++]=35;
	if((0x2000000000&legal_pos)!=0) move_list[move_list_num++]=38;
	if((0x8000000000&legal_pos)!=0) move_list[move_list_num++]=40;
	if((0x80000000000&legal_pos)!=0) move_list[move_list_num++]=44;
	if((0x100000000000&legal_pos)!=0) move_list[move_list_num++]=45;
	if((0x800000000000000&legal_pos)!=0) move_list[move_list_num++]=60;
	if((0x1000000000000000&legal_pos)!=0) move_list[move_list_num++]=61;
	if((0x400&legal_pos)!=0) move_list[move_list_num++]=11;
	if((0x800&legal_pos)!=0) move_list[move_list_num++]=12;
	if((0x1000&legal_pos)!=0) move_list[move_list_num++]=13;
	if((0x2000&legal_pos)!=0) move_list[move_list_num++]=14;
	if((0x20000&legal_pos)!=0) move_list[move_list_num++]=18;
	if((0x400000&legal_pos)!=0) move_list[move_list_num++]=23;
	if((0x2000000&legal_pos)!=0) move_list[move_list_num++]=26;
	if((0x40000000&legal_pos)!=0) move_list[move_list_num++]=31;
	if((0x200000000&legal_pos)!=0) move_list[move_list_num++]=34;
	if((0x4000000000&legal_pos)!=0) move_list[move_list_num++]=39;
	if((0x20000000000&legal_pos)!=0) move_list[move_list_num++]=42;
	if((0x400000000000&legal_pos)!=0) move_list[move_list_num++]=47;
	if((0x4000000000000&legal_pos)!=0) move_list[move_list_num++]=51;
	if((0x8000000000000&legal_pos)!=0) move_list[move_list_num++]=52;
	if((0x10000000000000&legal_pos)!=0) move_list[move_list_num++]=53;
	if((0x20000000000000&legal_pos)!=0) move_list[move_list_num++]=54;
	if((0x2&legal_pos)!=0) move_list[move_list_num++]=2;
	if((0x40&legal_pos)!=0) move_list[move_list_num++]=7;
	if((0x100&legal_pos)!=0) move_list[move_list_num++]=9;
	if((0x8000&legal_pos)!=0) move_list[move_list_num++]=16;
	if((0x1000000000000&legal_pos)!=0) move_list[move_list_num++]=49;
	if((0x80000000000000&legal_pos)!=0) move_list[move_list_num++]=56;
	if((0x200000000000000&legal_pos)!=0) move_list[move_list_num++]=58;
	if((0x4000000000000000&legal_pos)!=0) move_list[move_list_num++]=63;
	if((0x200&legal_pos)!=0) move_list[move_list_num++]=10;
	if((0x4000&legal_pos)!=0) move_list[move_list_num++]=15;
	if((0x2000000000000&legal_pos)!=0) move_list[move_list_num++]=50;
	if((0x40000000000000&legal_pos)!=0) move_list[move_list_num++]=55;
}

// ムーブオーダリング(中盤)
void Mid_move_ordering(int *move_list, int move_pos){
	int i=0, temp;

	if(move_pos==0) return;

	while(move_list[i++]!=0){
		if(move_list[i-1]==move_pos){
			temp=move_list[0];
			move_list[0]=move_list[i-1];
			move_list[i-1]=temp;
			break;
		}
	}
}

// ムーブオーダリング(読み切り)
void End_move_ordering(BOARD *board, int *move_list, int move_pos) {
	int i = 0, temp, num[60] = { 0 }, left = 0;
	uint64_t move, reverse_pos, legal_pos;

	if (move_pos != 0) {
		while (move_list[i++] != 0) {
			if (move_list[i - 1] == move_pos) {
				temp = move_list[0];
				move_list[0] = move_list[i - 1];
				move_list[i - 1] = temp;
				i = 1;
				left = 1;
				break;
			}
		}
	}

	while (move_list[i++] != 0) {
		move = (uint64_t)1 << (move_list[i - 1] - 1);
		reverse_pos = GetReverse(board, move);
		Do_move_nohash(board, move, reverse_pos);
		legal_pos = Move_picker(board);
		num[i - 1] = Count_stone(legal_pos);
		UnDo_move_nohash(board, move, reverse_pos);
	}
	if(i > 2) my_qsort(move_list, num, left, i - 2);
}

// 着手数の小さい順にソート
void my_qsort(int *move_list, int *num, int left, int right) {
	if (left<right) {
		int i = left, j = right;
		int temp_move_list, temp_num, pivod;

		pivod = move_list[i + (j - i) / 2];

		while (1) {
			while (move_list[i]<pivod) i++;
			while (move_list[j]>pivod) j--;
			if (i >= j) break;

			temp_move_list = move_list[i];
			move_list[i] = move_list[j];
			move_list[j] = temp_move_list;
			temp_num = num[i];
			num[i] = num[j];
			num[j] = temp_num;
			i++;
			j--;
		}

		my_qsort(move_list, num, left, i - 1);
		my_qsort(move_list, num, j + 1, right);
	}
}

// ランダムプレイヤー
uint64_t Random_search(BOARD *board){
	uint64_t legal_pos, move_pos=1;
	int move_list[64]={0}, move_list_num=0, move_randam;
	
	legal_pos=Move_picker(board);
	for(int i=1;i<65;i++){
		if((move_pos&legal_pos)!=0) move_list[move_list_num++]=i;
		move_pos<<=1;
	}
	move_randam=(move_list[rand()%move_list_num]-1);
	move_pos=(uint64_t)1<<move_randam;

	int i=0;
	return move_pos;
}

// PVS
double pvs(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth){
	int black_num, white_num, move_list[64]={0}, move_list_num=0, pass=-1, entry_num, best_move=0, best_pos=0, save_cluster[2]={-1, 100};
	double var, max=-MY_INFINITY;
	uint64_t legal_pos, reverse_pos, move_pos=1;

	entry_num=board->key&(entry_count-1);
	for(int i=0;i<3;i++){
		if(cluster[i].ttentry[entry_num].key==board->key){
			best_pos=cluster[i].ttentry[entry_num].move_pos;
			if(cluster[i].ttentry[entry_num].depth>=depth-deep&&cluster[i].ttentry[entry_num].depth!=0){
				if(cluster[i].ttentry[entry_num].lower>=beta){
					if(deep==0) move_pos_pv[0]=cluster[i].ttentry[entry_num].move_pos;
					return cluster[i].ttentry[entry_num].lower;
				}
				if(cluster[i].ttentry[entry_num].upper>=alpha||cluster[i].ttentry[entry_num].upper==cluster[i].ttentry[entry_num].lower){
					if(deep==0) move_pos_pv[0]=cluster[i].ttentry[entry_num].move_pos;
					return cluster[i].ttentry[entry_num].upper;
				}
				alpha = max(alpha, cluster[i].ttentry[entry_num].lower);
				beta = min(beta, cluster[i].ttentry[entry_num].upper);
			}
			break;
		}
		else if(cluster[i].ttentry[entry_num].key==0) break;
	}

	if((legal_pos=Move_picker(board))==0){
		pass=0;
		board->turn=change_turn(board->turn);
		if((legal_pos=Move_picker(board))==0){
			black_num=Count_stone(board->black);
			white_num=Count_stone(board->white);
			board->turn=change_turn(board->turn);
			if(board->turn==BLACK) return (black_num-white_num)/*100.0*/;
			else return (white_num-black_num)/*100.0*/;
		}
		board->turn=change_turn(board->turn);
	}

	if(deep>=depth) return Evaluate(board)+(float)(rand()%(101*rand_margin)-(51*rand_margin))/100.0;

	// prob cut
	if(depth-deep==5){
		double rbeta = beta + 3 + rand_margin + (60 - board->empty_num)*0.1;
		double ralpha = alpha - 3 - rand_margin - (60 - board->empty_num)*0.1;

		var = Mid_alphabeta(board, &cluster[0], ralpha-0.01, ralpha, 0, 3);
		if (ralpha >= var) return alpha;
	}
	else {
		if (depth - deep == 8) {
			double rbeta = beta + 3 + rand_margin + (60 - board->empty_num)*0.1;
			double ralpha = alpha - 3 - rand_margin - (60 - board->empty_num)*0.1;

			var = Mid_alphabeta(board, &cluster[0], rbeta, rbeta + 0.01, 0, 4);
			if (rbeta <= var) return beta;

			var = Mid_alphabeta(board, &cluster[0], ralpha - 0.01, ralpha, 0, 4);
			if (ralpha >= var) return alpha;
		}
		else {
			if (depth - deep == 12) {
				double rbeta = beta + 3 + rand_margin + (60 - board->empty_num)*0.1;
				double ralpha = alpha - 3 - rand_margin - (60 - board->empty_num)*0.1;

				var = Mid_alphabeta(board, &cluster[0], rbeta, rbeta + 0.01, 0, 6);
				if (rbeta <= var) return beta;

				var = Mid_alphabeta(board, &cluster[0], ralpha - 0.01, ralpha, 0, 6);
				if (ralpha >= var) return alpha;
			}
			else {
				if (depth - deep == 16) {
					double rbeta = beta + 3 + rand_margin + (60 - board->empty_num)*0.1;
					double ralpha = alpha - 3 - rand_margin - (60 - board->empty_num)*0.1;

					var = Mid_alphabeta(board, &cluster[0], rbeta, rbeta + 0.01, 0, 8);
					if (rbeta <= var) return beta;

					var = Mid_alphabeta(board, &cluster[0], ralpha - 0.01, ralpha, 0, 8);
					if (ralpha >= var) return alpha;
				}
				else{
					if (depth - deep == 20) {
						double rbeta = beta + 3 + rand_margin + (60 - board->empty_num)*0.1;
						double ralpha = alpha - 3 - rand_margin - (60 - board->empty_num)*0.1;

						var = Mid_alphabeta(board, &cluster[0], rbeta, rbeta + 0.01, 0, 10);
						if (rbeta <= var) return beta;

						var = Mid_alphabeta(board, &cluster[0], ralpha - 0.01, ralpha, 0, 10);
						if (ralpha >= var) return alpha;
					}
				}
			}
		}
	}

	if(pass==0){
		board->turn=change_turn(board->turn);
		var=-pvs(board, &cluster[0], -beta, -alpha, deep, depth);
		node++;
		board->turn=change_turn(board->turn);
		if(var>alpha){
			alpha=var;
			move_pos_pv[deep]=move_pos;
		}
		if (var > max) max = var;
	}
	else{
		Killer_move(move_list, legal_pos);
		Mid_move_ordering(move_list, best_pos);

		move_list_num=0;
		while (move_list[move_list_num] != 0 && alpha < beta) {
			move_pos = (uint64_t)1 << (move_list[move_list_num++] - 1);
			reverse_pos = GetReverse(board, move_pos);
			Do_move_hash(board, move_pos, reverse_pos);
			node++;
			if (depth - deep > 3) {
				if ((move_list_num - 1) == 0) var = -pvs(board, &cluster[0], -beta, -alpha, deep + 1, depth);
				else {
					var = -pvs(board, &cluster[0], -alpha - 0.01, -alpha, deep + 1, depth);
					if (alpha < var&&var < beta) var = -pvs(board, &cluster[0], -beta, -var, deep + 1, depth);
				}
			}
			else var = -Mid_alphabeta(board, &cluster[0], -beta, -alpha, deep + 1, depth);

			UnDo_move_hash(board, move_pos, reverse_pos);

			if (var > alpha) {
				alpha = var;
				best_move = move_list[move_list_num - 1];
			}
			if (var > max) max = var;
		}
	}
	if(search_stop==true) return 0;
	if(deep==0) move_pos_pv[0]=(uint64_t)1<<(best_move-1);
	for(int i=0;i<3;i++){
		if(cluster[i].ttentry[entry_num].key==board->key||cluster[i].ttentry[entry_num].key==0){
			if(cluster[i].ttentry[entry_num].depth<depth-deep){
				if(max <= alpha) Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)cluster[i].ttentry[entry_num].lower, (float)max, depth-deep-1);
				else if(max >= beta) Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)max, (float)cluster[i].ttentry[entry_num].upper, depth-deep-1);
				else Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)var, (float)var, depth-deep-1);
			}
			return max;
		}
		else if(save_cluster[1]>cluster[i].ttentry[entry_num].depth){
			save_cluster[1]=cluster[i].ttentry[entry_num].depth;
			save_cluster[0]=i;
		}
	}

	if(save_cluster[1]<depth-deep){
		if(max <= alpha) Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)cluster[save_cluster[0]].ttentry[entry_num].lower, (float)max, depth-deep-1);
		else if(max >= beta) Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)max, (float)cluster[save_cluster[0]].ttentry[entry_num].upper, depth-deep-1);
		else Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)var, (float)var, depth-deep-1);
	}
	
	return max;
}

// 単純alpha-beta(枝刈あり)
double Mid_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth) {
	int black_num, white_num, move_list[64] = { 0 }, move_list_num = 0, pass = -1, best_move = 0, best_pos = 0, save_cluster[2] = { -1, 100 }, futility_margin;
	double var, max = -MY_INFINITY;
	uint64_t legal_pos, reverse_pos, move_pos = 1;

	if ((legal_pos = Move_picker(board)) == 0) {
		pass = 0;
		board->turn = change_turn(board->turn);
		if ((legal_pos = Move_picker(board)) == 0) {
			black_num = Count_stone(board->black);
			white_num = Count_stone(board->white);
			board->turn = change_turn(board->turn);
			if (board->turn == BLACK) return (black_num - white_num)/*100.0*/;
			else return (white_num - black_num)/*100.0*/;
		}
		board->turn = change_turn(board->turn);
	}

	// futility cut
	if (futility_margin = depth - deep <=2) {
		var = Evaluate(board) + (float)(rand() % (101 * rand_margin) - (51 * rand_margin)) / 100.0;
		if (var < alpha - rand_margin - futility_margin * 3 || beta + rand_margin + futility_margin * 3 < var) return var;
	}

	if (deep >= depth) return var;

	if (pass == 0) {
		board->turn = change_turn(board->turn);
		var = -Mid_alphabeta(board, &cluster[0], -beta, -alpha, deep, depth);
		node++;
		board->turn = change_turn(board->turn);
		if (var>alpha) {
			alpha = var;
			move_pos_pv[deep] = move_pos;
		}
		if (var > max) max = var;
	}
	else {
		Killer_move(move_list, legal_pos);

		move_list_num = 0;
		while (move_list[move_list_num] != 0 && alpha<beta) {
			move_pos = (uint64_t)1 << (move_list[move_list_num++] - 1);
			reverse_pos = GetReverse(board, move_pos);
			Do_move_nohash(board, move_pos, reverse_pos);
			node++;
			var = -Mid_alphabeta(board, &cluster[0], -beta, -alpha, deep + 1, depth);

			UnDo_move_nohash(board, move_pos, reverse_pos);

			if (var>alpha) {
				alpha = var;
				move_pos_pv[deep] = move_pos;
				best_move = move_list[move_list_num - 1];
			}
			if (var > max) max = var;
		}
	}
	return max;
}

// 単純alpha-beta(枝刈なし)
double End_alphabeta(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth) {
	int black_num, white_num, move_list[64] = { 0 }, move_list_num = 0, pass = -1, best_move = 0, best_pos = 0, save_cluster[2] = { -1, 100 };
	double var, max=-MY_INFINITY;
	uint64_t legal_pos, reverse_pos, move_pos = 1;

	if ((legal_pos = Move_picker(board)) == 0) {
		pass = 0;
		board->turn = change_turn(board->turn);
		if ((legal_pos = Move_picker(board)) == 0) {
			black_num = Count_stone(board->black);
			white_num = Count_stone(board->white);
			board->turn = change_turn(board->turn);
			if (board->turn == BLACK) return (black_num - white_num)/*100.0*/;
			else return (white_num - black_num)/*100.0*/;
		}
		board->turn = change_turn(board->turn);
	}

	if (board->empty_num==0) {
		black_num = Count_stone(board->black);
		white_num = Count_stone(board->white);
		if (board->turn == BLACK) return (black_num - white_num)/*100.0*/;
		else return (white_num - black_num)/*100.0*/;
	}
	if(deep>=depth) return Evaluate(board) + (float)(rand() % (101 * rand_margin) - (51 * rand_margin)) / 100.0;

	if (pass == 0) {
		board->turn = change_turn(board->turn);
		var = -End_alphabeta(board, &cluster[0], -beta, -alpha, deep, depth);
		node++;
		board->turn = change_turn(board->turn);
		if (var>alpha) {
			alpha = var;
			move_pos_pv[deep] = move_pos;
		}
		if(var>max) max = var;
	}
	else {
		Killer_move(move_list, legal_pos);

		move_list_num = 0;
		while (move_list[move_list_num] != 0 && alpha<beta) {
			move_pos = (uint64_t)1 << (move_list[move_list_num++] - 1);
			reverse_pos = GetReverse(board, move_pos);
			if (board->empty_num == 1) {
				black_num = Count_stone(board->black);
				white_num = Count_stone(board->white);
				if (board->turn == BLACK) return (black_num - white_num+2*Count_stone(reverse_pos)+1)/*100.0*/;
				else return (white_num - black_num + 2 * Count_stone(reverse_pos) + 1)/*100.0*/;
			}
			Do_move_nohash(board, move_pos, reverse_pos);
			node++;
			var = -End_alphabeta(board, &cluster[0], -beta, -alpha, deep + 1, depth);

			UnDo_move_nohash(board, move_pos, reverse_pos);
			if (var > alpha) {
				alpha = var;
				move_pos_pv[deep] = move_pos;
				best_move = move_list[move_list_num - 1];
			}
			if (var > max) max = var;
		}
	}
	return max;
}

// 完全読み切り
double End_search(BOARD *board, CLUSTER *cluster, double alpha, double beta, int deep, int depth){
	int black_num, white_num, move_list[64]={0}, move_list_num=0, pass=-1, entry_num, best_move=0, best_pos=0, save_cluster[2]={-1, 100};
	double var, max=-MY_INFINITY;
	uint64_t legal_pos, reverse_pos, move_pos=1;

	entry_num = board->key&(entry_count - 1);
	for (int i = 0;i<3;i++) {
		if (cluster[i].ttentry[entry_num].key == board->key) {
			best_pos = cluster[i].ttentry[entry_num].move_pos;
			if (cluster[i].ttentry[entry_num].depth >= depth - deep&&cluster[i].ttentry[entry_num].depth != 0) {
				if (cluster[i].ttentry[entry_num].lower >= beta) {
					if (deep == 0) move_pos_pv[0] = cluster[i].ttentry[entry_num].move_pos;
					return cluster[i].ttentry[entry_num].lower;
				}
				if (cluster[i].ttentry[entry_num].upper >= alpha || cluster[i].ttentry[entry_num].upper == cluster[i].ttentry[entry_num].lower) {
					if (deep == 0) move_pos_pv[0] = cluster[i].ttentry[entry_num].move_pos;
					return cluster[i].ttentry[entry_num].upper;
				}
				alpha = max(alpha, cluster[i].ttentry[entry_num].lower);
				beta = min(beta, cluster[i].ttentry[entry_num].upper);
			}
			break;
		}
		else if (cluster[i].ttentry[entry_num].key == 0) break;
	}

	if((legal_pos=Move_picker(board))==0){
		pass=0;
		board->turn=change_turn(board->turn);
		if((legal_pos=Move_picker(board))==0){
			black_num=Count_stone(board->black);
			white_num=Count_stone(board->white);
			board->turn=change_turn(board->turn);
			if(board->turn==BLACK) return (black_num-white_num)/*100.0*/;
			else return (white_num-black_num)/*100.0*/;
		}
		board->turn=change_turn(board->turn);
	}

	if(deep >= depth){
		black_num=Count_stone(board->black);
		white_num=Count_stone(board->white);
		if(board->turn==BLACK) return (black_num-white_num)/*100.0*/;
		else return (white_num-black_num)/*100.0*/;
	}

	if(pass==0){
		board->turn=change_turn(board->turn);
		var=-End_search(board, &cluster[0], -beta, -alpha, deep, depth);
		node++;
		board->turn=change_turn(board->turn);
		if(var>alpha){
			alpha=var;
			move_pos_pv[deep]=move_pos;
		}
		if(var>max) max = var;
	}
	else{
		Killer_move(move_list, legal_pos);
		Mid_move_ordering(move_list, best_pos);

		move_list_num=0;
		while(move_list[move_list_num]!=0&&alpha<beta){
			move_pos=(uint64_t)1<<(move_list[move_list_num++]-1);
			reverse_pos=GetReverse(board, move_pos);
			Do_move_hash(board, move_pos, reverse_pos);
			node++;
			if (depth - deep > 9 ) {
				if ((move_list_num - 1) == 0) {
					var = -End_search(board, &cluster[0], -beta, -alpha, deep + 1, depth);
				}
				else {
					var = -End_search(board, &cluster[0], -alpha - 1, -alpha, deep + 1, depth);
					if (alpha < var&&var < beta) var = -End_search(board, &cluster[0], -beta, -var, deep + 1, depth);
				}
			}
			else var = -End_alphabeta(board, &cluster[0], -beta, -alpha, deep + 1, depth);
			
			UnDo_move_hash(board, move_pos, reverse_pos);

			if(var>alpha){
				alpha=var;
				move_pos_pv[deep]=move_pos;
				best_move=move_list[move_list_num-1];
			}
			if (var > max) max = var;
		}
	}

	if (search_stop == true) return 0;
	if (deep == 0) move_pos_pv[0] = (uint64_t)1 << (best_move - 1);
	for (int i = 0;i<3;i++) {
		if (cluster[i].ttentry[entry_num].key == board->key || cluster[i].ttentry[entry_num].key == 0) {
			if (cluster[i].ttentry[entry_num].depth<depth - deep) {
				if (max <= alpha) Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)cluster[i].ttentry[entry_num].lower, (float)max, depth - deep - 1);
				else if (max >= beta) Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)max, (float)cluster[i].ttentry[entry_num].upper, depth - deep - 1);
				else Save_tt(&cluster[i].ttentry[0], best_move, board->key, (float)var, (float)var, depth - deep - 1);
			}
			return max;
		}
		else if (save_cluster[1]>cluster[i].ttentry[entry_num].depth) {
			save_cluster[1] = cluster[i].ttentry[entry_num].depth;
			save_cluster[0] = i;
		}
	}

	if (save_cluster[1]<depth - deep) {
		if (max <= alpha) Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)cluster[save_cluster[0]].ttentry[entry_num].lower, (float)max, depth - deep - 1);
		else if (max >= beta) Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)max, (float)cluster[save_cluster[0]].ttentry[entry_num].upper, depth - deep - 1);
		else Save_tt(&cluster[save_cluster[0]].ttentry[0], best_move, board->key, (float)var, (float)var, depth - deep - 1);
	}

	return max;
}