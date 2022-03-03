#ifndef GridBox_h
#define GridBox_h
#pragma once

class GridBox {
public:
    GridBox(int positionX, int positionY, bool isPositionOccupied, bool isPlayerCharacter, int indexPosition);
    GridBox() {};

    inline bool isGridBoxOccupied() { return m_isPositionOccupied; }
    inline void setGridBoxOccupied(bool isOccupied) { m_isPositionOccupied = isOccupied; }

    inline bool isGridBoxOccupiedByPlayer() { return m_isPlayerCharacter; }
    inline void setGridBoxOccupiedByPlayer(bool isOccupied) { m_isPlayerCharacter = isOccupied; }

    inline int getGridIndex() { return m_indexPosition; }
    inline int setGridIndex(int newIndex) { m_indexPosition = newIndex; }

    inline int getPositionX() { return m_positionX; }
    inline void setPositionX(int newPos) { m_positionX = newPos; }

    inline int getPositionY() { return m_positionY; }
    inline void setPositionY(int newPos) { m_positionY = newPos; }    

private:
    int m_positionX = 0;
    int m_positionY = 0;
    bool m_isPositionOccupied = false;
    bool m_isPlayerCharacter = false;
    int m_indexPosition = 0;
};
#endif // !GridBox_h

