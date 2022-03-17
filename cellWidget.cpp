#include "cellWidget.h"
#include "QDebug"
#include <QMouseEvent>


sudokuCellWidget::sudokuCellWidget(QWidget *parent, QSharedPointer<Cell> c) :
  QTextEdit(parent),
  sudokuCell(c)
{
  candidateColor = Qt::lightGray;

  this->setFontFamily("Arial");
  solvedFont = this->font();
  solvedFont.setPointSize(22);
  solvedFont.setBold(true);


  clueFont = this->font();
  clueFont.setPointSize(22);
  clueFont.setBold(true);

  candidateFont = this->font();
  candidateFont.setPointSize(10);
  candidateFont.setItalic(true);

  setMinimumSize(50, 50);
  setMaximumSize(50, 50);

  setAlignment(Qt::AlignHCenter);
  setAlignment(Qt::AlignVCenter);

  setReadOnly(true);

  setFrameShape(QFrame::Box);

  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//  currentText = "";

//  this->setText(currentText);

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
      this->setText(currentText);
    }
  else if (sudokuCell->getSolvedFlag() == true)
    {
      currentText.clear();
      currentText = "  " + QString::number(sudokuCell->getCellValue());

      this->setFont(solvedFont);
      this->setTextColor(0x0ceff3);
      this->setText(currentText);
    }
  else   //show candidates aka Note mode
    {
      prepareCandidateStr();
//      this->setFont(candidateFont);
//      this->setTextColor(Qt::lightGray);
    }
}

void sudokuCellWidget::setUnselect()
{
  this->setStyleSheet(" ");
}


int sudokuCellWidget::getCellNo() const
{
  return sudokuCell->getCellNumber();
}



int sudokuCellWidget::getCellValue() const
{
  return sudokuCell->getCellValue();
}

void sudokuCellWidget::insertHighLighted(int candidate, QColor col)
{
  if (highLightedCandidates.find(candidate) == highLightedCandidates.end())
    highLightedCandidates.remove(candidate);     //may be color changes

  highLightedCandidates.insert(candidate, col);
}

void sudokuCellWidget::removeHighLighted(int candidate)
{
  if (highLightedCandidates.find(candidate) != highLightedCandidates.end())
    highLightedCandidates.remove(candidate);
}

void sudokuCellWidget::clearHighLighted()
{
  highLightedCandidates.clear();
}

void sudokuCellWidget::prepareCandidateStr()
{
  this->clear();
  this->setFont(candidateFont);
  this->setTextColor(candidateColor);
  this->insertPlainText("  ");

  int newLineCount = 0;
  auto notes = sudokuCell->getCandidates();

  for (int i = 1; i < 10; i++)              //1to9
    {
      newLineCount++;
      auto it = notes.find(i);
      if (it != notes.end()) //it's exist
        {
          if (highLightedCandidates.find(*it) != highLightedCandidates.end()) //highLight candidate
            {
              this->setTextColor(highLightedCandidates[*it]);
              this->insertPlainText(QString::number(i) + "  ");
            }
          else
            {
              this->setTextColor(candidateColor);
              this->insertPlainText(QString::number(i) + "  ");
            }
        }
      else
        this->insertPlainText("    ");


      if (newLineCount % 3 == 0)
        this->insertPlainText("\n  ");
    }
}



void sudokuCellWidget::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
    {
      emit cellSelected(sudokuCell->getCellNumber());
      this->setStyleSheet("background-color: rgb(150, 27, 15);");
    }
}


