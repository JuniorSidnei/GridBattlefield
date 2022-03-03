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

	//m_allCharacters.push_back(*m_playerCharacter);
	//m_allCharacters.push_back(*m_enemyCharacter);
}

void CharacterManager::sortAllPlayers() {
	std::random_shuffle(m_allCharacters.begin(), m_allCharacters.end());
}
