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

	void setup();

	void getPlayerChoice();

	BaseCharacter::CharacterClass getClass(int choice);
	
	void createEnemyCharacter();

	void alocateCharactersPositions();

	bool isSetupComplete() { return m_isSetupComplete; }

	void startGame();

private:
	CharacterManager m_characterManager;
	Grid* m_grid{nullptr};
	std::vector<BaseCharacter> m_allCharacters;
	TurnManager m_turnManager;

	bool m_isSetupComplete = false;
	int m_gridLines = 5;
	int m_gridCollumns = 5;
};
#endif // !Battlefield_h


