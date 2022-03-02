#ifndef Battlefield_h
#define Battlefield_h
#include "BaseCharacter.h"
#include "CharacterManager.h"
#include <iostream>
#include "Grid.h"
using namespace std;

class BattleField {
public:

	BattleField(){};

	//list<BaseCharacter>* AllPlayers;
	//shared_ptr<Character> PlayerCharacter;
	//Character* PlayerCharacter;
	//shared_ptr<Character>* EnemyCharacter;

	int currentTurn;
	int numberOfPossibleTiles;


	void Setup();

	void GetPlayerChoice();

	BaseCharacter::CharacterClass getClass(int choice);
	
	void CreateEnemyCharacter();

	void AlocateCharactersPositions();

	//move the start game, start turn, end turn, handle turn to turn manager
	//void StartGame();

	//void StartTurn();

	//void HandleTurn();

private:
	CharacterManager m_characterManager;
	Grid m_grid;
};
#endif // !Battlefield_h


