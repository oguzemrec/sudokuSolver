#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <QSet>
#include "group.h"

#define CELL_NUMBER 81

QT_FORWARD_DECLARE_CLASS(Group)


using namespace std;

using group_ptr = QSharedPointer<Group>;
class Cell {
public:


Cell(int no = -1) : cellNumber(no)
{
}

void operator=(int value)
{
  this->setCellValue(value);
}
void show()
{
  cout << "Cell:" << cellNumber << " - " << "Value:" << cellValue << endl;
}

void showBoxCells();
void showColumnCells();
void showRowCells();

int getCellNumber() const;
void setCellNumber(int value);

int getRowNumber() const;
void setRowNumber(int value);

int getColumnNumber() const;
void setColumnNumber(int value);

int getBoxNumber() const;
void setBoxNumber(int value);

int getCellValue() const;
void setCellValue(int value);

void setCellClue(int value);
void removeCellClue();

void setOwnRow(group_ptr value);

void setOwnColumn(group_ptr value);

void setOwnBox(group_ptr value);

enum  class ToggleCandidateSts {
  ADDED=0,
  REMOVED = 1,
};

void addCandidate(int num);
void removeCandidate(int num);
ToggleCandidateSts toggleCandidate(int num);
QSet<int> getCandidates();

void setDefault();
void resetCell();
bool getSolvedFlag() const;

bool getClueFlag() const;

group_ptr getOwnBox() const;

group_ptr getOwnColumn() const;

group_ptr getOwnRow() const;

private:
int cellValue = 0;


int cellNumber = 0;

int rowNumber = 0;
int columnNumber = 0;
int boxNumber = 0;

QSet<int> candidates{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };

group_ptr ownRow;
group_ptr ownColumn;
group_ptr ownBox;

bool solvedFlag = false;
bool clueFlag = false;
};

#endif // CELL_H
