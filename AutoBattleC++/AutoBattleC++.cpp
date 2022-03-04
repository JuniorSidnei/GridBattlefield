#include "BattleField.h"
#include <iostream>

int main() {
    BattleField* battleField = new(BattleField);
    battleField->getPlayerChoice();

    if (battleField->isSetupComplete()) {
        battleField->startGame();
    }

    system("pause");
    delete(battleField);
    return 0;
}