#ifndef TurnManager_h
#define TurnManager_h
#pragma once
#include "CharacterManager.h"
#include "Grid.h"

class TurnManager {
public:

	TurnManager() {};
	~TurnManager() {};

	enum class GameStates {
		GameNotStarted = 0,
		GameStarted = 1,
		GameEnded = 2
	};

	void handleTurn(Grid& grid, std::vector<std::unique_ptr<BaseCharacter>>& characters);
	void endGame();

private:
	int m_currentTurn = 1;
	GameStates m_gameState = GameStates::GameNotStarted;
};

#endif // !TurnManager_h