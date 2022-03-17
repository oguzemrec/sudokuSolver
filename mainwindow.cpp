#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "keyNumber.h"
#include "commands.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow),
  sudoku(new Sudoku)
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

  for (int i = 0; i < 9; ++i)   //entry-numbers buttons
    {
      sudokuKeyNumber *key = new sudokuKeyNumber(this, i + 1);
      ui->layoutKey->addWidget(key);
      connect(key, &sudokuKeyNumber::keyClicked, this, &MainWindow::keyClicked);
    }

  for (int y = 0; y < 9; y++)   //take placing the cells with order
    {
      for (int x = 0; x < 9; x++)
        {
          int cellNumber = ((y * 9)) + (x + 1);

          QSharedPointer<sudokuCellWidget> edit(new sudokuCellWidget(this, sudoku->getCell(cellNumber)));

          gridCells.insert(cellNumber - 1, edit);

          connect(edit.get(), &sudokuCellWidget::cellSelected, [ = ](int cellNo)
      {
        auto cell = sudoku->getCell(cellNo);
        if (cell->getClueFlag() == true || cell->getSolvedFlag() == true)
          this->setHighLight(cell->getCellValue());
        else
          this->resetHighLight();

        if (selectedCell == -1)
          selectedCell = cellNo;
        else
        {
          gridCells[selectedCell - 1]->setUnselect();
          selectedCell = cellNo;
        }
      });

          ui->gridLayoutSudoku->addWidget(edit.get(), y, x);
        }

      ui->gridLayoutSudoku->setSpacing(0);
    }

  for (int i = 0; i < 2; i++)   //grid lines
    {
      QFrame *lineV = new QFrame(this);
      lineV->setFrameShape(QFrame::VLine);
      lineV->setMinimumSize(3, 432);    //because of the margin
      lineV->setMaximumSize(3, 450);
      lineV->setLineWidth(3);
      ui->gridLayoutSudoku->addWidget(lineV, 0, (i + 1) * 3);

      QFrame *lineH = new QFrame(this);
      lineH->setFrameShape(QFrame::HLine);
      lineH->setMinimumSize(432, 2);    //because of the margin
      lineH->setMaximumSize(450, 2);
      lineH->setLineWidth(3);
      ui->gridLayoutSudoku->addWidget(lineH, (i + 1) * 3, 0, Qt::AlignTop);
    }
}

MainWindow::~MainWindow()
{
  //undoStack->clear();
  delete ui;
}

void MainWindow::keyClicked(int number)
{
  if (selectedCell == -1)
    return;

  auto w = gridCells[selectedCell - 1];
  auto cell = sudoku->getCell(selectedCell);

  if (cell->getCellValue() == number || cell->getClueFlag() != false || cell->getSolvedFlag() != false)
    return;     //to prevent the same command and entering certain value

  switch (gridMode)
    {
    case GridEntryMode::CLUE:
    {
      sudokuSolver::CellEntrAttemp res = solver.isValueProper(cell, number);    //search out the other cells are neighbour
      if (res == sudokuSolver::CellEntrAttemp::NOT_FOUND)       //if the number of cell is proper
        {
          undoStack->beginMacro(QObject::tr("Add Clue, Cell:%1's Value:%2").arg(cell->getCellNumber()).arg(number));
          undoStack->push(new AddClueValue(cell, w, number));

          auto effected = solver.effectedCells(cell, number);
          for (int c: effected)
            undoStack->push(new RemoveCandidate(sudoku->getCell(c), gridCells[c - 1], number));

          undoStack->endMacro();
        }
      break;
    }

    case GridEntryMode::NOTE:
      undoStack->push(new ToggleCandidate(cell, w, number));
      break;

    case GridEntryMode::SOLVING:
    {
      sudokuSolver::CellEntrAttemp res = solver.isValueProper(cell, number);    //search out the other cells are neighbour

      if (res == sudokuSolver::CellEntrAttemp::NOT_FOUND)       //if the number of cell is proper
        {
          undoStack->beginMacro(QObject::tr("Change Cell %1's Value:%2").arg(cell->getCellNumber()).arg(number));
          undoStack->push(new ChangeCellValue(cell, w, cell->getCellValue(), number));

          auto effected = solver.effectedCells(cell, number);
          for (int c: effected)
            undoStack->push(new RemoveCandidate(sudoku->getCell(c), gridCells[c - 1], number));

          undoStack->endMacro();
        }

      break;
    }

    default:
      break;
    }
  sudoku->scanGrid();
  ui->labelClueNumber->setText(QString::number(sudoku->getClueCellsCount()));
}

