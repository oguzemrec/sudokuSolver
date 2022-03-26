#ifndef WING_H
#define WING_H

#include "abstractTechnics.h"
#include "sudoku.h"


class XYWing /*: public AbstractTechnics*/
{
public:
XYWing();

QString getInfo()
{
  return QObject::tr("XY-Wing Solution Method: X=%1,Y=%2, Z=%3").arg(X).arg(Y).arg(Z);
}


QVector<XYWing> findTechnics(const QSharedPointer<Sudoku> &sudoku);

int X = 0, Y = 0, Z = 0;
int cellNumbers[3];

//signals:
//void technicResolved(QVector<QVector<int>>);
};

#endif // WING_H
