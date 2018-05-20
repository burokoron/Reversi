#ifndef LEARNER_H
#define LEARNER_H

#include "board.h"
#include "evaluation.h"

// 学習
void Learn();

// 評価関数の初期化
void Reset_evaluate();

// 損失の初期化
void Init_Grad2();

// 評価関数のコピー
void Copy_evaluate();

// 評価関数の更新
void Update_evaluate(const BOARD *board, float t_value);

// 更新前後の評価関数の差
double Evaluate_margin();

#endif LEARNER_H
