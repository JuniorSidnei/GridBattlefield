#include "Grid.h"
#include "Types.h"


Grid::Grid(int lines, int columns)
{
    m_lines = lines;
    m_collumns = columns;

    for (int i = 0; i < m_lines; i++) {

        for (int j = 0; j < m_collumns; j++) {
            auto newBox = GridBox(i, j, false, (m_collumns * i + j));
            m_gridBoxes.push_back(newBox);
            //Console.Write($"{newBox.Index}\n");
        }
    }
}

Grid::~Grid() 
{

}

GridBox Grid::getGridBoxWithIndex(int index) {
    /*if (index > m_gridBoxes.size()) {
        std::cout << "Nehuma box disponivel. Retornando uma box nova."
        return;
    }*/

    return m_gridBoxes[index];
}

void Grid::drawBattlefield() {
    for (int i = 0; i < m_lines; i++) {
        for (int j = 0; j < m_collumns; j++) {
            int gridPos = m_collumns * i + j;
           
            if (m_gridBoxes[gridPos].isGridBoxOccupied()) {
                printf("[X]\t");
            }
            else {
                printf("[ ]\t");
            }
        }
        printf("\n");
    }
    printf("\n");
}