#include "TetrisHelper.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

#define GRID_WIDTH 7
#define GRID_HEIGHT 10
#define USERBBLOCK_SIZE 3


int displayData[GRID_HEIGHT][GRID_WIDTH] = { 0, };

class Display {
public:
	void draw() {
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				drawPosition(k, i, displayData[i][k] == 1);
			}
		}
	}
};

class GameEngine {
public:
	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = {
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0},
		{0, 1, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0},
		{1, 1, 0, 0, 0, 0, 0}
	};
	int userBlock[USERBBLOCK_SIZE][USERBBLOCK_SIZE] = {
		{1, 1, 1},
		{1, 0, 0},
		{1, 0, 0}
	};
	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;

	void init() {
		// ���� ���� �ʱ�ȭ
	}

	// while �������� �Ź� �ҷ����� �Լ�
	void next(float dt, char keyboardInput) {
		elapsed += dt;
		if (elapsed >= 0.5f) {
			blockY++;
			elapsed -= 0.5f;
		}

	}
	// ����� �Ʒ��� ������ �� �ֳ� ( Ȯ�θ� )
	bool canGoDown() {
		for (int i = 0; i < USERBBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT)
					return false;
				if(userBlock[i][k] == 1 && gameGridData[i + blockY + 1])

			}
		}
	}

	// ����� �������� �� �� �ֳ� Ȯ��
	bool canGoLeft() {

	}
	// ����� ���������� �� �� �ֳ� Ȯ��
	bool canGoRight() {

	}
	// ���� ���� �����͸� ȭ�鿡 ����� �� �ִ� �����ͷ� ��ȯ
	void makeDisplayData() {
		for (int i = 0; i < GRID_HEIGHT; i++) {
			for (int k = 0; k < GRID_WIDTH; k++) {
				displayData[i][k] = gameGridData[i][k];
			}
		}

		for (int i = 0; i < USERBBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBBLOCK_SIZE; k++) {
				if (i + blockY < 0 || i+ blockY > GRID_HEIGHT) {
					// DO NOTHING
				}
				else if (k + blockX < 0 || k + blockX > GRID_WIDTH) {
					// DO NOTHING
				}
				else {
					// displayData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : displayData[i + blockY][k + blockX];
					int _x = k + blockX;
					int _y = i + blockY;
					displayData[_y][_x] = userBlock[i][k] | displayData[_y][_x];
				}

			}
		}
	}
};