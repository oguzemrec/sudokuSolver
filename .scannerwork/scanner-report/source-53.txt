#include "sudokuSolver.h"
#include "qdebug.h"

sudokuSolver::sudokuSolver(QObject *parent) : QObject(parent)
{
}

sudokuSolver::CellEntrAttemp sudokuSolver::isValueProper(QSharedPointer<Cell> cell, int number)
{
  auto row = cell->getOwnRow()->getCells();
  auto column = cell->getOwnColumn()->getCells();
  auto box = cell->getOwnBox()->getCells();

  for (auto r : row)
    {
      if (r.get() == cell)
        continue;
      if (r->getCellValue() == number)
        return CellEntrAttemp::EXIST_INROW;
    }


  for (auto c : column)
    {
      if (c.get() == cell)
        continue;

      if (c->getCellValue() == number)
        return CellEntrAttemp::EXIST_INCOLUMN;
    }

  for (auto b : box)
    {
      if (b.get() == cell)
        continue;

      if (b->getCellValue() == number)
        return CellEntrAttemp::EXIST_INBOX;
    }

  return CellEntrAttemp::NOT_FOUND;
}

QSet<int> sudokuSolver::effectedCells(QSharedPointer<Cell> cell, int candidate)
{
  QSet<int> vCandidates;
  auto row = cell->getOwnRow()->getCells();
  auto column = cell->getOwnColumn()->getCells();
  auto box = cell->getOwnBox()->getCells();

  for (auto r : row)
    {
      auto candidates = r->getCandidates();
      if (candidates.find(candidate) != candidates.end())
        vCandidates.insert(r->getCellNumber());
    }

  for (auto c : column)
    {
      auto candidates = c->getCandidates();
      if (candidates.find(candidate) != candidates.end())
        vCandidates.insert(c->getCellNumber());
    }

  for (auto b : box)
    {
      auto candidates = b->getCandidates();
      if (candidates.find(candidate) != candidates.end())
        vCandidates.insert(b->getCellNumber());
    }
  return vCandidates;
}



void sudokuSolver::solveSudoku_(const QVector<QSharedPointer<Cell> > &gridCells)
{
  static int iterationCount = 0;
  int N = 9;
  QSharedPointer<Cell> grid[9][9];

  auto solutionCells = solutionGrid.getCells();

  for (auto c: gridCells)
    solutionCells[c->getCellNumber() - 1]->setCellValue(c->getCellValue());

  for (auto c: solutionCells)
    grid[c->getRowNumber() - 1][c->getColumnNumber() - 1] = c;

  iterationCount = 0;
  auto solveSudoku = [ = ]( int row, int col, auto&& solveSudoku)->bool
                     {
                       if (iterationCount >= 100000)
                         return false;
                       iterationCount++;

                       if (row == 9 - 1 && col == 9)
                         return true;

                       if (col == N)
                         {
                           row++;
                           col = 0;
                         }

                       if (grid[row][col]->getCellValue() > 0)
                         return solveSudoku(row, col + 1, solveSudoku);

                       for (int num = 1; num <= N; num++)
                         {
                           if (isValueProper(grid[row][col], num) == CellEntrAttemp::NOT_FOUND)
                             {
                               grid[row][col]->setCellValue(num);

                               if (solveSudoku(row, col + 1, solveSudoku))
                                 return true;
                             }

                           grid[row][col]->setCellValue(0);
                         }

                       return false;
                     };


  auto ret = solveSudoku(0, 0, solveSudoku);

  emit solutionEvent(ret, iterationCount);
}

Sudoku sudokuSolver::getSolutionGrid() const
{
  return solutionGrid;
}
