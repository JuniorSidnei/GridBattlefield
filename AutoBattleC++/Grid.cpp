#include "Grid.h"
#include "Types.h"


Grid::Grid(int lines, int columns) {

    if (lines < 3 && columns < 3) {
        std::cout << "Grid size is too small! Try again!";
        return;
    }

    m_lines = lines;
    m_collumns = columns;

    for (int i = 0; i < m_lines; i++) {

        for (int j = 0; j < m_collumns; j++) {
            auto *newBox = new GridBox(j, i, false, false, (m_collumns * i + j));
            m_gridBoxes.insert(m_gridBoxes.end(), *newBox);
            //std::cout << "grid box index: " << newBox.getGridIndex() << " \n";
        }
    }
    
    drawBattlefield();
}

Grid::~Grid() 
{

}

void Grid::setCharactersIcons(char playerIcon, char enemyIcon) {
    m_playerIcon = playerIcon;
    m_enemyIcon = enemyIcon;
}

void Grid::drawBattlefield() {
    for (int i = 0; i < m_lines; i++) {
        for (int j = 0; j < m_collumns; j++) {
            int gridPos = m_collumns * i + j;
            
            if (m_gridBoxes[gridPos].isGridBoxOccupied()) {
                std::cout << "[X] ";
            }
            else {
                std::cout << "[ ] ";
            }
        }
        printf("\n");
    }
    printf("\n");
}

void  Grid::drawBattlefieldWithIcons() {
    for (int i = 0; i < m_lines; i++) {
        for (int j = 0; j < m_collumns; j++) {
            int gridPos = m_collumns * i + j;

            if (m_gridBoxes[gridPos].isGridBoxOccupied()) {
                if (m_gridBoxes[gridPos].isGridBoxOccupiedByPlayer()) {
                    std::cout << "[" << m_playerIcon << "] ";
                }
                else {
                    std::cout << "[" << m_enemyIcon << "] ";
                }
            }
            else {
                std::cout << "[ ] ";
            }
        }
        printf("\n");
    }
    printf("\n");
}