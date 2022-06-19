#ifndef WING_H
#define WING_H

#include "abstractTechnics.h"
#include "sudoku.h"

class XWing
{
public:

XWing()
{
};

QString getInfo();


QVector<XWing> findTechnics(const QSharedPointer<Sudoku> &sudoku, bool skyScraperMode = false);

int Z = 0;
int cellNumbers[4];
int groupNumbers[2];     //row or coloumn

private:
bool skyScraper = false;
QString strType = "row";   //or coloumn

enum XWingType {
  COLUMN=0,
  ROW=1
};

struct sTwoCandidate {
public:
  sTwoCandidate(const QSet<QSharedPointer<Cell> >& cells_, const int &candidate_)
  {
    cells = cells_;
    candidate = candidate_;
  }
  QSet<QSharedPointer<Cell> > cells;
  int candidate;
};
};


class XYZWing /*: public AbstractTechnics*/
{
public:

XYZWing()
{
};

QString getInfo()
{
  return QObject::tr("XYZ-Wing Solution Method: Z=%1").arg(Z);
}


QVector<XYZWing> findTechnics(const QSharedPointer<Sudoku> &sudoku);

int X = 0;
int Y = 0;
int Z = 0;
int cellNumbers[3];
QSet<int> intersectedCells;
};

class YWing /*: public AbstractTechnics*/
{
public:

YWing()
{
};

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
