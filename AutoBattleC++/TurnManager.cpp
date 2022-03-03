#include "TurnManager.h"

void TurnManager::startGame(BaseCharacter &playerCharacter, BaseCharacter &enemyCharacter, Grid &grid) {
	m_gameState = GameStates::GameStarted;
	//characterManager.sortAllPlayers();
	//startTurn(characterManager.getAllCharacters()[0]);
	//TODO make this random between the characters
	m_player = playerCharacter;
	m_enemy = enemyCharacter;
	m_grid = &grid;
	startTurn();
}

void TurnManager::startTurn() {
	if (m_player.isCloseToTarget()) {
		m_player.attack(m_player.getTarget());
		nextTurn(m_enemy);
	} 
	else {
		m_player.moveToTarget(*m_grid);
	}

	
	//se não tiver mover na direção mais proxima
}

void TurnManager::nextTurn(BaseCharacter &character)
{
}

void TurnManager::endGame()
{
}
