#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "keyNumber.h"
#include "commands.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);

  undoStack = new QUndoStack(this);
  undoGroup = new QUndoGroup(this);
  undoGroup->setActiveStack(undoStack);


  QAction *undoAction = undoGroup->createUndoAction(this);
  QAction *redoAction = undoGroup->createRedoAction(this);


  connect(ui->buttonUndo, &QPushButton::clicked, undoAction, &QAction::trigger);
  connect(ui->buttonRedo, &QPushButton::clicked, redoAction, &QAction::trigger);

  ui->undoView->setGroup(undoGroup);
  ui->undoView->setWindowTitle(tr("Command List"));


  for (int i = 0; i < 9; ++i)
    {
      sudokuKeyNumber *key = new sudokuKeyNumber(this, i + 1);
      ui->layoutKey->addWidget(key);
      connect(key, &sudokuKeyNumber::keyClicked, this, &MainWindow::keyClicked);
    }


//  ui->gridLayoutSudoku->SetMinimumSize(450,450);

  for (int y = 0; y < 9; y++)
    {
      for (int x = 0; x < 9; x++)
        {
          int cellNumber = ((y * 9)) + (x + 1);

          sudokuCellWidget *edit = new sudokuCellWidget(this, cellNumber);

          gridCells.insert(cellNumber - 1, edit);

          connect(edit, &sudokuCellWidget::cellSelected, [ = ](int cellNo) {
        if (selectedCell == -1)
          selectedCell = cellNo;
        else
        {
          gridCells[selectedCell - 1]->setUnSelect();
          selectedCell = cellNo;
        }
      });

          ui->gridLayoutSudoku->addWidget(edit, y, x);
        }

      ui->gridLayoutSudoku->setSpacing(0);
    }
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::keyClicked(int number)
{
  if (selectedCell == -1)
    return;

  auto w = gridCells[selectedCell - 1];


  if (w->getCellValue() == number)
    return;                            //preventing the same command

  undoStack->push(new CellValueChanged(w, w->getCellValue(), number));

  // gridCells[selectedCell - 1]->enterNumber(number);
}


void MainWindow::on_actionlk_triggered()
{
  QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_buttonErase_clicked()
{
  if (selectedCell == -1)
    return;


  auto w = gridCells[selectedCell - 1];

  if (w->getCellValue() == 0)
    return;                        //preventing the same command


  undoStack->push(new EraseCell(w, w->getCellValue()));
}

//void MainWindow::on_pushButton_clicked()
//{
//  auto w = gridCells[0];
//  auto w2 = gridCells[1];

//  undoStack->beginMacro(tr("Test Macro"));

//  undoStack->push(new CellValueChanged(w, w->getCellValue(), 1));
//  undoStack->push(new CellValueChanged(w2, w2->getCellValue(), 2));

//  undoStack->endMacro();
//}
