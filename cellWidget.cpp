#include "cellWidget.h"
#include "QDebug"
#include <QMouseEvent>


sudokuCellWidget::sudokuCellWidget(QWidget *parent, QSharedPointer<Cell> c) :
  QTextEdit(parent),
  sudokuCell(c)
{
  this->setFontFamily("Arial");
  solvedFont = this->font();
  solvedFont.setPointSize(22);
  solvedFont.setBold(true);


  clueFont = this->font();
  clueFont.setPointSize(22);
  clueFont.setBold(true);

  candidateFont = this->font();
  candidateFont.setPointSize(9);
  candidateFont.setItalic(true);







  setMinimumSize(50, 50);
  setMaximumSize(50, 50);

  setAlignment(Qt::AlignHCenter);
  setAlignment(Qt::AlignVCenter);

  setReadOnly(true);

  setFrameShape(QFrame::Box);


  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  currentText = "";

  this->setText(currentText);

  updateCellWidget();
}

void sudokuCellWidget::updateCellWidget()
{
  if (sudokuCell->getClueFlag() == true)
    {
      currentText.clear();
      currentText = "  " + QString::number(sudokuCell->getCellValue());

      this->setFont(clueFont);
      this->setTextColor(0x0c7cf3);
    }
  else if (sudokuCell->getSolvedFlag() == true)
    {
      currentText.clear();
      currentText = "  " + QString::number(sudokuCell->getCellValue());

      this->setFont(solvedFont);
      this->setTextColor(0x0ceff3);
    }
  else   //show candidates aka Note mode
    {
      prepareCandidateStr();
      this->setFont(candidateFont);
      this->setTextColor(Qt::lightGray);
    }

  this->setText(currentText);
}

void sudokuCellWidget::setUnSelect()
{
  this->setStyleSheet(" ");
}


int sudokuCellWidget::getCellNo() const
{
  return sudokuCell->getCellNumber();
}

void sudokuCellWidget::enterClue(int num)
{
//  clueMode = true;
//  lock = true;

//  cellValue = num;

//  currentText.clear();
//  currentText = "  " + QString::number(num);

//  this->setTextColor(0x0c7cf3);
//  this->setText(currentText);
}

void sudokuCellWidget::eraseClue()
{
//  clueMode = false;
//  lock = false;
//  cellValue = 0;
//  currentText.clear();
//  this->setText(currentText);
}

void sudokuCellWidget::enterNumber(int num)
{
//  if (num <= 0 || lock != false || clueMode != false)
//    return;

//  cellValue = num;

//  currentText.clear();

//  currentText = "  " + QString::number(num);

//  this->setTextColor(0x0ceff3);

//  this->setText(currentText);

//  lock = true;
}

void sudokuCellWidget::clearCell()
{
//  if (clueMode != false)
//    return;

//  currentText.clear();
//  cellValue = 0;
//  lock = false;
//  this->clear();
}

int sudokuCellWidget::getCellValue() const
{
  return sudokuCell->getCellValue();
}

bool sudokuCellWidget::getLock() const
{
  return lock;
}

void sudokuCellWidget::setLock(bool value)
{
  lock = value;
}

bool sudokuCellWidget::getClueMode() const
{
  return clueMode;
}

void sudokuCellWidget::prepareCandidateStr()
{
  QString temp = "  ";
  int newLineCount = 0;
  auto notes = sudokuCell->getCandidates();

  for (int i = 1; i < 10; i++)              //1to9
    {
      newLineCount++;
      auto it = notes.find(i);
      if (it != notes.end()) //it's exist
        temp.append(QString::number(i) + "  ");
      else
        temp.append("    ");

      if (newLineCount % 3 == 0)
        temp.append("\n  ");
    }

  currentText = temp;
}



void sudokuCellWidget::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
    {
      emit cellSelected(sudokuCell->getCellNumber());
      this->setStyleSheet("background-color: rgb(255, 27, 15);");
    }
}


