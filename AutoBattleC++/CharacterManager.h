#ifndef CharacterManager_h
#define CharacterManager_h
#pragma once

#include <list>
#include <iostream>
#include <vector>
#include "BaseCharacter.h"

class CharacterManager {
public:
	CharacterManager() {};
	~CharacterManager();
	void initializeCharacters(BaseCharacter::CharacterClass playerClass, BaseCharacter::CharacterClass enemyClass, Grid &grid);

	void changeEnemyIconIfNeeded(BaseCharacter::CharacterClass playerClass, BaseCharacter::CharacterClass enemyClass);

	std::vector<std::unique_ptr<BaseCharacter>> &getAllCharacters() { return m_allCharacters; }
	BaseCharacter* getPlayer() { return m_allCharacters[m_playerIndex].get(); }
	BaseCharacter* getEnemy() { return m_allCharacters[m_enemyIndex].get(); }

private:
	std::pair<int, int> randomizeCharactersPostions(Grid &grid);

private:
	std::vector<std::unique_ptr<BaseCharacter>> m_allCharacters;
	std::size_t m_playerIndex{0};
	std::size_t m_enemyIndex{0};
};
#endif

