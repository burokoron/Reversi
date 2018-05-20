#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#include "evaluation.h"

float pattern_1_yellow[59][6561];
float pattern_1_green[59][6561];
float pattern_1_blue[59][6561];
float pattern_2_red[59][81];
float pattern_2_yellow[59][243];
float pattern_2_green[59][729];
float pattern_2_blue[59][2187];
float pattern_2_purple[59][6561];
float pattern_3_red[59][19683];
float pattern_4_red[59][59049];
float pattern_5_red[59][59049];

//@•]‰¿ŠÖ”‚ğ“Ç‚İ‚Ş
void Init_Evaluate_function(){
	int i, j, count = 0;
	FILE *fp;

	if(fopen_s(&fp, "evaluation.bin", "rb")!=0){
		printf("No file\n");
		exit(1);
	}

	for(i=0;i<59;i++){
		for(j=0;j<6561;j++){
			if (count == 0) {
				fread(&pattern_1_yellow[i][j], sizeof(float), 1, fp);
				if (pattern_1_yellow[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_1_yellow[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<6561;j++){
			if (count == 0) {
				fread(&pattern_1_green[i][j], sizeof(float), 1, fp);
				if (pattern_1_green[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_1_green[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<6561;j++){
			if (count == 0) {
				fread(&pattern_1_blue[i][j], sizeof(float), 1, fp);
				if (pattern_1_blue[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_1_blue[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<81;j++){
			if (count == 0) {
				fread(&pattern_2_red[i][j], sizeof(float), 1, fp);
				if (pattern_2_red[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_2_red[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<243;j++){
			if (count == 0) {
				fread(&pattern_2_yellow[i][j], sizeof(float), 1, fp);
				if (pattern_2_yellow[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_2_yellow[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<729;j++){
			if (count == 0) {
				fread(&pattern_2_green[i][j], sizeof(float), 1, fp);
				if (pattern_2_green[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_2_green[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<2187;j++){
			if (count == 0) {
				fread(&pattern_2_blue[i][j], sizeof(float), 1, fp);
				if (pattern_2_blue[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_2_blue[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<6561;j++){
			if (count == 0) {
				fread(&pattern_2_purple[i][j], sizeof(float), 1, fp);
				if (pattern_2_purple[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_2_purple[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<19683;j++){
			if (count == 0) {
				fread(&pattern_3_red[i][j], sizeof(float), 1, fp);
				if (pattern_3_red[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_3_red[i][j] = 0.0;
				count--;
			}
		}
	}
	
	for(i=0;i<59;i++){
		for(j=0;j<59049;j++){
			if (count == 0) {
				fread(&pattern_4_red[i][j], sizeof(float), 1, fp);
				if (pattern_4_red[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_4_red[i][j] = 0.0;
				count--;
			}
		}
	}

	for(i=0;i<59;i++){
		for(j=0;j<59049;j++){
			if (count == 0) {
				fread(&pattern_5_red[i][j], sizeof(float), 1, fp);
				if (pattern_5_red[i][j] == 0.0) {
					fread(&count, sizeof(int), 1, fp);
					count--;
				}
			}
			else {
				pattern_5_red[i][j] = 0.0;
				count--;
			}
		}
	}

	fclose(fp);
}

//	•]‰¿ŠÖ”‚ğ‘‚«‚Ş
void Write_evaluate(){
	int i, j, count;
	float zero = 0.0;
	FILE *fp;

	if (fopen_s(&fp, "evaluation.bin", "wb+") != 0) {
		printf("No file\n");
		exit(1);
	}

	count = 0;

	for (i = 0;i<59;i++) {
		for (j = 0;j<6561;j++) {
			if (pattern_1_yellow[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_1_yellow[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_1_yellow[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<6561;j++) {
			if (pattern_1_green[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_1_green[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_1_green[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<6561;j++) {
			if (pattern_1_blue[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_1_blue[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_1_blue[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<81;j++) {
			if (pattern_2_red[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_2_red[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_2_red[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<243;j++) {
			if (pattern_2_yellow[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_2_yellow[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_2_yellow[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<729;j++) {
			if (pattern_2_green[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_2_green[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_2_green[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<2187;j++) {
			if (pattern_2_blue[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_2_blue[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_2_blue[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<6561;j++) {
			if (pattern_2_purple[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_2_purple[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_2_purple[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<19683;j++) {
			if (pattern_3_red[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_3_red[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_3_red[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<59049;j++) {
			if (pattern_4_red[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_4_red[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_4_red[i][j], sizeof(float), 1, fp);
		}
	}

	for (i = 0;i<59;i++) {
		for (j = 0;j<59049;j++) {
			if (pattern_5_red[i][j] == 0.0) count++;
			else if (count != 0) {
				fwrite(&zero, sizeof(float), 1, fp);
				fwrite(&count, sizeof(int), 1, fp);
				fwrite(&pattern_5_red[i][j], sizeof(float), 1, fp);
				count = 0;
			}
			else fwrite(&pattern_5_red[i][j], sizeof(float), 1, fp);
		}
	}

	fclose(fp);
}

//@•]‰¿’l‚ğ•Ô‚·
double Evaluate(const BOARD *board){
	double value=0;
	int pattern_1_yellow_index[4]={0}, pattern_1_green_index[4]={0}, pattern_1_blue_index[4]={0};
	int pattern_2_red_index[4]={0}, pattern_2_yellow_index[4]={0}, pattern_2_green_index[4]={0}, pattern_2_blue_index[4]={0}, pattern_2_purple_index[4]={0};
	int pattern_3_red_index[4]={0};
	int pattern_4_red_index[4]={0};
	int pattern_5_red_index[8]={0};

	if((0x1&board->black)!=0){//h8
		pattern_2_purple_index[1]+=0x1;
		pattern_3_red_index[3]+=0x19A1;
		pattern_4_red_index[1]+=0x9;
		pattern_4_red_index[2]+=0x4CE3;
		pattern_5_red_index[3]+=0x51;
		pattern_5_red_index[4]+=0x4CE3;
	}else if((0x1&board->white)!=0){
		pattern_2_purple_index[1]+=0x2;
		pattern_3_red_index[3]+=0x3342;
		pattern_4_red_index[1]+=0x12;
		pattern_4_red_index[2]+=0x99C6;
		pattern_5_red_index[3]+=0xA2;
		pattern_5_red_index[4]+=0x99C6;
	}
	if((0x2&board->black)!=0){//g8
		pattern_1_yellow_index[3]+=0x1;
		pattern_2_blue_index[3]+=0x1;
		pattern_3_red_index[3]+=0x88B;
		pattern_4_red_index[2]+=0x19A1;
		pattern_5_red_index[3]+=0x1;
		pattern_5_red_index[4]+=0x19A1;
	}else if((0x2&board->white)!=0){
		pattern_1_yellow_index[3]+=0x2;
		pattern_2_blue_index[3]+=0x2;
		pattern_3_red_index[3]+=0x1116;
		pattern_4_red_index[2]+=0x3342;
		pattern_5_red_index[3]+=0x2;
		pattern_5_red_index[4]+=0x3342;
	}
	if((0x4&board->black)!=0){//f8
		pattern_1_green_index[3]+=0x1;
		pattern_2_green_index[3]+=0x1;
		pattern_3_red_index[3]+=0x2D9;
		pattern_4_red_index[2]+=0x88B;
		pattern_5_red_index[4]+=0x88B;
	}else if((0x4&board->white)!=0){
		pattern_1_green_index[3]+=0x2;
		pattern_2_green_index[3]+=0x2;
		pattern_3_red_index[3]+=0x5B2;
		pattern_4_red_index[2]+=0x1116;
		pattern_5_red_index[4]+=0x1116;
	}
	if((0x8&board->black)!=0){//e8
		pattern_1_blue_index[3]+=0x1;
		pattern_2_red_index[1]+=0x1;
		pattern_2_yellow_index[3]+=0x1;
		pattern_4_red_index[2]+=0x2D9;
		pattern_5_red_index[4]+=0x2D9;
		pattern_5_red_index[5]+=0xF3;
	}else if((0x8&board->white)!=0){
		pattern_1_blue_index[3]+=0x2;
		pattern_2_red_index[1]+=0x2;
		pattern_2_yellow_index[3]+=0x2;
		pattern_4_red_index[2]+=0x5B2;
		pattern_5_red_index[4]+=0x5B2;
		pattern_5_red_index[5]+=0x1E6;
	}
	if((0x10&board->black)!=0){//d8
		pattern_1_blue_index[2]+=0x1;
		pattern_2_yellow_index[1]+=0x1;
		pattern_2_red_index[3]+=0x1;
		pattern_4_red_index[2]+=0xF3;
		pattern_5_red_index[4]+=0xF3;
		pattern_5_red_index[5]+=0x2D9;
	}else if((0x10&board->white)!=0){
		pattern_1_blue_index[2]+=0x2;
		pattern_2_yellow_index[1]+=0x2;
		pattern_2_red_index[3]+=0x2;
		pattern_4_red_index[2]+=0x1E6;
		pattern_5_red_index[4]+=0x1E6;
		pattern_5_red_index[5]+=0x5B2;
	}
	if((0x20&board->black)!=0){///c8
		pattern_1_green_index[2]+=0x1;
		pattern_2_green_index[1]+=0x1;
		pattern_3_red_index[2]+=0x2D9;
		pattern_4_red_index[2]+=0x51;
		pattern_5_red_index[5]+=0x88B;
	}else if((0x20&board->white)!=0){
		pattern_1_green_index[2]+=0x2;
		pattern_2_green_index[1]+=0x2;
		pattern_3_red_index[2]+=0x5B2;
		pattern_4_red_index[2]+=0xA2;
		pattern_5_red_index[5]+=0x1116;
	}
	if((0x40&board->black)!=0){//b8
		pattern_1_yellow_index[2]+=0x1;
		pattern_2_blue_index[1]+=0x1;
		pattern_3_red_index[2]+=0x88B;
		pattern_4_red_index[2]+=0x1B;
		pattern_5_red_index[5]+=0x19A1;
		pattern_5_red_index[6]+=0x51;
	}else if((0x40&board->white)!=0){
		pattern_1_yellow_index[2]+=0x2;
		pattern_2_blue_index[1]+=0x2;
		pattern_3_red_index[2]+=0x1116;
		pattern_4_red_index[2]+=0x36;
		pattern_5_red_index[5]+=0x3342;
		pattern_5_red_index[6]+=0xA2;
	}
	if((0x80&board->black)!=0){//a8
		pattern_2_purple_index[0]+=0x1;
		pattern_3_red_index[2]+=0x51;
		pattern_4_red_index[2]+=0x9;
		pattern_4_red_index[3]+=0x4CE3;
		pattern_5_red_index[5]+=0x4CE3;
		pattern_5_red_index[6]+=0x4CE3;
	}else if((0x80&board->white)!=0){
		pattern_2_purple_index[0]+=0x2;
		pattern_3_red_index[2]+=0xA2;
		pattern_4_red_index[2]+=0x12;
		pattern_4_red_index[3]+=0x99C6;
		pattern_5_red_index[5]+=0x99C6;
		pattern_5_red_index[6]+=0x99C6;
	}
	if((0x100&board->black)!=0){//h7
		pattern_1_yellow_index[1]+=0x1;
		pattern_2_blue_index[2]+=0x1;
		pattern_3_red_index[3]+=0xF3;
		pattern_4_red_index[1]+=0x1B;
		pattern_5_red_index[3]+=0x19A1;
		pattern_5_red_index[4]+=0x51;
	}else if((0x100&board->white)!=0){
		pattern_1_yellow_index[1]+=0x2;
		pattern_2_blue_index[2]+=0x2;
		pattern_3_red_index[3]+=0x1E6;
		pattern_4_red_index[1]+=0x36;
		pattern_5_red_index[3]+=0x3342;
		pattern_5_red_index[4]+=0xA2;
	}
	if((0x200&board->black)!=0){//g7
		pattern_1_yellow_index[1]+=0x3;
		pattern_1_yellow_index[3]+=0x3;
		pattern_2_purple_index[1]+=0x3;
		pattern_3_red_index[3]+=0x51;
		pattern_4_red_index[1]+=0x1;
		pattern_4_red_index[2]+=0x3;
		pattern_5_red_index[3]+=0x1B;
		pattern_5_red_index[4]+=0x1B;
	}else if((0x200&board->white)!=0){
		pattern_1_yellow_index[1]+=0x6;
		pattern_1_yellow_index[3]+=0x6;
		pattern_2_purple_index[1]+=0x6;
		pattern_3_red_index[3]+=0xA2;
		pattern_4_red_index[1]+=0x2;
		pattern_4_red_index[2]+=0x6;
		pattern_5_red_index[3]+=0x36;
		pattern_5_red_index[4]+=0x36;
	}
	if((0x400&board->black)!=0){//f7
		pattern_1_yellow_index[1]+=0x9;
		pattern_1_green_index[3]+=0x3;
		pattern_2_red_index[1]+=0x3;
		pattern_2_blue_index[3]+=0x3;
		pattern_3_red_index[3]+=0x1B;
		pattern_5_red_index[4]+=0x9;
	}else if((0x400&board->white)!=0){
		pattern_1_yellow_index[1]+=0x12;
		pattern_1_green_index[3]+=0x6;
		pattern_2_red_index[1]+=0x6;
		pattern_2_blue_index[3]+=0x6;
		pattern_3_red_index[3]+=0x36;
		pattern_5_red_index[4]+=0x12;
	}
	if((0x800&board->black)!=0){//e7
		pattern_1_yellow_index[1]+=0x1B;
		pattern_1_blue_index[3]+=0x3;
		pattern_2_yellow_index[1]+=0x3;
		pattern_2_green_index[3]+=0x3;
		pattern_5_red_index[4]+=0x3;
		pattern_5_red_index[5]+=0x1;
	}else if((0x800&board->white)!=0){
		pattern_1_yellow_index[1]+=0x36;
		pattern_1_blue_index[3]+=0x6;
		pattern_2_yellow_index[1]+=0x6;
		pattern_2_green_index[3]+=0x6;
		pattern_5_red_index[4]+=0x6;
		pattern_5_red_index[5]+=0x2;
	}
	if((0x1000&board->black)!=0){//d7
		pattern_1_yellow_index[1]+=0x51;
		pattern_1_blue_index[2]+=0x3;
		pattern_2_green_index[1]+=0x3;
		pattern_2_yellow_index[3]+=0x3;
		pattern_5_red_index[4]+=0x1;
		pattern_5_red_index[5]+=0x3;
	}else if((0x1000&board->white)!=0){
		pattern_1_yellow_index[1]+=0xA2;
		pattern_1_blue_index[2]+=0x6;
		pattern_2_green_index[1]+=0x6;
		pattern_2_yellow_index[3]+=0x6;
		pattern_5_red_index[4]+=0x2;
		pattern_5_red_index[5]+=0x6;
	}
	if((0x2000&board->black)!=0){//c7
		pattern_1_yellow_index[1]+=0xF3;
		pattern_1_green_index[2]+=0x3;
		pattern_2_blue_index[1]+=0x3;
		pattern_2_red_index[3]+=0x3;
		pattern_3_red_index[3]+=0x1B;
		pattern_5_red_index[5]+=0x9;
	}else if((0x2000&board->white)!=0){
		pattern_1_yellow_index[1]+=0x1E6;
		pattern_1_green_index[2]+=0x6;
		pattern_2_blue_index[1]+=0x3;
		pattern_2_red_index[3]+=0x6;
		pattern_3_red_index[3]+=0x36;
		pattern_5_red_index[5]+=0x12;
	}
	if((0x4000&board->black)!=0){//b7
		pattern_1_yellow_index[1]+=0x2D9;
		pattern_1_yellow_index[2]+=0x3;
		pattern_2_purple_index[0]+=0x3;
		pattern_3_red_index[3]+=0x51;
		pattern_4_red_index[2]+=0x1;
		pattern_4_red_index[3]+=0x3;
		pattern_5_red_index[5]+=0x1B;
		pattern_5_red_index[6]+=0x1B;
	}else if((0x4000&board->white)!=0){
		pattern_1_yellow_index[1]+=0x5B2;
		pattern_1_yellow_index[2]+=0x6;
		pattern_2_purple_index[0]+=0x6;
		pattern_3_red_index[3]+=0xA2;
		pattern_4_red_index[2]+=0x2;
		pattern_4_red_index[3]+=0x6;
		pattern_5_red_index[5]+=0x36;
		pattern_5_red_index[6]+=0x36;
	}
	if((0x8000&board->black)!=0){//a7
		pattern_1_yellow_index[1]+=0x88B;
		pattern_2_blue_index[0]+=0x3;
		pattern_3_red_index[3]+=0xF3;
		pattern_4_red_index[3]+=0x19A1;
		pattern_5_red_index[5]+=0x51;
		pattern_5_red_index[6]+=0x19A1;
	}else if((0x8000&board->white)!=0){
		pattern_1_yellow_index[1]+=0x1116;
		pattern_2_blue_index[0]+=0x6;
		pattern_3_red_index[3]+=0x1E6;
		pattern_4_red_index[3]+=0x3342;
		pattern_5_red_index[5]+=0xA2;
		pattern_5_red_index[6]+=0x3342;
	}
	if((0x10000&board->black)!=0){//h6
		pattern_1_green_index[1]+=0x1;
		pattern_2_green_index[2]+=0x1;
		pattern_3_red_index[3]+=0x9;
		pattern_4_red_index[1]+=0x51;
		pattern_5_red_index[3]+=0x88B;
	}else if((0x10000&board->white)!=0){
		pattern_1_green_index[1]+=0x2;
		pattern_2_green_index[2]+=0x2;
		pattern_3_red_index[3]+=0x12;
		pattern_4_red_index[1]+=0xA2;
		pattern_5_red_index[3]+=0x1116;
	}
	if((0x20000&board->black)!=0){//g6
		pattern_1_green_index[1]+=0x3;
		pattern_1_yellow_index[3]+=0x9;
		pattern_2_red_index[1]+=0x9;
		pattern_2_blue_index[2]+=0x3;
		pattern_3_red_index[3]+=0x3;
		pattern_5_red_index[3]+=0x9;
	}else if((0x20000&board->white)!=0){
		pattern_1_green_index[1]+=0x6;
		pattern_1_yellow_index[3]+=0x12;
		pattern_2_red_index[1]+=0x12;
		pattern_2_blue_index[2]+=0x6;
		pattern_3_red_index[3]+=0x6;
		pattern_5_red_index[3]+=0x12;
	}
	if((0x40000&board->black)!=0){//f6
		pattern_1_green_index[1]+=0x9;
		pattern_1_green_index[3]+=0x9;
		pattern_2_yellow_index[1]+=0x9;
		pattern_2_purple_index[1]+=0x9;
		pattern_3_red_index[3]+=0x1;
	}else if((0x40000&board->white)!=0){
		pattern_1_green_index[1]+=0x12;
		pattern_1_green_index[3]+=0x12;
		pattern_2_yellow_index[1]+=0x12;
		pattern_2_purple_index[1]+=0x12;
		pattern_3_red_index[3]+=0x2;
	}
	if((0x80000&board->black)!=0){//e6
		pattern_1_green_index[1]+=0x1B;
		pattern_1_blue_index[3]+=0x9;
		pattern_2_green_index[1]+=0x9;
		pattern_2_blue_index[3]+=0x9;
	}else if((0x80000&board->white)!=0){
		pattern_1_green_index[1]+=0x36;
		pattern_1_blue_index[3]+=0x12;
		pattern_2_green_index[1]+=0x12;
		pattern_2_blue_index[3]+=0x12;
	}
	if((0x100000&board->black)!=0){//d6
		pattern_1_green_index[1]+=0x51;
		pattern_1_blue_index[2]+=0x9;
		pattern_2_blue_index[1]+=0x9;
		pattern_2_green_index[3]+=0x9;
	}else if((0x100000&board->white)!=0){
		pattern_1_green_index[1]+=0xA2;
		pattern_1_blue_index[2]+=0x12;
		pattern_2_blue_index[1]+=0x12;
		pattern_2_green_index[3]+=0x12;
	}
	if((0x200000&board->black)!=0){//c6
		pattern_1_green_index[1]+=0xF3;
		pattern_1_green_index[2]+=0x9;
		pattern_2_purple_index[0]+=0x9;
		pattern_2_yellow_index[3]+=0x9;
		pattern_3_red_index[2]+=0x1;
	}else if((0x200000&board->white)!=0){
		pattern_1_green_index[1]+=0x1E6;
		pattern_1_green_index[2]+=0x12;
		pattern_2_purple_index[0]+=0x12;
		pattern_2_yellow_index[3]+=0x12;
		pattern_3_red_index[2]+=0x2;
	}
	if((0x400000&board->black)!=0){//b6
		pattern_1_green_index[1]+=0x2D9;
		pattern_1_yellow_index[2]+=0x9;
		pattern_2_blue_index[0]+=0x3;
		pattern_2_red_index[3]+=0x9;
		pattern_3_red_index[2]+=0x3;
		pattern_5_red_index[6]+=0x2D9;
	}else if((0x400000&board->white)!=0){
		pattern_1_green_index[1]+=0x5B2;
		pattern_1_yellow_index[2]+=0x12;
		pattern_2_blue_index[0]+=0x6;
		pattern_2_red_index[3]+=0x12;
		pattern_3_red_index[2]+=0x6;
		pattern_5_red_index[6]+=0x5B2;
	}
	if((0x800000&board->black)!=0){//a6
		pattern_1_green_index[1]+=0x88B;
		pattern_2_green_index[0]+=0x1;
		pattern_3_red_index[2]+=0x9;
		pattern_4_red_index[3]+=0x88B;
		pattern_5_red_index[6]+=0x88B;
	}else if((0x800000&board->white)!=0){
		pattern_1_green_index[1]+=0x1116;
		pattern_2_green_index[0]+=0x2;
		pattern_4_red_index[3]+=0x1116;
		pattern_5_red_index[6]+=0x1116;
	}
	if((0x1000000&board->black)!=0){//h5
		pattern_1_blue_index[1]+=0x1;
		pattern_2_red_index[1]+=0x1B;
		pattern_2_yellow_index[2]+=0x1;
		pattern_4_red_index[1]+=0xF3;
		pattern_5_red_index[2]+=0xF3;
		pattern_5_red_index[3]+=0x2D9;
	}else if((0x1000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x2;
		pattern_2_red_index[1]+=0x36;
		pattern_2_yellow_index[2]+=0x2;
		pattern_4_red_index[1]+=0x1E6;
		pattern_5_red_index[2]+=0x1E6;
		pattern_5_red_index[3]+=0x5B2;
	}
	if((0x2000000&board->black)!=0){//g5
		pattern_1_blue_index[1]+=0x3;
		pattern_1_yellow_index[3]+=0x1B;
		pattern_2_yellow_index[1]+=0x1B;
		pattern_2_green_index[2]+=0x3;
		pattern_5_red_index[2]+=0x1;
		pattern_5_red_index[3]+=0x3;
	}else if((0x2000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x6;
		pattern_1_yellow_index[3]+=0x36;
		pattern_2_yellow_index[1]+=0x36;
		pattern_2_green_index[2]+=0x6;
		pattern_5_red_index[2]+=0x2;
		pattern_5_red_index[3]+=0x6;
	}
	if((0x4000000&board->black)!=0){//f5
		pattern_1_blue_index[1]+=0x9;
		pattern_1_green_index[3]+=0x1B;
		pattern_2_green_index[1]+=0x1B;
		pattern_2_blue_index[2]+=0x9;
	}else if((0x4000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x12;
		pattern_1_green_index[3]+=0x36;
		pattern_2_green_index[1]+=0x36;
		pattern_2_blue_index[2]+=0x12;
	}
	if((0x8000000&board->black)!=0){//e5
		pattern_1_blue_index[1]+=0x1B;
		pattern_1_blue_index[3]+=0x1B;
		pattern_2_blue_index[1]+=0x1B;
		pattern_2_purple_index[1]+=0x1B;
	}else if((0x8000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x36;
		pattern_1_blue_index[3]+=0x36;
		pattern_2_blue_index[1]+=0x36;
		pattern_2_purple_index[1]+=0x36;
	}
	if((0x10000000&board->black)!=0){//d5
		pattern_1_blue_index[1]+=0x51;
		pattern_1_blue_index[2]+=0x1B;
		pattern_2_purple_index[0]+=0x1B;
		pattern_2_blue_index[3]+=0x1B;
	}else if((0x10000000&board->white)!=0){
		pattern_1_blue_index[1]+=0xA2;
		pattern_1_blue_index[2]+=0x36;
		pattern_2_purple_index[0]+=0x36;
		pattern_2_blue_index[3]+=0x36;
	}
	if((0x20000000&board->black)!=0){//c5
		pattern_1_blue_index[1]+=0xF3;
		pattern_1_green_index[2]+=0x1B;
		pattern_2_blue_index[0]+=0x9;
		pattern_2_green_index[3]+=0x1B;
	}else if((0x20000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x1E6;
		pattern_1_green_index[2]+=0x36;
		pattern_2_blue_index[0]+=0x12;
		pattern_2_green_index[3]+=0x36;
	}
	if((0x40000000&board->black)!=0){//b5
		pattern_1_blue_index[1]+=0x2D9;
		pattern_1_yellow_index[2]+=0x1B;
		pattern_2_green_index[0]+=0x3;
		pattern_2_yellow_index[3]+=0x1B;
		pattern_5_red_index[6]+=0x3;
		pattern_5_red_index[7]+=0x1;
	}else if((0x40000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x5B2;
		pattern_1_yellow_index[2]+=0x36;
		pattern_2_green_index[0]+=0x6;
		pattern_2_yellow_index[3]+=0x36;
		pattern_5_red_index[6]+=0x6;
		pattern_5_red_index[7]+=0x2;
	}
	if((0x80000000&board->black)!=0){//a5
		pattern_1_blue_index[1]+=0x88B;
		pattern_2_red_index[2]+=0x1B;
		pattern_2_yellow_index[0]+=0x1;
		pattern_2_red_index[3]+=0x1B;
		pattern_4_red_index[3]+=0x2D9;
		pattern_5_red_index[6]+=0x2D9;
		pattern_5_red_index[7]+=0xF3;
	}else if((0x80000000&board->white)!=0){
		pattern_1_blue_index[1]+=0x1116;
		pattern_2_red_index[2]+=0x36;
		pattern_2_yellow_index[0]+=0x2;
		pattern_2_red_index[3]+=0x36;
		pattern_4_red_index[3]+=0x5B2;
		pattern_5_red_index[6]+=0x5B2;
		pattern_5_red_index[7]+=0x1E6;
	}
	if((0x100000000&board->black)!=0){//h4
		pattern_1_blue_index[0]+=0x1;
		pattern_2_yellow_index[1]+=0x51;
		pattern_2_red_index[2]+=0x1;
		pattern_4_red_index[1]+=0x2D9;
		pattern_5_red_index[2]+=0x2D9;
		pattern_5_red_index[3]+=0xF3;
	}else if((0x100000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x2;
		pattern_2_yellow_index[1]+=0xA2;
		pattern_2_red_index[2]+=0x2;
		pattern_4_red_index[1]+=0x5B2;
		pattern_5_red_index[2]+=0x5B2;
		pattern_5_red_index[3]+=0x1E6;
	}
	if((0x200000000&board->black)!=0){//g4
		pattern_1_blue_index[0]+=0x3;
		pattern_1_yellow_index[3]+=0x51;
		pattern_2_green_index[1]+=0x51;
		pattern_2_yellow_index[2]+=0x3;
		pattern_5_red_index[2]+=0x3;
		pattern_5_red_index[3]+=0x1;
	}else if((0x200000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x6;
		pattern_1_yellow_index[3]+=0xA2;
		pattern_2_green_index[1]+=0xA2;
		pattern_2_yellow_index[2]+=0x6;
		pattern_5_red_index[2]+=0x6;
		pattern_5_red_index[3]+=0x2;
	}
	if((0x400000000&board->black)!=0){//f4
		pattern_1_blue_index[0]+=0x9;
		pattern_1_green_index[3]+=0x51;
		pattern_2_blue_index[1]+=0x51;
		pattern_2_green_index[2]+=0x9;
	}else if((0x400000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x12;
		pattern_1_green_index[3]+=0xA2;
		pattern_2_blue_index[1]+=0xA2;
		pattern_2_green_index[2]+=0x12;
	}
	if((0x800000000&board->black)!=0){//e4
		pattern_1_blue_index[0]+=0x1B;
		pattern_1_blue_index[3]+=0x51;
		pattern_2_purple_index[0]+=0x51;
		pattern_2_blue_index[2]+=0x1B;
	}else if((0x800000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x36;
		pattern_1_blue_index[3]+=0xA2;
		pattern_2_purple_index[0]+=0xA2;
		pattern_2_blue_index[2]+=0x36;
	}
	if((0x1000000000&board->black)!=0){//d4
		pattern_1_blue_index[0]+=0x51;
		pattern_1_blue_index[2]+=0x51;
		pattern_2_blue_index[0]+=0x1B;
		pattern_2_purple_index[1]+=0x51;
	}else if((0x1000000000&board->white)!=0){
		pattern_1_blue_index[0]+=0xA2;
		pattern_1_blue_index[2]+=0xA2;
		pattern_2_blue_index[0]+=0xA2;
		pattern_2_purple_index[1]+=0xA2;
	}
	if((0x2000000000&board->black)!=0){//c4
		pattern_1_blue_index[0]+=0xF3;
		pattern_1_green_index[2]+=0x51;
		pattern_2_green_index[0]+=0x9;
		pattern_2_blue_index[3]+=0x51;
	}else if((0x2000000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x1E6;
		pattern_1_green_index[2]+=0xA2;
		pattern_2_green_index[0]+=0x12;
		pattern_2_blue_index[3]+=0xA2;
	}
	if((0x4000000000&board->black)!=0){//b4
		pattern_1_blue_index[0]+=0x2D9;
		pattern_1_yellow_index[2]+=0x51;
		pattern_2_yellow_index[0]+=0x3;
		pattern_2_green_index[3]+=0x51;
		pattern_5_red_index[6]+=0x1;
		pattern_5_red_index[7]+=0x3;
	}else if((0x4000000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x5B2;
		pattern_1_yellow_index[2]+=0xA2;
		pattern_2_yellow_index[0]+=0x6;
		pattern_2_green_index[3]+=0xA2;
		pattern_5_red_index[6]+=0x2;
		pattern_5_red_index[7]+=0x6;
	}
	if((0x8000000000&board->black)!=0){//a4
		pattern_1_blue_index[0]+=0x88B;
		pattern_2_red_index[0]+=0x1;
		pattern_2_yellow_index[3]+=0x51;
		pattern_4_red_index[3]+=0xF3;
		pattern_5_red_index[6]+=0xF3;
		pattern_5_red_index[7]+=0x2D9;
	}else if((0x8000000000&board->white)!=0){
		pattern_1_blue_index[0]+=0x1116;
		pattern_2_red_index[0]+=0x2;
		pattern_2_yellow_index[3]+=0xA2;;
		pattern_4_red_index[3]+=0x1E6;
		pattern_5_red_index[6]+=0x1E6;
		pattern_5_red_index[7]+=0x5B2;
	}
	if((0x10000000000&board->black)!=0){//h3
		pattern_1_green_index[0]+=0x1;
		pattern_2_green_index[1]+=0xF3;
		pattern_3_red_index[1]+=0x9;
		pattern_4_red_index[1]+=0x88B;
		pattern_5_red_index[2]+=0x88B;
	}else if((0x10000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x2;
		pattern_2_green_index[1]+=0x1E6;
		pattern_3_red_index[1]+=0x12;
		pattern_4_red_index[1]+=0x1116;
		pattern_5_red_index[2]+=0x1116;
	}
	if((0x20000000000&board->black)!=0){//g3
		pattern_1_green_index[0]+=0x3;
		pattern_1_yellow_index[3]+=0xF3;
		pattern_2_blue_index[1]+=0xF3;
		pattern_2_red_index[2]+=0x3;
		pattern_3_red_index[1]+=0x3;
		pattern_5_red_index[2]+=0x9;
	}else if((0x20000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x6;
		pattern_1_yellow_index[3]+=0x1E6;
		pattern_2_blue_index[1]+=0x1E6;
		pattern_2_red_index[2]+=0x6;
		pattern_3_red_index[1]+=0x6;
		pattern_5_red_index[2]+=0x12;
	}
	if((0x40000000000&board->black)!=0){//f3
		pattern_1_green_index[0]+=0x3;
		pattern_1_green_index[3]+=0xF3;
		pattern_2_purple_index[0]+=0xF3;
		pattern_2_yellow_index[2]+=0x9;
		pattern_3_red_index[1]+=0x1;
	}else if((0x40000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x6;
		pattern_1_green_index[3]+=0x1E6;
		pattern_2_purple_index[0]+=0x1E6;
		pattern_2_yellow_index[2]+=0x12;
		pattern_3_red_index[1]+=0x2;
	}
	if((0x80000000000&board->black)!=0){//e3
		pattern_1_green_index[0]+=0x9;
		pattern_1_blue_index[3]+=0xF3;
		pattern_2_blue_index[0]+=0x51;
		pattern_2_green_index[2]+=0x1B;
	}else if((0x80000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x12;
		pattern_1_blue_index[3]+=0x1E6;
		pattern_2_blue_index[0]+=0xA2;
		pattern_2_green_index[2]+=0x36;
	}
	if((0x100000000000&board->black)!=0){//d3
		pattern_1_green_index[0]+=0x1B;
		pattern_1_blue_index[2]+=0xF3;
		pattern_2_green_index[0]+=0x1B;
		pattern_2_blue_index[2]+=0x51;
	}else if((0x100000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x36;
		pattern_1_blue_index[2]+=0x1E6;
		pattern_2_green_index[0]+=0x36;
		pattern_2_blue_index[2]+=0xA2;
	}
	if((0x200000000000&board->black)!=0){//c3
		pattern_1_green_index[0]+=0x51;
		pattern_1_green_index[2]+=0xF3;
		pattern_2_yellow_index[0]+=0x9;
		pattern_2_purple_index[1]+=0xF3;
		pattern_3_red_index[0]+=0x1;
	}else if((0x200000000000&board->white)!=0){
		pattern_1_green_index[0]+=0xA2;
		pattern_1_green_index[2]+=0x1E6;
		pattern_2_yellow_index[0]+=0x12;
		pattern_2_purple_index[1]+=0x1E6;
		pattern_3_red_index[0]+=0x2;
	}
	if((0x400000000000&board->black)!=0){//b3
		pattern_1_green_index[0]+=0xF3;
		pattern_1_yellow_index[2]+=0xF3;
		pattern_2_red_index[0]+=0x3;
		pattern_2_blue_index[3]+=0xF3;
		pattern_3_red_index[0]+=0x3;
		pattern_5_red_index[7]+=0x9;
	}else if((0x400000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x1E6;
		pattern_1_yellow_index[2]+=0x1E6;
		pattern_2_red_index[0]+=0x6;
		pattern_2_blue_index[3]+=0x1E6;
		pattern_3_red_index[0]+=0x6;
		pattern_5_red_index[7]+=0x12;
	}
	if((0x800000000000&board->black)!=0){//a3
		pattern_1_green_index[0]+=0x2D9;
		pattern_2_green_index[3]+=0xF3;
		pattern_3_red_index[0]+=0x9;
		pattern_4_red_index[3]+=0x51;
		pattern_5_red_index[7]+=0x88B;
	}else if((0x800000000000&board->white)!=0){
		pattern_1_green_index[0]+=0x5B2;
		pattern_2_green_index[3]+=0x1E6;
		pattern_3_red_index[0]+=0x12;
		pattern_4_red_index[3]+=0xA2;
		pattern_5_red_index[7]+=0x1116;
	}
	if((0x1000000000000&board->black)!=0){//h2
		pattern_1_yellow_index[0]+=0x1;
		pattern_2_blue_index[1]+=0x2D9;
		pattern_3_red_index[1]+=0xF3;
		pattern_4_red_index[1]+=0x19A1;
		pattern_5_red_index[1]+=0x51;
		pattern_5_red_index[2]+=0x19A1;
	}else if((0x1000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x2;
		pattern_2_blue_index[1]+=0x5B2;
		pattern_3_red_index[1]+=0x1E6;
		pattern_4_red_index[1]+=0x3342;
		pattern_5_red_index[1]+=0xA2;
		pattern_5_red_index[2]+=0x3342;
	}
	if((0x2000000000000&board->black)!=0){//g2
		pattern_1_yellow_index[0]+=0x3;
		pattern_1_yellow_index[3]+=0x2D9;
		pattern_2_purple_index[0]+=0x2D9;
		pattern_3_red_index[1]+=0x51;
		pattern_4_red_index[0]+=0x1;
		pattern_4_red_index[1]+=0x3;
		pattern_5_red_index[1]+=0x1B;
		pattern_5_red_index[2]+=0x1B;
	}else if((0x2000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x6;
		pattern_1_yellow_index[3]+=0x5B2;
		pattern_2_purple_index[0]+=0x5B2;
		pattern_3_red_index[1]+=0xA2;
		pattern_4_red_index[0]+=0x2;
		pattern_4_red_index[1]+=0x6;
		pattern_5_red_index[1]+=0x36;
		pattern_5_red_index[2]+=0x36;
	}
	if((0x4000000000000&board->black)!=0){//f2
		pattern_1_yellow_index[0]+=0x9;
		pattern_1_green_index[3]+=0x2D9;
		pattern_2_blue_index[0]+=0xF3;
		pattern_2_red_index[2]+=0x9;
		pattern_3_red_index[1]+=0x1B;
		pattern_5_red_index[1]+=0x9;
	}else if((0x4000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x12;
		pattern_1_green_index[3]+=0x5B2;
		pattern_2_blue_index[0]+=0x1E6;
		pattern_2_red_index[2]+=0x12;
		pattern_3_red_index[1]+=0x36;
		pattern_5_red_index[1]+=0x12;
	}
	if((0x8000000000000&board->black)!=0){//e2
		pattern_1_yellow_index[0]+=0x1B;
		pattern_1_blue_index[3]+=0x2D9;
		pattern_2_green_index[0]+=0x51;
		pattern_2_yellow_index[2]+=0x1B;
		pattern_5_red_index[0]+=0x1;
		pattern_5_red_index[1]+=0x3;
	}else if((0x8000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x36;
		pattern_1_blue_index[3]+=0x5B2;
		pattern_2_green_index[0]+=0xA2;
		pattern_2_yellow_index[2]+=0x36;
		pattern_5_red_index[0]+=0x2;
		pattern_5_red_index[1]+=0x6;
	}
	if((0x10000000000000&board->black)!=0){//d2
		pattern_1_yellow_index[0]+=0x51;
		pattern_1_blue_index[2]+=0x2D9;
		pattern_2_yellow_index[0]+=0x1B;
		pattern_2_green_index[2]+=0x51;
		pattern_5_red_index[0]+=0x3;
		pattern_5_red_index[1]+=0x1;
	}else if((0x10000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0xA2;
		pattern_1_blue_index[2]+=0x5B2;
		pattern_2_yellow_index[0]+=0x36;
		pattern_2_green_index[2]+=0xA2;
		pattern_5_red_index[0]+=0x6;
		pattern_5_red_index[1]+=0x2;
	}
	if((0x20000000000000&board->black)!=0){//c2
		pattern_1_yellow_index[0]+=0xF3;
		pattern_1_green_index[2]+=0x2D9;
		pattern_2_red_index[0]+=0x9;
		pattern_2_blue_index[2]+=0xF3;
		pattern_3_red_index[0]+=0x1B;
		pattern_5_red_index[0]+=0x9;
	}else if((0x20000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x1E6;
		pattern_1_green_index[2]+=0x5B2;
		pattern_2_red_index[0]+=0x12;
		pattern_2_blue_index[2]+=0x1E6;
		pattern_3_red_index[0]+=0x36;
		pattern_5_red_index[0]+=0x12;
	}
	if((0x40000000000000&board->black)!=0){//b2
		pattern_1_yellow_index[0]+=0x2D9;
		pattern_1_yellow_index[2]+=0x2D9;
		pattern_2_purple_index[1]+=0x2D9;
		pattern_3_red_index[0]+=0xF3;
		pattern_4_red_index[0]+=0x3;
		pattern_4_red_index[3]+=0x1;
		pattern_5_red_index[0]+=0x1B;
		pattern_5_red_index[7]+=0x1B;
	}else if((0x40000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x5B2;
		pattern_1_yellow_index[2]+=0x5B2;
		pattern_2_purple_index[1]+=0x5B2;
		pattern_3_red_index[0]+=0x1E6;
		pattern_4_red_index[0]+=0x6;
		pattern_4_red_index[3]+=0x2;
		pattern_5_red_index[0]+=0x36;
		pattern_5_red_index[7]+=0x36;
	}
	if((0x80000000000000&board->black)!=0){//a2
		pattern_1_yellow_index[0]+=0x88B;
		pattern_2_blue_index[3]+=0x2D9;
		pattern_3_red_index[0]+=0xF3;
		pattern_4_red_index[3]+=0x1B;
		pattern_5_red_index[0]+=0x51;
		pattern_5_red_index[7]+=0x19A1;
	}else if((0x80000000000000&board->white)!=0){
		pattern_1_yellow_index[0]+=0x1116;
		pattern_2_blue_index[3]+=0x5B2;
		pattern_3_red_index[0]+=0x1E6;
		pattern_4_red_index[3]+=0x36;
		pattern_5_red_index[0]+=0xA2;
		pattern_5_red_index[7]+=0x3342;
	}
	if((0x100000000000000&board->black)!=0){//h1
		pattern_2_purple_index[0]+=0x88B;
		pattern_3_red_index[1]+=0x19A1;
		pattern_4_red_index[0]+=0x9;
		pattern_4_red_index[1]+=0x4CE3;
		pattern_5_red_index[1]+=0x4CE3;
		pattern_5_red_index[2]+=0x4CE3;
	}else if((0x100000000000000&board->white)!=0){
		pattern_2_purple_index[0]+=0x1116;
		pattern_3_red_index[1]+=0x3342;
		pattern_4_red_index[0]+=0x12;
		pattern_4_red_index[1]+=0x99C6;
		pattern_5_red_index[1]+=0x99C6;
		pattern_5_red_index[2]+=0x99C6;
	}
	if((0x200000000000000&board->black)!=0){//g1
		pattern_1_yellow_index[3]+=0x88B;
		pattern_2_blue_index[0]+=0x2D9;
		pattern_3_red_index[1]+=0x88B;
		pattern_4_red_index[0]+=0x1B;
		pattern_5_red_index[1]+=0x19A1;
		pattern_5_red_index[2]+=0x51;
	}else if((0x200000000000000&board->white)!=0){
		pattern_1_yellow_index[3]+=0x1116;
		pattern_2_blue_index[0]+=0x5B2;
		pattern_3_red_index[1]+=0x1116;
		pattern_4_red_index[0]+=0x36;
		pattern_5_red_index[1]+=0x3342;
		pattern_5_red_index[2]+=0xA2;
	}
	if((0x400000000000000&board->black)!=0){//f1
		pattern_1_green_index[3]+=0x88B;
		pattern_2_green_index[0]+=0xF3;
		pattern_3_red_index[1]+=0x2D9;
		pattern_4_red_index[0]+=0x51;
		pattern_5_red_index[1]+=0x88B;

	}else if((0x400000000000000&board->white)!=0){
		pattern_1_green_index[3]+=0x1116;
		pattern_2_green_index[0]+=0x1E6;
		pattern_3_red_index[1]+=0x5B2;
		pattern_4_red_index[0]+=0xA2;
		pattern_5_red_index[1]+=0x1116;
	}
	if((0x800000000000000&board->black)!=0){//e1
		pattern_1_blue_index[3]+=0x88B;
		pattern_2_yellow_index[0]+=0x51;
		pattern_2_red_index[1]+=0x1B;
		pattern_4_red_index[0]+=0xF3;
		pattern_5_red_index[0]+=0xF3;
		pattern_5_red_index[1]+=0x2D9;
	}else if((0x800000000000000&board->white)!=0){
		pattern_1_blue_index[3]+=0x1116;
		pattern_2_yellow_index[0]+=0xA2;
		pattern_2_red_index[1]+=0x36;
		pattern_4_red_index[0]+=0x1E6;
		pattern_5_red_index[0]+=0x1E6;
		pattern_5_red_index[1]+=0x5B2;
	}
	if((0x1000000000000000&board->black)!=0){//d1
		pattern_1_blue_index[2]+=0x88B;
		pattern_2_red_index[0]+=0x1B;
		pattern_2_yellow_index[2]+=0x51;
		pattern_4_red_index[0]+=0x2D9;
		pattern_5_red_index[0]+=0x2D9;
		pattern_5_red_index[1]+=0xF3;
	}else if((0x1000000000000000&board->white)!=0){
		pattern_1_blue_index[2]+=0x1116;
		pattern_2_red_index[0]+=0x36;
		pattern_2_yellow_index[2]+=0xA2;
		pattern_4_red_index[0]+=0x5B2;
		pattern_5_red_index[0]+=0x5B2;
		pattern_5_red_index[1]+=0x1E6;
	}
	if((0x2000000000000000&board->black)!=0){//c1
		pattern_1_green_index[2]+=0x88B;
		pattern_2_green_index[2]+=0xF3;
		pattern_3_red_index[0]+=0x2D9;
		pattern_4_red_index[0]+=0x88B;
		pattern_5_red_index[0]+=0x88B;
	}else if((0x2000000000000000&board->white)!=0){
		pattern_1_green_index[2]+=0x1116;
		pattern_2_green_index[2]+=0x1E6;
		pattern_3_red_index[0]+=0x5B2;
		pattern_4_red_index[0]+=0x1116;
		pattern_5_red_index[0]+=0x1116;
	}
	if((0x4000000000000000&board->black)!=0){//b1
		pattern_1_yellow_index[2]+=0x88B;
		pattern_2_blue_index[2]+=0x2D9;
		pattern_3_red_index[0]+=0x88B;
		pattern_4_red_index[0]+=0x19A1;
		pattern_5_red_index[0]+=0x19A1;
		pattern_5_red_index[7]+=0x51;
	}else if((0x4000000000000000&board->black)!=0){
		pattern_1_yellow_index[2]+=0x1116;
		pattern_2_blue_index[2]+=0x5B2;
		pattern_3_red_index[0]+=0x1116;
		pattern_4_red_index[0]+=0x3342;
		pattern_5_red_index[0]+=0x3342;
		pattern_5_red_index[7]+=0xA2;
	}
	if((0x8000000000000000&board->black)!=0){//a1
		pattern_2_purple_index[1]+=0x88B;
		pattern_3_red_index[0]+=0x19A1;
		pattern_4_red_index[0]+=0x4CE3;
		pattern_4_red_index[3]+=0x9;
		pattern_5_red_index[0]+=0x4CE3;
		pattern_5_red_index[7]+=0x4CE3;
	}else if((0x8000000000000000&board->black)!=0){
		pattern_2_purple_index[1]+=0x1116;
		pattern_3_red_index[0]+=0x3342;
		pattern_4_red_index[0]+=0x99C6;
		pattern_4_red_index[3]+=0x12;
		pattern_5_red_index[0]+=0x99C6;
		pattern_5_red_index[7]+=0x99C6;
	}
	value+=pattern_1_yellow[board->empty_num-1][pattern_1_yellow_index[0]];
	value+=pattern_1_yellow[board->empty_num-1][pattern_1_yellow_index[1]];
	value+=pattern_1_yellow[board->empty_num-1][pattern_1_yellow_index[2]];
	value+=pattern_1_yellow[board->empty_num-1][pattern_1_yellow_index[3]];
	value+=pattern_1_green[board->empty_num-1][pattern_1_green_index[0]];
	value+=pattern_1_green[board->empty_num-1][pattern_1_green_index[1]];
	value+=pattern_1_green[board->empty_num-1][pattern_1_green_index[2]];
	value+=pattern_1_green[board->empty_num-1][pattern_1_green_index[3]];
	value+=pattern_1_blue[board->empty_num-1][pattern_1_blue_index[0]];
	value+=pattern_1_blue[board->empty_num-1][pattern_1_blue_index[1]];
	value+=pattern_1_blue[board->empty_num-1][pattern_1_blue_index[2]];
	value+=pattern_1_blue[board->empty_num-1][pattern_1_blue_index[3]];
	value+=pattern_2_red[board->empty_num-1][pattern_2_red_index[0]];
	value+=pattern_2_red[board->empty_num-1][pattern_2_red_index[1]];
	value+=pattern_2_red[board->empty_num-1][pattern_2_red_index[2]];
	value+=pattern_2_red[board->empty_num-1][pattern_2_red_index[3]];
	value+=pattern_2_yellow[board->empty_num-1][pattern_2_yellow_index[0]];
	value+=pattern_2_yellow[board->empty_num-1][pattern_2_yellow_index[1]];
	value+=pattern_2_yellow[board->empty_num-1][pattern_2_yellow_index[2]];
	value+=pattern_2_yellow[board->empty_num-1][pattern_2_yellow_index[3]];
	value+=pattern_2_green[board->empty_num-1][pattern_2_green_index[0]];
	value+=pattern_2_green[board->empty_num-1][pattern_2_green_index[1]];
	value+=pattern_2_green[board->empty_num-1][pattern_2_green_index[2]];
	value+=pattern_2_green[board->empty_num-1][pattern_2_green_index[3]];
	value+=pattern_2_blue[board->empty_num-1][pattern_2_blue_index[0]];
	value+=pattern_2_blue[board->empty_num-1][pattern_2_blue_index[1]];
	value+=pattern_2_blue[board->empty_num-1][pattern_2_blue_index[2]];
	value+=pattern_2_blue[board->empty_num-1][pattern_2_blue_index[3]];
	value+=pattern_2_purple[board->empty_num-1][pattern_2_purple_index[0]];
	value+=pattern_2_purple[board->empty_num-1][pattern_2_purple_index[1]];
	value+=pattern_3_red[board->empty_num-1][pattern_3_red_index[0]];
	value+=pattern_3_red[board->empty_num-1][pattern_3_red_index[1]];
	value+=pattern_3_red[board->empty_num-1][pattern_3_red_index[2]];
	value+=pattern_3_red[board->empty_num-1][pattern_3_red_index[3]];
	value+=pattern_4_red[board->empty_num-1][pattern_4_red_index[0]];
	value+=pattern_4_red[board->empty_num-1][pattern_4_red_index[1]];
	value+=pattern_4_red[board->empty_num-1][pattern_4_red_index[2]];
	value+=pattern_4_red[board->empty_num-1][pattern_4_red_index[3]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[0]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[1]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[2]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[3]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[4]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[5]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[6]];
	value+=pattern_5_red[board->empty_num-1][pattern_5_red_index[7]];

	if(board->turn==BLACK) return value;
	else return -value;
}