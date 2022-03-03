#include "TurnManager.h"

void TurnManager::startGame(BaseCharacter &playerCharacter, BaseCharacter &enemyCharacter, Grid &grid) {
	cout << "The battle begins!\n";
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
		cout << "Player attacked enemy\n";
		m_player.attack();
		nextTurn(m_enemy);
	} 
	else {
		//no one is taking damage
		cout << "Player moved to enemy\n";
		m_player.moveToTarget(*m_grid);
		m_grid->drawBattlefieldWithIcons(m_player.getIcon(), m_enemy.getIcon());
		nextTurn(m_enemy);
		getchar();
	}
}

void TurnManager::nextTurn(BaseCharacter &character) {
	m_currentTurn++;
	cout << "The: " << m_currentTurn << " turn, has started!\n";
	if (character.isCloseToTarget()) {
		character.attack();
		nextTurn(m_player);
	}
	else {
		m_enemy.moveToTarget(*m_grid);
		m_grid->drawBattlefieldWithIcons(m_player.getIcon(), m_enemy.getIcon());
		getchar();
	}
}

void TurnManager::endGame()
{
}
