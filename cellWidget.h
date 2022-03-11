#ifndef GRIDCELLWIDGET_H
#define GRIDCELLWIDGET_H

#include <QTextEdit>
#include <QObject>


class sudokuCellWidget : public QTextEdit
{
Q_OBJECT

public:

sudokuCellWidget(QWidget *parent = nullptr, int cellNo = -1);


void setUnSelect();
int getCellNo() const;

void enterNumber(int num);
void clearCell();

int getCellValue() const;

signals:

void cellSelected(int cellNo);


private:

int cellNo;

int cellValue = 0;

QString currentText;

protected:
void mousePressEvent(QMouseEvent *event) override;
};

#endif // GRIDCELLWIDGET_H
