#include "cell.h"
 #include <algorithm>
#include <functional>
void Cell::showBoxCells()
{
  if (ownBox)
    ownBox->show();
}

void Cell::showColumnCells()
{
  if (ownColumn)
    ownColumn->show();
}

void Cell::showRowCells()
{
  if (ownRow)
    ownRow->show();
}

int Cell::getCellNumber() const
{
  return cellNumber;
}

void Cell::setCellNumber(int value)
{
  cellNumber = value;
}

int Cell::getRowNumber() const
{
  return rowNumber;
}

void Cell::setRowNumber(int value)
{
  rowNumber = value;
}

int Cell::getColumnNumber() const
{
  return columnNumber;
}

void Cell::setColumnNumber(int value)
{
  columnNumber = value;
}

int Cell::getBoxNumber() const
{
  return boxNumber;
}

void Cell::setBoxNumber(int value)
{
  boxNumber = value;
}

int Cell::getCellValue() const
{
  return cellValue;
}

void Cell::setCellValue(int value)
{
  cellValue = value;
  solvedFlag = true;
  //candidates.clear();
}

void Cell::setCellClue(int value)
{
  cellValue = value;
  clueFlag = true;
  //candidates.clear();
}

void Cell::removeCellClue()
{
  setDefault();
}

void Cell::setOwnRow(group_ptr value)
{
  ownRow = value;
}

void Cell::setOwnColumn(group_ptr value)
{
  ownColumn = value;
}

void Cell::setOwnBox(group_ptr value)
{
  ownBox = value;
}

void Cell::addCandidate(int num)
{
  candidates.insert(num);
}
void Cell::updateCandidates(QSet<int> can)
{
  candidates = can;
}

void Cell::removeCandidate(int num)
{
  auto it = candidates.find(num);

  if (it != candidates.end())
    candidates.erase(it);
}

Cell::ToggleCandidateSts Cell::toggleCandidate(int num)
{
  auto it = candidates.find(num);
  auto res = ToggleCandidateSts::REMOVED;

  if (it != candidates.end())
    candidates.erase(it);
  else
    {
      candidates.insert(num);
      res = ToggleCandidateSts::ADDED;
    }

  return res;
}

QSet<int> Cell::getCandidates()const
{
  return candidates;
}

void Cell::setDefault()
{
  cellValue = 0;
  solvedFlag = false;
  clueFlag = false;
}

void Cell::resetCell()
{
  cellValue = 0;
  solvedFlag = false;
  clueFlag = false;
  //candidates = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  candidates = { 1, 2, 3, 4 };
}

bool Cell::getSolvedFlag() const
{
  return solvedFlag;
}

bool Cell::getClueFlag() const
{
  return clueFlag;
}

const group_ptr&  Cell::getOwnBox() const
{
  return ownBox;
}

const group_ptr&  Cell::getOwnColumn() const
{
  return ownColumn;
}

const group_ptr&  Cell::getOwnRow() const
{
  return ownRow;
}
