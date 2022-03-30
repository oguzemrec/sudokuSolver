#include "wing.h"
#include <QDebug>

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

  auto findRelatedCells = [ = ](const int& cellNo)->QSet<int> {
                            QSet<int> relatedCells;
                            auto inter = sudoku->getCommonCells(cellNo);

                            for (const auto& icell: inter)
                              if (twoCandidateCells.count(icell) > 0 && icell != cellNo) //check if it's two candiate or not and not equal the pivot cell number
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
      int pivotCellNumber = i.key();
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

          YWing xyzWing;       //Arbitrator
          xyzWing.X = potX;
          xyzWing.Y = potY;
          xyzWing.Z = potZ;

          QSet<int> potCell2{ potY, potZ };
          QSet<int> potCell3{ potX, potZ };
          QVector<int> SecondCellNumber = findConnectedCells(potCell2, relatedCells);
          QVector<int> ThirdCellNumber = findConnectedCells(potCell3, relatedCells);

          if (SecondCellNumber.size() != 0 && ThirdCellNumber.size() != 0)
            {
              xyzWing.cellNumbers[0] = pivotCellNumber;

              for (const auto& sec:SecondCellNumber)
                {
                  for (const auto& third: ThirdCellNumber)
                    {
                      xyzWing.cellNumbers[1] = sec;
                      xyzWing.cellNumbers[2] = third;
                      if (checkSameGroups(xyzWing.cellNumbers[0], xyzWing.cellNumbers[1], xyzWing.cellNumbers[2]) != true)
                        {
                          xyzWing.intersectedCells = sudoku->getIntersectCells(sec, third);
                          xyzWing.intersectedCells.remove(pivotCellNumber); //remove the target cell
                          solutions.push_back(xyzWing);
                        }
                    }
                }

              break;
            }
        }
    }



  return solutions;
}

QVector<XYZWing> XYZWing::findTechnics(const QSharedPointer<Sudoku> &sudoku)
{
  QVector<XYZWing> solutions;
  QMap<int, QSet<int> > threeCandidateCells;


  sudoku->scanGrid();

  auto cells = sudoku->getEmptyCells();

  for (const auto &c: cells)    //first distillation to get three size candidates
    {
      auto candidates = c->getCandidates();
      if (candidates.size() == 3)
        threeCandidateCells.insert(c->getCellNumber(), candidates);
    }

  auto findIntersectedTwoCandCells = [ = ](const int& cellNo, const QSet<int>& pivotCandidates)->QSet<int> {
                                       QSet<int> relatedCells;

                                       auto common = sudoku->getCommonCells(cellNo);

                                       for (const auto& icell: common)
                                         {
                                           auto icellCandidates = sudoku->getCell(icell)->getCandidates();
                                           if (icellCandidates.size() == 2)
                                             {
                                               auto temp = pivotCandidates;
                                               if (auto inter = temp.intersect(icellCandidates); inter.size() == 2)
                                                 relatedCells.insert(icell);
                                             }
                                         }


                                       return relatedCells;
                                     };

  auto findConnectedCells = [ = ](const QSet<int>& potential, const QSet<int>& relatedCells, QMapIterator<int, QSet<int> > twoCandidateCells)->QVector<int> {
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

  QMapIterator<int, QSet<int> > i(threeCandidateCells);

  while (i.hasNext())
    {
      i.next();

      auto relatedCells = findIntersectedTwoCandCells(i.key(), i.value());

      QMap<int, QSet<int> > twoRelatedCandidateCells;
      for (const auto &c: relatedCells)    //searh two candidates Cells in related cells for two cells
        {
          const auto& candidates = sudoku->getCell(c)->getCandidates();
          twoRelatedCandidateCells.insert(c, candidates);
        }

      if (relatedCells.size() == 0)
        continue;

      QSetIterator<int> setIt(i.value());
      int pivotCellNumber = i.key();
      int potX = setIt.next();
      int potY = setIt.next();
      int potZ = setIt.next();



      const auto createSolutionMethod = [ = ]( QSet<int> potCell2, QSet<int> potCell3, int X, int Y, int common) ->QVector<XYZWing> {
                                          QVector<XYZWing> solution;
                                          QVector<int> SecondCells = findConnectedCells(potCell2, relatedCells, twoRelatedCandidateCells);
                                          QVector<int> ThirdCells = findConnectedCells(potCell3, relatedCells, twoRelatedCandidateCells);


                                          XYZWing xyzWing; //Arbitrator

                                          xyzWing.X = X;
                                          xyzWing.Y = Y;
                                          xyzWing.Z = common;

                                          xyzWing.cellNumbers[0] = pivotCellNumber;
                                          for (const auto& sec:SecondCells)
                                            {
                                              for (const auto& third: ThirdCells)
                                                {
                                                  xyzWing.cellNumbers[1] = sec;
                                                  xyzWing.cellNumbers[2] = third;
                                                  if (checkSameGroups(xyzWing.cellNumbers[0], xyzWing.cellNumbers[1], xyzWing.cellNumbers[2]) != true)
                                                    {
                                                      xyzWing.intersectedCells = sudoku->getIntersectCells(pivotCellNumber, sec, third);
                                                      xyzWing.intersectedCells.remove(pivotCellNumber); //remove the target cell

                                                      solution.push_back(xyzWing);
                                                      qDebug() << xyzWing.getInfo();
                                                    }
                                                }
                                            }
                                          return solution;
                                        };


      solutions.append(createSolutionMethod(QSet<int> { potY, potX }, QSet<int> { potX, potZ }, potZ, potY, potX));
      solutions.append(createSolutionMethod(QSet<int> { potY, potX }, QSet<int> { potY, potZ }, potX, potZ, potY));
      solutions.append(createSolutionMethod(QSet<int> { potY, potZ }, QSet<int> { potX, potZ }, potX, potY, potZ));
    }
  return solutions;
}
