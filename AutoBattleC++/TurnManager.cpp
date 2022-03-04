#include "TurnManager.h"
#include <algorithm>
#include <iostream>

void TurnManager::handleTurn(Grid &grid, std::vector<std::unique_ptr<BaseCharacter>> &characters) {
	if (m_currentTurn == 0) {
		cout << "The battle begins!\n";
		m_gameState = GameStates::GameStarted;
		std::random_shuffle(characters.begin(), characters.end());
	}

	cout << "Turn: " << m_currentTurn << ", starting now!\n";
	for(auto &character : characters) {
		if (character->isDead()) {
			auto type = character->getType();
			if (type == BaseCharacter::CharacterType::Player) {
				cout << "ENEMY TEAM WON!\n";
			} else {
				cout << "PLAYER TEAM WON!\n";
			}
			endGame();
			return;
		}

		if (character->isCloseToTarget()) {
			cout << "Character attacked enemy\n";
			character->attack();
		}
		else {
			cout << "Character moved to enemy\n";
			character->moveToTarget(grid);
			grid.drawBattlefieldWithIcons();
		}
	}

	m_currentTurn++;
	system("pause");
	handleTurn(grid, characters);
}

void TurnManager::endGame() {
	cout << "The battle has ended! Thanks!\n";
}
