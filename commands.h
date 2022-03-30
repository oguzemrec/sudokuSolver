#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "cellWidget.h"
#include "cell.h"

using cellWeakPtr = QWeakPointer<Cell>;
using  widgetWeakPtr = QWeakPointer<sudokuCellWidget>;

class ChangeCellValue : public QUndoCommand
{
public:
ChangeCellValue(cellWeakPtr c, widgetWeakPtr w, int oldNumber, int newNumber,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

int oldValue = 0;
int newValue = 0;
};

class AddClueValue : public QUndoCommand
{
public:
AddClueValue(cellWeakPtr c, widgetWeakPtr w, int candidate,
             QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

int clueValue;
};

class RemoveCandidate : public QUndoCommand
{
public:
RemoveCandidate(cellWeakPtr c, widgetWeakPtr w, int candidate,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

int candidate;
};
class InsertCandidate : public QUndoCommand
{
public:
InsertCandidate(cellWeakPtr c, widgetWeakPtr w, QSet<int> oldCandidates, QSet<int> newCandidates,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

QSet<int> candidates;
QSet<int> oldCandidates;
};

class ToggleCandidate : public QUndoCommand
{
public:
ToggleCandidate(cellWeakPtr c, widgetWeakPtr w, int candidate,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

int candidate;
};

class EraseCell : public QUndoCommand
{
public:
EraseCell(cellWeakPtr c, widgetWeakPtr w, int oldValue, QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cellWeakPtr c;
widgetWeakPtr w;

int oldValue = 0;
};

#endif // COMMANDS_H
