#include "CharacterManager.h"
#include <algorithm>

CharacterManager::~CharacterManager() {
	delete(m_playerCharacter.get());
	delete(m_enemyCharacter.get());
}

void CharacterManager::initializeCharacters(BaseCharacter::CharacterClass playerClass, BaseCharacter::CharacterClass enemyClass, Grid &grid) {
    srand(time(NULL));

    m_playerCharacter = std::make_unique<BaseCharacter>();
	m_playerCharacter->setCharacterType(BaseCharacter::CharacterType::Player);
	m_playerCharacter->setCharacterClassAndStatus(playerClass);
	
	m_enemyCharacter = std::make_unique<BaseCharacter>();
	m_enemyCharacter->setCharacterType(BaseCharacter::CharacterType::Enemy);
    m_enemyCharacter->setCharacterClassAndStatus(enemyClass);

	m_playerCharacter->setTarget(m_enemyCharacter.get());
	m_enemyCharacter->setTarget(m_playerCharacter.get());

    changeEnemyIconIfNeeded(playerClass, enemyClass);
	
    auto gridPositions = randomizeCharactersPostions(grid);

    grid.getBoxWithIndex(gridPositions.first).setGridBoxOccupied(true);
    grid.getBoxWithIndex(gridPositions.first).setGridBoxOccupiedByPlayer(true);
    m_playerCharacter->setGridBox(grid.getBoxWithIndex(gridPositions.first));

    grid.getBoxWithIndex(gridPositions.second).setGridBoxOccupied(true);
    m_enemyCharacter->setGridBox(grid.getBoxWithIndex(gridPositions.second));

    grid.setCharactersIcons(m_playerCharacter->getIcon(), m_enemyCharacter->getIcon());
}

void CharacterManager::insertCharacter(BaseCharacter& character) {
	m_allCharacters.push_back(character);
}

void CharacterManager::changeEnemyIconIfNeeded(BaseCharacter::CharacterClass playerClass, BaseCharacter::CharacterClass enemyClass) {
    if (enemyClass == playerClass) {
        auto newEnemyIcon = 'p';

        switch (enemyClass) {
        case BaseCharacter::CharacterClass::Archer:
            newEnemyIcon = 'a';
            break;
        case BaseCharacter::CharacterClass::Cleric:
            newEnemyIcon = 'c';
            break;
        case BaseCharacter::CharacterClass::Warrior:
            newEnemyIcon = 'w';
            break;
        default:
            break;
        }

        m_enemyCharacter->setIcon(newEnemyIcon);
    }
}

std::pair<int, int> CharacterManager::randomizeCharactersPostions(Grid &grid) {
    srand(time(NULL));
    auto max = grid.getGridBoxes().size() - 1;
    auto playerRandPos = rand() % max + 1;
    auto enemyRandPos = rand() % max + 1;

    if (enemyRandPos == playerRandPos) {
        randomizeCharactersPostions(grid);
        return std::make_pair(0, 0);
    }

    return std::make_pair(playerRandPos, enemyRandPos);
}
