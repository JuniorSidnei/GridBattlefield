#ifndef CharacterManager_h
#define CharacterManager_h
#pragma once

#include <list>
#include <iostream>
#include <vector>
#include "BaseCharacter.h"
using namespace std;

class CharacterManager {
public:

	~CharacterManager();
	void initializePlayers();
	

public:

	vector<BaseCharacter> getAllCharacters() { return m_allCharacters; }
	BaseCharacter* getPlayer() { return m_playerCharacter.get(); }
	BaseCharacter* getEnemy() { return m_enemyCharacter.get(); }

private:
	vector<BaseCharacter> m_allCharacters;
	unique_ptr<BaseCharacter> m_playerCharacter;
	unique_ptr<BaseCharacter> m_enemyCharacter;
};
#endif

