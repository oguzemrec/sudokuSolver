#include "commands.h"
#include "qdebug.h"


ChangeCellValue::ChangeCellValue(cellWeakPtr c_, widgetWeakPtr w_, int oldValue_, int newValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  oldValue(oldValue_),
  newValue(newValue_)
{
}

void ChangeCellValue::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  if (newValue != 0)
    cellSharedPtr->setCellValue(newValue);
  else
    cellSharedPtr->setDefault();

  widgetSharedPtr->updateCellWidget();
}

void ChangeCellValue::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  if (oldValue != 0)
    cellSharedPtr->setCellValue(newValue);
  else
    cellSharedPtr->setDefault();

  widgetSharedPtr->updateCellWidget();
}

AddClueValue::AddClueValue(cellWeakPtr c_, widgetWeakPtr w_, int clueValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  clueValue(clueValue_)
{
}

void AddClueValue::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->setCellClue(clueValue);

  widgetSharedPtr->updateCellWidget();
}

void AddClueValue::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->removeCellClue();
  widgetSharedPtr->updateCellWidget();
}

RemoveCandidate::RemoveCandidate(cellWeakPtr c_, widgetWeakPtr w_, int candidate_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  candidate(candidate_)
{
}

void RemoveCandidate::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->removeCandidate(candidate);
  widgetSharedPtr->updateCellWidget();
}

void RemoveCandidate::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->addCandidate(candidate);
  widgetSharedPtr->updateCellWidget();
}

InsertCandidate::InsertCandidate(cellWeakPtr c_, widgetWeakPtr w_, QSet<int> oldCandidates_, QSet<int> newCandidates, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  candidates(newCandidates),
  oldCandidates(oldCandidates_)
{
}

void InsertCandidate::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  setText(QObject::tr("Filled Candidates, Cell :%1").arg(widgetSharedPtr->getCellNo()));

  cellSharedPtr->updateCandidates(candidates);
  widgetSharedPtr->updateCellWidget();
}

void InsertCandidate::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->updateCandidates(oldCandidates);
  widgetSharedPtr->updateCellWidget();
}
ToggleCandidate::ToggleCandidate(cellWeakPtr c_, widgetWeakPtr w_, int candidate_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  candidate(candidate_)
{
}

void ToggleCandidate::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  auto res = cellSharedPtr->toggleCandidate(candidate);

  if (res == Cell::ToggleCandidateSts::ADDED)
    setText(QObject::tr("Added Note, Cell :%1, Value:%2").arg(widgetSharedPtr->getCellNo()).arg(candidate));
  if (res == Cell::ToggleCandidateSts::REMOVED)
    setText(QObject::tr("Removed Note, Cell :%1, Value:%2").arg(widgetSharedPtr->getCellNo()).arg(candidate));

  widgetSharedPtr->updateCellWidget();
}

void ToggleCandidate::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->toggleCandidate(candidate);
  widgetSharedPtr->updateCellWidget();
}


EraseCell::EraseCell(cellWeakPtr c_, widgetWeakPtr w_, int oldValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  oldValue(oldValue_)
{
}

void EraseCell::redo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  cellSharedPtr->setDefault();
  widgetSharedPtr->updateCellWidget();
}

void EraseCell::undo()
{
  if (!c)
    return;
  if (!w)
    return;

  auto cellSharedPtr = c.toStrongRef();
  auto widgetSharedPtr = w.toStrongRef();

  if (oldValue == 0)
    return;

  cellSharedPtr->setCellClue(oldValue);
  widgetSharedPtr->updateCellWidget();
}
