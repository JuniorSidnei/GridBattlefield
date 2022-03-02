#include "GridBox.h"

GridBox::GridBox(int positionX, int positionY, bool isPositionOccupied, int indexPosition) {
    m_positionX = positionX;
    m_positionY = positionY;
    m_isPositionOccupied = isPositionOccupied;
    m_indexPosition = indexPosition;
}
