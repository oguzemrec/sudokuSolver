#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <QVector>
#include <QSharedPointer>
#include "cell.h"

QT_FORWARD_DECLARE_CLASS(Cell)

using namespace std;

#define GROUP_NUMBER 9
class Group
{
public:

Group()
{
}

QSharedPointer<Cell> operator[](int index)
{
  return cells[index];
}
//void operator=(int index,int val)
//{
//    cells[index]->setCellValue(val);
//}


Group(int no, QVector<QSharedPointer<Cell> > t);
void show();

QVector<QSharedPointer<Cell> > getCells() const;
QSet<int> getCellNumbers() const;

private:
int number = 0;
QVector<QSharedPointer<Cell> > cells;
};

#endif // GROUP_H
