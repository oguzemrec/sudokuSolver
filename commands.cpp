#include "commands.h"
#include "qdebug.h"


ChangeCellValue::ChangeCellValue(cell_ptr c_, widget_ptr w_, int oldValue_, int newValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  oldValue(oldValue_),
  newValue(newValue_)
{
}

void ChangeCellValue::redo()
{
  if (newValue != 0)
    c->setCellValue(newValue);
  else
    c->setDefault();

  w->updateCellWidget();
}

void ChangeCellValue::undo()
{
  if (oldValue != 0)
    c->setCellValue(newValue);
  else
    c->setDefault();

  w->updateCellWidget();
}

AddClueValue::AddClueValue(cell_ptr c_, widget_ptr w_, int clueValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  clueValue(clueValue_)
{
}

void AddClueValue::redo()
{
  c->setCellClue(clueValue);
  w->updateCellWidget();
}

void AddClueValue::undo()
{
  c->removeCellClue();
  w->updateCellWidget();
}

RemoveCandidate::RemoveCandidate(cell_ptr c_, widget_ptr w_, int candidate_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  candidate(candidate_)
{
}

void RemoveCandidate::redo()
{
  c->removeCandidate(candidate);
  w->updateCellWidget();
}

void RemoveCandidate::undo()
{
  c->addCandidate(candidate);
  w->updateCellWidget();
}


ToggleCandidate::ToggleCandidate(cell_ptr c_, widget_ptr w_, int candidate_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  candidate(candidate_)

{
}

void ToggleCandidate::redo()
{
  auto res = c->toggleCandidate(candidate);

  if (res == Cell::ToggleCandidateSts::ADDED)
    setText(QObject::tr("Added Note, Cell :%1, Value:%2").arg(w->getCellNo()).arg(candidate));
  if (res == Cell::ToggleCandidateSts::REMOVED)
    setText(QObject::tr("Removed Note, Cell :%1, Value:%2").arg(w->getCellNo()).arg(candidate));

  w->updateCellWidget();
}

void ToggleCandidate::undo()
{
  c->toggleCandidate(candidate);
  w->updateCellWidget();
}


EraseCell::EraseCell(cell_ptr c_, widget_ptr w_, int oldValue_, QUndoCommand *parent) :
  QUndoCommand(parent),
  c(c_),
  w(w_),
  oldValue(oldValue_)
{
}

void EraseCell::redo()
{
  c->setDefault();
  c->addCandidate(oldValue);
  w->updateCellWidget();
}

void EraseCell::undo()
{
  if (oldValue == 0)
    return;

  c->setCellClue(oldValue);
  w->updateCellWidget();
}
