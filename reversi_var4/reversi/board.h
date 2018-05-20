#ifndef BOARD_H
#define BOARD_H

//���
enum TURN{
	BLACK = 0, //���
	WHITE = 1 //���
};

// �Ֆ�
typedef struct BOARD{
	uint64_t black, white; //�΂̔z�u
	int turn; //���
	int move_num, empty_num; //�萔, �󂫃}�X�̐�
	uint64_t key; //�n�b�V���l
}BOARD;

// �Ֆʂ̏�����
void Init_board(BOARD *board);

//�@�x���`�}�[�N�̔Ֆʂ̏�����
void Init_ffo(BOARD *board, char *position, int turn);

// ���@�萶��
uint64_t Move_picker(const BOARD *board);

// �΂̔��]�p�^�[��
uint64_t GetReverse(BOARD *board, uint64_t move_pos);

// 1��i�߂�(hash�L��)
void Do_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1��i�߂�(hash����)
void Do_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1��߂�(hash�L��)
void UnDo_move_hash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

// 1��߂�(hash����)
void UnDo_move_nohash(BOARD *board, uint64_t move_pos, uint64_t reverse_pos);

//�΂𐔂���
int Count_stone(uint64_t bits);

#endif