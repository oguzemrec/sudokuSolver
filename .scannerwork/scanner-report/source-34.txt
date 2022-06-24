#ifndef GRIDCELLWIDGET_H
#define GRIDCELLWIDGET_H

#include <QTextEdit>
#include <QObject>
#include  "cell.h"

class sudokuCellWidget : public QTextEdit
{
Q_OBJECT

public:

sudokuCellWidget(QWidget *parent = nullptr, QSharedPointer<Cell> c = nullptr, QSize size = QSize(50, 50));

void updateCellWidget();

void setUnselect();

int getCellNo() const;
int getCellValue() const;
bool getClueMode() const;


void insertHighLighted(int candidate, QColor col);
void removeHighLighted(int candidate);
void clearHighLighted();

void setCell(const QSharedPointer<Cell>&  c);
void setClickable(bool value);

signals:

void cellSelected(int cellNo);

private:

bool clickable = true;


QString currentText;
void prepareCandidateStr();

QSharedPointer<Cell> sudokuCell;

QFont candidateFont, solvedFont, clueFont;

QMap<int, QColor> highLightedCandidates;
QColor candidateColor;

protected:
void mousePressEvent(QMouseEvent *event) override;
};

#endif // GRIDCELLWIDGET_H
