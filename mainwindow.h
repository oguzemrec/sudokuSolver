#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "cellWidget.h"
#include <QMap>
#include <QUndoCommand>
#include <QUndoStack>
#include <QUndoGroup>

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



private:
Ui::MainWindow *ui;

int selectedCell = -1;   //1to81

QMap<int, sudokuCellWidget *> gridCells;    //0to80

QUndoStack *undoStack = nullptr;
QUndoGroup *undoGroup;
};
#endif // MAINWINDOW_H
