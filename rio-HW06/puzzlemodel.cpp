#include "puzzlemodel.h"
#include <stdlib.h>

PuzzleModel::PuzzleModel(QObject *parent)
: QObject(parent), m_Rows(4), m_Cols(4)
{
    m_Positions = {};
    srand(time(NULL));
    shuffle();
}

bool duplicate(const int n, const QList<int> *lst) {
    for (int i = 0; i < lst->size(); i++) {
        if(lst->at(i) == n) {
            return true;
        }
    }
    return false;
}

void PuzzleModel::shuffle() {
    m_Positions.clear();
    while (m_Positions.size() < m_Rows*m_Cols) {
        int rnd = rand() % 16 + 1;
        if (!duplicate(rnd, &m_Positions)) {
            m_Positions.append(rnd);
        }
    }
}

int PuzzleModel::value(int r, int c) {
    return m_Positions[(4*c)+r];
}

int PuzzleModel::slide(int tileNum) {
    int i(0), j(0); //i = location of tileNum, j = location of 16
    while(i < m_Positions.size() && j < m_Positions.size()) {
        if (m_Positions[j] == 16 && m_Positions[i] == tileNum) break;
        else {
            if(m_Positions[i] != tileNum) i++;
            if(m_Positions[j] != 16) j++;
        }
    }

    //Swap numbers
    int tmp = m_Positions[i];
    m_Positions[i] = m_Positions[j];
    m_Positions[j] = tmp;

    return j;
}

bool PuzzleModel::neighboring(int r, int c) {
    //Check Left Side
    if(r-1 >= 0) {
        if(value(r-1, c) == 16) {
            return true;
        }
    }
    //Check right side
    if(r+1 < 4) {
        if (value(r+1, c) == 16) {
            return true;
        }
    }
    //Check top side
    if (c-1 >= 0) {
        if (value(r, c-1) == 16) {
            return true;
        }
    }
    //Check bottom side
    if (c+1 < 4) {
        if (value(r, c+1) == 16) {
            return true;
        }
    }
    return false;
}
