#ifndef Battlefield_h
#define Battlefield_h
#include "BaseCharacter.h"
#include "CharacterManager.h"
#include "TurnManager.h"
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

	int currentTurn = 0;
	int numberOfPossibleTiles = 0;


	void Setup();

	void GetPlayerChoice();

	BaseCharacter::CharacterClass getClass(int choice);
	
	void CreateEnemyCharacter();

	void AlocateCharactersPositions();

	bool isSetupComplete() { return m_isSetupComplete; }

	void StartGame();

private:
	CharacterManager m_characterManager;
	Grid* m_grid{nullptr};
	TurnManager m_turnManager;

	bool m_isSetupComplete = false;
	int m_gridLines = 5;
	int m_gridCollumns = 5;
};
#endif // !Battlefield_h


