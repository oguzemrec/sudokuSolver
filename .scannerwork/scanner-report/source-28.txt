#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QObject>
#include "sudoku.h"

class sudokuSolver : public QObject
{
Q_OBJECT
public:

enum  class CellEntrAttemp {
  NOT_FOUND =0,
  EXIST_INROW = 1,
  EXIST_INCOLUMN = 2,
  EXIST_INBOX= 3,
};


Q_ENUM(CellEntrAttemp);

explicit sudokuSolver(QObject *parent = nullptr);

CellEntrAttemp isValueProper(QSharedPointer<Cell> cell, int number);

QSet<int> effectedCells(QSharedPointer<Cell> cell, int candidate);

//will return
void solveSudoku_(const QVector<QSharedPointer<Cell> >  &gridCells);

Sudoku getSolutionGrid() const;

signals:
void solutionEvent(bool solutionRes, int iterationCount);
private:
Sudoku solutionGrid;
};

#endif // SUDOKUSOLVER_H
