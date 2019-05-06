#include "puzzleview.h"
#include <QMessageBox>
#include <QApplication>

PuzzleView::PuzzleView(PuzzleModel* model, QWidget *parent)
    :QWidget(parent), m_Model(model)
{
    QGridLayout* m_Layout = new QGridLayout();
    for (int i = 0; i < 4; i++) { //Columns
        for (int j = 0; j < 4; j++) { //Rows
            Tile* tmp = new Tile(m_Model->value(j, i));
            m_Layout->addWidget(tmp, i, j, 0);
            m_Buttons.addButton(tmp, (4*i)+j);
        }
    }

    QPushButton* Shuffle = new QPushButton("Shuffle");
    QPushButton* Quit = new QPushButton("Quit");
    QGridLayout* buttonGrid = new QGridLayout();
    buttonGrid->addWidget(Shuffle);
    buttonGrid->addWidget(Quit);

    connect(Shuffle, SIGNAL(clicked(bool)), m_Model, SLOT(shuffle()));
    connect(Shuffle, SIGNAL(clicked(bool)), this, SLOT(updateFrame()));
    connect(Quit, SIGNAL(clicked(bool)), QApplication::instance(), SLOT(quit()));

    QGridLayout* mainFrame = new QGridLayout();
    mainFrame->addLayout(m_Layout, 0, 0);
    mainFrame->addLayout(buttonGrid, 1, 0);
    this->setLayout(mainFrame);

    connect(&m_Buttons, SIGNAL(buttonClicked(QAbstractButton*)), this, SLOT(tryToSlide(QAbstractButton*)));
}

void PuzzleView::updateFrame() {
    int i = 0;
    for(QAbstractButton* b: m_Buttons.buttons()) {
        b->setText(QString("%1").arg(m_Model->m_Positions.at(i)));
        if (b->text() == "16") b->setText("");
        i++;
    }
}

bool winCondition(QList<int>* arr) {
    for (int i = 1; i < arr->size(); i++) { //Start index 1 because i-1, check index before
        if (arr->at(i-1) > arr->at(i)) {
            return false;
        }
    }
    return true;
}

void PuzzleView::tryToSlide(QAbstractButton* button) {
    int val(button->text().toInt() == 0 ? 16 : button->text().toInt());
    int r, c;
    for (int i = 0; i < m_Model->m_Positions.size(); i++) {
        if(m_Model->m_Positions[i] == val) {
            r = ((i%4));
            c = ((i-r)/4);
        }
    }
    if(m_Model->neighboring(r, c)) {
        int pos16 = m_Model->slide(val); //returns index of position 16
        QAbstractButton* pointer16 = m_Buttons.buttons()[pos16];
        pointer16->setText(button->text());
        button->setText("");
    }
    if (winCondition(&(m_Model->m_Positions))) {
        QMessageBox::information(this, "You Won!", "You have won the game, click shuffle to play again..", QMessageBox::Ok);
    }
}

void PuzzleView::refresh() {

}
