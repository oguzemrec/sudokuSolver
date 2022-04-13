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
      if (c->getClueFlag() == true || c->getSolvedFlag() == true)
        continue;
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
      if (c->getClueFlag() == true || c->getSolvedFlag() == true)
        continue;

      auto candidates = c->getCandidates();
      if (candidates.size() == 3)
        threeCandidateCells.insert(c->getCellNumber(), candidates);
    }

  auto findIntersectedTwoCandCells = [ = ](const int& cellNo, const QSet<int>& pivotCandidates)->QSet<int> {
                                       QSet<int> relatedCells;

                                       auto common = sudoku->getCommonCells(cellNo);

                                       for (const auto& icell: common)
                                         {
                                           if (sudoku->getCell(icell)->getClueFlag() == true || sudoku->getCell(icell)->getSolvedFlag() == true)
                                             continue;

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


QString XWing::getInfo()
{
  qDebug() << groupNumbers[0] << groupNumbers[1];

  return QObject::tr("X-Wing Z=%1, %2%3-%2%4").arg(Z).arg(strType).arg(groupNumbers[0]).arg(groupNumbers[1]);
}

QVector<XWing> XWing::findTechnics(const QSharedPointer<Sudoku> &sudoku)
{
  auto findTwoSameCandidate = [ = ](const QVector<QSharedPointer<Cell> >& rowCol) ->QVector<sTwoCandidate > {   //cell and candiate
                                QVector<sTwoCandidate> twoSameCandidates;

                                for (int i = 1; i <= 9; ++i) //search for each number
                                  {
                                    QSet<QSharedPointer<Cell> >  potCells;
                                    for (auto c: rowCol)
                                      {
                                        if (c->getClueFlag() == true || c->getSolvedFlag() == true || c->getCandidates().size() == 0)
                                          continue;
                                        auto candidates = c->getCandidates();
                                        if (candidates.find(i) != candidates.end())
                                          potCells.insert(c);
                                      }

                                    if (potCells.size() == 2)
                                      {
                                        sTwoCandidate s(potCells, i);
                                        twoSameCandidates.push_back(s);
                                      }
                                  }

                                return twoSameCandidates;
                              };


  auto checkRowColumn = [ = ](  QSet<QSharedPointer<Cell> > targetCells, QSet<QSharedPointer<Cell> > searchCells, XWingType type) ->bool {  //cell and candiate
                          QSet<int> targetRC;
                          QSet<int> searchRC;

                          if (XWingType::ROW == type)
                            {
                              for (const auto&tCell : targetCells)
                                targetRC.insert(tCell->getColumnNumber());

                              for (const auto&sCell : searchCells)
                                searchRC.insert(sCell->getColumnNumber());
                            }

                          else if (XWingType::COLUMN == type)
                            {
                              for (const auto&tCell : targetCells)
                                targetRC.insert(tCell->getRowNumber());

                              for (const auto&sCell : searchCells)
                                searchRC.insert(sCell->getRowNumber());
                            }

                          return (targetRC == searchRC)? true:false;
                        };

  auto createSolution = [ = ]( sTwoCandidate target, sTwoCandidate search, XWingType type) ->XWing {  //cell and candiate
                          XWing wing;

                          if (type == XWingType::COLUMN)
                            wing.strType = "Column";
                          else if (type == XWingType::ROW)
                            wing.strType = "Row";

                          wing.Z = target.candidate;

                          int cellOrder = 0;

                          auto targetCells = target.cells;


                          for (const auto&tCell : targetCells)
                            {
                              wing.cellNumbers[cellOrder++] = tCell->getCellNumber();


                              if (type == XWingType::COLUMN)
                                wing.groupNumbers[0] = tCell->getColumnNumber();
                              else if (type == XWingType::ROW)
                                wing.groupNumbers[0] = tCell->getRowNumber();
                            }
                          auto searchCells = search.cells;

                          for (const auto&sCell : searchCells)
                            {
                              wing.cellNumbers[cellOrder++] = sCell->getCellNumber();


                              if (type == XWingType::COLUMN)
                                wing.groupNumbers[1] = sCell->getColumnNumber();
                              else if (type == XWingType::ROW)
                                wing.groupNumbers[1] = sCell->getRowNumber();
                            }

                          return wing;
                        };

  auto findSolutions = [ = ]( QVector<QSharedPointer<Group> > group, XWingType type) -> QVector<XWing>  {  //cell and candiate
                         QVector<XWing> solutions;

                         for (int i = 1; i <= 9; ++i)
                           {
                             //get target row
                             auto targetGroupCells = findTwoSameCandidate(group[i - 1]->getCells());

                             if (targetGroupCells.size() == 0)
                               continue;

                             for (int y = 1 + i ; y <= 9; ++y)
                               {
                                 auto searchGroupCells = findTwoSameCandidate(group[y - 1]->getCells());

                                 if (searchGroupCells.size() == 0)
                                   continue;

                                 for (const auto&tar : targetGroupCells)
                                   {
                                     auto targetCandidate = tar.candidate;
                                     for (const auto&ser : searchGroupCells)
                                       {
                                         if (ser.candidate != targetCandidate)
                                           continue;

                                         if (checkRowColumn(tar.cells, ser.cells, type) == true)
                                           solutions.push_back(createSolution(tar, ser, type));

                                         //check if row numbers are the same or not
                                       }
                                   }
                               }
                           }
                         return solutions;
                       };

  QVector<XWing> solutions;

  solutions.append(findSolutions(sudoku->getRows(), XWingType::ROW));
  solutions.append(findSolutions(sudoku->getColumns(), XWingType::COLUMN));
  return solutions;
}
