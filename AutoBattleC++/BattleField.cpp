#include "Grid.h"
#include "BattleField.h"
#include <iostream>
#include "BattleField.h"
#include <list>
#include <string>

using namespace std;

BattleField::BattleField() {
    m_grid = Grid(m_gridLines, m_gridCollumns);
}

void BattleField::getPlayerChoice() {
    cout << "Choose Between One of this Classes, type the number of the class\n";

    cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer\n";
    
    int choice;  
    cin >> choice;

    auto characterClass = getClass(choice);
    auto enemyClass = getClass(rand() % 4 + 1);
    m_characterManager.initializeCharacters(characterClass, enemyClass, m_grid);
    showCharacterStatus();
}

void BattleField::showCharacterStatus() {
    //srand(time(NULL));

    string playerName;
    string enemyName;
    auto* player = m_characterManager.getPlayer();
    auto* enemy = m_characterManager.getEnemy();
    cout << "Excelent! Your class is: " << player->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << player->getHealth() << "\n";
    cout << "Damage: " << player->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << player->getDamageMultiplier() << "\n";
    cout << "A legendary " << player->getClassName() << " must have a name, so write your name: " << "\n";

    cin >> playerName;
    cout << "Let's meet your oponent, " << playerName << "!\n\n";

    cout << "Enemy class is: " << enemy->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << enemy->getHealth() << "\n";
    cout << "Damage: " << enemy->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << enemy->getDamageMultiplier() << "\n";
    cout << "A legendary enemy " << enemy->getClassName() << " must have a name, so write his name: " << "\n";

    cin >> enemyName;
    cout << "You will fight against the might: " << enemyName << "!\n";

    m_grid.drawBattlefieldWithIcons();
    cout << "\n\n";
    cout << "Your positions are the class icons! Don't forget\n";
    cout << "Your are: " << player->getIcon() << ", your enemy is: " << enemy->getIcon() << "!\n";
    cout << "Let's fight!\n";
    m_isSetupComplete = true;
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

void BattleField::startGame() {
    m_turnManager.handleTurn(m_grid, m_characterManager.getAllCharacters());
}
