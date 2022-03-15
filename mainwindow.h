#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cellWidget.h"
#include <QMap>
#include <QUndoCommand>
#include <QUndoStack>
#include <QUndoGroup>
#include "sudoku.h"
#include "sudokuSolver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
MainWindow(QWidget *parent = nullptr);
~MainWindow();

private slots:
void keyClicked(int number);
void on_actionlk_triggered();

void on_buttonErase_clicked();


void on_radioButtonClueEntering_clicked(bool checked);

void on_radioButtonNoteMode_clicked(bool checked);

void on_radioButtonSolvingMode_clicked(bool checked);

private:
Ui::MainWindow *ui;

int selectedCell = -1;   //1to81
int clueNumbers = 0;   //must be at least 17
QMap<int, QSharedPointer<sudokuCellWidget> > gridCells;    //0to80

QUndoStack *undoStack = nullptr;
QUndoGroup *undoGroup;

Sudoku *sudoku;
sudokuSolver solver;

enum  class GridEntryMode {
  CLUE =0,
  NOTE = 1,
  SOLVING = 2,
};

GridEntryMode gridMode = GridEntryMode::CLUE;
};
#endif // MAINWINDOW_H
