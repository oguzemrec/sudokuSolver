#include "abstractTechnics.h"

AbstractTechnics::AbstractTechnics(QObject *parent) : QObject(parent)
{
}

//QMap<int, QMap<int, QColor> > AbstractTechnics::getEffectedCells() const
//{
//  return effectedCells;
//}

//void AbstractTechnics::insertEffectedCell(const int &cellNo, const QMap<int, QColor> &effected)
//{
//  effectedCells.insert(cellNo, effected);
//}

//void AbstractTechnics::insertEffectedCandidate(const int &cellNo, const QMap<int, QColor> &effected)
//{
//  if (auto it = effectedCells.find(cellNo);  it != effectedCells.end())
//    {
//      it->insert(effected);
//    }
//  else
//    {
//      effectedCells.insert(cellNo, effected);
//    }
//}
