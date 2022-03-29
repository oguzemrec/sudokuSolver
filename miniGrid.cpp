#include "miniGrid.h"
#include "QGridLayout"
#include "QPushButton"
#include "QLabel"
miniGrid::miniGrid(QWidget *parent) : QWidget(parent)
{
  int boxSize = 35 * 9;

  setMinimumSize(QSize(boxSize, boxSize));
  setMaximumSize(QSize(boxSize, boxSize));

  QGridLayout *gridLayout = new QGridLayout;

  layoutWidget = new QVBoxLayout(this);
  layoutWidget->addLayout(gridLayout);

  for (int y = 0; y < 9; y++)     //take placing the cells with order
    {
      for (int x = 0; x < 9; x++)
        {
          int cellNumber = ((y * 9)) + (x + 1);

          QSharedPointer<sudokuCellWidget> edit(new sudokuCellWidget(this, nullptr, QSize(35, 35)));
          edit->setClickable(false);

          gridCells.insert(cellNumber, edit);

          gridLayout->addWidget(edit.get(), y, x);
        }

      gridLayout->setSpacing(0);
    }

  for (int i = 0; i < 2; i++)     //grid lines
    {
      QFrame *lineV = new QFrame(this);
      lineV->setFrameShape(QFrame::VLine);
      lineV->setMinimumSize(3, boxSize - 22);      //because of the margin
      lineV->setMaximumSize(3, boxSize - 22);
      lineV->setLineWidth(2);
      gridLayout->addWidget(lineV, 0, (i + 1) * 3);

      QFrame *lineH = new QFrame(this);
      lineH->setFrameShape(QFrame::HLine);
      lineH->setMinimumSize(boxSize - 22, 2);      //because of the margin
      lineH->setMaximumSize(boxSize - 22, 2);
      lineH->setLineWidth(2);
      gridLayout->addWidget(lineH, (i + 1) * 3, 0, Qt::AlignTop);
    }
}

void miniGrid::insertSudokuGrid(const Sudoku &sudoku)
{
  auto cells = sudoku.getCells();

  for (auto c: cells)
    {
      gridCells[c->getCellNumber()]->setCell(c);
      gridCells[c->getCellNumber()]->updateCellWidget();
    }
}

void miniGrid::insertCell(const QSharedPointer<Cell> &cell)
{
  gridCells[cell->getCellNumber()]->setCell(cell);
  gridCells[cell->getCellNumber()]->updateCellWidget();
}

void miniGrid::insertHighLighted(const int &cellNo, QMap<int, QColor> candidates)
{
  QMapIterator<int, QColor> i(candidates);

  while (i.hasNext())
    {
      i.next();
      gridCells[cellNo]->insertHighLighted(i.key(), i.value());
      gridCells[cellNo]->updateCellWidget();
    }
}



QString miniGrid::getInfo()
{
  return info;
}

void miniGrid::setInfo(const QString &value)
{
  info = value;
}
