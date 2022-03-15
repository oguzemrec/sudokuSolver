#include "group.h"


Group::Group(int no, QVector<QSharedPointer<Cell> > t):
    number(no),
    cells(t)
{}

void Group::show(){cout << "Group:" <<number<<" - " << "Value:";
                   for(auto c:cells)
                       cout <<c->getCellNumber()<<",";
                                  cout<< endl;}

QVector<QSharedPointer<Cell> > Group::getCells() const
{
    return cells;
}
