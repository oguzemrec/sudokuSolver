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
  solved = true;
}

void Cell::setCellClue(int value)
{
  cellValue = value;
  clueCell = true;
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

QSet<int> Cell::getCandidates()
{
  return candidates;
}

void Cell::setDefault()
{
  cellValue = 0;
  solved = false;
  clueCell = false;
}

bool Cell::getSolvedFlag() const
{
  return solved;
}

bool Cell::getClueFlag() const
{
  return clueCell;
}

group_ptr Cell::getOwnBox() const
{
  return ownBox;
}

group_ptr Cell::getOwnColumn() const
{
  return ownColumn;
}

group_ptr Cell::getOwnRow() const
{
  return ownRow;
}