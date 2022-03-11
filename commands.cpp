#include "commands.h"
#include "qdebug.h"


CellValueChanged::CellValueChanged(sudokuCellWidget * w_, int oldNumber_, int newNumber_, QUndoCommand *parent) :
  QUndoCommand(parent),
  w(w_),
  oldNumber(oldNumber_),
  newNumber(newNumber_)
{
}

void CellValueChanged::redo()
{
  qDebug() << "redo";

  if (newNumber != 0)
    w->enterNumber(newNumber);
  else
    w->clearCell();

  setText(QObject::tr("Change Cell %1's Value:%2").arg(w->getCellNo()).arg(w->getCellValue()));
}

void CellValueChanged::undo()
{
  qDebug() << "undo";

  if (oldNumber != 0)
    w->enterNumber(oldNumber);
  else
    w->clearCell();
}


EraseCell::EraseCell(sudokuCellWidget * w_, int oldNumber_, QUndoCommand *parent) :
  QUndoCommand(parent),
  w(w_),
  oldNumber(oldNumber_)
{
}

void EraseCell::redo()
{
  w->clearCell();

  setText(QObject::tr("Erase Cell:%1").arg(w->getCellNo()));
}

void EraseCell::undo()
{
  if (oldNumber != 0)
    w->enterNumber(oldNumber);
}
