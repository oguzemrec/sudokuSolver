#include "keyNumber.h"

sudokuKeyNumber::sudokuKeyNumber(QWidget *parent, int num) :
  QPushButton(parent),
  keyNumber(num)
{
  setText(QString::number(num));
  setMaximumSize(50, 50);

  connect(this, &QPushButton::clicked, [ = ](){
    emit keyClicked(keyNumber);
  });
}
