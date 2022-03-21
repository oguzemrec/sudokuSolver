#ifndef MINIGRID_H
#define MINIGRID_H

#include <QWidget>
#include "cellWidget.h"
#include "sudoku.h"
class miniGrid : public QWidget
{
Q_OBJECT
public:
explicit miniGrid(QWidget *parent = nullptr);

public:
void insertSudokuGrid(const Sudoku& sudoku);
void insertCell(const QSharedPointer<Cell>& cell);
void insertCell(const int& cellNo, const int&value);
signals:
private:
QMap<int, QSharedPointer<sudokuCellWidget> > gridCells;    //1to81
};

#endif // MINIGRID_H
