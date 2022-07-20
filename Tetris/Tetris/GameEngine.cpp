#include "GameEngine.h"


void GameEngine::init() {
	// ���� ���� �ʱ�ȭ
	makeUserBlock();
}
void GameEngine::next(float dt, char keyboardInput) {
	if (state == GameState::GAMEOVER) return;
	elapsed += dt;
	if (elapsed >= 0.5f) {
		if (canGoDown()) {
			blockY++;
		}
		else {
			// userblcok �� gameGridData�� ����
			trans();
			if (gameOverDecision()) state = GameState::GAMEOVER;
		}
		elapsed -= 0.5f;
	}

	controlCheck = controlCheck + dt;

	if (keyboardInput == 'a' && canGoLeft() && controlCheck > 0.1) {
		blockX--;
		controlCheck = 0.0f;
	}
	if (keyboardInput == 'd' && canGoRight() && controlCheck > 0.1) {
		blockX++;
		controlCheck = 0.0f;
	}

	if (keyboardInput == 's' && canGoDown() && controlCheck > 0.1) {
		blockY++;
		controlCheck = 0.0f;
	}
}

bool GameEngine::canGoDown() {
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				if (userBlock[i][k] == 1 && i + blockY + 1 >= GRID_HEIGHT)
					return false;
				if (userBlock[i][k] == 1 && gameGridData[i + blockY + 1][k + blockX] == 1) {
					return false;
				}

			}
		}
		return true;
}

bool GameEngine::canGoLeft() {
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockX - 1 < 0) {
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX - 1] == 1) {
				return false;
			}

		}
	}

	return true;
}

bool GameEngine::canGoRight() {
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && k + blockX + 1 > GRID_WIDTH - 1) {
				return false;
			}
			if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX + 1] == 1) {
				return false;
			}


		}
	}

	return true;
}

bool GameEngine::isLineFilled(int y) {
	for (int i = 0; i < GRID_WIDTH; i++) {
		if (gameGridData[y][i] == 0) return false;
	}
	return true;
}

void GameEngine::eraseLine(int y) {
	for (int i = 0; i < GRID_WIDTH; i++) {
		gameGridData[y][i] = 0;
	}
}

void GameEngine::drop(int y) {
	for (int i = y; i >= 0; i--) {
		for (int k = 0; k < GRID_WIDTH; k++) {
			gameGridData[i][k] = i - 1 < 0 ? 0 : gameGridData[i - 1][k];
		}
	}
}

void GameEngine::trans() {
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			gameGridData[i + blockY][k + blockX] = userBlock[i][k] == 1 ? userBlock[i][k] : gameGridData[i + blockY][k + blockX];
		}
	}

	// �� ���� ���� �� �ִ��� Ȯ��
	for (int i = 0; i < GRID_HEIGHT; i++) {
		if (isLineFilled(i)) {
			eraseLine(i);
			drop(i);
		}
	}

	//���ο� ��� ����
	makeUserBlock();
}

bool GameEngine::gameOverDecision() {
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1 && gameGridData[i + blockY][k + blockX] == 1) {
				return true;
			}
		}
	}

	return false;
}

void GameEngine::makeUserBlock() {
	blockX = 0;
	blockY = 0;

	srand(time(0));

	// �������� ��� ����
	int various = rand() % 3;
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			userBlock[i][k] = userBlockVarious[various][i][k];
		}
	}

}

bool GameEngine::canRotate() {
	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (userBlock[i][k] == 1) {
				int __x = blockX + USERBLOCK_SIZE - 1 - i; // ȸ�� �� x ��ǥ
				int __y = blockY + k; // ȸ�� �� y ��ǥ
				// ���� ���� üũ
				if (__x > GRID_WIDTH - 1 || __x < 0) {
					return false;
				}
				// ���� ���� üũ
				if (__y > GRID_HEIGHT - 1 || __y < 0) {
					return false;
				}
				// �ٸ� ��� üũ
				if (gameGridData[__y][__x] == 1) {
					return false;
				}
			}
		}
	}
	return true;
}

void GameEngine::rotate() {
	if (canRotate()) {
		int temp[USERBLOCK_SIZE][USERBLOCK_SIZE] = { 0, };
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				temp[i][k] = userBlock[i][k];
			}
		}
		for (int i = 0; i < USERBLOCK_SIZE; i++) {
			for (int k = 0; k < USERBLOCK_SIZE; k++) {
				userBlock[k][USERBLOCK_SIZE - 1 - i] = temp[i][k];
			}
		}
	}
}

void GameEngine::makeDisplayData() {
	for (int i = 0; i < GRID_HEIGHT; i++) {
		for (int k = 0; k < GRID_WIDTH; k++) {
			displayData[i][k] = gameGridData[i][k];
		}
	}

	for (int i = 0; i < USERBLOCK_SIZE; i++) {
		for (int k = 0; k < USERBLOCK_SIZE; k++) {
			if (i + blockY < 0 || i + blockY > GRID_HEIGHT) {
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