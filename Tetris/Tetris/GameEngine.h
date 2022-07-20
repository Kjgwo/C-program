#ifndef __GAME__ENGINE_H_
#define __GAME__ENGINE_H_

#include "Header.h"

class GameEngine {
public:
	enum class GameState {
		PLAYING, GAMEOVER
	};
	GameState state = GameState::PLAYING;

	int gameGridData[GRID_HEIGHT][GRID_WIDTH] = { 0, };
	int userBlock[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };

	int userBlockVarious[3][USERBLOCK_SIZE][USERBLOCK_SIZE] = {
	{
		{0, 1, 0},
		{0, 1, 0},
		{0, 1, 0}
	},
	{
		{0, 0, 0},
		{0, 1, 1},
		{0, 1, 1}
	},
	{
		{0, 0, 0},
		{0, 1, 0},
		{1, 1, 0}

	}
	};

	int blockX = 0;
	int blockY = 0;

	float elapsed = 0.0f;
	float controlCheck = 0.0f;

	void init();

	// while �������� �Ź� �ҷ����� �Լ�
	void next(float dt, char keyboardInput);

	// ����� �Ʒ��� ������ �� �ֳ� ( Ȯ�θ� )
	bool canGoDown();

	// ����� �������� �� �� �ֳ� Ȯ��
	bool canGoLeft();

	// ����� ���������� �� �� �ֳ� Ȯ��
	bool canGoRight();

	bool isLineFilled(int y);

	void eraseLine(int y);

	// y ��ǥ�� �������� ��ĭ�� �Ʒ��� ����
	void drop(int y);

	// userblock�� gameGrid�� �����ϴ� �Լ�
	void trans();

	bool gameOverDecision();

	void makeUserBlock();

	bool canRotate();

	void rotate();

	// ���� ���� �����͸� ȭ�鿡 ����� �� �ִ� �����ͷ� ��ȯ
	void makeDisplayData();
};

#endif // !__GAME_ENGINE_H_