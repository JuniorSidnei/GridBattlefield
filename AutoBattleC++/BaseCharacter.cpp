#include "BaseCharacter.h"

void BaseCharacter::attack() {
	m_target->takeDamage(m_baseDamage * m_damageMultiplier);
}

void BaseCharacter::takeDamage(int damage) {
	m_health -= damage;
}

bool BaseCharacter::isDead() {
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
	//refactor this to use the maps instead of a bunch of ifs
	if (m_gridBox.getPositionX() +1 == m_target->getGridBox().getPositionX()) {
		if (m_gridBox.getPositionY() == m_target->getGridBox().getPositionY()) {
			return true;
		}
		else {
			return false;
		}
	} else if (m_gridBox.getPositionX() -1 == m_target->getGridBox().getPositionX()) {
		if (m_gridBox.getPositionY() == m_target->getGridBox().getPositionY()) {
			return true;
		} else {
			return false;
		}
	} else if (m_gridBox.getPositionY() +1 == m_target->getGridBox().getPositionY()) {
		if (m_gridBox.getPositionX() == m_target->getGridBox().getPositionX()) {
			return true;
		} else {
			return false;
		}
	} else if (m_gridBox.getPositionY() -1 == m_target->getGridBox().getPositionY()) {
		if (m_gridBox.getPositionX() == m_target->getGridBox().getPositionX()) {
			return true;
		} else {
			return false;
		}
	}
	return false;
}

void BaseCharacter::moveToTarget(Grid &grid) {
	//todo if this works, implement diagonal movement
	//if is player and next move will get close to enem, return

	grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupied(false);
	grid.getGridBoxes()[m_target->getGridBox().getGridIndex()].setGridBoxOccupied(false);

	if (m_characterType == CharacterType::Player) {
		grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupiedByPlayer(false);
	}

	if (m_target->getGridBox().getPositionX() > m_gridBox.getPositionX()) {
		createNewGridBox(m_gridBox.getPositionX() + 1, m_gridBox.getPositionY(), grid.getCollumns());
		cout << "Character moved right\n\n";
	}
	else if (m_target->getGridBox().getPositionX() < m_gridBox.getPositionX()) {
		createNewGridBox(m_gridBox.getPositionX() - 1, m_gridBox.getPositionY(), grid.getCollumns());
		cout << "Character moved left\n\n";
	}
	else if (m_target->getGridBox().getPositionY() > m_gridBox.getPositionY()) {
		createNewGridBox(m_gridBox.getPositionX(), m_gridBox.getPositionY() + 1, grid.getCollumns());
		cout << "Character moved up\n\n";
	} else if (m_target->getGridBox().getPositionY() < m_gridBox.getPositionY()) {
		createNewGridBox(m_gridBox.getPositionX(), m_gridBox.getPositionY() - 1, grid.getCollumns());
		cout << "Character moved down\n\n";
	}

	grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupied(true);
	grid.getGridBoxes()[m_target->getGridBox().getGridIndex()].setGridBoxOccupied(true);
	if (m_characterType == CharacterType::Player) {
		grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupiedByPlayer(true);
	}
	
}

void BaseCharacter::createNewGridBox(int newX, int newY, int gridCollumns) {
	auto isPlayer = m_characterType == CharacterType::Player;
	m_gridBox.setGridBoxOccupied(false);
	m_target->getGridBox().setGridBoxOccupied(false);
	auto* newBox = new GridBox(newX, newY, true, isPlayer, (gridCollumns * newY + newX));
	m_gridBox = *newBox;
}

