#ifndef GRIDCELLWIDGET_H
#define GRIDCELLWIDGET_H

#include <QTextEdit>
#include <QObject>
#include  "cell.h"

class sudokuCellWidget : public QTextEdit
{
Q_OBJECT

public:

sudokuCellWidget(QWidget *parent = nullptr, QSharedPointer<Cell> c = nullptr);

void updateCellWidget();

void setUnSelect();
int getCellNo() const;

void enterClue(int num);
void eraseClue();


void enterNumber(int num);
void clearCell();


int getCellValue() const;

bool getLock() const;
void setLock(bool value);

bool getClueMode() const;

signals:

void cellSelected(int cellNo);


private:

QString currentText;
void prepareCandidateStr();

bool lock = false; // for certain values: solutions
bool clueMode = false; // for initial values

QSharedPointer<Cell> sudokuCell;

QFont candidateFont, solvedFont, clueFont;

protected:
void mousePressEvent(QMouseEvent *event) override;
};

#endif // GRIDCELLWIDGET_H
