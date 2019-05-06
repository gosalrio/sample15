#ifndef PUZZLEMODEL_H
#define PUZZLEMODEL_H

#include <QPushButton>
#include <QObject>

class PuzzleModel : public QObject
{
    Q_OBJECT
public:
    explicit PuzzleModel(QObject *parent = 0);
    int value(int r, int c);
    int slide(int tileNum);
    bool neighboring(int r, int c);
    QList<int> m_Positions;

private:
    int m_Rows;
    int m_Cols;

signals:
    void gridChanged();

public slots:
    void shuffle();
};

#endif // PUZZLEMODEL_H
