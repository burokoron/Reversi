#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "main.h"

int update_flag=0;

// 手の入力
uint64_t Input(const BOARD *board, uint64_t legal_pos)
{
	uint64_t move_pos;
	char move[3];
	do{
		do{
			if(board->turn==BLACK){
				printf("先手番(黒)、手を入力して下さい。: ");
				scanf_s(" %s", move, 3);
			}
			else{
				printf("後手番(白)、手を入力して下さい。: ");
				scanf_s(" %s", move, 3);
			}
		}while ((move[0]<'a'||'h'<move[0])||(move[1]<'1'||'8'<move[1]));
		
		move_pos=(uint64_t)1<<(7-move[0]+'a'+8*(7-move[1]+'1'));

	}while ((legal_pos&move_pos)==0);

	return move_pos;
}

// 盤面の出力
void Output_board(const BOARD *board)
{
	uint64_t pos = (uint64_t)1<<63;

	printf(" ａｂｃｄｅｆｇｈ\n");
	for(int i=0;i<64;i++){
		if(i%8==0){
			printf("%d", i/8+1);
		}
		if((board->black&pos)!=0) printf("○");
		else if((board->white&pos)!=0) printf("●");
		else printf("－");
		
		if(i % 8 == 7) printf("\n");

		pos >>= 1;
	}

	printf("\n");
}

// 勝敗
int Result(const BOARD *board){
	int black_num, white_num;

	black_num=Count_stone(board->black);
	white_num=Count_stone(board->white);

	printf("先手番(黒)：%d\n", black_num);
	printf("後手番(白)：%d\n", white_num);
	if(black_num>white_num){
		printf("先手番(黒)の勝ち\n");
		printf("\n");
		return BLACK;
	}
	else if(white_num>black_num){
		printf("後手番(白)の勝ち\n");
		printf("\n");
		return WHITE;
	}
	else{
		printf("引き分け\n");
		printf("\n");
		return -1;
	}
}

// コンピュータの思考
uint64_t Com_think(BOARD *board, int level){
	double var = 0, start, end;
	int hash_rate=0;
	int node_max[]={0, 0, 0, 0, 0, 0, 0, 3, 3, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 30};
	int margin[]={100, 100, 100, 100, 50, 25, 10, 10, 3, 10, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1};
	CLUSTER cluster[3];
	
	node=0;
	entry_count=1048576;
	search_stop=false;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			moves_pv[i].move[j]=0;
		}
	}

	for(int i=0;i<100;i++){
		move_pos_pv[i]=0;
	}

	if(level==1) return Random_search(board);
	else if(level==2&&rand()%4!=0) return Random_search(board);
	else if (level == 3 && rand() % 2 != 0) return Random_search(board);
	else if (level == 4 && rand() % 4 == 0) return Random_search(board);
	else{
		if(level>=8){
			var = (double)Book_search(board, 35-level);
			if(fabs(var)!=9999){
				if (board->turn == WHITE) var *= -1;
				printf("BOOK\n");
				printf("value = %.2lf\n", var);
				return move_pos_pv[0];
			}
		}
		for(int i=0;i<3;i++){
			cluster[i].ttentry = (TTENTRY*)calloc(entry_count, sizeof(TTENTRY));
		}
		rand_margin = margin[level - 2];
		printf("depth, move,  value,      nodes, hash_rate,   time,     nps\n");
		start=clock();
		for(int depth=1;depth<60;depth++){
			if (board->empty_num == depth) {
				//if (depth > 19 && level < 31) break;
				var = End_search(board, &cluster[0], -MY_INFINITY, MY_INFINITY, 0, depth);
				end = clock();
				hash_rate = 0;
				for (int j = 0;j < 3;j++) {
					for (int i = 0;i < entry_count;i++) {
						if (cluster[j].ttentry[i].depth > 0) hash_rate++;
					}
				}
				uint64_t com_move_pos = 1;
				int i;
				for (i = 0;i<64;i++) {
					if ((move_pos_pv[0] & com_move_pos) != 0) break;
					com_move_pos <<= 1;
				}
				if (end - start == 0) printf("%5d,   %c%d, %6.0f, %10d, %9.2f, %6.2f, %7d\n", depth, 7 - i % 8 + 'a', 8 - i / 8, var, node, (float)(hash_rate * 100) / (float)(entry_count * 3), (end - start) / CLOCKS_PER_SEC, node);
				else printf("%5d,   %c%d, %6.0f, %10d, %9.2f, %6.2f, %7d\n", depth, 7 - i % 8 + 'a', 8 - i / 8, var, node, (float)(hash_rate * 100) / (float)(entry_count * 3), (end - start) / CLOCKS_PER_SEC, (int)((double)node / ((end - start) / CLOCKS_PER_SEC)));
				break;
			}
			var=pvs(board, &cluster[0], -MY_INFINITY, MY_INFINITY, 0, depth);
			end=clock();
			hash_rate=0;
			for(int j=0;j<3;j++){
				for(int i=0;i<entry_count;i++){
					if(cluster[j].ttentry[i].depth>0) hash_rate++;
				}
			}
			uint64_t com_move_pos = 1;
			int i;
			for (i = 0;i<64;i++) {
				if ((move_pos_pv[0]&com_move_pos) != 0) break;
				com_move_pos <<= 1;
			}
			if(end-start==0) printf("%5d,   %c%d, %6.2f, %10d, %9.2f, %6.2f, %7d\n", depth, 7 - i % 8 + 'a', 8 - i / 8, var, node, (float)(hash_rate * 100) / (float)(entry_count * 3), (end - start) / CLOCKS_PER_SEC, node);
			else printf("%5d,   %c%d, %6.2f, %10d, %9.2f, %6.2f, %7d\n",depth, 7 - i % 8 + 'a', 8 - i / 8, var, node, (float)(hash_rate*100)/(float)(entry_count*3), (end-start)/CLOCKS_PER_SEC, (int)((double)node/((end-start)/CLOCKS_PER_SEC)));

			if (node >= pow(2.0, node_max[level - 2]) /*|| (depth > 20 && level <31)*/) break;
		}
	}

	for(int i=0;i<3;i++){
		Delete_tt(cluster[i].ttentry);
	}
	
	return move_pos_pv[0];
}

