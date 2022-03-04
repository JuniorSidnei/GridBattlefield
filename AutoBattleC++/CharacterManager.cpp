#include "CharacterManager.h"
#include <algorithm>

CharacterManager::~CharacterManager() {
	delete(m_playerCharacter.get());
	delete(m_enemyCharacter.get());
}

void CharacterManager::initializePlayers() {
	m_playerCharacter = std::make_unique<BaseCharacter>();
	m_playerCharacter->setCharacterType(BaseCharacter::CharacterType::Player);
	
	m_enemyCharacter = std::make_unique<BaseCharacter>();
	m_enemyCharacter->setCharacterType(BaseCharacter::CharacterType::Enemy);

	m_playerCharacter->setTarget(m_enemyCharacter.get());
	m_enemyCharacter->setTarget(m_playerCharacter.get());
}

void CharacterManager::insertCharacter(BaseCharacter& character) {
	m_allCharacters.push_back(character);
}
