#ifndef Grid_h
#define Grid_h
#pragma once
#include <iostream>
#include <Vector>
#include "GridBox.h"

class Grid {

public:

    Grid(int lines, int columns);
    Grid() {  };
    ~Grid();

    std::vector<GridBox> &getGridBoxes() { return m_gridBoxes; }
    GridBox getBoxWithIndex(int index) { return m_gridBoxes[index]; }
    void drawBattlefield();

private:
    int m_lines = 0;
    int m_collumns = 0;
    std::vector<GridBox> m_gridBoxes;
};
#endif

