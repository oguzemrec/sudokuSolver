#ifndef MINIGRID_H
#define MINIGRID_H

#include <QWidget>
#include <QVBoxLayout>

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
void insertHighLighted(const int &cellNo, QMap<int, QColor> candidates);

QString getInfo();
void setInfo(const QString &value);

signals:
private:
QString info;
QMap<int, QSharedPointer<sudokuCellWidget> > gridCells;    //1to81
QVBoxLayout * layoutWidget;
};

#endif // MINIGRID_H
