#ifndef SUDOKU_H
#define SUDOKU_H


#include <QVector>
#include <QSharedPointer>
#include "cell.h"
#include "group.h"


class Sudoku
{
public:

Sudoku();

QVector<QSharedPointer<Group> > getBoxes() const;
QSharedPointer<Cell>  getCell(int cellNo) const;
QSet<int> getIntersectCells(int cellNo) const;

int getClueCellsCount() const
{
  return clueCellCount;
};

int getSolvedCells() const
{
  return solvedCellCount;
}

int getEmptyCellCount() const
{
  return emptyCellCount;
}

void scanGrid();

QVector<QSharedPointer<Cell> > getEmptyCells() const;

QVector<QSharedPointer<Group> > getRows() const;

QVector<QSharedPointer<Cell> > getCells() const;

private:
QVector<QSharedPointer<Cell> > cells;

QVector<QSharedPointer<Group> > Rows;
QVector<QSharedPointer<Group> > Boxes;
QVector<QSharedPointer<Group> > Columns;

int clueCellCount = 0; // must be at least 17
int solvedCellCount = 0;
int emptyCellCount = 0; //candidates cells also

QVector<QSharedPointer<Cell> > emptyCells;
};

#endif // SUDOKU_H
