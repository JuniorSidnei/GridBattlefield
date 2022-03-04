#include "BaseCharacter.h"

void BaseCharacter::attack() {
	std::cout << "<<< " << getCharacterType(m_characterType) << " " << getClassName() << " attacked!\n";
	m_target->takeDamage(m_baseDamage * m_damageMultiplier);
}

void BaseCharacter::takeDamage(int damage) {
	m_health -= damage;
	if (m_health <= 0) m_health = 0;
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

std::string BaseCharacter::getCharacterType(CharacterType type) {
	if (type == CharacterType::Player) {
		return "Player";
	}
	return "Enemy";
}

bool BaseCharacter::isCloseToTarget() {
	auto pivot = m_gridBox.getPositionXY();
	auto positionsToCheck = m_fourDirectionPositions;

	if (m_characterType == CharacterType::Player) {
		positionsToCheck = m_eightDirectionPositions;
	}

	for (auto &positionToCheck : positionsToCheck) {
		auto x = pivot.first + positionToCheck.first;
		auto y = pivot.second + positionToCheck.second;

		auto position = std::make_pair(x, y);
		if (checkPosition(position)) {
			return true;
		} 
	}
	
	return false;
}

void BaseCharacter::moveToTarget(Grid &grid) {
	grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupied(false);
	grid.getGridBoxes()[m_target->getGridBox().getGridIndex()].setGridBoxOccupied(false);

	if (m_characterType == CharacterType::Player) {
		grid.getGridBoxes()[m_gridBox.getGridIndex()].setGridBoxOccupiedByPlayer(false);
	}

	auto targetPosition = m_target->getGridBox().getPositionXY();
	auto currentPosition = m_gridBox.getPositionXY();
	auto currentDirection = DirectionToMove::Left;

	if (m_characterType == CharacterType::Player) {
		currentDirection = validateEightDirection(targetPosition, currentPosition);
	}
	else {
		currentDirection = validateFourDirection(targetPosition, currentPosition);
	}

	auto newPositionX = currentPosition.first + m_directionPosition[currentDirection].first;
	auto newPositionY = currentPosition.second + m_directionPosition[currentDirection].second;

	createNewGridBox(newPositionX, newPositionY, grid.getCollumns());

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

bool BaseCharacter::checkPosition(std::pair<int, int> &position) {
	if (position.first == m_target->getGridBox().getPositionX() &&
		position.second == m_target->getGridBox().getPositionY()) {
		return true;
	}
	return false;
}

BaseCharacter::DirectionToMove BaseCharacter::validateEightDirection(std::pair<int, int> &targetPosition, std::pair<int, int> &currentPosition) {
	if (currentPosition.first > targetPosition.first) {
		if (currentPosition.second == targetPosition.second) {
			std::cout << "Player moved left\n";
			return DirectionToMove::Left;
		} else if (currentPosition.second > targetPosition.second) {
			std::cout << "Player moved top left\n";
			return DirectionToMove::Top_left;
		} else if (currentPosition.second < targetPosition.second) {
			std::cout << "Player moved down left\n";
			return DirectionToMove::Down_left;
		}
	}
	else if (currentPosition.first < targetPosition.first) {
		if (currentPosition.second == targetPosition.second) {
			std::cout << "Player moved right\n";
			return DirectionToMove::Right;
		} else if (currentPosition.second > targetPosition.second) {
			std::cout << "Player moved top right\n";
			return DirectionToMove::Top_right;
		} else if (currentPosition.second < targetPosition.second) {
			std::cout << "Player moved down right\n";
			return DirectionToMove::Down_right;
		}
	}
	else if (currentPosition.second > targetPosition.second) {
		if (currentPosition.first == targetPosition.first) {
			std::cout << "Player moved top\n";
			return DirectionToMove::Top;
		} else if (currentPosition.first > targetPosition.first) {
			std::cout << "Player moved top left\n";
			return DirectionToMove::Top_left;
		} else if (currentPosition.first < targetPosition.first) {
			std::cout << "Player moved top right\n";
			return DirectionToMove::Top_right;
		}
	}
	else if (currentPosition.second < targetPosition.second) {
		if (currentPosition.first == targetPosition.first) {
			std::cout << "Player moved top\n";
			return DirectionToMove::Top;
		} else if (currentPosition.first > targetPosition.first) {
			std::cout << "Player moved down left\n";
			return DirectionToMove::Down_left;
		} else if (currentPosition.first < targetPosition.first) {
			std::cout << "Player moved down right\n";
			return DirectionToMove::Down_right;
		}
	}
}

BaseCharacter::DirectionToMove BaseCharacter::validateFourDirection(std::pair<int, int> &targetPosition, std::pair<int, int> &currentPosition) {
	if (currentPosition.first > targetPosition.first) {
		std::cout << "Enemy moved left\n";
		return DirectionToMove::Left;
	} else if (currentPosition.first < targetPosition.first) {
		std::cout << "Enemy moved right\n";
		return DirectionToMove::Right;
	}else if (currentPosition.second > targetPosition.second) {
		std::cout << "Enemy moved top\n";
		return DirectionToMove::Top;
	} else if (currentPosition.second < targetPosition.second) {
		std::cout << "Enemy moved down\n";
		return DirectionToMove::Down;
	}
}

