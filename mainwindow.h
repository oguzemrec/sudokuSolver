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
#include <QStackedWidget>

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
void solutionEvent(bool solutionRes, int iterationCount);


void on_actionlk_triggered();

void on_buttonErase_clicked();


void on_radioButtonClueEntering_clicked(bool checked);

void on_radioButtonNoteMode_clicked(bool checked);

void on_radioButtonSolvingMode_clicked(bool checked);

void on_pushButtonClearUndoView_clicked();

void on_buttonSolution_clicked();

void on_buttonReset_clicked();

void on_buttonXYWing_clicked();


void on_pageComboBox_activated(int index);

private:
Ui::MainWindow *ui;

int selectedCell = -1;   //1to81
QMap<int, QSharedPointer<sudokuCellWidget> > gridCells;    //1to81

QUndoStack *undoStack = nullptr;
QUndoGroup *undoGroup;

QSharedPointer<Sudoku> sudoku;

sudokuSolver *solver;
enum  class GridEntryMode {
  CLUE =0,
  NOTE = 1,
  SOLVING = 2,
};

GridEntryMode gridMode = GridEntryMode::CLUE;

void setHighLight(int cellValue);
void resetHighLight();
QVector<QSharedPointer<sudokuCellWidget> > highLightedWCells;

void updateMethodWidget(QString method);
QStackedWidget *    stackedWidget;
QVector<QWidget *> stackedWidgets;
};
#endif // MAINWINDOW_H
