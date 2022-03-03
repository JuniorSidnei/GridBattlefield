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
		PlayerTurn = 2,
		EnemyTurn = 3,
		GameEnded = 4
	};

	void startGame(BaseCharacter& playerCharacter, BaseCharacter& enemyCharacter, Grid &grid);
	void startTurn();
	void nextTurn(BaseCharacter &character);
	void endGame();

private:
	//TODO change this to be the vector instead of two characters
	std::vector<BaseCharacter> m_allCharacters;
	BaseCharacter m_player;
	BaseCharacter m_enemy;
	Grid *m_grid{nullptr};
	GameStates m_gameState = GameStates::GameNotStarted;
};

#endif // !TurnManager_h