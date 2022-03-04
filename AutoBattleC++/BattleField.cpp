#include "Grid.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include <iostream>
#include "BattleField.h"
#include <list>
#include <string>

using namespace std;

void BattleField::setup() {
    m_grid = new Grid(m_gridLines, m_gridCollumns);
    m_characterManager.initializePlayers();
}

void BattleField::getPlayerChoice() {
    cout << "Choose Between One of this Classes, type the number of the class\n";

    cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";
    
    int choice;  
    string name;
    cin >> choice;

    auto characterClass = getClass(choice);
  
    auto *player = m_characterManager.getPlayer();
    player->setCharacterClassAndStatus(characterClass);
    m_characterManager.insertCharacter(*player);
    cout << "Excelent! Your class is: " << player->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << player->getHealth() << "\n";
    cout << "Damage: " << player->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << player->getDamageMultiplier() << "\n"; 
    cout << "A legendary " << player->getClassName() << " must have a name, so write your name: " << "\n";

    cin >> name;
    cout << "Let's begin, " << name << "!\n\n\n";
    createEnemyCharacter();
}

void BattleField::createEnemyCharacter() {
    srand(time(NULL));

    string name;
    auto enemyClass = getClass(rand() % 4 + 1);
    auto *enemy = m_characterManager.getEnemy();
    enemy->setCharacterClassAndStatus(enemyClass);
    m_characterManager.insertCharacter(*enemy);
    auto* player = m_characterManager.getPlayer();
    auto playerClass = player->getClass();
    if (enemyClass == playerClass) {
        auto newEnemyIcon = 'p';

        switch (playerClass) {
        case BaseCharacter::CharacterClass::Archer:
            newEnemyIcon = 'a';
            break;
        case BaseCharacter::CharacterClass::Cleric:
            newEnemyIcon = 'c';
            break;
        case BaseCharacter::CharacterClass::Warrior:
            newEnemyIcon = 'w';
            break;
        default:
            break;
        }

        enemy->setIcon(newEnemyIcon);
    }

    cout << "Enemy class is: " << enemy->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << enemy->getHealth() << "\n";
    cout << "Damage: " << enemy->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << enemy->getDamageMultiplier() << "\n";
    cout << "A legendary enemy " << enemy->getClassName() << " must have a name, so write his name: " << "\n";

    cin >> name;
    cout << "You will fight against the might: " << name << "!\n";
    alocateCharactersPositions();
}

BaseCharacter::CharacterClass BattleField::getClass(int choice) {
    switch ((choice)) {
    case 1:
        return BaseCharacter::CharacterClass::Paladin;
        break;
    case 2:
        return BaseCharacter::CharacterClass::Warrior;
        break;
    case 3:
        return BaseCharacter::CharacterClass::Cleric;
        break;
    case 4:
        return BaseCharacter::CharacterClass::Archer;
        break;
    default:
        printf("Choose a valid number class!\n");
        getPlayerChoice();
        break;
    }
}

void BattleField::alocateCharactersPositions() {

    srand(time(NULL));
    auto max = m_grid->getGridBoxes().size();
    auto playerRandPos = rand() % max + 1;
    auto enemyRandPos = rand() % max + 1;

    if (enemyRandPos == playerRandPos) {
        alocateCharactersPositions();
        return;
    }

    auto player = m_characterManager.getPlayer();
    m_grid->getGridBoxes()[playerRandPos].setGridBoxOccupied(true);
    m_grid->getGridBoxes()[playerRandPos].setGridBoxOccupiedByPlayer(true);
    player->setGridBox(m_grid->getGridBoxes()[playerRandPos]);
    
    auto enemy = m_characterManager.getEnemy();
    m_grid->getGridBoxes()[enemyRandPos].setGridBoxOccupied(true);
    m_grid->getGridBoxes()[enemyRandPos].setGridBoxOccupiedByPlayer(false);
    enemy->setGridBox(m_grid->getGridBoxes()[enemyRandPos]);

    cout << "\n\n\n";
    m_grid->setCharactersIcons(player->getIcon(), enemy->getIcon());
    m_grid->drawBattlefieldWithIcons();
    cout << "\n\n";
    cout << "Your positions are the class icons! Don't forget\n";
    cout << "Your are: " << player->getIcon() << ", your enemy is: " << enemy->getIcon() << "!\n";
    cout << "Let's fight!\n";
    m_isSetupComplete = true;
}

void BattleField::startGame() {
    m_turnManager.startGame(*m_grid, *m_characterManager.getAllCharacters());
}
