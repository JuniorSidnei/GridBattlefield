#include "TurnManager.h"
#include <algorithm>
#include <iostream>

void TurnManager::startGame(Grid &grid, std::vector<BaseCharacter> &characters) {
	cout << "The battle begins!\n";
	m_gameState = GameStates::GameStarted;
	m_characters = characters;
	std::random_shuffle(m_characters.begin(), m_characters.end());
	m_grid = &grid;
	handleTurn();
}

void TurnManager::handleTurn() {
	cout << "Turn: " << m_currentTurn << ", starting now!\n";
	for(auto character : m_characters) {
		if (character.isDead()) {
			auto type = character.getType();
			if (type == BaseCharacter::CharacterType::Player) {
				cout << "ENEMY TEAM WON!\n";
			} else {
				cout << "PLAYER TEAM WON!\n";
			}
			endGame();
			return;
		}

		if (character.isCloseToTarget()) {
			cout << "Character attacked enemy\n";
			character.attack();
		}
		else {
			cout << "Character moved to enemy\n";
			character.moveToTarget(*m_grid);
			m_grid->drawBattlefieldWithIcons();
		}
	}

	m_currentTurn++;
	system("pause");
	handleTurn();

	//if (m_characters[0].isCloseToTarget()) {
	//	
	//	m_characters[1].attack();
	//	nextTurn(m_characters[1]);
	//} 
	//else {
	//	//no one is taking damage
	//	
	//	m_characters[0].moveToTarget(*m_grid);
	//	if (m_characters[0].getType() == BaseCharacter::CharacterType::Player) {
	//		m_grid->drawBattlefieldWithIcons(m_characters[0].getIcon(), m_characters[1].getIcon());
	//	}
	//	else {
	//		m_grid->drawBattlefieldWithIcons(m_characters[1].getIcon(), m_characters[0].getIcon());
	//	}
	//	
	//	nextTurn(m_characters[1]);
	//	getchar();
	//}
}

void TurnManager::endGame() {
	cout << "The battle has ended! Thanks!\n";
}
