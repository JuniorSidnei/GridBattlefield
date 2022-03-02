#include "Grid.h"
#include "BattleField.h"
#include "Types.h"
#include "Character.h"
#include <iostream>
#include "BattleField.h"
#include <list>
#include <string>

using namespace std;

void BattleField::Setup() {
  
    //initializing grid
    //TODO make this random
    m_grid = Grid(5, 5);
    //initializing all characters(player and enemy)
    m_characterManager.initializePlayers();
    //TODO assemble this after the grid is created
    //make a random number to get a box in the grid an set to player and enemy
 
}

void BattleField::GetPlayerChoice() {
    //asks for the player to choose between for possible classes via console.
    cout << "Choose Between One of this Classes, type the number of the class\n";

    cout << "[1] Paladin, [2] Warrior, [3] Cleric, [4] Archer";
    //store the player choice in a variable
    int choice;  
    string name;
    cin >> choice;

    auto characterClass = getClass(choice);
  
    auto player = m_characterManager.getPlayer();
    player->setCharacterClassAndStatus(characterClass);
    cout << "Excelent! Your class is: " << player->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << player->getHealth() << "\n";
    cout << "Damage: " << player->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << player->getDamageMultiplier() << "\n";
    cout << "A legendary " << player->getClassName() << " must have a name, so write your name: " << "\n";

    getline(cin, name);
    cout << "Let's begin, " << name << "!\n";
    CreateEnemyCharacter();
}

void BattleField::CreateEnemyCharacter() {
    srand(time(NULL));

    string name;
    auto enemyClass = getClass(rand() % 4 + 1);
    auto enemy = m_characterManager.getEnemy();
    enemy->setCharacterClassAndStatus(enemyClass);
    cout << "Excelent! Enemy class is: " << enemy->getClassName() << "\n";
    cout << "Here are the class status.\n";
    cout << "HP: " << enemy->getHealth() << "\n";
    cout << "Damage: " << enemy->getBaseDamage() << "\n";
    cout << "Damage multiplier: " << enemy->getDamageMultiplier() << "\n";
    cout << "A legendary enemy " << enemy->getClassName() << "must have a name, so write their name: " << "\n";

    getline(cin, name);
    cout << "You will fight against the might: " << name << "!\n";
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
        GetPlayerChoice();
    }
}

//void BattleField::StartGame()
//{
    //populates the character variables and targets
    //EnemyCharacter->target = PlayerCharacter;
    //PlayerCharacter->target = EnemyCharacter;
    //AllPlayers->push_back(PlayerCharacter);
    //AllPlayers->push_back(EnemyCharacter);
    //AlocatePlayers();
    //StartTurn();

//}

//void BattleField::StartTurn() {

    //if (currentTurn == 0)
    //{
    //    //AllPlayers.Sort();  
    //}
    //std::list<Character>::iterator it;

    //for (it = AllPlayers->begin(); it != AllPlayers->end(); ++it) {
    //    it->StartTurn(m_grid);
    //}

    //currentTurn++;
    //HandleTurn();
//}

//void BattleField::HandleTurn()
//{
    //if (PlayerCharacter->Health == 0)
    //{
    //    return;
    //}
    //else if (EnemyCharacter->Health == 0)
    //{
    //    printf("\n");

    //    // endgame?

    //    printf("\n");

    //    return;
    //}
    //else
    //{
    //    printf("\n");
    //    printf("Click on any key to start the next turn...\n");
    //    printf("\n");

    //    //TODO
    //    //ConsoleKeyInfo key = Console.ReadKey();
    //    StartTurn();
    //}
//}

void BattleField::AlocateCharactersPositions()
{
    //int random = 0;
    //auto l_front = m_grid->grids.begin();
    //advance(l_front, random);
    //Types::GridBox* RandomLocation = &*l_front;

    //if (!RandomLocation->ocupied)
    //{
    //    //Types::GridBox* PlayerCurrentLocation = RandomLocation;
    //    PlayerCurrentLocation = &*l_front;
    //    l_front->ocupied = true;
    //    PlayerCharacter->currentBox = *l_front;
    //    AlocateEnemyCharacter();
    //}
    //else
    //{
    //    AlocatePlayerCharacter();
    //}
}