// 学習用の思考
/*uint64_t Learn_think(BOARD *board, int depth){
	double var=0, start, end, margin, update;
	int hash_rate=0;
	CLUSTER cluster[3];

	node=0;
	entry_count=1048576;
	search_stop=false;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			moves_pv[i].move[j]=0;
		}
	}

	for(int i=0;i<100;i++){
		move_pos_pv[i]=0;
	}

	for(int i=0;i<3;i++){
		cluster[i].ttentry = (TTENTRY*)calloc(entry_count, sizeof(TTENTRY));
	}

	for(int i=1;i<60;i++){
		var=pvs(board, &cluster[0], -MY_INFINITY, MY_INFINITY, 0, i);
		if(board->empty_num==i) var=End_search(board, &cluster[0], -MY_INFINITY, MY_INFINITY, 0, i);
		if(board->empty_num==i) break;
		if(node>1048576) break;
	}

	for(int i=0;i<3;i++){
		Delete_tt(cluster[i].ttentry);
	}
	
	if(fabs(var)>=100.0) var=var/100.0;
	if(fabs(var)<=10.0){
	margin=var-Evaluate(board);
	sum_update+=fabs(margin);
	update=(1.0/42.0)*margin;
	Update_evaluate(board, update);
	}else update_flag=1;

	
	return move_pos_pv[0];
}*/

// コンピュータの打ち手の出力
void Output_com_move(const BOARD *board, uint64_t move_pos){
	uint64_t com_move_pos=1;
	int i;
	for(i=0;i<64;i++){
		if((move_pos&com_move_pos)!=0) break;
		com_move_pos<<=1;
	}

	if(board->turn==BLACK) printf("先手番(黒)の手：");
	else printf("後手番(白)の手：");
	printf("%c%d\n", 7-i%8+'a', 8-i/8);
}

// 人間vs人間
void Man_vs_man(void)
{
	BOARD board;
	uint64_t move_pos, legal_pos, reverse_pos;
	
	Init_board(&board);

	Output_board(&board);

	do{
		if((legal_pos=Move_picker(&board))==0){
			if(board.turn==BLACK) board.turn=WHITE;
			else if(board.turn==WHITE) board.turn=BLACK;
			if((legal_pos=Move_picker(&board))==0) break;
			else if(board.turn==BLACK){
				printf("先手番(白): パス\n");
				board.move_num++;
			}
			else{
				printf("後手番(黒): パス\n");
				board.move_num++;
			}
		}
		move_pos=Input(&board, legal_pos);
		reverse_pos=GetReverse(&board, move_pos);
		Do_move_hash(&board, move_pos, reverse_pos);
		Output_board(&board);
	}while (true);
	
	Result(&board);
}

// 人間vsコンピュータ
void Man_vs_com(int level){
	BOARD board;
	uint64_t move_pos, legal_pos, reverse_pos;
	int turn_man;
	
	Init_board(&board);
	srand((unsigned)time(NULL));
	if(rand()%2==0) turn_man=BLACK;
	else turn_man=WHITE;

	Output_board(&board);
	do{
		if((legal_pos=Move_picker(&board))==0){
			if(board.turn==BLACK) board.turn=WHITE;
			else if(board.turn==WHITE) board.turn=BLACK;
			if((legal_pos=Move_picker(&board))==0) break;
			else if(board.turn==BLACK){
				printf("先手番(白): パス\n");
				board.move_num++;
			}
			else{
				printf("後手番(黒): パス\n");
				board.move_num++;
			}
		}
		if(board.turn==turn_man) move_pos=Input(&board, legal_pos);
		else{
			move_pos=Com_think(&board, level);
			Output_com_move(&board, move_pos);
		}
		reverse_pos=GetReverse(&board, move_pos);
		Do_move_hash(&board, move_pos, reverse_pos);
		Output_board(&board);
	}while (true);
	
	Result(&board);
}

