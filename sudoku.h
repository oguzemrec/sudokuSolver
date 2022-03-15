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


private:
QVector<QSharedPointer<Cell> > cells;

QVector<QSharedPointer<Group> > Rows;
QVector<QSharedPointer<Group> > Boxes;
QVector<QSharedPointer<Group> > Columns;
};

#endif // SUDOKU_H
