#ifndef LEARNER_H
#define LEARNER_H

#include "board.h"
#include "evaluation.h"

// �w�K
void Learn();

// �]���֐��̏�����
void Reset_evaluate();

// �����̏�����
void Init_Grad2();

// �]���֐��̃R�s�[
void Copy_evaluate();

// �]���֐��̍X�V
void Update_evaluate(const BOARD *board, float t_value);

// �X�V�O��̕]���֐��̍�
double Evaluate_margin();

#endif LEARNER_H
