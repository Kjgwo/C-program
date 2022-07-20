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

	// while 루프에서 매번 불려지는 함수
	void next(float dt, char keyboardInput);

	// 블록이 아래로 내려갈 수 있나 ( 확인만 )
	bool canGoDown();

	// 블록이 왼쪽으로 갈 수 있나 확인
	bool canGoLeft();

	// 블록이 오른쪽으로 갈 수 있나 확인
	bool canGoRight();

	bool isLineFilled(int y);

	void eraseLine(int y);

	// y 좌표를 기준으로 한칸씩 아래로 내림
	void drop(int y);

	// userblock를 gameGrid에 전사하는 함수
	void trans();

	bool gameOverDecision();

	void makeUserBlock();

	bool canRotate();

	void rotate();

	// 실제 게임 데이터를 화면에 출력할 수 있는 데이터로 변환
	void makeDisplayData();
};

#endif // !__GAME_ENGINE_H_