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

    Group(){}


    Group(int no,QVector<QSharedPointer<Cell>> t);
   void show();

   QVector<QSharedPointer<Cell> > getCells() const;

private:
   int number=0;
   QVector<QSharedPointer<Cell>> cells;
};

#endif // GROUP_H
