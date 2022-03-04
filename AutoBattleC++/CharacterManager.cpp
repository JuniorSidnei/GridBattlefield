#include "CharacterManager.h"
#include <algorithm>

CharacterManager::~CharacterManager() { }

void CharacterManager::initializeCharacters(BaseCharacter::CharacterClass playerClass, BaseCharacter::CharacterClass enemyClass, Grid &grid) {
    srand(time(NULL));

    m_playerIndex = m_allCharacters.size();
    m_allCharacters.emplace_back(std::make_unique<BaseCharacter>());
    m_allCharacters[m_playerIndex]->setCharacterType(BaseCharacter::CharacterType::Player);
    m_allCharacters[m_playerIndex]->setCharacterClassAndStatus(playerClass);
	
    m_enemyIndex = m_allCharacters.size();
    m_allCharacters.emplace_back(std::make_unique<BaseCharacter>());
    m_allCharacters[m_enemyIndex]->setCharacterType(BaseCharacter::CharacterType::Enemy);
    m_allCharacters[m_enemyIndex]->setCharacterClassAndStatus(enemyClass);

    m_allCharacters[m_playerIndex]->setTarget(m_allCharacters[m_enemyIndex].get());
    m_allCharacters[m_enemyIndex]->setTarget(m_allCharacters[m_playerIndex].get());

    changeEnemyIconIfNeeded(playerClass, enemyClass);
	
    auto gridPositions = randomizeCharactersPostions(grid);

    grid.getBoxWithIndex(gridPositions.first).setGridBoxOccupied(true);
    grid.getBoxWithIndex(gridPositions.first).setGridBoxOccupiedByPlayer(true);
    m_allCharacters[m_playerIndex]->setGridBox(grid.getBoxWithIndex(gridPositions.first));

    grid.getBoxWithIndex(gridPositions.second).setGridBoxOccupied(true);
    m_allCharacters[m_enemyIndex]->setGridBox(grid.getBoxWithIndex(gridPositions.second));

    grid.setCharactersIcons(m_allCharacters[m_playerIndex]->getIcon(), m_allCharacters[m_enemyIndex]->getIcon());
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

        m_allCharacters[m_enemyIndex]->setIcon(newEnemyIcon);
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
