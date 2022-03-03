#include "GridBox.h"

GridBox::GridBox(int positionX, int positionY, bool isPositionOccupied, bool isPlayerCharacter, int indexPosition) {
    m_positionX = positionX;
    m_positionY = positionY;
    m_isPositionOccupied = isPositionOccupied;
    m_isPlayerCharacter = isPlayerCharacter;
    m_indexPosition = indexPosition;
}
