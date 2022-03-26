#include "sudoku.h"

Sudoku::Sudoku()
{
  Rows.reserve(GROUP_NUMBER);
  Boxes.reserve(GROUP_NUMBER);
  Columns.reserve(GROUP_NUMBER);
  cells.reserve(CELL_NUMBER);

  for (int i = 0; i < CELL_NUMBER; ++i)
    cells.append(QSharedPointer<Cell>(new Cell(i + 1)));


  {   //Rows
    int order = 0;
    int y = 0;
    for (int i = 0; i < GROUP_NUMBER; ++i)
      {
        y = order * 9;
        order++;

        QVector<QSharedPointer<Cell> > RowCells;

        RowCells.reserve(GROUP_NUMBER);
        for (int k = 0; k < GROUP_NUMBER; ++k)
          {
            RowCells.append(cells[y + k]);
            cells[y + k]->setRowNumber(i + 1);
          }

        Rows.append(QSharedPointer<Group>(new Group(i + 1, RowCells)));
      }
  }

  {   //Columns
    for (int i = 0; i < GROUP_NUMBER; ++i)
      {
        QVector<QSharedPointer<Cell> > columnCells;
        columnCells.reserve(GROUP_NUMBER);
        for (int k = 0; k < GROUP_NUMBER; ++k)
          {
            columnCells.append(cells[((k) * 9) + i]);
            cells[((k) * 9) + i]->setColumnNumber(i + 1);
          }

        Columns.append(QSharedPointer<Group>(new Group(i + 1, columnCells)));
      }
  }

  {//Boxes
    // if the box number 1,4,7 the coefficient is 0
    // if the box number 2,5,8 the coefficient is 1
    // if the box number 3,6,9 the coefficient is 2
    //coefficient (((boxNumber+2)%3)*3 +1)
    //orderLineOffset represents 3 line. one box subset contains 3 lines
    int boxNumber = 0;
    int orderLineOffset = 0;
    for (int i = 0; i < GROUP_NUMBER; ++i)
      {
        boxNumber = i + 1;

        if (boxNumber == 4)
          orderLineOffset = 1;
        else if (boxNumber == 7)
          orderLineOffset = 2;

        QVector<QSharedPointer<Cell> > BoxCells;
        BoxCells.reserve(9);
        for (int y = 0; y < 3; ++y)
          {
            int no = (((boxNumber + 2) % 3) * 3 + 1) + ((y + (orderLineOffset * 3)) * 9);
            BoxCells.append(cells[no - 1]);
            cells[no - 1]->setBoxNumber(boxNumber);

            BoxCells.append(cells[no]);
            cells[no]->setBoxNumber(boxNumber);

            BoxCells.append(cells[no + 1]);
            cells[no + 1]->setBoxNumber(boxNumber);
          }

        Boxes.append(QSharedPointer<Group>(new Group(boxNumber, BoxCells)));
      }
  }


  for (auto c:cells)
    {
      c->setOwnBox(Boxes[c->getBoxNumber() - 1]);
      c->setOwnRow(Rows[c->getRowNumber() - 1]);
      c->setOwnColumn(Columns[c->getColumnNumber() - 1]);
    }
}

QVector<QSharedPointer<Group> > Sudoku::getBoxes() const
{
  return Boxes;
}

QSharedPointer<Cell>  Sudoku::getCell(int cellNo) const
{
  return cells[cellNo - 1];
}

QSet<int> Sudoku::getIntersectCells(int cellNo) const
{
  QSet<int> inter;
  auto box = cells[cellNo - 1]->getOwnBox()->getCells();
  auto column = cells[cellNo - 1]->getOwnColumn()->getCells();
  auto row = cells[cellNo - 1]->getOwnRow()->getCells();

  for (auto const& b: box)
    inter.insert(b->getCellNumber());

  for (auto const& c: column)
    inter.insert(c->getCellNumber());

  for (auto const& r: row)
    inter.insert(r->getCellNumber());

  return inter;
}



void Sudoku::scanGrid()
{
  emptyCells.clear();

  clueCellCount = 18;
  solvedCellCount = 0;
  emptyCellCount = 0;

  for (auto c:cells)
    {
      if (c->getClueFlag() == true)
        clueCellCount++;
      else if (c->getSolvedFlag() == true)
        solvedCellCount++;
      else
        {
          emptyCells.push_back(c);
          emptyCellCount++;
        }
    }
}

QVector<QSharedPointer<Cell> > Sudoku::getEmptyCells() const
{
  return emptyCells;
}

QVector<QSharedPointer<Group> > Sudoku::getRows() const
{
  return Rows;
}

QVector<QSharedPointer<Cell> > Sudoku::getCells() const
{
  return cells;
}


bool Sudoku::IsSameGroup(Sections sec, QSet<int> cells)
{
  QSet<int> groupNo;

  for (const auto& c: cells)
    {
      if (sec == Sections::BOX)
        {
          groupNo.insert(getCell(c)->getBoxNumber());
        }
      else if (sec == Sections::COLUMN)
        {
          groupNo.insert(getCell(c)->getColumnNumber());
        }
      else if (sec == Sections::ROW)
        {
          groupNo.insert(getCell(c)->getRowNumber());
        }
    }

  if (groupNo.size() > 1)
    return false;
  else
    return true;
}
