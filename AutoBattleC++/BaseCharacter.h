#ifndef BaseCharacter_h
#define BaseCharacter_h
#pragma once
#include <utility>
#include "Grid.h"
#include "GridBox.h"
#include <map>
#include <iostream>
#include <string>

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
        std::string ClassName = "a";

        CharacterStatus(int health, float baseDamage, float damageMultiplier, char icon, const std::string& className) {
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
    bool isDead();

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

    inline std::string getName() { return m_name; }
    inline void setName(const std::string& name) { m_name = name; }

    inline CharacterStatus getCharacteStatus() { return m_characterStatus[m_characterClass]; }
    void setCharacterClassAndStatus(CharacterClass characterClass);

    inline std::string getClassName() { return m_characterStatus[m_characterClass].ClassName; }
    inline CharacterClass getClass() { return m_characterClass; }

    bool isCloseToTarget();
    void moveToTarget(Grid &grid);
    void createNewGridBox(int newX, int newY, int gridCollumns);

  

private:
    bool checkPosition(std::pair<int, int> &position);
    

protected:
    int m_health = 0;
    float m_baseDamage = 0;
    float m_damageMultiplier = 0;
    char m_icon = 0;
    CharacterType m_characterType = CharacterType::Player;
    CharacterClass m_characterClass = CharacterClass::Paladin;
    std::string m_name;

    BaseCharacter* m_target = nullptr;
    GridBox m_gridBox;

    std::vector<std::pair<int, int>> m_fourDirectionPositions = {
        {-1, 0}, //left
        {0,  1}, //top
        {1,  0}, //right
        {0, -1}  //down
    };

    std::vector<std::pair<int, int>> m_eightDirectionPositions = {
        {-1,   0}, //left
        {-1,   1}, //top_left
        {0,    1}, //top
        {1,    1}, //top_right
        {0,    1}, //right
        {1,   -1}, //down_right
        {0,   -1}, //down
        {-1,  -1} //down_left
    };

    std::map<CharacterClass, CharacterStatus> m_characterStatus {
        { CharacterClass::Paladin, CharacterStatus(250, 25.0f, 1.2f, 'P', "Paladin")},
        { CharacterClass::Archer, CharacterStatus(150, 35.0f, 1.5f, 'A', "Archer")},
        { CharacterClass::Warrior, CharacterStatus(350, 30.0f, 1.2f, 'W', "Warrior")},
        { CharacterClass::Cleric, CharacterStatus(200, 20.0f, 1.3f, 'C', "Cleric")}
    };
};
#endif