#include "wing.h"
#include <QDebug>

YWing::YWing()
//  : AbstractTechnics(this)
{
}


//try cell 3, 81, 18
QVector<YWing>  YWing::findTechnics(const QSharedPointer<Sudoku>  &sudoku)
{
  QVector<YWing> solutions;


  QMap<int, QSet<int> > twoCandidateCells;

  sudoku->scanGrid();
  auto cells = sudoku->getEmptyCells();

  for (const auto &c: cells)  //first distillation to get two size candidates
    {
      auto candidates = c->getCandidates();
      if (candidates.size() == 2)
        twoCandidateCells.insert(c->getCellNumber(), candidates);
    }
  qDebug() << "twoCandidateCells" << twoCandidateCells.size();

  auto findRelatedCells = [ = ](const int& cellNo)->QSet<int> {
                            QSet<int> relatedCells;
                            auto inter = sudoku->getCommonCells(cellNo);

                            for (const auto& icell: inter)
                              if (twoCandidateCells.count(icell) > 0 && icell != cellNo)
                                relatedCells.insert(icell);

                            return relatedCells;
                          };

  auto findConnectedCells = [ = ](const QSet<int>& potential, const QSet<int>& relatedCells)->QVector<int> {
                              QVector<int> cellNo;
                              QMapIterator<int, QSet<int> > i(twoCandidateCells);

                              while (i.hasNext())
                                {
                                  i.next();
                                  auto no = i.key();
                                  auto candidates = i.value();
                                  if (candidates == potential)
                                    if (relatedCells.find(no) != relatedCells.constEnd())
                                      cellNo.push_back(no);
                                }
                              return cellNo;
                            };

  auto checkSameGroups = [ = ](int c1, int c2, int c3)->bool {
                           bool res = false;


                           res |= sudoku->IsSameGroup(Sudoku::ROW, { c1, c2, c3 });
                           res |= sudoku->IsSameGroup(Sudoku::COLUMN, { c1, c2, c3 });
                           res |= sudoku->IsSameGroup(Sudoku::BOX, { c1, c2, c3 });
                           return res;
                         };

  QMapIterator<int, QSet<int> > i(twoCandidateCells);

  while (i.hasNext())
    {
      i.next();

      auto relatedCells = findRelatedCells(i.key());

      if (relatedCells.size() == 0)
        continue;

      QSetIterator<int > setIt(i.value());
      int targetCellNumber = i.key();
      int potX = setIt.next();
      int potY = setIt.next();
      int potZ = 0;

      for (const auto &rc: relatedCells)
        {
          auto cell = twoCandidateCells.find(rc);

          cell.key();   //cell number

          auto rcCandidates = cell.value();   // candidate

          if (rcCandidates.find(potX) != rcCandidates.constEnd() && rcCandidates.find(potY) != rcCandidates.constEnd())
            continue;


          if (rcCandidates.find(potX) != rcCandidates.end())
            {
              for (const auto& it:rcCandidates)
                if (it != potX && it != potY)     //to prevent the same XY
                  potZ = it;
            }
          else if (rcCandidates.find(potY) != rcCandidates.end())
            {
              for (const auto& it:rcCandidates)
                if (it != potY && it != potX)
                  potZ = it;
            }
          else
            {
              continue;
            }

          if (potZ == 0)
            continue;

          YWing xywing;       //Arbitrator
          xywing.X = potX;
          xywing.Y = potY;
          xywing.Z = potZ;

          QSet<int> potCell2{ potY, potZ };
          QSet<int> potCell3{ potX, potZ };
          QVector<int> SecondCellNumber = findConnectedCells(potCell2, relatedCells);
          QVector<int> ThirdCellNumber = findConnectedCells(potCell3, relatedCells);

          if (SecondCellNumber.size() != 0 && ThirdCellNumber.size() != 0)
            {
              qDebug() << "targetCellNumber" << targetCellNumber;
              qDebug() << "SecondCellNumber" << SecondCellNumber.size();
              qDebug() << "ThirdCellNumber" << ThirdCellNumber.size();
              xywing.cellNumbers[0] = targetCellNumber;

              for (const auto& sec:SecondCellNumber)
                {
                  for (const auto& third: ThirdCellNumber)
                    {
                      xywing.cellNumbers[1] = sec;
                      xywing.cellNumbers[2] = third;
                      if (checkSameGroups(xywing.cellNumbers[0], xywing.cellNumbers[1], xywing.cellNumbers[2]) != true)
                        {
                          xywing.intersectedCells = sudoku->getIntersectCells(sec, third);
                          xywing.intersectedCells.remove(targetCellNumber); //remove the target cell
                          solutions.push_back(xywing);
                        }
                    }
                }

              break;
            }
        }
    }



  return solutions;


  //  wing.X = 7; wing.Y = 1;  wing.Z = 2;
  //  wing.cellNumbers[0] = 3;
  //  wing.cellNumbers[1] = 18;
  //  wing.cellNumbers[2] = 81;
  //  solutions.push_back(wing);


  //  wing.X = 2; wing.Y = 4;  wing.Z = 8;
  //  wing.cellNumbers[0] = 11;
  //  wing.cellNumbers[1] = 16;
  //  wing.cellNumbers[2] = 23;
  //  solutions.push_back(wing);

  //  return solutions;
  //  auto cell_3 = sudoku->getCell(3);
  //  auto cell_81 = sudoku->getCell(81);
  //  auto cell_18 = sudoku->getCell(18);
  //  auto cell_80 = sudoku->getCell(80);   //value

  //  QMap<int, QColor> cellCandidates;

  //  int X = 3, Y = 1, Z = 7;

  //  cellCandidates.insert(X, Qt::yellow);
  //  cellCandidates.insert(Y, Qt::red);
  //  effectedCells.insert(3, cellCandidates);

  //  cellCandidates.remove(Y);
  //  cellCandidates.insert(Z, Qt::red);
  //  effectedCells.insert(18, cellCandidates);

  //  cellCandidates.remove(X);
  //  cellCandidates.insert(Y, Qt::yellow);
  //  effectedCells.insert(81, cellCandidates);


  //  cellCandidates.clear();
  //  effectedCells.insert(81, cellCandidates);
}
