#include "BaseCharacter.h"
using namespace std;

BaseCharacter::BaseCharacter(float health, float baseDamage, float damageMultiplier, char icon) {
	m_health = health;
	m_baseDamage = baseDamage;
	m_damageMultiplier = damageMultiplier;
	m_icon = icon;
}

BaseCharacter::~BaseCharacter() {

}

void BaseCharacter::attack(BaseCharacter* target) {
	target->takeDamage(m_baseDamage * m_damageMultiplier);
}

void BaseCharacter::moveTo(GridBoxPosition* gridPosition) {
	m_gridPosition = gridPosition;
}

void BaseCharacter::takeDamage(int damage) {
	m_health -= damage;
}

bool BaseCharacter::isCharacterDead() {
	return m_health <= 0;
}
