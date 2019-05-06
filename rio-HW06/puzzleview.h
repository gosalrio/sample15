#ifndef PUZZLEVIEW_H
#define PUZZLEVIEW_H

#include <QWidget>
#include "puzzlemodel.h"
#include "tile.h"
#include <QGridLayout>
#include <QButtonGroup>

class PuzzleView : public QWidget
{
    Q_OBJECT
public:
    explicit PuzzleView(PuzzleModel* model, QWidget *parent = 0);
    void refresh();

private:
    PuzzleModel* m_Model;
    QGridLayout* m_Layout;
    QButtonGroup m_Buttons;

signals:

public slots:
    void tryToSlide(QAbstractButton* button);
    void updateFrame();
};

#endif // PUZZLEVIEW_H