void MainWindow::on_buttonErase_clicked()
{
  if (selectedCell == -1)
    return;

  auto w = gridCells[selectedCell - 1];
  auto cell = sudoku->getCell(selectedCell);

  if (w->getCellValue() == 0)
    return;     //to prevent the same command


  switch (gridMode)
    {
    case GridEntryMode::CLUE: //Only can be erased clue cells
    {
      if (cell->getClueFlag() != true)
        break;

      undoStack->beginMacro(QObject::tr("Erase Clue Cell:%1's Value:%2").arg(cell->getCellNumber()).arg(cell->getCellValue()));
      undoStack->push(new EraseCell(cell, w, cell->getCellValue()));
      undoStack->endMacro();

      break;
    }

    case GridEntryMode::NOTE:
      //doing nothing for now
      break;

    case GridEntryMode::SOLVING:
    {
      if (cell->getSolvedFlag() != true)
        break;

      undoStack->beginMacro(QObject::tr("Erase Solved Cell:%1's Value:%2").arg(cell->getCellNumber()).arg(cell->getCellValue()));
      undoStack->push(new EraseCell(cell, w, cell->getCellValue()));
      undoStack->endMacro();

      break;
    }

    default:
      break;
    }

  sudoku->scanGrid();
  ui->labelClueNumber->setText(QString::number(sudoku->getClueCellsCount()));
}


void MainWindow::on_actionlk_triggered()
{
  QMessageBox::aboutQt(this, "About Qt");
}

void MainWindow::on_radioButtonClueEntering_clicked(bool checked)
{
  sudoku->scanGrid();
  auto clueCount = sudoku->getClueCellsCount();

  ui->labelClueNumber->setText(QString::number(clueCount));

  if (false == checked)         //checking clue number
    {
      if (clueCount < 17)
        ui->radioButtonClueEntering->setChecked(true);
    }
  if (true == checked)          //checking clue number
    {
      gridMode = GridEntryMode::CLUE;
    }
}

void MainWindow::on_radioButtonNoteMode_clicked(bool checked)
{
  sudoku->scanGrid();
  auto clueCount = sudoku->getClueCellsCount();

  ui->labelClueNumber->setText(QString::number(clueCount));

  if (true == checked)          //checking clue number
    {
      if (clueCount < 17)
        ui->radioButtonClueEntering->setChecked(true);
      else
        gridMode = GridEntryMode::NOTE;
    }
}

void MainWindow::on_radioButtonSolvingMode_clicked(bool checked)
{
  sudoku->scanGrid();
  auto clueCount = sudoku->getClueCellsCount();

  ui->labelClueNumber->setText(QString::number(clueCount));

  if (true == checked)          //checking clue number
    {
      if (clueCount < 17)
        ui->radioButtonClueEntering->setChecked(true);
      else
        gridMode = GridEntryMode::SOLVING;
    }
}

void MainWindow::on_pushButtonClearUndoView_clicked()
{
  undoStack->clear();
}

void MainWindow::setHighLight(int cellValue)
{
  for (auto hc: highLightedWCells)
    {
      hc->clearHighLighted();
      hc->updateCellWidget();
    }

  auto cCells = sudoku->getEmptyCells();   //only contains candidate cells

  for (auto c: cCells)
    {
      auto candidates = c->getCandidates();
      if (candidates.find(cellValue) != candidates.end())
        {
          auto w = gridCells[c->getCellNumber() - 1];
          w->insertHighLighted(cellValue, Qt::yellow);
          w->updateCellWidget();
          highLightedWCells.push_back(w);
        }
    }
}

void MainWindow::resetHighLight()
{
  for (auto hc: highLightedWCells)
    {
      hc->clearHighLighted();
      hc->updateCellWidget();
    }
}
