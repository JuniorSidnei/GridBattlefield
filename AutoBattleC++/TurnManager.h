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

	void startGame(Grid &grid, std::vector<BaseCharacter>& characters);
	void handleTurn();
	void endGame();

private:
	Grid *m_grid{nullptr};
	std::vector<BaseCharacter> m_characters;
	int m_currentTurn = 0;
	GameStates m_gameState = GameStates::GameNotStarted;
};

#endif // !TurnManager_h