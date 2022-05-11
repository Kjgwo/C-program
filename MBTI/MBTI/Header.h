#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cstdlib>

int score_I_E = 0; // 내향, 외향
int score_S_N = 0; // 감각, 직관
int score_T_F = 0; // 사고, 감성
int score_J_P = 0; // 판단, 인식

int getInput();
int dis1(int input);
int dis2(int input);
void question(const char* quest, int score, int qst);
void getResult(char* mbti);
void printResult(char* mbti);

void test_I_E();
void test_S_N();
void test_T_F();
void test_J_P();
