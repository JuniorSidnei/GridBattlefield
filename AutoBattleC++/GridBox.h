#ifndef GridBox_h
#define GridBox_h
#pragma once

class GridBox {
public:
    GridBox(int positionX, int positionY, bool isPositionOccupied, int indexPosition);
    GridBox() {};

    inline bool isGridBoxOccupied() { return m_isPositionOccupied; }
    inline int getGridIndex() { return m_indexPosition; }

private:
    int m_positionX = 0;
    int m_positionY = 0;
    bool m_isPositionOccupied = false;
    int m_indexPosition = 0;
};
#endif // !GridBox_h

