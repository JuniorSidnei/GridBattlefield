#include "BaseCharacter.h"

void BaseCharacter::attack() {
	m_target->takeDamage(m_baseDamage * m_damageMultiplier);
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

bool BaseCharacter::isCloseToTarget() {
	if (m_gridBox.getPositionX() +1 == m_target->getGridBox().getPositionX()) {
		return true;
	} else if (m_gridBox.getPositionX() -1 == m_target->getGridBox().getPositionX()) {
		return true;
	} else if (m_gridBox.getPositionY() +1 == m_target->getGridBox().getPositionY()) {
		return true;
	} else if (m_gridBox.getPositionY() -1 == m_target->getGridBox().getPositionY()) {
		return true;
	}
	
	return false;
}

void BaseCharacter::moveToTarget(Grid &grid) {
	if (m_target->getGridBox().getPositionX() > m_gridBox.getPositionX()) {
		//a nova posição do grid é o mesmo calculo:
		//coluna * x + y
		//i = linha
		//j = coluna
		createNewGridBox(m_gridBox.getPositionX() + 1, m_gridBox.getPositionY(), grid.getCollumns());
		cout << "Character moved right";
	}
	else if (m_target->getGridBox().getPositionX() < m_gridBox.getPositionX()) {
		createNewGridBox(m_gridBox.getPositionX() - 1, m_gridBox.getPositionY(), grid.getCollumns());
		cout << "Character moved left";
	}
	else if (m_target->getGridBox().getPositionY() > m_gridBox.getPositionY()) {
		createNewGridBox(m_gridBox.getPositionX(), m_gridBox.getPositionY() + 1, grid.getCollumns());
		cout << "Character moved up";
	} else if (m_target->getGridBox().getPositionY() < m_gridBox.getPositionY()) {
		createNewGridBox(m_gridBox.getPositionX(), m_gridBox.getPositionY() - 1, grid.getCollumns());
		cout << "Character moved down";
	}
}

void BaseCharacter::createNewGridBox(int newX, int newY, int gridCollumns) {
	auto isPlayer = m_characterType == CharacterType::Player;
	m_gridBox.setGridBoxOccupied(false);
	auto* newBox = new GridBox(newX, newY, true, isPlayer, (gridCollumns * newX + newY));
	m_gridBox = *newBox;
}

