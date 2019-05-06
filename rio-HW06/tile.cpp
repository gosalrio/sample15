#include "tile.h"

Tile::Tile(int tileNumber, QPushButton* parent)
:QPushButton(parent), m_Number(tileNumber)
{
    if(this->m_Number != 16) {
        this->setText(QString("%1").arg(m_Number));
    }
    else {
        this->setText(QString(" "));
    }
}
