#include "CharacterManager.h"

CharacterManager::~CharacterManager() {
	delete(m_playerCharacter.get());
	delete(m_enemyCharacter.get());
}

void CharacterManager::initializePlayers() {
	m_playerCharacter = std::make_unique<BaseCharacter>();
	m_playerCharacter->setCharacterType(BaseCharacter::CharacterType::Player);
	m_enemyCharacter = std::make_unique<BaseCharacter>();
	m_enemyCharacter->setCharacterType(BaseCharacter::CharacterType::Enemy);

	m_allCharacters.push_back(*m_playerCharacter.get());
	m_allCharacters.push_back(*m_enemyCharacter.get());
}
