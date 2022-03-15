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
