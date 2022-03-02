#include "BaseCharacter.h"

void BaseCharacter::attack(BaseCharacter* target) {
	target->takeDamage(m_baseDamage * m_damageMultiplier);
}

void BaseCharacter::moveTo(GridBox newGridBox) {
	m_gridBox = newGridBox;
}

void BaseCharacter::takeDamage(int damage) {
	m_health -= damage;
}

bool BaseCharacter::isCharacterDead() {
	return m_health <= 0;
}

void BaseCharacter::setCharacterClassAndStatus(CharacterClass characterClass) {
	m_characterClass = characterClass;
	m_health = m_characterStatus[m_characterClass].Health;
	m_baseDamage = m_characterStatus[m_characterClass].BaseDamage;
	m_damageMultiplier = m_characterStatus[m_characterClass].DamageMultiplier;
	m_icon= m_characterStatus[m_characterClass].Icon;
}
