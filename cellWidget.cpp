#include "cellWidget.h"
#include "QDebug"
#include <QMouseEvent>


sudokuCellWidget::sudokuCellWidget(QWidget *parent, int cellNo) :
  QTextEdit(parent),
  cellNo(cellNo)
{
  this->setFontFamily("Arial");
  auto numberFont = this->font();

  numberFont.setPointSize(23);



  setFont(numberFont);

  setFixedSize(50, 50);

  setAlignment(Qt::AlignHCenter);
  setAlignment(Qt::AlignVCenter);

  setReadOnly(true);

  setFrameShape(QFrame::Box);


  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  currentText = " ";

  this->setText(currentText);
}

void sudokuCellWidget::setUnSelect()
{
  this->setStyleSheet(" ");
}


int sudokuCellWidget::getCellNo() const
{
  return cellNo;
}

void sudokuCellWidget::enterNumber(int num)
{
  if (num <= 0)
    return;

  cellValue = num;

  currentText.clear();

  currentText = "  " + QString::number(num);

//     this->setTextColor(Qt::white);


  this->setText(currentText);
}

void sudokuCellWidget::clearCell()
{
  currentText.clear();
  cellValue = 0;
  this->clear();
}

int sudokuCellWidget::getCellValue() const
{
  return cellValue;
}



void sudokuCellWidget::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
    {
      emit cellSelected(cellNo);
      this->setStyleSheet("background-color: rgb(255, 27, 15);");
    }
}


