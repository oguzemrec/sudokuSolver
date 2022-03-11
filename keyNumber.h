#ifndef SUDOKUNUMBERKEY_H
#define SUDOKUNUMBERKEY_H

#include <QPushButton>
#include <QWidget>

class sudokuKeyNumber : public QPushButton
{
    Q_OBJECT
public:
    sudokuKeyNumber(QWidget *parent, int num);

signals:
   void keyClicked(int num);
private:
    int keyNumber=0;

};

#endif // SUDOKUNUMBERKEY_H
