#pragma once
using namespace std;

class BaseCharacter {
public:

	enum CharacterType {
		Player, Enemy
	};

    enum CharacterClass {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4
    };

    struct GridBoxPosition {
        int PositionX;
        int PositionY;
        bool IsPositionOccupied;
        int IndexPosition;

        GridBoxPosition(int positionX, int positionY, bool isPositionOccupied, int indexPosition) {
            PositionX = positionX;
            PositionY = positionY;
            IsPositionOccupied = isPositionOccupied;
            IndexPosition = indexPosition;
        }
    };

    BaseCharacter(float health, float baseDamage, float damageMultiplier, char icon);
    ~BaseCharacter();

    void attack(BaseCharacter *target);
    void moveTo(GridBoxPosition *gridPosition);

    void takeDamage(int damage);
    bool isCharacterDead();

    float getHealth() { return m_health; }
    void setHealth(int health) { m_health = health; }

    float getBaseDamage() { return m_baseDamage; }
    void setBaseDamage(float baseDamage) { m_baseDamage = baseDamage; }

    float getDamageMultiplier() { return m_damageMultiplier; }
    void setDamageMultiplier(float damageMultiplier) { m_damageMultiplier = damageMultiplier; }

    char getIcon() { return m_icon; }
    void setIcon(char icon) { m_icon = icon; }

    BaseCharacter *getTarget() { return m_target; }
    void setTarget(BaseCharacter *target) { m_target = target; }

    GridBoxPosition *getGridPosition() { return m_gridPosition; }
    void setGridPosition(GridBoxPosition* gridPosition) { m_gridPosition = gridPosition; }

protected:
    float m_health = 0;
    float m_baseDamage = 0;
    float m_damageMultiplier = 0;
    char m_icon = 0;

    BaseCharacter* m_target = nullptr;
    GridBoxPosition* m_gridPosition = nullptr;
};

