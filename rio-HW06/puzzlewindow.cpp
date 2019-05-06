#include "puzzlewindow.h"
#include <QGridLayout>
#include <QPushButton>
#include "puzzleview.h"

PuzzleWindow::PuzzleWindow(QMainWindow *parent) :
    QMainWindow(parent)
{
    this->setWindowTitle("Sample 15 Puzzle");
    this->setMinimumHeight(400);
    this->setMinimumWidth(750);

    PuzzleModel* model = new PuzzleModel();
    PuzzleView* view = new PuzzleView(model);
    this->setCentralWidget(view);
}
