#ifndef WING_H
#define WING_H

#include "abstractTechnics.h"
#include "sudoku.h"


class YWing /*: public AbstractTechnics*/
{
public:
YWing();

QString getInfo()
{
  return QObject::tr("Y-Wing Solution Method: Z=%1").arg(Z);
}


QVector<YWing> findTechnics(const QSharedPointer<Sudoku> &sudoku);

int X = 0;
int Y = 0;
int Z = 0;
int cellNumbers[3];
QSet<int> intersectedCells;
};

#endif // WING_H
