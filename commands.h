#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "cellWidget.h"
#include "cell.h"

using cell_ptr = QSharedPointer<Cell>;
using  widget_ptr = QSharedPointer<sudokuCellWidget>;



class ChangeCellValue : public QUndoCommand
{
public:
ChangeCellValue(cell_ptr c, widget_ptr w, int oldNumber, int newNumber,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cell_ptr c;
widget_ptr w;

int oldValue = 0;
int newValue = 0;
};

class AddClueValue : public QUndoCommand
{
public:
AddClueValue(cell_ptr c, widget_ptr w, int candidate,
             QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cell_ptr c;
widget_ptr w;

int clueValue;
};

class RemoveCandidate : public QUndoCommand
{
public:
RemoveCandidate(cell_ptr c, widget_ptr w, int candidate,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cell_ptr c;
widget_ptr w;

int candidate;
};

class ToggleCandidate : public QUndoCommand
{
public:
ToggleCandidate(cell_ptr c, widget_ptr w, int candidate,
                QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cell_ptr c;
widget_ptr w;

int candidate;
};

class EraseCell : public QUndoCommand
{
public:
EraseCell(cell_ptr c, widget_ptr w, int oldValue, QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

cell_ptr c;
widget_ptr w;

int oldValue = 0;
};

#endif // COMMANDS_H
