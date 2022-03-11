#ifndef COMMANDS_H
#define COMMANDS_H

#include <QUndoCommand>
#include "cellWidget.h"

class CellValueChanged : public QUndoCommand
{
public:
CellValueChanged(sudokuCellWidget * w, int oldNumber, int newNumber,
                 QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

sudokuCellWidget *w;

int oldNumber = 0;
int newNumber = 0;
};

class EraseCell : public QUndoCommand
{
public:
EraseCell(sudokuCellWidget * w, int oldNumber, QUndoCommand *parent = nullptr);

private:

void redo() override;
void undo() override;

sudokuCellWidget *w;

int oldNumber = 0;
};

#endif // COMMANDS_H