// コンピュータvsコンピュータ
int Com_vs_com(int com_1_level, int com_2_level){
	BOARD board;
	uint64_t move_pos, legal_pos, reverse_pos;
	int num = 0;;
	
	Init_board(&board);

	while (rand() % 20 != 0) {
		num++;
		if (num >= 30) break;
	}num = 0;

	Output_board(&board);
	do{
		if((legal_pos=Move_picker(&board))==0){
			if(board.turn==BLACK) board.turn=WHITE;
			else if(board.turn==WHITE) board.turn=BLACK;
			if((legal_pos=Move_picker(&board))==0) break;
			else if(board.turn==BLACK){
				printf("先手番(白): パス\n");
				board.move_num++;
			}
			else{
				printf("後手番(黒): パス\n");
				board.move_num++;
			}
		}
		if (num > board.move_num) move_pos = Com_think(&board, 31);
		else {
			if (board.turn == BLACK) move_pos = Com_think(&board, com_1_level);
			else move_pos = Com_think(&board, com_2_level);
		}
		Output_com_move(&board, move_pos);
		reverse_pos=GetReverse(&board, move_pos);
		Do_move_hash(&board, move_pos, reverse_pos);
		Output_board(&board);
	}while (true);
	
	return Result(&board);
}

// ベンチマーク
void ffo(){
	BOARD board;
	uint64_t move_pos;
	char position[] = "O--OOOOX-OOOOOOXOOXXOOOXOOXOOOXXOOOOOOXX---OOOOX----O--X--------";
	int turn = BLACK;

	Init_ffo(&board, position, turn);
	Output_board(&board);

	move_pos=Com_think(&board, 32);
	Output_com_move(&board, move_pos);
}

int main(void)
{
	int number, level[2], winner, win[2], game;
	double start, end;
	char str[100];

	srand((unsigned)time(NULL));
	Init_Evaluate_function();

	do{
		do{
			printf("1. 人 VS 人  2. 人 VS COM  3. COM VS COM 4. 学習 5. ベンチマーク\n");
			printf("番号を入力: ");
			scanf_s("%s", str, 100);
			number=atoi(str);
		}while(number<1||5<number);
		
		switch(number){
		    case 1:
				Man_vs_man();
				break;
			case 2:
				do{
					printf("COMのレベル(1-34)を入力: ");
					scanf_s("%s", str, 100);
					level[0]=atoi(str);
				}while(level[0]<1||34<level[0]);
				Man_vs_com(level[0]);
				break;
			case 3:
				do{
					printf("COM_1のレベル(1-34)を入力: ");
					scanf_s("%s", str, 100);
					level[0]=atoi(str);
				}while(level[0]<1||34<level[0]);
				do{
					printf("COM_2のレベル(1-34)を入力: ");
					scanf_s("%s", str, 100);
					level[1]=atoi(str);
				}while(level[1]<1||34<level[1]);
				do {
					printf("対局数(偶数)を入力: ");
					scanf_s("%s", str, 100);
					game = atoi(str);
				} while (game%2==1);

				win[0]=0;
				win[1]=0;
				
				start=clock();
				for(int i=0;i<game/2;i++){
					winner=Com_vs_com(level[0], level[1]);
					switch(winner){
						case BLACK:
							win[0]++;
							break;
						case WHITE:
							win[1]++;
							break;
					}
				}
				for (int i = 0;i < game/2;i++) {
					winner=Com_vs_com(level[1], level[0]);
					switch(winner){
						case BLACK:
							win[1]++;
							break;
						case WHITE:
							win[0]++;
							break;
					}
				}
				end=clock();
				printf("COM_1: %d勝\n", win[0]);
				printf("COM_2: %d勝\n", win[1]);
				printf("引分 : %d回\n", game-win[0]-win[1]);
				printf("総思考時間: %f\n", (end-start)/CLOCKS_PER_SEC);
				break;
			case 4:
				Learn();
				break;
			case 5:
				ffo();
				break;
		}

		do{
			printf("もう一度やりますか？ (y/n): ");
			scanf_s(" %s", str, 100);
			printf("\n");
		}while(str[0]!='y'&&str[0]!='n');
	}while(str[0]=='y');
	
	return 0;
}
