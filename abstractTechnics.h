#ifndef ABSTRACTTECHNICS_H
#define ABSTRACTTECHNICS_H

#include <QObject>
#include <QMap>
#include <QColor>

class AbstractTechnics : public QObject
{
Q_OBJECT
public:
explicit AbstractTechnics(QObject *parent = nullptr);

virtual QString getInfo() = 0;

QMap<int, QMap<int, QColor> > getEffectedCells() const;

void insertEffectedCell(const int& cellNo, const QMap<int, QColor>& effected);

void insertEffectedCandidate(const int& cellNo, const QMap<int, QColor>& effected);
};

#endif // ABSTRACTTECHNICS_H
