#ifndef BaseCharacter_h
#define BaseCharacter_h
#pragma once
#include "Grid.h"
#include "GridBox.h"
#include <map>
#include <string>

using namespace std;

class BaseCharacter {
public:

	enum class CharacterType {
		Player, Enemy
	};

    enum class CharacterClass {
        Paladin = 1,
        Warrior = 2,
        Cleric = 3,
        Archer = 4
    };

    struct CharacterStatus {
        int Health = 0;
        float BaseDamage = 0;
        float DamageMultiplier = 0;
        char Icon = 'A';
        string ClassName = "a";

        CharacterStatus(int health, float baseDamage, float damageMultiplier, char icon, const string& className) {
            Health = health;
            BaseDamage = baseDamage;
            DamageMultiplier = damageMultiplier;
            Icon = icon;
            ClassName = className;
        };

        CharacterStatus() {};
    };

    BaseCharacter() {};
    ~BaseCharacter() {};

    void attack();

    void takeDamage(int damage);
    bool isCharacterDead();

    inline int getHealth() { return m_health; }
    inline void setHealth(int health) { m_health = health; }

    inline float getBaseDamage() { return m_baseDamage; }
    inline void setBaseDamage(float baseDamage) { m_baseDamage = baseDamage; }

    inline float getDamageMultiplier() { return m_damageMultiplier; }
    inline void setDamageMultiplier(float damageMultiplier) { m_damageMultiplier = damageMultiplier; }

    char getIcon() { return m_icon; }
    inline void setIcon(char icon) { m_icon = icon; }

    inline BaseCharacter *getTarget() { return m_target; }
    inline void setTarget(BaseCharacter *target) { m_target = target; }

    inline GridBox getGridBox() { return m_gridBox; }
    inline void setGridBox(GridBox gridBox) { m_gridBox = gridBox; }

    inline CharacterType getType() { return m_characterType; }
    inline void setCharacterType(CharacterType characterType) { m_characterType = characterType; }

    inline string getName() { return m_name; }
    inline void setName(const string& name) { m_name = name; }

    inline CharacterStatus getCharacteStatus() { return m_characterStatus[m_characterClass]; }
    void setCharacterClassAndStatus(CharacterClass characterClass);

    inline string getClassName() { return m_characterStatus[m_characterClass].ClassName; }
    inline CharacterClass getClass() { return m_characterClass; }

    bool isCloseToTarget();
    void moveToTarget(Grid &grid);
    void createNewGridBox(int newX, int newY, int gridCollumns);

protected:
    int m_health = 0;
    float m_baseDamage = 0;
    float m_damageMultiplier = 0;
    char m_icon = 0;
    CharacterType m_characterType = CharacterType::Player;
    CharacterClass m_characterClass = CharacterClass::Paladin;
    string m_name;

    BaseCharacter* m_target = nullptr;
    GridBox m_gridBox;


    map<CharacterClass, CharacterStatus> m_characterStatus {
        { CharacterClass::Paladin, CharacterStatus(250, 25.0f, 1.2f, 'P', "Paladin")},
        { CharacterClass::Archer, CharacterStatus(150, 35.0f, 1.5f, 'A', "Archer")},
        { CharacterClass::Warrior, CharacterStatus(350, 30.0f, 1.2f, 'W', "Warrior")},
        { CharacterClass::Cleric, CharacterStatus(200, 20.0f, 1.3f, 'C', "Cleric")}
    };
};
#endif