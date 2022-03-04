#include "TurnManager.h"
#include <algorithm>
#include <iostream>

void TurnManager::handleTurn(Grid &grid, std::vector<std::unique_ptr<BaseCharacter>> &characters) {
	if (m_gameState == GameStates::GameNotStarted) {
		std::cout << "The battle begins!\n";
		m_gameState = GameStates::GameStarted;
		std::random_shuffle(characters.begin(), characters.end());
	}

	std::cout << "Turn: " << m_currentTurn << ", starting now!\n";
	for(auto &character : characters) {
		if (character->isDead()) {
			if (character->getType() == BaseCharacter::CharacterType::Player) {
				std::cout << "ENEMY TEAM WON!\n";
			} else {
				std::cout << "PLAYER TEAM WON!\n";
			}
			endGame();
			return;
		}

		if (character->isCloseToTarget()) {
			std::cout << "Character attacked enemy\n";
			character->attack();
		}
		else {
			std::cout << "Character moved to enemy\n";
			character->moveToTarget(grid);
			grid.drawBattlefieldWithIcons();
		}
	}

	m_currentTurn++;
	system("pause");
	handleTurn(grid, characters);
}

void TurnManager::endGame() {
	m_gameState = GameStates::GameEnded;
	std::cout << "The battle has ended! Thanks!\n";
}
